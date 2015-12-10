/*
 * query_limit.h
 *
 *  Created on: 3 дек. 2015 г.
 *      Author: stas
 */

#ifndef YS_PGU_QUERY_LIMIT_H
#define YS_PGU_QUERY_LIMIT_H

#include <ys/expr.h>

namespace ys {
namespace pgu {
namespace query {

class limit: public ys::expr {
public:
	YS_EXPR_CONSTRUCTORS(limit);

	columns operator&(const columns& e) {
		columns ret{cstr()};
		ret.append_expr(e, ", ");
		return ret;
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

#endif /* YS_PGU_QUERY_LIMIT_H */
