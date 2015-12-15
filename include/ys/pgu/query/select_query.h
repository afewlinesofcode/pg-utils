/*
 * select_query.h
 *
 *  Created on: 15 дек. 2015 г.
 *      Author: stas
 */

#ifndef YS_PGU_QUERY_SELECT_QUERY_H
#define YS_PGU_QUERY_SELECT_QUERY_H

#include <sstream>
#include <ys/basic_expr.h>
#include <ys/pgu/query/where.h>

namespace ys {
namespace pgu {
namespace query {

class select_query: public ys::basic_expr<select_query> {
public:
	using basic_expr::basic_expr;

	query::where& where() {
		return _where;
	}

	select_query& operator&(const query::where& w) {
		_where &= w;
		return *this;
	}

	std::string str() const {
		std::ostringstream s;

		s << "select " << _where;

		return s.str();
	}
private:
	query::where _where;
};

}
}
}

#endif /* YS_PGU_QUERY_SELECT_QUERY_H */
