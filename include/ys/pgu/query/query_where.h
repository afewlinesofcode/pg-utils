/*
 * query_where.h
 *
 *  Created on: 3 дек. 2015 г.
 *      Author: stas
 */

#ifndef SRC_YS_PGQ_QUERY_WHERE_H_
#define SRC_YS_PGQ_QUERY_WHERE_H_

#include <ys/pgu/cond_expr.h>

namespace ys {
namespace pgu {

class query_where: public cond_expr {
public:
	query_where(const std::string& e = "") :
			cond_expr { e } {
	}
	query_where(const char* e) :
			cond_expr { e } {
	}
	query_where(const cond_expr& e) :
			cond_expr { e } {
	}

private:
	friend std::ostream& operator <<(std::ostream& os, const query_where& o) {
		if (o.empty()) return os;
		return os << " where " << o.to_string() << ' ';
	}
};

} /* namespace pg */
} /* namespace ys */

#endif /* SRC_YS_PGQ_QUERY_WHERE_H_ */
