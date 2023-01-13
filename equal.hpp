#ifndef EQUAL_HPP
# define EQUAL_HPP

namespace ft
{
	template <class Iter1, class Iter2>
	bool equal(Iter1 first1, Iter1 last1, Iter2 first2)
	{
		while (first1 != last1)
		{
			if (!(*first1 == *first2))
			{
				return (false);
			}
			++first1;
			++first2;
		}
		return (true);
	}
}
#endif