/*
 * @author    Stanislav Yaranov <stanislav.yaranov@gmail.com>
 * @date      2015-12-04
 *
 * Log:
 *     2015-12-04
 *         Created.
 */

#ifndef YS_TRAITS_H_
#define YS_TRAITS_H_

#include <type_traits>

namespace ys {

/**
 * Provides the member type in the case of T is arithmetic.
 */
template<typename T>
struct is_arithmetic 
		: public std::enable_if<std::is_arithmetic<T>::value, T> {
};

/**
 * Required overload for any_of with parameters pack.
 */
template<typename T>
constexpr
bool
any_of(T val, T arg) {
  return val == arg;
}

/**
 * Returns true if val is one of specified arguments.
 */
template<typename T1, typename... T2>
constexpr
bool
any_of(T1 val, T1 arg, T2 ...args) {
  return any_of(val, arg) || any_of(val, args...);
}

/*
 * Required overload for none_of with parameters pack.
 */
template<typename T>
constexpr
bool
none_of(T val, T arg) {
  return val != arg;
}

/**
 * Returns true if there is no argument equal to val.
 */
template<typename T1, typename... T2>
constexpr
bool
none_of(T1 val, T1 arg, T2 ...args) {
  return none_of(val, arg) && none_of(val, args...);
}

}

#endif /* YS_TRAITS_H_ */
