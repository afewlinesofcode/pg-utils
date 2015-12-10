/*
 * query_groupby.h
 *
 *  Created on: 3 дек. 2015 г.
 *      Author: stas
 */

#ifndef YS_PGU_QUERY_GROUPBY_H
#define YS_PGU_QUERY_GROUPBY_H

#include <ys/expr.h>

namespace ys {
namespace pgu {
namespace query {

class groupby: public ys::expr {
public:
	YS_EXPR_CONSTRUCTORS(groupby);

	groupby operator&(const groupby& e) {
		groupby ret{cstr()};
		ret.append_expr(e, ", ");
		return ret;
	};

	groupby& operator&=(const groupby& e) {
		append_expr(e, ", ");
		return *this;
	}

	std::string str() const override {
		return empty() ? "" : "group by " + cstr();
	}
};

} /* namespace query */
} /* namespace pgu */
} /* namespace ys */

#endif /* YS_PGU_QUERY_GROUPBY_H */
