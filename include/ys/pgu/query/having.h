/*
 * query_having.h
 *
 *  Created on: 3 дек. 2015 г.
 *      Author: stas
 */

#ifndef YS_PGU_QUERY_HAVING_H
#define YS_PGU_QUERY_HAVING_H

#include <ys/expr.h>
#include <ys/pgu/query/cond.h>

namespace ys {
namespace pgu {
namespace query {

class having: public ys::expr {
public:
	YS_EXPR_CONSTRUCTORS(having);

	having(const cond& c) {
		append(c.cstr());
	}

	having& operator&=(const having& e) {
		intelligent_append(e, " and ");
		return *this;
	}

	having& operator|=(const having& e) {
		intelligent_append(e, " or ");
		return *this;
	}

	std::string str() const override {
		return empty() ? "" : "having " + cstr();
	}
};

} /* namespace query */
} /* namespace pgu */
} /* namespace ys */

#endif /* YS_PGU_QUERY_HAVING_H */
