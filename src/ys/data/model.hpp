/*
 * model.hpp
 *
 *  Created on: 23 нояб. 2015 г.
 *      Author: stas
 */

#include <boost/fusion/algorithm/iteration.hpp>
#include <boost/fusion/include/iteration.hpp>

namespace ys {
namespace data {

template<typename T>
model<T>::model(const T& data): data(data), original(data) {
}

template<typename T>
model<T>::model(): model(T{}) {
}

template<typename T>
model<T>::~model() {
}

template<typename T>
void model<T>::commit() {
	original = data;
}

template<typename T>
void model<T>::rollback() {
	data = original;
}

template<typename T>
typename model<T>::modified_map model<T>::get_modified() {
//	boost::fusion::for_each(T::map, traverser{});
	return {};
}

} /* namespace data */
} /* namespace ys */
