/*
 * groupby.h
 *
 *  Created on: 3 дек. 2015 г.
 *      Author: stas
 */

#ifndef YS_PGU_QUERY_GROUPBY_H
#define YS_PGU_QUERY_GROUPBY_H

#include <ys/basic_expr.h>

namespace ys {
namespace pgu {
namespace query {

class groupby: public ys::basic_expr<groupby> {
public:
	using basic_expr::basic_expr;

	std::string str() const {
		return empty() ? "" : "group by " + cstr();
	}
};

} /* namespace query */
} /* namespace pgu */
} /* namespace ys */

#endif /* YS_PGU_QUERY_GROUPBY_H */
