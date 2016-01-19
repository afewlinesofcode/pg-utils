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

		auto q = select_from("users") &
			where("city_id = $1") &
			group_by("age") &
			having(_("count(1)") > 10);
		
		q.where() || (
			_("city_id in ") &
				(
				 	select_from("avail_cities") &
						columns("id") &
						(where("country_id") == 12)
				)
		);

		q & order_by("name");

		cout << q.str() << endl;
	}

	return 0;
}

