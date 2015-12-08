/*
 * main.cpp
 *
 *  Created on: 23 нояб. 2015 г.
 *      Author: stas
 */

#include <iostream>
#include <sstream>

#include <ys/string/basic_expr.h>

int main(int argc, char* argv[]) {
	{
		using _ = ys::string::basic_expr;

		std::cout << (_{"trackerid"} == _{13729} && _{"drift"} == _{0} && _{"datetime"} < _{"current_timestamp - interval '1' week"}).str() << std::endl;
	}

	{
//		using namespace ys::pgu::query;

//		auto q = select_from{"table"} & columns{"qwe"};
	}
	return 0;
}

