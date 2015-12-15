/*
 * alias.h
 *
 *  Created on: 10 дек. 2015 г.
 *      Author: stas
 */

#ifndef INCLUDE_YS_PGU_QUERY_ALIAS_H_
#define INCLUDE_YS_PGU_QUERY_ALIAS_H_

#include <ys/pgu/query/columns.h>
#include <ys/pgu/query/cond.h>
#include <ys/pgu/query/groupby.h>
#include <ys/pgu/query/having.h>
#include <ys/pgu/query/limit.h>
#include <ys/pgu/query/offset.h>
#include <ys/pgu/query/orderby.h>
#include <ys/pgu/query/where.h>
#include <ys/pgu/query/select_query.h>

namespace ys{
namespace pgu {
namespace query {
namespace alias {

using _c = ys::pgu::query::columns;
using _ = ys::pgu::query::cond;
using _g = ys::pgu::query::groupby;
using _h = ys::pgu::query::having;
using _lim = ys::pgu::query::limit;
using _ofs = ys::pgu::query::offset;
using _o = ys::pgu::query::orderby;
using _w = ys::pgu::query::where;
using _select = ys::pgu::query::select_query;

}
}
}
}

#endif /* INCLUDE_YS_PGU_QUERY_ALIAS_H_ */
