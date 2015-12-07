/*
 * expr.h
 *
 *  Created on: 7 дек. 2015 г.
 *      Author: stas
 */

#ifndef INCLUDE_YS_PGU_EXPR_H_
#define INCLUDE_YS_PGU_EXPR_H_

#include <iostream>

namespace ys {
namespace pgu {

using namespace std;

class expr {
public:
	virtual ~expr() {
		cout << "~expr\n";
	}

	virtual void show() {
		cout << "expr\n";
	}
};

}
}

#endif /* INCLUDE_YS_PGU_EXPR_H_ */
