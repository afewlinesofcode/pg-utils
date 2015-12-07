/*
 * query_columns.h
 *
 *  Created on: 3 дек. 2015 г.
 *      Author: stas
 */

#ifndef YS_PGU_QUERY_COLUMNS_H
#define YS_PGU_QUERY_COLUMNS_H

namespace ys {
namespace pgu {
namespace query {

class columns {
public:
	columns(const char* e = "") :
				_expr { e } {
	}

	columns(const std::string& e) :
			_expr { e } {
	}

	bool empty() const {
		return _expr.empty();
	}

	operator std::string() const {
		return str();
	}

	std::string str() const {
		return empty() ? "*" : _expr;
	}

	std::string compile() const {
		return str();
	}

private:
	std::string _expr;

	friend std::ostream& operator <<(std::ostream& os, const columns& o) {
		return os << o.compile();
	}
};

} /* namespace query */
} /* namespace pgu */
} /* namespace ys */

#endif /* YS_PGU_QUERY_COLUMNS_H */
