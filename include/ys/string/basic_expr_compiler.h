/*
 * basic_expr_compiler.h
 *
 *  Created on: 8 дек. 2015 г.
 *      Author: stas
 */

#ifndef YS_STRING_BASIC_EXPR_COMPILER_H
#define YS_STRING_BASIC_EXPR_COMPILER_H

#include <string>

namespace ys {
namespace string {

class basic_expr;

class basic_expr_compiler {
public:
	basic_expr_compiler(const basic_expr& expr) :
			expr(expr) {
	}

	std::string compile() const;

	void append(const std::string& expr_str) {
	}
private:
	const basic_expr& expr;
};

}
}

#endif /* YS_STRING_BASIC_EXPR_COMPILER_H */
