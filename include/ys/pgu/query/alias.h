/*
 * alias.h
 *
 *  Created on: 10 дек. 2015 г.
 *      Author: stas
 */

#ifndef INCLUDE_YS_PGU_QUERY_ALIAS_H_
#define INCLUDE_YS_PGU_QUERY_ALIAS_H_

#include <ys/pgu/query/cond.h>
#include <ys/pgu/query/columns.h>
#include <ys/pgu/query/groupby.h>
#include <ys/pgu/query/having.h>

namespace ys{
namespace pgu {
namespace query {
namespace alias {

using _ = ys::pgu::query::cond;
using _c = ys::pgu::query::columns;
using _g = ys::pgu::query::groupby;
using _h = ys::pgu::query::having;

}
}
}
}

#endif /* INCLUDE_YS_PGU_QUERY_ALIAS_H_ */
