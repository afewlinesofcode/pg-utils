/*
 * main.cpp
 *
 *  Created on: 23 нояб. 2015 г.
 *      Author: stas
 */

#include <ys/pgu/query/alias.h>
#include <iostream>
#include <sstream>
#include <string>

class rows: public ys::basic_expr<rows> {
public:
	using basic_expr::basic_expr;
};

int main(int argc, char* argv[]) {
	{
		using namespace std;
		using namespace ys::pgu::query::alias;

		{
			_ c = (((_{23} + _{15})() / _{73})() || (_{"qwe"} == _{"$val"})());
			std::cout << "conditions: " << c << std::endl;
		}

		{
			_c c = _c{"code"} & _c{"cardid"};
			c &= _c{"createddatetime"};
			cout << "columns: " << _c{} << ", " << c << endl;
		}

		{
			_g g = _g{"id, name"} & _g{"datetime"};
			g &= _g{"owner"};
			cout << "groupby: " << g << endl;
		}

		{
			_h h1;
			_h h = _{"count(id)"} > _{1};
			h |= _{} && _{"is_bool(table.col2)"};
			h &= (_{"table.col1"} == _{"$arg1"} || _{"table.col2"})();
			cout << "having: " << h << endl;
		}

		{
			_w w1;
			_w w = _{"count(id)"} > _{1};
			w |= _{} && _{"is_bool(table.col2)"};
			w &= (_{"table.col1"} == _{"$arg1"} || _{"table.col2"})();
			cout << "where: " << w << endl;
		}

		{
			_ofs o;

			o = _{"is_val"};
			cout << o << endl;
		}

		{
			auto e = (_{ "trackerid" } == _{ 13729 } && _{ "drift" } == _{ 0 } && _{ "datetime" } <
				_{"current_timestamp"} - _{"interval '1' weeks" });
			std::cout << e << endl;
		}

		{
			auto q = _select{} & _w{_{"createddatetime"} > _{"current_timestamp"}};

			q.where() = q.where()() || _{"cardtype"} == _{"'emergency'"};

			cout << q << endl;
		}

		// desired usage example
//		q.where() && _w{
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

