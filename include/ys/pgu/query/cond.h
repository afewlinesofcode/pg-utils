/*
 * cond_expr.h
 *
 *  Created on: 3 дек. 2015 г.
 *      Author: stas
 */

#ifndef YS_PGU_QUERY_COND_EXPR_H
#define YS_PGU_QUERY_COND_EXPR_H

#include <ys/expr.h>

#define YS_PGU_QUERY_COND_OP(op, sym)\
	cond op(const cond& e) {\
		cond c{cstr()};\
		c.intelligent_append(e, sym);\
		return c;\
	}

namespace ys {
namespace pgu {
namespace query {

class cond: public ys::expr {
public:
	using expr::expr;

	cond operator()() {
		return cond{"(" + cstr() + ")"};
	}

	YS_PGU_QUERY_COND_OP(operator+, " + ")
	YS_PGU_QUERY_COND_OP(operator-, " - ")
	YS_PGU_QUERY_COND_OP(operator*, " * ")
	YS_PGU_QUERY_COND_OP(operator/, " / ")
	YS_PGU_QUERY_COND_OP(operator==, " = ")
	YS_PGU_QUERY_COND_OP(operator!=, " <> ")
	YS_PGU_QUERY_COND_OP(operator<, " < ")
	YS_PGU_QUERY_COND_OP(operator<=, " <= ")
	YS_PGU_QUERY_COND_OP(operator>, " > ")
	YS_PGU_QUERY_COND_OP(operator>=, " >= ")
	YS_PGU_QUERY_COND_OP(operator&&, " and ")
	YS_PGU_QUERY_COND_OP(operator||, " or ")

	cond& operator&=(const cond& e) {
		intelligent_append(e, " and ");
		return *this;
	}

	cond& operator|=(const cond& e) {
		intelligent_append(e, " or ");
		return *this;
	}
};

} // namespace query
} // namespace pgu
} // namespace ys

#endif /* YS_PGU_QUERY_COND_EXPR_H */
