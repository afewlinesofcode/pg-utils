/*
 * main.cpp
 *
 *  Created on: 23 нояб. 2015 г.
 *      Author: stas
 */

#include <iostream>
#include <sstream>

#include <ys/pgu/query/cond_expr.h>

int main(int argc, char* argv[]) {
	{
		using _ = ys::pgu::query::cond_expr;

		std::cout << (_{ "trackerid" } == _{ 13729 } && _{ "drift" } == _{ 0 } && _{ "datetime" } <
				_{"current_timestamp"} - _{"interval '1' week" }).str() << std::endl;

		// desired usage
//		q.where() && _where{
//				_exists{
//						_select{ "dummy name" } &
//								_from{ "transport.stoptypes1" } &
//								_columns{ "stoptypes1.id" } &
//								_where{
//										(_{ "stoptypes1.stopid" } == _{ "stops.id" }) &&
//												(_{ "stoptypes1.type1id" } == _{ "any($types1Id::int[])" })
//								}
//				}
//		};
	}

	{
//		using namespace ys::pgu::query;

//		auto q = select_from{"table"} & columns{"qwe"};
	}
	return 0;
}

