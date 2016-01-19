/*
 * cond_expr.h
 *
 *  Created on: 3 дек. 2015 г.
 *      Author: stas
 */

#ifndef YS_PGU_QUERY_COND_EXPR_H_
#define YS_PGU_QUERY_COND_EXPR_H_

#include <ys/pgu/query/basic_expr.h>

namespace ys {
namespace pgu {
namespace query {

class expr: public basic_expr<expr> {
public:
	using basic_expr::basic_expr;
	using basic_expr::operator=;
};

} // namespace query
} // namespace pgu
} // namespace ys

#endif /* YS_PGU_QUERY_COND_EXPR_H_ */
