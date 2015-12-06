/*
 * query_where.h
 *
 *  Created on: 3 дек. 2015 г.
 *      Author: stas
 */

#ifndef YS_PGU_QUERY_WHERE_H
#define YS_PGU_QUERY_WHERE_H

#include <ys/pgu/query/cond_expr.h>

namespace ys {
namespace pgu {
namespace query {

class where: public cond_expr {
public:
	where(const std::string& e = "") :
			cond_expr { e } {
	}
	where(const char* e) :
			cond_expr { e } {
	}
	where(const cond_expr& e) :
			cond_expr { e } {
	}

private:
	friend std::ostream& operator <<(std::ostream& os, const where& o) {
		if (o.empty()) return os;
		return os << " where " << o.to_string() << ' ';
	}
};

} /* namespace query */
} /* namespace pgu */
} /* namespace ys */

#endif /* YS_PGU_QUERY_WHERE_H */
