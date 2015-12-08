/*
 * expr.h
 *
 *  Created on: 7 дек. 2015 г.
 *      Author: stas
 */

#ifndef YS_STRING_BASIC_EXPR_H
#define YS_STRING_BASIC_EXPR_H

#define YS_STRING_BASIC_EXPR_DEFINE_M(name, type)\
	template<typename T>\
	basic_expr& name(const T& e) {\
		return static_cast<basic_expr&>(append(type, basic_expr { e }));\
	}\
	basic_expr& name(const basic_expr& e) {\
		return static_cast<basic_expr&>(append(type, e));\
	}\


#include <iostream>
#include <string>
#include <vector>
#include <ys/string/expr.h>
#include <ys/string/basic_expr_compiler.h>

namespace ys {
namespace string {

class basic_expr: public expr {
	friend class basic_expr_compiler;
public:
	using expr::expr;

	YS_STRING_BASIC_EXPR_DEFINE_M(add, "+")
	YS_STRING_BASIC_EXPR_DEFINE_M(sub, "-")
	YS_STRING_BASIC_EXPR_DEFINE_M(mul, "*")
	YS_STRING_BASIC_EXPR_DEFINE_M(div, "/")
	YS_STRING_BASIC_EXPR_DEFINE_M(lt, "<")
	YS_STRING_BASIC_EXPR_DEFINE_M(lte, "<=")
	YS_STRING_BASIC_EXPR_DEFINE_M(gt, ">")
	YS_STRING_BASIC_EXPR_DEFINE_M(gte, ">=")

	basic_expr& operator+(const basic_expr& e) {
		return add(e);
	}

	basic_expr& operator-(const basic_expr& e) {
		return sub(e);
	}

	basic_expr& operator*(const basic_expr& e) {
		return mul(e);
	}

	basic_expr& operator/(const basic_expr& e) {
		return div(e);
	}

	basic_expr& operator<(const basic_expr& e) {
		return lt(e);
	}

	basic_expr& operator<=(const basic_expr& e) {
		return lte(e);
	}

	basic_expr& operator>(const basic_expr& e) {
		return gt(e);
	}

	basic_expr& operator>=(const basic_expr& e) {
		return gte(e);
	}

	std::string str() const override {
		return (basic_expr_compiler{*this}).compile();
	}
};

} // namespace string
} // namespace ys

#endif /* YS_STRING_BASIC_EXPR_H */
