/*
 * main.cpp
 *
 *  Created on: 23 нояб. 2015 г.
 *      Author: stas
 */

#include <iostream>

#include <ys/string/basic_expr.h>

int main(int argc, char* argv[]) {
	{
		using _ = ys::string::basic_expr;

		std::cout << ((_{ 12 } + _{ 13 })*_{14}).str() << std::endl;
	}
	return 0;
}

