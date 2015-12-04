/*
 * query_orderby.h
 *
 *  Created on: 3 дек. 2015 г.
 *      Author: stas
 */

#ifndef SRC_YS_PGQ_QUERY_ORDERBY_H_
#define SRC_YS_PGQ_QUERY_ORDERBY_H_

#include <ys/pgu/expr.h>

namespace ys {
namespace pgu {

class query_orderby: public expr {
public:
	query_orderby(const char* e = "") :
			expr { e } {
	}
	query_orderby(const std::string& e) :
			expr { e } {
	}
	query_orderby(const expr& e) :
			expr { e } {
	}

private:
	friend std::ostream& operator <<(std::ostream& os, const query_orderby& o) {
		if (o.empty()) return os;
		return os << " order by " << o.to_string() << ' ';
	}
};

} /* namespace pg */
} /* namespace ys */

#endif /* SRC_YS_PGQ_QUERY_ORDERBY_H_ */
