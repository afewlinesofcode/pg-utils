/*
 * query_relations.h
 *
 *  Created on: 3 дек. 2015 г.
 *      Author: stas
 */

#ifndef YS_PGU_QUERY_RELATIONS_H
#define YS_PGU_QUERY_RELATIONS_H

#include <ys/pgu/query/expr.h>

namespace ys {
namespace pgu {
namespace query {

class relations: public expr {
public:
	relations(const std::string& e = "") :
			expr { e } {
	}
	relations(const char* e) :
			expr { e } {
	}
	relations(const expr& e) :
			expr { e } {
	}

private:
	friend std::ostream& operator <<(std::ostream& os, const relations& o) {
		if (!o.empty()) os << ' ' << o.to_string() << ' ';
		return os;
	}
};

} /* namespace query */
} /* namespace pgu */
} /* namespace ys */

#endif /* YS_PGU_QUERY_RELATIONS_H */
