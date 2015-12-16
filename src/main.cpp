/*
 * main.cpp
 *
 *  Created on: 23 нояб. 2015 г.
 *      Author: stas
 */

#include <ys/pgu/query/query.h>
#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char* argv[]) {
	{
		using namespace std;
		using namespace ys::pgu::query;

		cout << (_{12} + _{"qwe"} + 17) << endl;

		auto q = select_from("test") &
			relations{"test1"} &
			columns{"id, cardid"} &
			where{"cardtype"_c == "'emergency'" || "cardtype"_c > 0} &
			groupby{"id, name"} &
			having("count(id)"_c > 1) &
			orderby{""};

//		auto ins = insert_into("test") & columns{"id, cardid"} & values{"$arg1, $arg2"};

		cout << q.str() << endl;
//		// desired usage example
//		q.where() && _w{5
//				_exists{
//						_select{ "dummy name" } <<
//								_rel{ "transport.stoptypes1" } <<
//								_col{ "stoptypes1.id" } <<
//								_w{
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

