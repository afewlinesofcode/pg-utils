/*
 * model.h
 *
 *  Created on: 17 дек. 2015 г.
 *      Author: stas
 */

#ifndef YS_PGU_MODEL_H
#define YS_PGU_MODEL_H

#include <tuple>
#include <iostream>
#include <vector>

namespace ys {
namespace pgu {

struct record {
	int id { };
	std::string name;

	struct attrs {
		static constexpr auto all() {
			return std::make_tuple(
					std::make_pair("id", &record::id),
					std::make_pair("name", &record::name)
							);
		}
		static constexpr auto mod() {
			return std::make_tuple(
					std::make_pair("name", &record::name)
							);
		}
	};
};

template<typename M, typename A>
class attr_modified;

template<typename Record>
class model {
	template<typename M, typename A>
	friend class model_accessor;

public:
	using record_type = Record;

	record_type data;

	model() {
	}
	model(const record_type& t) :
			data { t }, original { t } {
	}
	void modified() {
		std::vector<std::string> vec;
		for_each_attr<attr_modified>(record_type::attrs::mod(), vec);

		std::cout << "modified " << vec.size() << " items" << std::endl;
		for (std::string& s : vec) {
			std::cout << "\t" << s << std::endl;
		}
	}

	template<
			template<typename, typename > class Fun,
			typename Tuple,
			typename Arg,
			int N = 0
	>
	void for_each_attr(
			const Tuple& tup,
			Arg& arg,
			typename std::enable_if<
					N < std::tuple_size<Tuple>::value
			>::type * = 0) {
		Fun<typename std::tuple_element<N, Tuple>::type,
				typename std::remove_reference<decltype(*this)>::type>
		(std::get<N>(tup), *this)(arg);
		for_each_attr<Fun, Tuple, Arg, N + 1>(tup, arg);
	}
	template<
			template<typename, typename > class Fun,
			typename Tuple,
			typename Arg,
			int N
	>
	void for_each_attr(
			const Tuple&,
			Arg&,
			typename std::enable_if<
					N >= std::tuple_size<Tuple>::value
			>::type * = 0) {
	}

private:
	record_type original;
};

template<typename A, typename M>
class model_accessor {
public:
	using attr_type = A;
	using model_type = M;
	using record_type = typename M::record_type;

	const attr_type& _attr;
	model_type& _model;

	model_accessor(const A& a, M& m) :
			_attr { a }, _model { m } {
	}
	record_type& get_data() {
		return _model.data;
	}
	record_type& get_original() {
		return _model.original;
	}
};

template<typename A, typename M>
class attr_modified: public model_accessor<A, M> {
public:
	using attr_type = A;
	using model_type = M;

	attr_modified(const A& a, M& m) :
			model_accessor<A, M> { a, m } {
	}
	void operator()(std::vector<std::string>& ret) {
		auto attr = this->_attr.second;

		if (this->get_data().*attr != this->get_original().*attr) {
			ret.push_back(this->_attr.first);
		}
	}
};

}
}

#endif /* YS_PGU_MODEL_H */
