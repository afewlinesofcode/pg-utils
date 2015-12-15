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
#include <ys/basic_expr.h>

namespace ys {
namespace pgu {
namespace query {

template<type Type>
class builder: public ys::basic_expr<builder<Type>> {
public:
	const int type = Type;

	builder(const std::string& relations) {
		_relations &= relations;
	}

	template<typename T = typename std::enable_if<ys::none_of(Type, query::remove), query::columns>>
	typename T::type& columns() {
		return _columns;
	}

	template<typename T = typename std::enable_if<ys::any_of(Type, query::select), query::groupby>>
	typename T::type& groupby() {
		return _groupby;
	}

	template<typename T = typename std::enable_if<ys::any_of(Type, query::select), query::having>>
	typename T::type& having() {
		return _having;
	}

	template<typename T = typename std::enable_if<ys::any_of(Type, query::select), query::limit>>
	typename T::type& limit() {
		return _limit;
	}

	template<typename T = typename std::enable_if<ys::any_of(Type, query::select), query::offset>>
	typename T::type& offset() {
		return _offset;
	}

	template<typename T = typename std::enable_if<ys::any_of(Type, query::select), query::orderby>>
	typename T::type& orderby() {
		return _orderby;
	}

	query::relations& relations() {
		return _relations;
	}

	template<typename T = typename std::enable_if<ys::none_of(Type, query::insert), query::where>>
	typename T::type& where() {
		return _where;
	}

	template<typename T = typename std::enable_if<ys::none_of(Type, query::remove), builder>>
	T::type& operator&=(const query::columns& v) {
		return append_section(_columns, v);
	}

	template<typename T = typename std::enable_if<ys::any_of(Type, query::select), query::builder>>
	T::type& operator&=(const query::groupby& v) {
		return append_section(_groupby, v);
	}

	template<typename T = typename std::enable_if<ys::any_of(Type, query::select), query::builder>>
	T::type& operator&=(const query::having& v) {
		return append_section(_having, v);
	}

	template<typename T = typename std::enable_if<ys::any_of(Type, query::select), query::builder>>
	T::type& operator&=(const query::limit& v) {
		return append_section(_limit, v);
	}

	template<typename T = typename std::enable_if<ys::any_of(Type, query::select), query::builder>>
	T::type& operator&=(const query::offset& v) {
		return append_section(_offset, v);
	}

	template<typename T = typename std::enable_if<ys::any_of(Type, query::select), query::builder>>
	T::type& operator&=(const query::orderby& v) {
		return append_section(_orderby, v);
	}

	builder& operator&=(const query::relations& v) {
		return append_section(_relations, v);
	}

	template<typename T = typename std::enable_if<ys::none_of(Type, query::insert), query::builder>>
	T::type& operator&=(const query::where& v) {
		return append_section(_where, v);
	}

//	template<typename T = typename std::enable_if<Type == query::select, std::string>>
//	typename T::type to_string() const {
//		std::ostringstream s;
//
//		s << "select" << _columns << "from" << _relations <<
//				_where << _groupby << _having << _orderby << _limit << _offset;
//
//		return s.str();
//	}

private:
	template<typename Type>
	builder& append_section(Type s, Type v) {
		s &= v;
		return *this;
	}
	/*
	 * Since std c++11 does not yet support template declarations for variables
	 * the following ones will exist in every specialization.
	 */

	query::relations _relations;
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
