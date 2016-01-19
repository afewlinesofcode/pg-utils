/*
 * having.h
 *
 *  Created on: 3 дек. 2015 г.
 *      Author: stas
 */

#ifndef YS_PGU_QUERY_HAVING_H_
#define YS_PGU_QUERY_HAVING_H_

#include <ys/pgu/query/basic_cond.h>

namespace ys {
namespace pgu {
namespace query {

class having: public basic_cond<having> {
public:
	using basic_cond::basic_cond;
	using basic_cond::operator=;

	std::string str() const {
		return empty() ? "" : "having " + cstr();
	}
};

} /* namespace query */
} /* namespace pgu */
} /* namespace ys */

#endif /* YS_PGU_QUERY_HAVING_H_ */
