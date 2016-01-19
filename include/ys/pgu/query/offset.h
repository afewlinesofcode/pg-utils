/*
 * offset.h
 *
 *  Created on: 3 дек. 2015 г.
 *      Author: stas
 */

#ifndef YS_PGU_QUERY_OFFSET_H_
#define YS_PGU_QUERY_OFFSET_H_

#include <ys/basic_expr.h>

namespace ys {
namespace pgu {
namespace query {

class offset: public ys::basic_expr<offset> {
public:
	using basic_expr::basic_expr;
	using basic_expr::operator=;

	std::string str() const {
		return empty() ? "" : "offset " + cstr();
	}
};

} /* namespace query */
} /* namespace pgu */
} /* namespace ys */

#endif /* YS_PGU_QUERY_OFFSET_H_ */
