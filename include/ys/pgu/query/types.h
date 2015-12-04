/*
 * types.h
 *
 *  Created on: 4 дек. 2015 г.
 *      Author: stas
 */

#ifndef YS_PGU_TYPES_H
#define YS_PGU_TYPES_H

namespace ys {
namespace pgu {
namespace query {

/*!
 * Enumeration of available query operations.
 */
enum op {
	select,//!< For building SELECT query.
	insert,//!< For building INSERT query.
	update,//!< For building UPDATE query.
	remove //!< For building DELETE query.
};

}
}
}

#endif /* YS_PGU_TYPES_H */
