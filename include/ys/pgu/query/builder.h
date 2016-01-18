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

  template<typename T = typename std::enable_if<
    ys::none_of(Type, query::remove), query::columns>>
  typename T::type& columns() {
    return _columns;
  }
  
  template<typename T = typename std::enable_if<
    ys::any_of(Type, query::select), query::groupby>>
  typename T::type& groupby() {
    return _groupby;
  }
  
  template<typename T = typename std::enable_if<
    ys::any_of(Type, query::select), query::having>>
  typename T::type& having() {
    return _having;
  }
  
  template<typename T = typename std::enable_if<
    ys::any_of(Type, query::select), query::limit>>
  typename T::type& limit() {
    return _limit;
  }
  
  template<typename T = typename std::enable_if<
    ys::any_of(Type, query::select), query::offset>>
  typename T::type& offset() {
    return _offset;
  }
  
  template<typename T = typename std::enable_if<
    ys::any_of(Type, query::select), query::orderby>>
  typename T::type& orderby() {
    return _orderby;
  }
  
  query::relations& relations() {
    return _relations;
  }
  
  template<typename T = typename std::enable_if<
    ys::none_of(Type, query::insert), query::where>>
  typename T::type& where() {
    return _where;
  }
  
  template<typename T = typename std::enable_if<
    ys::none_of(Type, query::remove), builder_type>>
  typename T::type& operator&(const query::columns& v) {
    return append_section(_columns, v);
  }
  
  template<typename T = typename std::enable_if<
    ys::any_of(Type, query::select), builder_type>>
  typename T::type& operator&(const query::groupby& v) {
    return append_section(_groupby, v);
  }
  
  template<typename T = typename std::enable_if<
    ys::any_of(Type, query::select), builder_type>>
  typename T::type& operator&(const query::having& v) {
    return append_section(_having, v);
  }
  
  template<typename T = typename std::enable_if<
    ys::any_of(Type, query::select), builder_type>>
  typename T::type& operator&(const query::limit& v) {
    return append_section(_limit, v);
  }
  
  template<typename T = typename std::enable_if<
    ys::any_of(Type, query::select), builder_type>>
  typename T::type& operator&(const query::offset& v) {
    return append_section(_offset, v);
  }
  
  template<typename T = typename std::enable_if<
    ys::any_of(Type, query::select), builder_type>>
  typename T::type& operator&(const query::orderby& v) {
    return append_section(_orderby, v);
  }
  
  builder& operator&(const query::relations& v) {
    return append_section(_relations, v);
  }
  
  template<typename T = typename std::enable_if<
    ys::none_of(Type, query::insert), builder_type>>
  typename T::type& operator&(const query::where& v) {
    return append_section(_where, v);
  }
  
  std::string str() const {
    return assemble(*this);
  }
  
private:
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

  template<typename E>
  builder_type& append_section(E& s, const E& v) {
    s & v;
    return *this;
  }
};

template<>
std::string assemble<type::select>(const builder<type::select>& b) {
  std::ostringstream s;
  
  s << "select " << b._columns
    << " from " << b._relations
    << " " << b._where
    << " " << b._groupby
    << " " << b._having
    << " " << b._orderby
    << " " << b._limit
    << " " << b._offset;
  
  return s.str();
}

template<>
std::string assemble<type::insert>(const builder<type::insert>& b) {
  std::ostringstream s;
  
  s << "select " << b._columns
    << " from " << b._relations
    << " " << b._where
    << " " << b._groupby
    << " " << b._having
    << " " << b._orderby
    << " " << b._limit
    << " " << b._offset;
  
  return s.str();
}

} /* namespace query */
} /* namespace pgu */
} /* namespace ys */

#endif /* YS_PGU_QUERY_BUILDER_H */
