#ifndef PAIR_HPP
# define PAIR_HPP

#include <iostream>

namespace ft
{
	template< class T1, class T2> 
	struct pair
	{
		typedef T1 		first_type;
		typedef T2 		second_type;

		pair();
		template<class U, class V> 
		pair(const pair<U,V>& pr);
		pair(const first_type& a, const second_type& b);

		T1	first;
		T2	second;

		pair&	operator=(const pair& pr);
		void	swap(pair<T1, T2> &x, pair<T1, T2> &y);
		template <size_t I> 
		typename std::tuple_element< I, pair<T1,T2> >::type&  get (pair<T1,T2>&  pr);
	};


	// template <class T1, class T2>  bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs);
	// template <class T1, class T2>  bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs);
	// template <class T1, class T2>  bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs);
	// template <class T1, class T2>  bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs);
	// template <class T1, class T2>  bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs);
	// template <class T1, class T2>  bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs);

	template< class T1, class T2>
	std::ostream &operator<<(std::ostream &out, const ft::pair<T1,T2> &c)
	{
		out << "key: " << c.first;
		out << " value: " << c.second << endl;
		return out;
	}
}

# include "pair.tpp"
#endif