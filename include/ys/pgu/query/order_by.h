/*
 * orderby.h
 *
 *  Created on: 3 дек. 2015 г.
 *      Author: stas
 */

#ifndef YS_PGU_QUERY_ORDER_BY_H_
#define YS_PGU_QUERY_ORDER_BY_H_

#include <ys/basic_expr.h>

namespace ys {
namespace pgu {
namespace query {

class order_by: public ys::basic_expr<order_by> {
public:
	using basic_expr::basic_expr;
	using basic_expr::operator=;

	std::string sep() const {
		return ", ";
	}
};

} /* namespace query */
} /* namespace pgu */
} /* namespace ys */

#endif /* YS_PGU_QUERY_ORDER_BY_H_ */
