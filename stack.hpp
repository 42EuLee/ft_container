#ifndef STACK_HPP
# define STACK_HPP

#include <iostream>
#include <algorithm>
#include "remove_const.hpp"
#include "vector.hpp"
// #include "reverseIterator.hpp"
// #include "is_integral.hpp"
#include "lexicographical_compare.hpp"
#include "equal.hpp"
#include "styling.h"

using std::cout;
using std::endl;

namespace ft
{
	template < class T, class Container = ft::vector<T> >
	class stack
	{
		public:
			typedef T										value_type;
			typedef Container								container_type;
			typedef typename Container::size_type			size_type;
			typedef typename Container::reference			reference;
			typedef typename Container::const_reference		const_reference;


		/* Constructors and destructors */

			explicit stack (const container_type& ctnr = container_type());
			~stack();

			reference top();
			const_reference top() const;
			bool empty() const;
			size_type size() const;
			void push( const value_type& value );
			void pop();
			container_type get_stack() const;


			stack&	operator=( const ft::stack<T, Container>& other );
		


			// protected:
				container_type				c;


	};

}

#include "stack.tpp"
// #include "vectorIterator.tpp"

#endif