/*
 * query_having.h
 *
 *  Created on: 3 дек. 2015 г.
 *      Author: stas
 */

#ifndef YS_PGU_QUERY_HAVING_H
#define YS_PGU_QUERY_HAVING_H

#include <ys/pgu/query/cond_expr.h>

namespace ys {
namespace pgu {
namespace query {

class having: public cond_expr {
public:
	having(const char* e = "") :
			cond_expr { e } {
	}
	having(const std::string& e) :
			cond_expr { e } {
	}
	having(const cond_expr& e) :
			cond_expr { e } {
	}

private:
	friend std::ostream& operator <<(std::ostream& os, const having& o) {
		if (o.empty()) return os;
		return os << " having " << o.to_string() << ' ';
	}
};

} /* namespace query */
} /* namespace pgu */
} /* namespace ys */

#endif /* YS_PGU_QUERY_HAVING_H */
