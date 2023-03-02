#ifndef PAIR_TPP
# define PAIR_TPP

using namespace ft;

namespace ft
{
	template <class T1, class T2> 
	pair< T1, T2 >::pair() : first() , second()
	{
		// cout << GRN << "pair constructor called" << RESET <<endl;
	}

	template <class T1, class T2>
	template <class U, class V>
	pair< T1, T2 >::pair(const pair<U,V>& r) : first(r.first), second(r.second)
	{
		// cout << "pair copy constructor called" << endl;

	}

	template <class T1, class T2>
	pair<T1, T2>::pair(const first_type &a, const second_type &b) : first(a), second(b)
	{
		// cout << "pair constructor called" << endl;
	}

	template <class T1, class T2>
	pair<T1, T2>& pair<T1, T2>::operator=(const pair<T1, T2> &pr)
	{
		this->first = pr.first;
		this->second = pr.second;
		return (*this);
	}

	template <class T1, class T2>
	void pair<T1, T2>::swap(pair<T1, T2> &x, pair<T1, T2> &y)
	{
		std::swap(x.first, y.first);
		std::swap(x.second, y.second);
	}

	template <class T1, class T2>
	bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return lhs.first==rhs.first && lhs.second==rhs.second; }

	template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(lhs==rhs); }

	template <class T1, class T2>
	bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }

	template <class T1, class T2>
	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(rhs<lhs); }

	template <class T1, class T2>
	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return rhs<lhs; }

	template <class T1, class T2>
	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(lhs<rhs); }

	template <class T1,class T2>
	pair<T1,T2> make_pair (T1 x, T2 y)
	{
		return(pair<T1,T2>(x,y));
	}
}


#endif