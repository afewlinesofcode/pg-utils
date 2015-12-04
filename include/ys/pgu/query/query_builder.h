/*
 * query.h
 *
 *  Created on: 3 дек. 2015 г.
 *      Author: stas
 */

#ifndef YS_PGU_QUERY_BUILDER_H
#define YS_PGU_QUERY_BUILDER_H

#include <type_traits>
#include <ys/pgu/cond_expr.h>
#include <ys/pgu/query_columns.h>
#include <ys/pgu/query_groupby.h>
#include <ys/pgu/query_having.h>
#include <ys/pgu/query_limit.h>
#include <ys/pgu/query_offset.h>
#include <ys/pgu/query_orderby.h>
#include <ys/pgu/query_relations.h>
#include <ys/pgu/query_where.h>
#include <string>

#include <ys/traits.h>

namespace ys {
namespace pgu {

template<query::op Type>
class query_builder {
public:
	const int type = Type;

	query_builder(const std::string& relation) {
		this->relation(relation);
	}

	query_builder& relation(const query_relations& relation) {
		_relation = relation;
		return *this;
	}

	template<typename T = query::if_none_of_t<Type, query::remove>>
	query_builder& columns(const query_columns& expr) {
		_columns = expr;
		return *this;
	}

	template<typename = query::if_none_of_t<Type, query::insert>>
	query_builder& where(const query_where& expr) {
		_where = expr;
		return *this;
	}

	template<typename = query::if_any_of_t<Type, query::select>>
	query_builder& groupby(const query_groupby& expr) {
		_groupby = expr;
		return *this;
	}

	template<typename = query::if_any_of_t<Type, query::select>>
	query_builder& having(const query_having& expr) {
		_having = expr;
		return *this;
	}

	template<typename = query::if_any_of_t<Type, query::select>>
	query_builder& orderby(const query_orderby& expr) {
		_orderby = expr;
		return *this;
	}

	template<typename = query::if_any_of_t<Type, query::select>>
	query_builder& limit(const query_limit& count) {
		_limit = count;
		return *this;
	}

	template<typename = query::if_any_of_t<Type, query::select>>
	query_builder& offset(const query_offset& start) {
		_offset = start;
		return *this;
	}

private:
	/*
	 * Since std c++11 does not yet support template declarations for variables
	 * the following ones will exist in every specialization.
	 */

	query_relations _relation;
	query_columns _columns;
	query_where _where;
	query_groupby _groupby;
	query_having _having;
	query_orderby _orderby;
	query_limit _limit;
	query_offset _offset;

//	template<>
//	typename std::enable_if<Type == query::select, std::string>::type to_string() const {
//
//	}
};
//std::string select_query_builder::to_string() const {
//	std::ostringstream s;
//
//	s << "select" << _query._columns << "from" << _query._relation <<
//			_query._where << _query._groupby << _query._having << _query._orderby << _query._limit << _query._offset;
//
//	return s.str();
//}

} /* namespace pgu */
} /* namespace ys */

#endif /* YS_PGU_QUERY_BUILDER_H */
