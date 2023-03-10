#ifndef VALUE_COMP_HPP
# define VALUE_COMP_HPP

#include "map.hpp"

namespace ft
{
	template< class Key, class T, class Compare, class Alloc = std::allocator<T> >
	class map<Key, T, Compare, Alloc>::value_compare
	{   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
		friend class map;
		protected:
			Compare comp;
			value_compare(Compare c) : comp(c) {}  // constructed with map's comparison object
		public:
			// typedef bool result_type;
			// typedef value_type first_argument_type;
			// typedef value_type second_argument_type;
			bool operator() (const value_type& x, const value_type& y) const
			{
				return comp(x.first, y.first);
			}
	};
}

#endif