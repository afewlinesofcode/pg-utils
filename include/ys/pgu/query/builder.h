/*
 * query.h
 *
 *  Created on: 3 дек. 2015 г.
 *      Author: stas
 */

#ifndef YS_PGU_QUERY_BUILDER_H
#define YS_PGU_QUERY_BUILDER_H

#include <type_traits>
#include <string>
#include <sstream>

#include <ys/pgu/query/columns.h>
#include <ys/pgu/query/groupby.h>
#include <ys/pgu/query/having.h>
#include <ys/pgu/query/limit.h>
#include <ys/pgu/query/offset.h>
#include <ys/pgu/query/orderby.h>
#include <ys/pgu/query/relations.h>
#include <ys/pgu/query/where.h>

#include <ys/traits.h>
#include <ys/pgu/query/types.h>
#include <ys/pgu/query/compile.h>

namespace ys {
namespace pgu {
namespace query {

template<type Type>
class builder {
public:
	const int type = Type;

	builder(const std::string& relation) {
		this->relation(relation);
	}

	query::relations& relation() {
		return _relation;
	}

	builder& relation(const relations& relation) {
		_relation = relation;
		return *this;
	}

	template<typename T = typename std::enable_if<ys::none_of(Type, query::remove), query::columns&>>
	typename T::type columns() {
		return _columns;
	}

	template<typename T = typename std::enable_if<ys::none_of(Type, query::remove), builder&>>
	typename T::type columns(const query::columns& expr) {
		_columns = expr;
		return *this;
	}

	template<typename T = typename std::enable_if<ys::none_of(Type, query::insert), query::where&>>
	typename T::type where() {
		return _where;
	}

	template<typename T = typename std::enable_if<ys::none_of(Type, query::insert), builder&>>
	typename T::type where(const query::where& expr) {
		_where = expr;
		return *this;
	}

	template<typename T = typename std::enable_if<ys::any_of(Type, query::select), query::groupby&>>
	typename T::type groupby() {
		return _groupby;
	}

	template<typename T = typename std::enable_if<ys::any_of(Type, query::select), builder&>>
	typename T::type groupby(const query::groupby& expr) {
		_groupby = expr;
		return *this;
	}

	template<typename T = typename std::enable_if<ys::any_of(Type, query::select), query::having&>>
	typename T::type having() {
		return _having;
	}

	template<typename T = typename std::enable_if<ys::any_of(Type, query::select), builder&>>
	typename T::type having(const query::having& expr) {
		_having = expr;
		return *this;
	}

	template<typename T = typename std::enable_if<ys::any_of(Type, query::select), query::orderby&>>
	typename T::type orderby() {
		return _orderby;
	}

	template<typename T = typename std::enable_if<ys::any_of(Type, query::select), builder&>>
	typename T::type orderby(const query::orderby& expr) {
		_orderby = expr;
		return *this;
	}

	template<typename T = typename std::enable_if<ys::any_of(Type, query::select), query::limit&>>
	typename T::type limit() {
		return _limit;
	}

	template<typename T = typename std::enable_if<ys::any_of(Type, query::select), builder&>>
	typename T::type limit(const query::limit& count) {
		_limit = count;
		return *this;
	}

	template<typename T = typename std::enable_if<ys::any_of(Type, query::select), query::offset&>>
	typename T::type offset() {
		return _offset;
	}

	template<typename T = typename std::enable_if<ys::any_of(Type, query::select), builder&>>
	typename T::type offset(const query::offset& start) {
		_offset = start;
		return *this;
	}

	template<typename T = typename std::enable_if<Type == query::select, std::string>>
	typename T::type to_string() const {
		std::ostringstream s;

		s << "select" << _columns << "from" << _relation <<
				_where << _groupby << _having << _orderby << _limit << _offset;

		return s.str();
	}

private:
	/*
	 * Since std c++11 does not yet support template declarations for variables
	 * the following ones will exist in every specialization.
	 */

	relations _relation;
	query::columns _columns;
	query::where _where;
	query::groupby _groupby;
	query::having _having;
	query::orderby _orderby;
	query::limit _limit;
	query::offset _offset;
};

} /* namespace query */
} /* namespace pgu */
} /* namespace ys */

#endif /* YS_PGU_QUERY_BUILDER_H */
