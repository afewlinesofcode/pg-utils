/*
 * query.h
 *
 *  Created on: 3 дек. 2015 г.
 *      Author: stas
 */

#ifndef YS_PGU_QUERY_BUILDER_H_
#define YS_PGU_QUERY_BUILDER_H_

#include <type_traits>
#include <string>
#include <sstream>

#include <ys/pgu/query/columns.h>
#include <ys/pgu/query/group_by.h>
#include <ys/pgu/query/having.h>
#include <ys/pgu/query/limit.h>
#include <ys/pgu/query/offset.h>
#include <ys/pgu/query/order_by.h>
#include <ys/pgu/query/relations.h>
#include <ys/pgu/query/where.h>

#include <ys/traits.h>
#include <ys/basic_expr.h>

namespace ys {
namespace pgu {
namespace query {

/*!
 * Enumeration of available query operations.
 */
enum type {
	select, //!< For building SELECT query.
	insert, //!< For building INSERT query.
	update, //!< For building UPDATE query.
	remove //!< For building DELETE query.
};

template<query::type Type>
class builder;

template<query::type Type>
std::string assemble(const builder<Type>&);

template<query::type Type>
class builder: public ys::basic_expr<builder<Type>> {
	friend std::string assemble<Type>(const builder<Type>&);

public:
	const int type = Type;

	using builder_type = query::builder<Type>;

	using basic_expr<builder<Type>>::basic_expr;
	using basic_expr<builder<Type>>::operator=;

	template<typename T = typename std::enable_if<
		ys::none_of(Type, query::remove), query::columns>>
		typename T::type& columns() {
			return columns_;
		}

	template<typename T = typename std::enable_if<
		ys::any_of(Type, query::select), query::group_by>>
		typename T::type& group_by() {
			return group_by_;
		}

	template<typename T = typename std::enable_if<
		ys::any_of(Type, query::select), query::having>>
		typename T::type& having() {
			return having_;
		}

	template<typename T = typename std::enable_if<
		ys::any_of(Type, query::select), query::limit>>
		typename T::type& limit() {
			return limit_;
		}

	template<typename T = typename std::enable_if<
		ys::any_of(Type, query::select), query::offset>>
		typename T::type& offset() {
			return offset_;
		}

	template<typename T = typename std::enable_if<
		ys::any_of(Type, query::select), query::order_by>>
		typename T::type& order_by() {
			return order_by_;
		}

	query::relations& relations() {
		return relations_;
	}

	template<typename T = typename std::enable_if<
		ys::none_of(Type, query::insert), query::where>>
		typename T::type& where() {
			return where_;
		}

	template<typename T = typename std::enable_if<
		ys::none_of(Type, query::remove), builder_type>>
		typename T::type& operator&(const query::columns& v) {
			return append_section(columns_, v);
		}

	template<typename T = typename std::enable_if<
		ys::any_of(Type, query::select), builder_type>>
		typename T::type& operator&(const query::group_by& v) {
			return append_section(group_by_, v);
		}

	template<typename T = typename std::enable_if<
		ys::any_of(Type, query::select), builder_type>>
		typename T::type& operator&(const query::having& v) {
			return append_section(having_, v);
		}

	template<typename T = typename std::enable_if<
		ys::any_of(Type, query::select), builder_type>>
		typename T::type& operator&(const query::limit& v) {
			return append_section(limit_, v);
		}

	template<typename T = typename std::enable_if<
		ys::any_of(Type, query::select), builder_type>>
		typename T::type& operator&(const query::offset& v) {
			return append_section(offset_, v);
		}

	template<typename T = typename std::enable_if<
		ys::any_of(Type, query::select), builder_type>>
		typename T::type& operator&(const query::order_by& v) {
			return append_section(order_by_, v);
		}

	builder_type& operator&(const query::relations& v) {
		return append_section(relations_, v);
	}

	template<typename T = typename std::enable_if<
		ys::none_of(Type, query::insert), builder_type>>
		typename T::type& operator&(const query::where& v) {
			return append_section(where_, v);
		}

	std::string str() const {
		return assemble(*this);
	}

private:
	/*
	 * Since std c++11 does not yet support template declarations for variables
	 * all of the followings will exist in every specialization.
	 */

	query::relations relations_;
	query::columns columns_;
	query::where where_;
	query::group_by group_by_;
	query::having having_;
	query::order_by order_by_;
	query::limit limit_;
	query::offset offset_;

	template<typename E>
	builder_type& append_section(E& s, const E& v) {
		s & v;
		return *this;
	}
};

template<>
std::string assemble<type::select>(const builder<type::select>& b) {
	std::ostringstream s;

	s << "select " << b.columns_
		<< " from " << b.relations_;

	if (!b.where_.empty())
		s << " where " << b.where_;

	if (!b.group_by_.empty())
		s << " group by " << b.group_by_;

	if (!b.having_.empty())
		s << " having " << b.having_;

	if (!b.order_by_.empty())
		s << " order by " << b.order_by_;

	if (!b.limit_.empty())
		s << " limit " << b.limit_;

	if (!b.offset_.empty())
		s << " offset " << b.offset_;
	
	//s << "select " << b.columns_
	//    << " from " << b.relations_
	//    << " " << b.where_
	//    << " " << b.group_by_
	//    << " " << b.having_
	//    << " " << b.order_by_
	//    << " " << b.limit_
	//    << " " << b.offset_;

	return s.str();
}

template<>
std::string assemble<type::insert>(const builder<type::insert>& b) {
	std::ostringstream s;

	s << "select " << b.columns_
		<< " from " << b.relations_
		<< " " << b.where_
		<< " " << b.group_by_
		<< " " << b.having_
		<< " " << b.order_by_
		<< " " << b.limit_
		<< " " << b.offset_;

	return s.str();
}

} /* namespace query */
} /* namespace pgu */
} /* namespace ys */

#endif /* YS_PGU_QUERY_BUILDER_H_ */
