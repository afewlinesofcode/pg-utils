/*
 * query_columns.h
 *
 *  Created on: 3 дек. 2015 г.
 *      Author: stas
 */

#ifndef YS_PGU_QUERY_COLUMNS_H
#define YS_PGU_QUERY_COLUMNS_H

#include <ys/expr.h>

namespace ys {
namespace pgu {
namespace query {

class columns: public ys::expr {
public:
	YS_EXPR_CONSTRUCTORS(columns);

	columns operator&(const columns& e) {
		return columns{cstr()} &= e;
	};

	columns& operator&=(const columns& e) {
		append_expr(e, ", ");
		return *this;
	}

	std::string str() const override {
		return empty() ? "*" : cstr();
	}
};

} /* namespace query */
} /* namespace pgu */
} /* namespace ys */

#endif /* YS_PGU_QUERY_COLUMNS_H */
