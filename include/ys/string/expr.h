/*
 * expr.h
 *
 *  Created on: 8 дек. 2015 г.
 *      Author: stas
 */

#ifndef YS_STRING_EXPR_H
#define YS_STRING_EXPR_H

#include <sstream>

namespace ys {
namespace string {

class expr {
public:
	expr() = default;
	expr(const expr&) = default;
	expr(expr&&) = default;
	template<typename T>
	explicit expr(const T& e) {
		_stream << e;
	}

	expr& operator=(const expr&) = delete;
	expr& operator=(expr&&) = delete;

	std::string str() const {
		return _stream.str();
	}

protected:
	std::ostringstream _stream;

private:
	friend std::ostream& operator <<(std::ostream& os, const expr& expr) {
		return os << expr.str();
	}
};

} // namespace string
} // namespace ys

#endif /* YS_STRING_EXPR_H */
