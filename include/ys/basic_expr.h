/*
 * basic_expr.h
 *
 *  Created on: 15 дек. 2015 г.
 *      Author: stas
 */

#ifndef YS_BASIC_EXPR_H_
#define YS_BASIC_EXPR_H_

#include <string>
#include <ys/traits.h>
#include <typeinfo>

namespace ys {

/**
 * Base class for building string-based typed expressions.
 */
template<typename E>
class basic_expr {
public:
	/**
	 * A typedef containing type for which basic_expr is being used.
	 */
	using expr_type = E;

	/**
	 * A self type.
	 */
	using basic_expr_type = basic_expr<E>;

	/**
	 * Get a reference to the target expr type.
	 */
	template<typename U>
	U const&
	expr_of(basic_expr<U> const& e) const {
		return static_cast<U const&>(e);
	}

	/**
	 * Default constructor.
	 */
	basic_expr() = default;

	/**
	 * Default copy-constructor.
	 * @param
	 */
	basic_expr(basic_expr const&) = default;

	/**
	 * Default move-constructor.
	 * @param
	 */
	basic_expr(basic_expr&&) = default;

	/**
	 * Copy-constructor.
	 * @param e
	 */
	template<typename U>
	basic_expr(basic_expr<U> const& e) :
		str_ { expr_of(e).str() } {
	}

	/**
	 * Create an expression from a string.
	 * @param s
	 */
	explicit basic_expr(std::string const& s) :
		str_ { s } {
	}

	/**
	 * Create an expression from an r-value referenced string.
	 * @param s
	 */
	explicit basic_expr(std::string&& str) :
		str_ { std::move(str) } {
	}

	/**
	 * Create an expression from a C-string.
	 * @param v
	 */
	explicit basic_expr(char const* v) :
		str_ { v } {
	}

	/**
	 * Create an expression from a value of an arithmetic type.
	 * @param v
	 */
	template<typename U, typename = typename is_arithmetic<U>::type>
	explicit basic_expr(U v) {
		str_ = std::to_string(v);
	}

	/**
	 * Default copy-assignment operator.
	 * @param
	 * @return
	 */
	basic_expr&
	operator=(basic_expr const&) = default;

	/**
	 * Default move-assignment operator.
	 * @param
	 * @return
	 */
	basic_expr&
	operator=(basic_expr&&) = default;

	/**
	 * Copy assignment.
	 * @param e
	 * @return
	 */
	template<typename U>
	basic_expr&
	operator=(basic_expr<U> const& e) {
		str_ = expr_of(e).str();
		return *this;
	}

	/**
	 * Copy specified string into the expression string.
	 * @param s
	 * @return
	 */
	basic_expr&
	operator=(std::string const& s) {
		str_ = s;
		return *this;
	}

	/**
	 * Move string into the expression string.
	 * @param s
	 * @return
	 */
	basic_expr&
	operator=(std::string&& s) {
		using namespace std;
		swap(str_, s);
		return *this;
	}

	/**
	 * Copy C-string into the expression string.
	 * @param s
	 * @return
	 */
	basic_expr&
	operator=(char const* s) {
		str_ = s;
		return *this;
	}

	/**
	 * Copy value of an arithmetic type into the expression string.
	 * @param s
	 * @return
	 */
	template<typename U, typename = typename is_arithmetic<U>::type>
	basic_expr&
	operator=(U v) {
		str_ = std::to_string(v);
		return *this;
	}

	/**
	 * Check whether the expression is empty.
	 * @return
	 */
	bool
	empty() const {
		return str_.empty();
	}

	/**
	 * Get the expression separator for appending.
	 * @return
	 */
	std::string
	sep() const {
		return " ";
	}

	/**
	 * Append an expression of another type.
	 * @param e
	 * @return
	 */
	template<typename U>
	expr_type
	operator&(basic_expr<U> const& e) {
		append_sep(e);
		return *this;
	}

	/**
	 * Append a string.
	 * @param s
	 * @return
	 */
	expr_type
	operator&(std::string const& s) {
		append_sep(s);
		return *this;
	}

	/**
	 * Append a C-string.
	 * @param s
	 * @return
	 */
	expr_type
	operator&(char const* s) {
		append_sep(s);
		return *this;
	}

	/**
	 * Append a value of an arithmetic type.
	 * @param v
	 * @return
	 */
	template<typename U, typename = typename is_arithmetic<U>::type>
	expr_type
	operator&(U v) {
		append_sep(expr_type { v });
		return *this;
	}

	/**
	 * Get the expression string.
	 * @return
	 */
	std::string
	str() const {
		return str_;
	}

protected:
	/**
	 * Get const reference to the expression string.
	 */
	const std::string&
	cstr() const {
		return str_;
	}

	/**
	 * Append a string.
	 * @param s
	 */
	void
	append(std::string const& s) {
		str_.append(s);
	}

	/**
	 * Append a C-string.
	 * @param s
	 */
	void
	append(char const* s) {
		append(std::string { s });
	}

	/**
	 * Append a value of an arithmetic type.
	 * @param v
	 */
	template<typename U, typename = typename is_arithmetic<U>::type>
	void
	append(U v) {
		append(std::to_string(v));
	}

	/**
	 * Append multiple values.
	 * @param arg
	 * @param args
	 */
	template<typename Arg, typename ...Args>
	void
	append(Arg const& arg, Args const& ...args) {
		append(arg);
		append(args...);
	}

	/**
	 * Append an expression of another type.
	 * @param e
	 */
	template<typename U>
	void
	append_sep(basic_expr<U> const& e) {
		append_sep(expr_of(e).str());
	}

	void
	append_sep(std::string const& s) {
		append_sep(s, expr_of(*this).sep());
	}

	void
	append_sep(char const* s) {
		append_sep(std::string { s });
	}

	template<typename U, typename = typename is_arithmetic<U>::type>
	void
	append_sep(U v) {
		append_sep(std::to_string(v));
	}

	/**
	 * Append an expression of another type with a specified separator.
	 * @param s Appended string.
	 * @param sep Appended separator.
	 */
	template<typename U>
	void
	append_sep(basic_expr<U> const& e, std::string const& sep) {
		append_sep(expr_of(e).str(), sep);
	}

	/**
	 * Append a string (possibly with a specified separator).
	 * @param s Appended string.
	 * @param sep Appended separator.
	 */
	void
	append_sep(std::string const& s, std::string const& sep) {
		if (s.empty())
			goto l_append_exit;
		if (empty())
			goto l_append_str;

		append(sep);

		l_append_str: append(s);
		l_append_exit: ;
	}

	void
	append_sep(char const* s, std::string const& sep) {
		append_sep(std::string { s }, sep);
	}

	template<typename U, typename = typename is_arithmetic<U>::type>
	void
	append_sep(U v, std::string const& sep) {
		append_sep(std::to_string(v), sep);
	}

	/**
	 * Replace the expression string with string specified.
	 * @param str A string to replace with.
	 */
	void
	replace(std::string const& str) {
		str_ = str;
	}
private:
	/**
	 * An expression string.
	 */
	std::string str_;

	friend
	std::ostream&
	operator<<(std::ostream& os, expr_type const& e) {
		os << e.str();
		return os;
	}
};

}

#endif /* YS_BASIC_EXPR_H_ */
