/*
 * query_type.h
 *
 *  Created on: 3 дек. 2015 г.
 *      Author: stas
 */

#ifndef YS_PGU_QUERY_H
#define YS_PGU_QUERY_H

#include <type_traits>
#include <ys/traits.h>
#include <ys/pgu/types.h>

namespace ys {
namespace pgu {

/*!
 * \brief A facade class for query builder.
 * Contains factory methods for creating query builder of certain type
 * and some utility methods.
 */
struct query {
	/*!
	 * Enable declaration in Val is one of Args.
	 */
	template<query_op Val, query_op ...Args>
	struct if_any_of {
		template<typename T = typename std::enable_if<ys::any_of(Val, Args...)>::type>
		using type = T;

	};

	/*!
	 * Enable declaration in Val is none of Args.
	 */
	template<query_op Val, query_op ...Args>
	struct if_none_of {
		template<typename T = typename std::enable_if<ys::none_of(Val, Args...)>::type>
		using type = T;

	};

	/*!
	 * A helper type for query::if_any_of.
	 */
	template<query_op Val, query_op ...Args>
	using if_any_of_t = typename if_any_of<Val, Args...>::type;

	/*!
	 * A helper type for query::if_none_of.
	 */
	template<query_op Val, query_op ...Args>
	using if_none_of_t = typename if_none_of<Val, Args...>::type;

	/*!
	 * A factory method for creating a SELECT query.
	 * @param relation A relation name on which the query will be built.
	 * @return
	 */
	static void select_from(const std::string& relation) {
		auto obj = query_builder<select>(relation);
	}

	/*!
	 * A factory method for creating an INSERT query.
	 * @param relation A relation name on which the query will be built.
	 * @return
	 */
//	static query_builder insert_into(const std::string& relation) {
//		return query_builder<insert>(relation);
//	}

	/*!
	 * A factory method for creating an UPDATE query.
	 * @param relation A relation name on which the query will be built.
	 * @return
	 */
//	static query_builder update_in(const std::string& relation) {
//		return query_builder<update>(relation);
//	}

	/*!
	 * A factory method for creating a DELETE query.
	 * @param relation A relation name on which the query will be built.
	 * @return
	 */
//	static query_builder delete_from(const std::string& relation) {
//		return query_builder<remove>(relation);
//	}
};

} /* namespace pgu */
} /* namespace ys */

#endif /* YS_PGU_QUERY_H */
