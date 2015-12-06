/*
 * query_offset.h
 *
 *  Created on: 3 дек. 2015 г.
 *      Author: stas
 */

#ifndef YS_PGU_QUERY_OFFSET_H
#define YS_PGU_QUERY_OFFSET_H

#include <ostream>
#include <string>

namespace ys {
namespace pgu {
namespace query {

class offset {
public:
	offset(unsigned count = 0) :
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

	friend std::ostream& operator <<(std::ostream& os, const offset& o) {
		if (o.empty()) return os;
		return os << " offset " << o.to_string() << ' ';
	}
};

} /* namespace query */
} /* namespace pgu */
} /* namespace ys */

#endif /* YS_PGU_QUERY_OFFSET_H */
