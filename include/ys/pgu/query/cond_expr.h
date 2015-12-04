/*
 * cond_expr.h
 *
 *  Created on: 3 дек. 2015 г.
 *      Author: stas
 */

#ifndef YS_PGU_QUERY_COND_EXPR_H
#define YS_PGU_QUERY_COND_EXPR_H

#include <ys/pgu/query/expr.h>

namespace ys {
namespace pgu {
namespace query {

class cond_expr: public expr {
public:
	cond_expr(const char* e = "") :
			expr { e } {
	}
	cond_expr(const std::string& e) :
			expr { e } {
	}
	cond_expr(const expr& e) :
			expr { e } {
	}
private:
	friend cond_expr operator &&(const cond_expr& expr1, const cond_expr& expr2) {
		return join(expr1, expr2, "and");
	}

	friend cond_expr operator ||(const cond_expr& expr1, const cond_expr& expr2) {
		return join(expr1, expr2, "or");
	}

	friend cond_expr join(const cond_expr& expr1, const cond_expr& expr2, const std::string& glue) {
		if (expr1.empty() && expr2.empty())
			return cond_expr { };
		if (expr1.empty())
			return expr2;
		if (expr2.empty())
			return expr1;

		return std::string("(").
				append(expr1.get()).
				append(") ").
				append(glue).
				append(" (").
				append(expr2.get()).
				append(")");
	}
};

} /* namespace query */
} /* namespace pgu */
} /* namespace ys */

#endif /* YS_PGU_QUERY_COND_EXPR_H */
