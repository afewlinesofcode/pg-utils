/*
 * query_type.h
 *
 *  Created on: 3 дек. 2015 г.
 *      Author: stas
 */

#ifndef YS_PGU_QUERY_H_
#define YS_PGU_QUERY_H_

#include <ys/pgu/query/builder.h>
#include <ys/pgu/query/cond.h>

namespace ys {
namespace pgu {
namespace query {

using _ = cond;

/*!
 * Create a SELECT query builder.
 * @param relation A relation name on which the query will be built.
 * @return
 */
builder<select> select_from(const std::string& relation) {
	return builder<select> { } & relations { relation };
}

/*!
 * Create a INSERT query builder.
 * @param relation A relation name on which the query will be built.
 * @return
 */
//builder<insert> insert_into(const std::string& relation) {
	//return builder<insert>(relation);
//}

/*!
 * Create a UPDATE query builder.
 * @param relation A relation name on which the query will be built.
 * @return
 */
//builder<update> update_in(const std::string& relation) {
	//return builder<update>(relation);
//}

/*!
 * Create a DELETE query builder.
 * @param relation A relation name on which the query will be built.
 * @return
 */
//builder<remove> delete_from(const std::string& relation) {
	//return builder<remove>(relation);
//}

} /* namespace query */
} /* namespace pgu */
} /* namespace ys */

#endif /* YS_PGU_QUERY_H_ */
