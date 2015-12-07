/*
 * main.cpp
 *
 *  Created on: 23 нояб. 2015 г.
 *      Author: stas
 */

#include <ys/pgu/query/cond_expr.h>
#include <ys/pgu/query/query.h>
#include <cstdint>
#include <string>
#include <iostream>
#include <tuple>
#include <vector>
#include <memory>
#include <utility>

#include <ys/pgu/expr.h>

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

	{
		using namespace ys::pgu::query;
//		using e = cond_expr;

//		auto q = select_from("test")
//				.columns("test.a, test.b")
//				.where( (e("a < $aval") && e("b = $bval")) || (e("c > $aval") && e("a = $bval")) )
//				.groupby("test.asd")
//				.having("count(q) = 5")
//				.orderby("test.id")
//				.limit(15)
//				.offset(142);

//		auto q1 = select_from { "test" } &
//				columns { "test.a, test.b" } &
//				where { (e { "a < $aval" } & e { "b = $bval" }) | (e { "c > $aval" } & e { "a = $bval" }) } &
//				groupby { "test.asd" } &
//				having { "count(q) = 5" } &
//				orderby { "test.id" } &
//				limit(15) &
//				offset(142);

//		auto q2 = select_from("test1") & columns("test.a, test.b");

	// TODO: q & where( (e("a < $aval") && e("b = $bval")) || (e("c > $aval") && e("a = $bval")) );
//		cout << q.to_string() << endl;
	}

	{
		using namespace std;
		using _ = ys::pgu::expr;

		cout << _{5} + "test.a" << endl;

		/*
		Examples:
		(_{5} > 3) || (_{"$val"} > _5);
		expr{} & "select from" & relation & where;
		*/
//		select_from("trackers.log") & where(_r{"datetime"}.between("123", "234") & _{"drift"} == 0);
	}

return 0;
}

