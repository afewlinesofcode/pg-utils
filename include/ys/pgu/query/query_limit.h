/*
 * query_limit.h
 *
 *  Created on: 3 дек. 2015 г.
 *      Author: stas
 */

#ifndef YS_PGU_QUERY_LIMIT_H
#define YS_PGU_QUERY_LIMIT_H

#include <ostream>
#include <string>

namespace ys {
namespace pgu {
namespace query {

class query_limit {
public:
	query_limit(unsigned count = 0) :
			_value(count) {
	}

	bool empty() const {
		return _value == 0;
	}

	operator std::string() const {
		return to_string();
	}

	std::string to_string() const {
		return std::to_string(_value);
	}

private:
	unsigned _value;

	friend std::ostream& operator <<(std::ostream& os, const query_limit& o) {
		if (o.empty()) return os;
		return os << " limit " << o.to_string() << ' ';
	}
};

} /* namespace query */
} /* namespace pgu */
} /* namespace ys */

#endif /* YS_PGU_QUERY_LIMIT_H */
