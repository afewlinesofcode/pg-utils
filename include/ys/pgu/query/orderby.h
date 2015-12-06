/*
 * query_orderby.h
 *
 *  Created on: 3 дек. 2015 г.
 *      Author: stas
 */

#ifndef YS_PGU_QUERY_ORDERBY_H
#define YS_PGU_QUERY_ORDERBY_H

#include <ys/pgu/query/expr.h>

namespace ys {
namespace pgu {
namespace query {

class orderby: public expr {
public:
	orderby(const char* e = "") :
			expr { e } {
	}
	orderby(const std::string& e) :
			expr { e } {
	}
	orderby(const expr& e) :
			expr { e } {
	}

private:
	friend std::ostream& operator <<(std::ostream& os, const orderby& o) {
		if (o.empty()) return os;
		return os << " order by " << o.to_string() << ' ';
	}
};

} /* namespace query */
} /* namespace pgu */
} /* namespace ys */

#endif /* YS_PGU_QUERY_ORDERBY_H */
