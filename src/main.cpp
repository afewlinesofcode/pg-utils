/*
 * main.cpp
 *
 *  Created on: 23 нояб. 2015 г.
 *      Author: stas
 */

#include <ys/pgu/query.h>
//#include <ys/pgu/model.h>
#include <iostream>

int main(int argc, char* argv[]) {
	{
		using namespace ys::pgu::query;

		auto q = select_from("users") &
			where("city_id = $1") &
			group_by("age") &
			having(_("count(1)") > 10);
		
		q.where() || (
			_("city_id in ") &
				_(
				 	select_from("avail_cities") &
						columns("id") &
						(where("country_id") == 12)
				)()
		);

		q.where()() && _("not blocked");

		q & columns("age") &
			order_by("name");

		q & columns("count(1) as cnt");

		std::cout << q.str() << std::endl;

	}

	return 0;
}

