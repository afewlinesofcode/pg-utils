/*
 * model.h
 *
 *  Created on: 23 нояб. 2015 г.
 *      Author: stas
 */

#ifndef YS_DATA_MODEL_H
#define YS_DATA_MODEL_H

#include <map>

namespace ys {
namespace data {

/**
 * model for data item represented by T (DefaultConstructable, CopyAssignable)
 */
template<typename T>
class model {
public:
	using modified_map = std::map<std::string, std::string>;

	T data;

	model(const T& data);
	model();
	~model();

	void commit();
	void rollback();

	modified_map get_modified();
protected:
private:
	T original;

	class traverser {
	public:
		template<class U>
		void operator()(U& u) const {
		}
	};
};

} /* namespace data */
} /* namespace ys */

#include "model.hpp"

#endif /* YS_DATA_MODEL_H */
