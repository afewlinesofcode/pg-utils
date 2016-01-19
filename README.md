ys-pgu
======

I will collect here different postgresql utilities which are helpful for me.

ys::pgu::query
--------------

A utility for building queries in run-time.

### Examples

```cpp
{
	using namespace ys::pgu::query;

	auto q = select_from("users") &
		where("city_id = $1") &
		groupby("age") &
		having(_("count(1)") > 10};
	
	q.where() | (
		_("city_id in ") &
			(select_from("avail_cities") &
				columns("id") &
				(where("country_id") == 12)()
	);

	q & orderby("name");
}
```
