/*
 * expr.h
 *
 *  Created on: 3 дек. 2015 г.
 *      Author: stas
 */

#ifndef YS_PGU_QUERY_EXPR_H
#define YS_PGU_QUERY_EXPR_H

#include <string>
#include <ostream>

namespace ys {
namespace pgu {
namespace query {

class expr {
public:
	expr(const char* e = "") :
			_expr { e } {
	}
	expr(const std::string& e) :
			_expr { e } {
	}

	void clear() {
		_expr.clear();
	}

	bool empty() const {
		return _expr.empty();
	}

	std::string to_string() const {
		return _expr;
	}

	operator std::string() const {
		return to_string();
	}

protected:
	const std::string& get() const {
		return _expr;
	}

private:
	std::string _expr;

	friend std::ostream& operator <<(std::ostream& os, const expr& expr) {
		return os << expr.to_string();
	}
};

} /* namespace query */
} /* namespace pgu */
} /* namespace ys */

#endif /* YS_PGU_QUERY_EXPR_H */
