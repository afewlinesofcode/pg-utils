/*
 * expr.h
 *
 *  Created on: 7 дек. 2015 г.
 *      Author: stas
 */

#ifndef YS_STRING_BASIC_EXPR_H
#define YS_STRING_BASIC_EXPR_H

#include <ys/string/expr.h>

namespace ys {
namespace string {

class basic_expr: public expr {
public:
	using expr::expr;

	basic_expr operator()() {
		basic_expr e{};
		e << "(" << str() << ")";
		return e;
	}

	basic_expr& operator+(const basic_expr& e) {
		*this << "+" << e;
		return *this;
	}

	basic_expr& operator-(const basic_expr& e) {
		*this << "-" << e;
		return *this;
	}

	basic_expr& operator*(const basic_expr& e) {
		*this << "*" << e;
		return *this;
	}

	basic_expr& operator/(const basic_expr& e) {
		*this << "/" << e;
		return *this;
	}

	basic_expr& operator==(const basic_expr& e) {
		*this << "==" << e;
		return *this;
	}

	basic_expr& operator!=(const basic_expr& e) {
		*this << "!=" << e;
		return *this;
	}

	basic_expr& operator<(const basic_expr& e) {
		*this << "<" << e;
		return *this;
	}

	basic_expr& operator<=(const basic_expr& e) {
		*this << "<=" << e;
		return *this;
	}

	basic_expr& operator>(const basic_expr& e) {
		*this << ">" << e;
		return *this;
	}

	basic_expr& operator>=(const basic_expr& e) {
		*this << ">=" << e;
		return *this;
	}

	basic_expr& operator||(const basic_expr& e) {
		*this << "||" << e;
		return *this;
	}

	basic_expr& operator&&(const basic_expr& e) {
		*this << "&&" << e;
		return *this;
	}
};

}
 // namespace string
}// namespace ys

#endif /* YS_STRING_BASIC_EXPR_H */
