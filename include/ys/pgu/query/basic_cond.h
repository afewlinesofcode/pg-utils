/*
 * basic_cond.h
 *
 *  Created on: 15 дек. 2015 г.
 *      Author: stas
 */

#ifndef YS_PGU_QUERY_BASIC_COND_H
#define YS_PGU_QUERY_BASIC_COND_H

#include <ys/basic_expr.h>

#define YS_PGU_QUERY_BASIC_COND_OP(op, sep)\
	template<typename T>\
	expr_type op(const basic_expr<T>& e) {\
		expr_type c{this->cstr()};\
		c.append(e, sep);\
		return c;\
	}

namespace ys {
namespace pgu {
namespace query {

template<typename E>
class basic_cond: public basic_expr<E> {
public:
	using expr_type = E;

	using basic_expr<E>::basic_expr;

	std::string sep() const {
		return " and ";
	}

	expr_type operator()() {
		return expr_type{"(" + this->cstr() + ")"};
	}

	YS_PGU_QUERY_BASIC_COND_OP(operator+, " + ")
	YS_PGU_QUERY_BASIC_COND_OP(operator-, " - ")
	YS_PGU_QUERY_BASIC_COND_OP(operator*, " * ")
	YS_PGU_QUERY_BASIC_COND_OP(operator/, " / ")
	YS_PGU_QUERY_BASIC_COND_OP(operator==, " = ")
	YS_PGU_QUERY_BASIC_COND_OP(operator!=, " <> ")
	YS_PGU_QUERY_BASIC_COND_OP(operator<, " < ")
	YS_PGU_QUERY_BASIC_COND_OP(operator<=, " <= ")
	YS_PGU_QUERY_BASIC_COND_OP(operator>, " > ")
	YS_PGU_QUERY_BASIC_COND_OP(operator>=, " >= ")
	YS_PGU_QUERY_BASIC_COND_OP(operator&&, " and ")
	YS_PGU_QUERY_BASIC_COND_OP(operator||, " or ")

	template<typename T>
	basic_cond& operator|=(const basic_expr<T>& e) {
		this->append(e, " or ");
		return *this;
	}
};

}
}
}

#endif /* YS_PGU_QUERY_BASIC_COND_H */
