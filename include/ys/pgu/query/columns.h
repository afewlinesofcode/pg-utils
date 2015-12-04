/*
 * query_columns.h
 *
 *  Created on: 3 дек. 2015 г.
 *      Author: stas
 */

#ifndef YS_PGU_QUERY_COLUMNS_H
#define YS_PGU_QUERY_COLUMNS_H

#include <ys/pgu/query/expr.h>

namespace ys {
namespace pgu {
namespace query {

class columns: public expr {
public:
	columns(const char* e = "") :
			expr { e } {
	}
	columns(const std::string& e) :
			expr { e } {
	}
	columns(const expr& e) :
			expr { e } {
	}

private:
	friend std::ostream& operator <<(std::ostream& os, const columns& o) {
		return os << ' ' << (o.empty() ? "*" : o.to_string()) << ' ';
	}
};

} /* namespace query */
} /* namespace pgu */
} /* namespace ys */

#endif /* YS_PGU_QUERY_COLUMNS_H */
