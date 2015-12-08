/*
 * expr.h
 *
 *  Created on: 8 дек. 2015 г.
 *      Author: stas
 */

#ifndef YS_STRING_EXPR_H
#define YS_STRING_EXPR_H

namespace ys {
namespace string {

template<typename T>
std::string to_string(T arg) {
	return std::to_string(arg);
}

std::string to_string(const char* arg);

class expr {
public:
	struct related_item_t {
		std::string t;
		const expr& e;
	};

	using related_item_type = related_item_t;
	using related_items_type = std::vector<related_item_type>;

	expr() = default;
	expr(const expr&) = default;
	expr(expr&&) = default;
	template<typename T>
	explicit expr(const T& e) {
		expr_str = to_string(e);
	}

	expr& operator=(const expr&) = delete;
	expr& operator=(expr&&) = delete;

	virtual ~expr() {
	}

	bool is_complex() const {
		return !related_items.empty();
	}

	virtual std::string str() const {
		return expr_str;
	}

protected:
	expr& append(const std::string& t, const expr& e) {
		related_items.push_back({ t, e });
		return *this;
	}

	const std::string& get_expr() const {
		return expr_str;
	}

	const expr::related_items_type& get_items() const {
		return related_items;
	}

private:
	std::string expr_str;
	expr::related_items_type related_items;
};

} // namespace string
} // namespace ys

#endif /* YS_STRING_EXPR_H */
