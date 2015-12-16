/*
 * orderby.h
 *
 *  Created on: 3 дек. 2015 г.
 *      Author: stas
 */

#ifndef YS_PGU_QUERY_ORDERBY_H
#define YS_PGU_QUERY_ORDERBY_H

#include <ys/basic_expr.h>

namespace ys {
namespace pgu {
namespace query {

class orderby: public ys::basic_expr<orderby> {
public:
	using basic_expr::basic_expr;
	using basic_expr::operator=;

	std::string str() const {
		return empty() ? "" : "order by " + cstr();
	}
};

} /* namespace query */
} /* namespace pgu */
} /* namespace ys */

#endif /* YS_PGU_QUERY_ORDERBY_H */
