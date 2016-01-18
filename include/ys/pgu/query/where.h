/*
 * where.h
 *
 *  Created on: 3 дек. 2015 г.
 *      Author: stas
 */

#ifndef YS_PGU_QUERY_WHERE_H
#define YS_PGU_QUERY_WHERE_H

#include <ys/pgu/query/basic_cond.h>

namespace ys {
namespace pgu {
namespace query {

class where: public basic_cond<where> {
public:
  using basic_cond::basic_cond;
  using basic_cond::operator=;

  std::string str() const {
    return empty() ? "" : "where " + cstr();
  }
};

} /* namespace query */
} /* namespace pgu */
} /* namespace ys */

#endif /* YS_PGU_QUERY_WHERE_H */
