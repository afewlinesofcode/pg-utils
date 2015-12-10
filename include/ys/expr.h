#ifndef YS_EXPR_H
#define YS_EXPR_H

#include <string>
#include <type_traits>

#define YS_EXPR_CONSTRUCTORS(class_name)\
	class_name() = default;\
	class_name(const class_name&) = default;\
	class_name(class_name&&) = default;\
	explicit class_name(const std::string& s): expr(s) {};\
	explicit class_name(std::string&& s): expr(std::move(s)) {};\
	explicit class_name(const char* s): expr(s) {};\
	template<typename T>\
	explicit class_name(T v): expr(v) {};

namespace ys {

class expr {
public:
	expr() = default;
	expr(const expr&) = default;
	expr(expr&&) = default;
	explicit expr(const std::string& str) :
			_str{ str } {
	}
	explicit expr(std::string&& str) :
			_str{ std::move(str) } {
	}
	explicit expr(const char* v) :
			_str{ v } {
	}
	template<typename T>
	explicit expr(T v) {
		static_assert(std::is_integral<T>::value, "integral value required");
		_str = std::to_string(v);
	}
	virtual ~expr() {
	}
	expr& operator=(const expr&) = default;
	expr& operator=(expr&&) = default;

	expr& operator&=(const expr& e) {
		return append(e.cstr());
	}

	bool empty() const {
		return _str.empty();
	}

	virtual std::string str() const {
		return _str;
	}

	const std::string& cstr() const {
		return _str;
	}

protected:
	expr& append(const std::string& s) {
		_str.append(s);
		return *this;
	}

	template<typename Arg, typename ...Args>
	expr& append(Arg arg, Args ... args) {
		_str.append(arg);
		append(args...);
		return *this;
	}

	expr& intelligent_append(const expr& e, const std::string& glue) {
		if (e.empty())
			goto intelligent_append_exit;
		if (empty())
			goto intelligent_append_str;

		append(glue);

		intelligent_append_str:
		append(e.cstr());

		intelligent_append_exit:
		return *this;
	}

private:
	std::string _str;

	friend std::ostream& operator <<(std::ostream& os, const expr& expr) {
		return os << expr.str();
	}
};

} // namespace ys

#endif /* YS_EXPR_H */
