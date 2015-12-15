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

template<typename E>
class basic_expr {
	template<typename U>
	friend class basic_expr;
public:
	using expr_type = E;

	basic_expr() = default;
	basic_expr(const basic_expr&) = default;
	basic_expr(basic_expr&&) = default;
	template<typename T>
	basic_expr(const basic_expr<T>& e) :
		_str { e._str } {
	}
	template<typename T>
	basic_expr(basic_expr<T>&& e) :
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
	template<typename T>
	explicit basic_expr(T v,
		typename std::enable_if<std::is_integral<T>::value, T>::type* = 0) {
		_str = std::to_string(v);
	}
	basic_expr& operator=(const basic_expr&) = default;
	basic_expr& operator=(basic_expr&&) = default;
	template<typename T>
	basic_expr& operator=(const basic_expr<T>& e) {
		_str = e._str;
		return *this;
	}
	template<typename T>
	basic_expr& operator=(basic_expr<T>&& e) {
		using namespace std;
		swap(_str, e._str);
		return *this;
	}

	bool empty() const {
		return _str.empty();
	}

	std::string sep() const {
		return ", ";
	}

	template<typename T>
	expr_type operator&(const basic_expr<T>& e) {
		return expr_type{cstr()} &= e;
	};

	template<typename T>
	basic_expr& operator&=(const basic_expr<T>& e) {
		append(e);
		return *this;
	}

	std::string str() const {
		return _str;
	}

	const std::string& cstr() const {
		return _str;
	}

protected:
	basic_expr& append(const std::string& s) {
		_str.append(s);
		return *this;
	}

	template<typename ...Args>
	basic_expr& append(const std::string& arg, Args ...args) {
		append(arg);
		append(args...);
		return *this;
	}

	template<typename T>
	basic_expr& append(const basic_expr<T>& e) {
		return append(e, static_cast<expr_type>(*this).sep());
	}

	template<typename T>
	basic_expr& append(const basic_expr<T>& e, const std::string& sep) {
		if (e.empty())
			goto l_append_exit;
		if (empty())
			goto l_append_str;

		append(sep);

		l_append_str: append(e._str);
		l_append_exit: return *this;
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
