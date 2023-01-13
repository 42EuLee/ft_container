#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <algorithm>
#include "vectorIterator.hpp"
#include "reverseIterator.hpp"
#include "is_integral.hpp"
#include "lexicographical_compare.hpp"
#include "equal.hpp"
#include "styling.h"

using std::cout;
using std::endl;

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:

			typedef T											value_type;
			typedef Alloc										allocator_type;
			typedef ptrdiff_t									difference_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef size_t										size_type;
			typedef	vectorIterator<T>							iterator;
			typedef vectorIterator<const T>						const_iterator;
			typedef ft::reverse_iterator<iterator>				reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;


		/* Constructors and destructors */
			explicit vector(const allocator_type& alloc = allocator_type());
	
			explicit vector(size_type n, const value_type& val = value_type(),
				const allocator_type& alloc = allocator_type());
	
			template <class InputIterator> 
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0);

			~vector(void);
			vector (const vector& x);

			T				*_vector;
			size_type		_capacity;
			size_type		_size;
			allocator_type	_alloc;




		/* Member functions */

			template <class InputIterator>
			void					assign(InputIterator first, InputIterator last);
			void					assign(size_type n, const value_type& val);
			reference				at(size_type n);
			const_reference 		at(size_type n) const;
			reference				back();
			const_reference 		back() const;
			iterator				begin();
			const_iterator			begin() const;
			size_type				capacity() const;
			void					clear() const;
			bool					empty() const;
			iterator				end();
			const_iterator			end() const;
			iterator				erase(iterator position);
			iterator				erase(iterator first, iterator last);
			reference				front();
			const_reference 		front() const;
			allocator_type			get_allocator() const;
			iterator				insert(iterator position, const value_type& val);
			void					insert(iterator position, size_type n, const value_type& val);
			template <class InputIterator>
			void					insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0);
			size_type				max_size() const;
			void					pop_back();
			void					push_back(const value_type &num);
			reverse_iterator		rbegin();
			const_reverse_iterator	rbegin() const;
			reverse_iterator		rend();
			const_reverse_iterator	rend() const;
			void					reserve(size_type n);
			void					resize(size_type n, value_type val = value_type());
			size_type				size() const;
			void					swap(vector& x);
			reference				operator[](size_type n);
			const_reference			operator[](size_type n) const;
			vector<T, Alloc>&		operator=(const vector& x);


	// vector::at // done
	// vector::back // done
	// vector::begin // done
	// vector::capacity // done
	// vector::clear //done
	// vector::empty // done
	// vector::end // done
	// vector::erase // done
	// vector::front // done
	// vector::get_allocator // done
	// vector::insert // done
	// vector::max_size // done
	// vector::operator[] // done
	// vector::operator= // done
	// vector::pop_back // done
	// vector::push_back // done
	// vector::reserve // done
	// vector::resize // done
	// vector::size // done

	// vector::assign // not done
	// vector::swap // nope
	// vector::rbegin // nope
	// vector::rend // nope


	// bool	operator<(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs);
	// bool	operator>(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs);
	// bool	operator<=(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs);
	// bool	operator>=(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs);
	// bool	operator==(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs);
	// bool	operator!=(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs);
	class	MaxAmountReached : public std::exception
	{
		public:
			virtual const char	*what(void) const throw();
	};
	};

}

// #include "iterator.hpp"
#include "vector.tpp"
#include "vectorIterator.tpp"


#endif