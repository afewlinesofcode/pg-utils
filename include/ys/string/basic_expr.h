/*
 * expr.h
 *
 *  Created on: 7 дек. 2015 г.
 *      Author: stas
 */

#ifndef YS_STRING_BASIC_EXPR_H
#define YS_STRING_BASIC_EXPR_H

#define YS_STRING_BASIC_EXPR_DEFINE_SIMPLE(name, type)\
	template<typename T>\
	basic_expr& name(const T& e) {\
		_stream << type << e;\
		return *this;\
	}\
	basic_expr& name(const basic_expr& e) {\
		_stream << type << e.str();\
		return *this;\
	}\


#include <iostream>
#include <string>
#include <vector>
#include <ys/string/expr.h>

namespace ys {
namespace string {

class basic_expr: public expr {
public:
	using expr::expr;

	basic_expr operator()() {
		return basic_expr{"(" + _stream.str() + ")"};
	}

	basic_expr& operator+(const basic_expr& e) {
		_stream << "+" << e;
		return *this;
	}

	basic_expr& operator-(const basic_expr& e) {
		_stream << "-" << e;
		return *this;
	}

	basic_expr& operator*(const basic_expr& e) {
		_stream << "*" << e;
		return *this;
	}

	basic_expr& operator/(const basic_expr& e) {
		_stream << "/" << e;
		return *this;
	}

	basic_expr& operator==(const basic_expr& e) {
		_stream << "==" << e;
		return *this;
	}

	basic_expr& operator!=(const basic_expr& e) {
		_stream << "!=" << e;
		return *this;
	}

	basic_expr& operator<(const basic_expr& e) {
		_stream << "<" << e;
		return *this;
	}

	basic_expr& operator<=(const basic_expr& e) {
		_stream << "<=" << e;
		return *this;
	}

	basic_expr& operator>(const basic_expr& e) {
		_stream << ">" << e;
		return *this;
	}

	basic_expr& operator>=(const basic_expr& e) {
		_stream << ">=" << e;
		return *this;
	}

	basic_expr& operator||(const basic_expr& e) {
		_stream << "||" << e;
		return *this;
	}

	basic_expr& operator&&(const basic_expr& e) {
		_stream << "&&" << e;
		return *this;
	}
};

}
 // namespace string
}// namespace ys

#endif /* YS_STRING_BASIC_EXPR_H */
