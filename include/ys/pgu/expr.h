/*
 * expr.h
 *
 *  Created on: 7 дек. 2015 г.
 *      Author: stas
 */

#ifndef YS_PGU_EXPR_H
#define YS_PGU_EXPR_H

#include <iostream>
#include <string>

namespace ys {
namespace pgu {

inline std::string
  to_string(const char* __val)
  { return std::string{__val}; }

class expr {
public:
	expr() {}

	template<typename T>
	expr(T e) {
		using namespace std;

		_expr = to_string(e);
	}

	virtual ~expr() {
	}

	std::string str() const {
		return _expr;
	}

	expr& operator+(const expr& e) {
		_expr.append("+").append(e.str());
		return *this;
	}

private:
	std::string _expr;

	friend std::ostream& operator << (std::ostream& os, const expr& e) {
		return os << e.str();
	}
};

}
}

#endif /* YS_PGU_EXPR_H */
