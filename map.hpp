#ifndef MAP_HPP
# define MAP_HPP

#include <iostream>
#include <algorithm>
#include "mapIterator.hpp"
#include "reverseIterator.hpp"
#include "is_integral.hpp"
#include "lexicographical_compare.hpp"
#include "equal.hpp"
#include "pair.hpp"
#include "styling.h"

using std::cout;
using std::endl;

namespace ft
{
	template< class Key, class T, class Compare, class Alloc = std::allocator<T>>
	class map
	{
		public:
			typedef	Key											key_type;
			typedef	T											map_type;
			typedef	ft::pair<const key_type, mapped_type>		value_type;
			typedef Compare										key_compare;
			typedef Alloc										allocator_type;

			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;

			typedef	mapIterator<T>								iterator;
			typedef mapIterator<const T>						const_iterator;
			typedef ft::reverse_iterator<iterator>				reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;
			typedef ptrdiff_t									difference_type;
			typedef size_t										size_type;

			
	};

}

#endif