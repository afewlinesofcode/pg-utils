/*
 * basic_expr_compiler.cpp
 *
 *  Created on: 8 дек. 2015 г.
 *      Author: stas
 */

#include <ys/string/basic_expr.h>

namespace ys {
namespace string {

std::string basic_expr_compiler::compile() const {
	std::string str { expr.get_expr() };
	const basic_expr::related_items_type& items { expr.get_items() };

	if (items.empty()) {
		return str;
	}

	for (auto& item: expr.get_items()) {
		basic_expr e = static_cast<basic_expr>(item.e);
		std::string expr_str = e.str();
		str.append(item.t).append(expr_str);
	}

	return "(" + str + ")";
}

}
}
