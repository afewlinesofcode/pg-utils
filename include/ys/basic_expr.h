/*
 * basic_expr.h
 *
 *  Created on: 15 дек. 2015 г.
 *      Author: stas
 */

#ifndef YS_BASIC_EXPR_H
#define YS_BASIC_EXPR_H

#include <string>

namespace ys {

template<typename T>
using arithmetic_t = typename std::enable_if<std::is_arithmetic<T>::value>::type;

template<typename E>
class basic_expr {
	template<typename U>
	friend class basic_expr;
public:
	using expr_type = E;
	using basic_expr_type = basic_expr<E>;

	basic_expr() = default;
	basic_expr(const basic_expr&) = default;
	basic_expr(basic_expr&&) = default;
	template<typename U>
	basic_expr(const basic_expr<U>& e) :
		_str { e._str } {
	}
	template<typename U>
	basic_expr(basic_expr<U>&& e) :
		_str { std::move(e._str) } {
	}

	explicit basic_expr(const std::string& str) :
		_str { str } {
	}
	explicit basic_expr(std::string&& str) :
		_str { std::move(str) } {
	}
	explicit basic_expr(const char* v) :
		_str { v } {
	}
	template<typename U, typename = arithmetic_t<U>>
	explicit basic_expr(U v) {
		_str = std::to_string(v);
	}

	basic_expr& operator=(const basic_expr&) = default;
	basic_expr& operator=(basic_expr&&) = default;
	template<typename U>
	basic_expr& operator=(const basic_expr<U>& e) {
		_str = e._str;
		return *this;
	}
	template<typename U>
	basic_expr& operator=(basic_expr<U>&& e) {
		using namespace std;
		swap(_str, e._str);
		return *this;
	}
	basic_expr& operator=(const std::string& s) {
		_str = s;
		return *this;
	}
	basic_expr& operator=(std::string&& s) {
		using namespace std;
		swap(_str, s);
		return *this;
	}
	basic_expr& operator=(const char* s) {
		_str = s;
		return *this;
	}
	template<typename U, typename = arithmetic_t<U>>
	basic_expr& operator=(U v) {
		using namespace std;
		_str = to_string(v);
		return *this;
	}

	bool empty() const {
		return _str.empty();
	}

	std::string sep() const {
		return ", ";
	}

	template<typename U>
	expr_type operator&(const basic_expr<U>& e) {
		append_sep(e);
		return *this;
	};
	expr_type operator&(const std::string& s) {
		append_sep(s);
		return *this;
	}
	expr_type operator&(const char* s) {
		append_sep(s);
		return *this;
	}
	template<typename U, typename = arithmetic_t<U>>
	expr_type operator&(U v) {
		append_sep(expr_type{v});
		return *this;
	};

	std::string str() const {
		return _str;
	}

	const std::string& cstr() const {
		return _str;
	}

protected:
	void append(const std::string& s) {
		_str.append(s);
	}
	void append(const char* s) {
		append(std::string{s});
	}
	template<typename U, typename = arithmetic_t<U>>
	void append(U v) {
		append(to_string(v));
	}
	template<typename Arg, typename ...Args>
	void append(const Arg& arg, const Args& ...args) {
		append(arg);
		append(args...);
	}
	template<typename U>
	void append_sep(const basic_expr<U>& e) {
		append_sep(e._str);
	}
	void append_sep(const std::string& s) {
		append_sep(s, static_cast<expr_type>(*this).sep());
	}
	void append_sep(const char* s) {
		append_sep(std::string{s});
	}
	template<typename U, typename = arithmetic_t<U>>
	void append_sep(U v) {
		using namespace std;
		append_sep(to_string(v));
	}
	template<typename U>
	void append_sep(const basic_expr<U>& e, const std::string& sep) {
		append_sep(e._str, sep);
	}
	void append_sep(const std::string& s, const std::string& sep) {
		if (s.empty())
			goto l_append_exit;
		if (empty())
			goto l_append_str;

		append(sep);

		l_append_str: append(s);
		l_append_exit:;
	}
	void append_sep(const char* s, const std::string& sep) {
		append_sep(std::string{s}, sep);
	}
	template<typename U, typename = arithmetic_t<U>>
	void append_sep(U v, const std::string& sep) {
		using namespace std;
		append_sep(to_string(v), sep);
	}

	void replace(const std::string& str) {
		_str = str;
	}
private:
	std::string _str;

	friend std::ostream& operator<<(std::ostream& os, const expr_type& e) {
		os << e.str();
		return os;
	}
};

}

#endif /* YS_BASIC_EXPR_H */
