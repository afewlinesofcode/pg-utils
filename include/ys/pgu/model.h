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

		static constexpr auto sel() {
			return std::make_tuple(
				std::make_pair("id", &record::id),
				std::make_pair("name", &record::name)
			);
		}
	};
};

template<typename Mod>
class model {
private:
	template<typename T>
	struct attr_modified;

public:
	using model_type = Mod;

	model() {
	}

	model(const model_type& t) :
		original { t } {
	}

	void modified() {
//		iterate_model_attrs<attr_modified>(record_type::attrs::mod());
	}

	template<
		template<typename> class Method,
		typename Tuple,
		int N = 0
	>
	void iterate_model_attrs(const Tuple& tup,
		typename std::enable_if<
			N < std::tuple_size<Tuple>::value
		>::type * = 0) {

		using element_type = typename std::tuple_element<N, Tuple>::type;
		element_type el = std::get<N>(tup);

		Method<element_type> s(*this);
		s(el);

		iterate_model_attrs<Method, Tuple, N + 1>(tup);
	}
	template<
		template<typename> class Method,
		typename Tuple,
		int N
	>
	void iterate_model_attrs(const Tuple&,
		typename std::enable_if<
			N >= std::tuple_size<Tuple>::value
		>::type * = 0) {
	}

private:
//	model_type current;
	model_type original;

	template<typename T>
	struct attr_modified {
		const Mod& model;
		attr_modified(const Mod& model) :
			model { model } {
		}
		void operator()(T attr_desc) {
//			auto attr = attr_desc.second;
//
//			if (model.current.*attr != model.original.*attr) {
//				std::cout << attr_desc.first << " is modified: " << model.current.*attr << ", " << model.original.*attr << std::endl;
//			}
		}
	};
};

}
}

#endif /* YS_PGU_MODEL_H */
