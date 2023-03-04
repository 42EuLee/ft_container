#ifndef MAP_HPP
# define MAP_HPP

#include <iostream>
#include <algorithm>
#include "mapIterator.hpp"
#include "reverseIterator.hpp"
#include "is_integral.hpp"
#include "lexicographical_compare.hpp"
#include <stdexcept>
#include "equal.hpp"
#include "pair.hpp"
#include "styling.h"
#include "rbt.hpp"

using std::cout;
using std::endl;

namespace ft
{
	template< class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > >
	class map
	{
		public:
			typedef	Key											key_type;
			typedef	T											mapped_type;
			typedef	ft::pair<const key_type, mapped_type>		value_type;

			class value_compare : std::binary_function<T, T, bool>
			{   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
				protected:
					Compare comp;
				public:
					value_compare(const Compare &c) : comp(c) {}  // constructed with map's comparison object
					bool operator() (const value_type& x, const value_type& y) const
					{
						return comp(x.first, y.first);
					}
			};

			typedef Compare										key_compare;
			// typedef value_compare							value_compare;
			typedef Alloc										allocator_type;

			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;

			typedef	mapIterator<value_type>						iterator;
			typedef mapIterator<const value_type>				const_iterator;
			typedef ft::reverse_iterator<iterator>				reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;
			typedef ptrdiff_t									difference_type;
			typedef size_t										size_type;

			allocator_type										_alloc;
			Compare												_compare;
			ft::RBT<value_type, value_compare, allocator_type>	rbt;
		
			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
			template <class InputIterator>  
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
			map (const map& x);
			~map();

			mapped_type& at (const key_type& k);
			const mapped_type& at (const key_type& k) const;
			iterator begin();
			const_iterator begin() const;
			void clear();
			size_type count (const key_type& k) const;
			bool empty() const;
			iterator end();
			const_iterator end() const;
			pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
	
			pair<iterator,iterator>   equal_range (const key_type& k);
			void erase (iterator position);
			size_type erase (const key_type& k);
			void erase (iterator first, iterator last);

			iterator find (const key_type& k);
			const_iterator find (const key_type& k) const;
			allocator_type get_allocator() const;


			pair<iterator,bool> insert (const value_type& val);
			iterator insert (iterator position, const value_type& val);
			template <class InputIterator>
			void insert (InputIterator first, InputIterator last);
			

	
			key_compare key_comp() const;
			iterator lower_bound (const key_type& k);
			
			const_iterator lower_bound (const key_type& k) const;

			size_type max_size() const;
			mapped_type& operator[] (const key_type& k);
			map& operator= (const map& x);
			reverse_iterator rbegin();
			const_reverse_iterator rbegin() const;
			reverse_iterator rend();
			const_reverse_iterator rend() const;
			size_type size() const;
			void swap (map& x);
			iterator upper_bound (const key_type& k);
			const_iterator upper_bound (const key_type& k) const;
			value_compare value_comp() const;

	};
}

#include "map.tpp"

#endif