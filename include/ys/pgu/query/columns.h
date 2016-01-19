/*
 * query_columns.h
 *
 *  Created on: 3 дек. 2015 г.
 *      Author: stas
 */

#ifndef YS_PGU_QUERY_COLUMNS_H_
#define YS_PGU_QUERY_COLUMNS_H_

#include <ys/basic_expr.h>

namespace ys {
namespace pgu {
namespace query {

class columns: public ys::basic_expr<columns> {
public:
	using basic_expr::basic_expr;
	using basic_expr::operator=;

	std::string sep() const {
		return ", ";
	}

	std::string str() const {
		return empty() ? "*" : cstr();
	}
};

} /* namespace query */
} /* namespace pgu */
} /* namespace ys */

#endif /* YS_PGU_QUERY_COLUMNS_H_ */
