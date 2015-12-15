/*
 * cond_expr.h
 *
 *  Created on: 3 дек. 2015 г.
 *      Author: stas
 */

#ifndef YS_PGU_QUERY_COND_EXPR_H
#define YS_PGU_QUERY_COND_EXPR_H

#include <ys/pgu/query/basic_cond.h>

namespace ys {
namespace pgu {
namespace query {

class cond: public basic_cond<cond> {
public:
	using basic_cond::basic_cond;
};

} // namespace query
} // namespace pgu
} // namespace ys

#endif /* YS_PGU_QUERY_COND_EXPR_H */
