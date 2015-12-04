/*
 * query_groupby.h
 *
 *  Created on: 3 дек. 2015 г.
 *      Author: stas
 */

#ifndef YS_PGU_QUERY_GROUPBY_H
#define YS_PGU_QUERY_GROUPBY_H

#include <ys/pgu/query/expr.h>

namespace ys {
namespace pgu {
namespace query {

class groupby: public expr {
public:
	groupby(const char* e = "") :
			expr { e } {
	}
	groupby(const std::string& e) :
			expr { e } {
	}
	groupby(const expr& e) :
			expr { e } {
	}

private:
	friend std::ostream& operator <<(std::ostream& os, const groupby& o) {
		if (o.empty()) return os;
		return os << " group by " << o.to_string() << ' ';
	}
};

} /* namespace query */
} /* namespace pgu */
} /* namespace ys */

#endif /* YS_PGU_QUERY_GROUPBY_H */
