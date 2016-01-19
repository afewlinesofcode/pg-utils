/*
 * basic_cond.h
 *
 *  Created on: 15 дек. 2015 г.
 *      Author: stas
 */

#ifndef YS_PGU_QUERY_BASIC_EXPR_H_
#define YS_PGU_QUERY_BASIC_EXPR_H_

#include <ys/basic_expr.h>

namespace ys {
namespace pgu {
namespace query {

template<typename E>
class basic_expr: public ys::basic_expr<E> {
public:
	using expr_type = E;

	using ys::basic_expr<E>::basic_expr;
	using ys::basic_expr<E>::operator=;

	std::string sep() const {
		return " and ";
	}

	expr_type operator()() {
		this->replace("(" + expr_of(*this).str() + ")");
		return *this;
	}

#	define YS_PGU_QUERY_BASIC_COND_OP(op, sep)\
	template<typename T>\
	expr_type op(const ys::basic_expr<T>& e) {\
		this->append_sep(e, sep);\
		return *this;\
	}\
	expr_type op(const std::string& s) {\
		this->append_sep(s, sep);\
		return *this;\
	}\
	expr_type op(std::string&& s) {\
		this->append_sep(s, sep);\
		return *this;\
	}\
	expr_type op(const char* s) {\
		this->append_sep(s, sep);\
		return *this;\
	}\
	template<typename T, typename = typename ys::is_arithmetic<T>::type>\
	expr_type op(T v) {\
		this->append_sep(v, sep);\
		return *this;\
	}
//	YS_PGU_QUERY_BASIC_COND_OP

	YS_PGU_QUERY_BASIC_COND_OP(operator+, " + ");
	YS_PGU_QUERY_BASIC_COND_OP(operator-, " - ");
	YS_PGU_QUERY_BASIC_COND_OP(operator*, " * ");
	YS_PGU_QUERY_BASIC_COND_OP(operator/, " / ");
	YS_PGU_QUERY_BASIC_COND_OP(operator==, " = ");
	YS_PGU_QUERY_BASIC_COND_OP(operator!=, " <> ");
	YS_PGU_QUERY_BASIC_COND_OP(operator<, " < ");
	YS_PGU_QUERY_BASIC_COND_OP(operator<=, " <= ");
	YS_PGU_QUERY_BASIC_COND_OP(operator>, " > ");
	YS_PGU_QUERY_BASIC_COND_OP(operator>=, " >= ");
	YS_PGU_QUERY_BASIC_COND_OP(operator&&, " and ");
	YS_PGU_QUERY_BASIC_COND_OP(operator||, " or ");
};

}
}
}

#endif /* YS_PGU_QUERY_BASIC_EXPR_H_ */