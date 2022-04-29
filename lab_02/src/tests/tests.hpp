#include "tests.h"

int RUN_TESTS()
{
    try
	{
		/*
		 * Constructors check
		 */
		set<int> a, d, e;
		//int b[2] = {10, 11};
		a = set<int>{ 10, 11, 12,11, 7, 2};
		int c[7] = { 3, 2, 6, 7, 7, 7, 4};
		d = set<int>(c, 7);
		set<long> g = set<long>{2, 3, 1, 2, 3, 7, 8};
		cout << g << ":g\n";
		cout << a << ":a\n";
		cout << d << ":d\n\n";
		
		e = set<int>();
		cout << (d ^ a) << ":d ^ a\n";
		cout << (d + a) << ":d + a\n";
		cout << (d - a) << ":d - a\n";
		cout << (d | a) << ":d | a\n";
		cout << (d & a) << ":d & a\n";
		cout << (d & d) << ":d & d\n";
		set<int> abc = (a + d) ^ d;
		cout << abc << ":abc = (a + d) ^ d\n\n";

		cout << (d.symmetric_difference(a)) << ":d.symmetric_difference(a)\n";
		cout << (d.combine(a)) << ":d.combine(a)\n";
		cout << (d.difference(a)) << ":d.difference(a)\n";
		cout << (d.intersect(a)) << ":d.intersect(a)\n\n";

		cout << (d.symmetric_difference(4)) << ":d.symmetric_difference(4)\n";
		cout << (d.combine(15)) << ":d.combine(15)\n";
		cout << (d.difference(3)) << ":d.difference(3)\n";
		cout << (d.intersect(4)) << ":d.intersect(4)\n\n";

		cout << (d ^ 4) << ":d ^ 4\n";
		cout << (d + 15) << ":d + 15\n";
		cout << (d - 3) << ":d - 3\n";
		cout << (d | 15) << ":d | 15\n";
		cout << (d & 4) << ":d & 4\n\n";

		cout << (4 ^ d) << ":4 ^ d\n";
		cout << (15 + d) << ":15 + d\n";
		cout << (3 - d) << ":3 - d\n";
		cout << (22 - d) << ":22 - d\n";
		cout << (15 | d) << ":15 | d\n";
		cout << (4 & d) << ":4 & d\n\n";

		e = d;
		cout << e << ":e = d\n";
		e ^= a;
		cout << e << ":e ^= a\n";
		e += a;
		cout << e << ":e += a\n";
		e -= a;
		cout << e << ":e -= a\n";
		e |= a;
		cout << e << ":e |= a\n";
		e &= a;
		cout << e << ":e &= a\n";
		e &= (a + 22);
		cout << e << ":e &= (a + 22)\n\n";

		cout << e.inSet(10) << " :e.inSet(10)\n";
		cout << e.inSet(22) << " :e.inSet(22)\n";
		cout << e.is_empty() << " :e.is_empty()\n";
		cout << e.get_size() << " :e.get_size()\n";
		cout << (set<char>{}).is_empty() << " :(set<char>{}).is_empty()\n";
		cout << (set<char>{}).get_size() << " :(set<char>{}).get_size()\n";
	}
	catch (bad_alloc_err& error)
	{
		cout << error.what();
	}
	catch (set_range_error& error)
	{
		cout << error.what();
	}
	catch (iterator_error& error)
	{
		cout << error.what();
	}

    return 0;
}