/*
 * cond_expr.h
 *
 *  Created on: 3 дек. 2015 г.
 *      Author: stas
 */

#ifndef YS_PGU_QUERY_COND_EXPR_H
#define YS_PGU_QUERY_COND_EXPR_H

#include <ys/string/expr.h>

namespace ys {
namespace pgu {
namespace query {

class cond_expr: public ys::string::expr {
public:
	using expr::expr;

	cond_expr operator()() {
		cond_expr e{};
		e << "(" << str() << ")";
		return e;
	}

	cond_expr& operator+(const cond_expr& e) {
		*this << "+" << e;
		return *this;
	}

	cond_expr& operator-(const cond_expr& e) {
		*this << "-" << e;
		return *this;
	}

	cond_expr& operator*(const cond_expr& e) {
		*this << "*" << e;
		return *this;
	}

	cond_expr& operator/(const cond_expr& e) {
		*this << "/" << e;
		return *this;
	}

	cond_expr& operator==(const cond_expr& e) {
		*this << "=" << e;
		return *this;
	}

	cond_expr& operator!=(const cond_expr& e) {
		*this << "<>" << e;
		return *this;
	}

	cond_expr& operator<(const cond_expr& e) {
		*this << "<" << e;
		return *this;
	}

	cond_expr& operator<=(const cond_expr& e) {
		*this << "<=" << e;
		return *this;
	}

	cond_expr& operator>(const cond_expr& e) {
		*this << ">" << e;
		return *this;
	}

	cond_expr& operator>=(const cond_expr& e) {
		*this << ">=" << e;
		return *this;
	}

	cond_expr& operator||(const cond_expr& e) {
		*this << " or " << e;
		return *this;
	}

	cond_expr& operator&&(const cond_expr& e) {
		*this << " and " << e;
		return *this;
	}
};

} // namespace query
} // namespace pgu
} // namespace ys

#endif /* YS_PGU_QUERY_COND_EXPR_H */
