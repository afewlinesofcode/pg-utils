ys-pgu
======

I will collect here different postgresql utilities which are helpful for me.

ys::pgu::query
--------------

A postgresql query builder utility.

### Example

**C++**

```cpp
#include <ys/pgu/query.h>
#include <iostream>

int main(int argc, char* argv[]) {
	{
		using namespace ys::pgu::query;

		auto q = select_from("users") &
			where("city_id = $1") &
			group_by("age") &
			having(_("count(1)") > 10);
		
		q.where() || (
			_("city_id in ") &
				_(
					select_from("avail_cities") &
						columns("id") &
						(where("country_id") == 12)
				)()
		);

		q.where()() && _("not blocked");

		q & columns("age") &
			order_by("name");

		q & columns("count(1) as cnt");

		std::cout << q.str() << std::endl;
	}

	return 0;
}
```
**SQL**
```sql
-- Result:
select age, count(1) as cnt from users
	where
		(city_id = $1 or city_id in (select id from avail_cities where country_id = 12))
		and not blocked
	group by age
	having count(1) > 10
	order by name
```
