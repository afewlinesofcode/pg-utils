/*
 * main.cpp
 *
 *  Created on: 23 нояб. 2015 г.
 *      Author: stas
 */

#include <ys/pgu/cond_expr.h>
#include <ys/pgu/query_builder.h>
#include <cstdint>
#include <string>
#include <iostream>
#include <tuple>

//#include "ys/data/model.h"

//struct record {
//	uint32_t id;
//	std::string name;
//
//	static constexpr auto map = std::make_tuple(
//			std::make_pair("id", &record::id),
//			std::make_pair("name", &record::name));
//
//	friend std::ostream& operator<<(std::ostream& os, const record& i) {
//		return os << i.id << ", [" << i.name << "]" << std::endl;
//	}
//};

int main(int argc, char* argv[]) {
	using namespace std;
	using namespace ys::pgu;

//	using namespace ys::data;
//
//
//	model<record> rec;
//
//	cout << rec.data;
//
//	rec.data.id = 12;
//	rec.data.name = "qwe";
//
//	cout << rec.data;
//
//	auto modified = rec.get_modified();

//	using ys::pgu::query;
//	using e = ys::pgu::cond_expr;
//
//	auto q = query::select_from("test")
//			.columns("test.a, test.b")
//			.where( (e("a < $aval") && e("b = $bval")) || (e("c > $aval") && e("a = $bval")) )
//			.groupby("test.asd")
//			.having("count(q) = 5")
//			.orderby("test.id")
//			.limit(15)
//			.offset(142);
//
//	cout << q.to_string() << endl;

	return 0;
}

