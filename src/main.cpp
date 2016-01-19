/*
 * main.cpp
 *
 *  Created on: 23 нояб. 2015 г.
 *      Author: stas
 */

#include <ys/pgu/query.h>
//#include <ys/pgu/model.h>
#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char* argv[]) {
	//{
	//    using namespace ys::pgu;

	//    model<record> m;
	//    m.data.name = "qwe";
	//    m.modified();
	//}
	{
		using namespace std;
		using namespace ys::pgu::query;

		cout << (_{ 12 }) << endl;

		auto q = select_from("test") &
			relations { "test1" } &
			columns { "id, cardid" } &
			where { _{"cardtype"} == "'emergency'" || _{"cardtype"} > 0 } &
			groupby { "id, name" } &
			having(_{"count(id)"} > 1) &
			orderby { "" };

		//auto ins = insert_into("test") &
		//    columns{"id, cardid"} &
		//    values{"$arg1, $arg2"};

		cout << q.str() << endl;
		// TODO: make example with query having lots of options and
		// nested queries
	}

	return 0;
}

