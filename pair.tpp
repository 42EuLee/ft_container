#ifndef PAIR_TPP
# define PAIR_TPP

using namespace ft;

template <class T1, class T2> 
pair< T1, T2 >::pair() : _first(void) , _second(void)
{
	cout << "pair constructor called" << endl;
}

template <class T1, class T2>
template <class U, class V>
pair< T1, T2 >::pair(const pair<U,V>& r) : _first(r._first), _second(r._second)
{
	cout << "copy constructor called" << endl;

}

template <class T1, class T2>
pair<T1, T2>::pair(const first_type &a, const second_type &b) : _first(a), _second(b)
{
	cout << "initialization called" << endl;
}

template <class T1, class T2>
pair<T1, T2>& pair<T1, T2>::operator=(const pair<T1, T2> &pr)
{
	this->_first = pr._first;
	this->_second = pr._second;
}

template <class T1, class T2>
void pair<T1, T2>::swap(pair<T1, T2> &x, pair<T1, T2> &y)
{
	std::swap(x._first, y._first);
	std::swap(x._second, y._second);
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


#endif