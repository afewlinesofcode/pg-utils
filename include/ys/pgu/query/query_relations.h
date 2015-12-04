/*
 * query_relations.h
 *
 *  Created on: 3 дек. 2015 г.
 *      Author: stas
 */

#ifndef SRC_YS_PGQ_QUERY_RELATIONS_H_
#define SRC_YS_PGQ_QUERY_RELATIONS_H_

#include <ys/pgu/expr.h>

namespace ys {
namespace pgu {

class query_relations: public expr {
public:
	query_relations(const std::string& e = "") :
			expr { e } {
	}
	query_relations(const char* e) :
			expr { e } {
	}
	query_relations(const expr& e) :
			expr { e } {
	}

private:
	friend std::ostream& operator <<(std::ostream& os, const query_relations& o) {
		if (!o.empty()) os << ' ' << o.to_string() << ' ';
		return os;
	}
};

} /* namespace pg */
} /* namespace ys */

#endif /* SRC_YS_PGQ_QUERY_RELATIONS_H_ */
