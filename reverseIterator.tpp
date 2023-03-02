#ifndef REVERSEITERATOR_TPP
# define REVERSEITERATOR_TPP

using namespace ft;

template <class Iter>
reverse_iterator<Iter>::reverse_iterator()
{
    // cout << "reverseIterator constructor called" << endl;
}

template <class Iter>
reverse_iterator<Iter>::reverse_iterator(iterator_type iter)
{
    // cout << "reverseIterator called" << endl;
    // cout << this->_base->first << endl;
    // cout << this->_base->first << endl;
	this->_base = iter - 1;
    // cout << *iter << endl;
}

template < class Iter>
template < class U > 
reverse_iterator<Iter>::reverse_iterator(const reverse_iterator<U> &ref)
{
    // cout << "Copy constructor called" << endl;
	this->_base = ref._base;
}

template <class Iter>
Iter reverse_iterator<Iter>::base() const
{
	return(this->_base + 1);
}

template <class Iter>
typename reverse_iterator<Iter>::reference reverse_iterator<Iter>::operator*() const
{
    return (*this->_base);
}

template <class Iter>
typename reverse_iterator<Iter>::pointer reverse_iterator<Iter>::operator->() const
{
    return &(operator*());
}

template <class Iter>
reverse_iterator<Iter>& reverse_iterator<Iter>::operator++()
{
    this->_base--;
    return (*this);
}

template <class Iter>
reverse_iterator<Iter> reverse_iterator<Iter>::operator++(int)
{
    reverse_iterator  tmp = *this;
    ++(*this);
    return (tmp);
}

template <class Iter>
reverse_iterator<Iter>& reverse_iterator<Iter>::operator--()
{
    this->_base++;
    return (*this);
}

template <class Iter>
reverse_iterator<Iter> reverse_iterator<Iter>::operator--(int)
{
    reverse_iterator  tmp = *this;
    --(*this);
    return (tmp);
}

template <class Iter>
reverse_iterator<Iter>& reverse_iterator<Iter>::operator+=(difference_type diff)
{
    this->_base -= diff;
    return (*this);
}

template <class Iter>
reverse_iterator<Iter>& reverse_iterator<Iter>::operator-=(difference_type diff)
{
    this->_base += diff;
    return (*this);
}

template <class Iter>
typename reverse_iterator<Iter>::reference reverse_iterator<Iter>::operator[](difference_type diff)
{
    return (*(this->_base - diff));
}

template <class Iter, class Iter2> // Changing my stuff
bool operator<(const reverse_iterator<Iter> &lhs, const reverse_iterator<Iter2> &rhs)
{
    return ((lhs.base()) > (rhs.base()));
}

template <class Iter, class Iter2>
bool operator==(const reverse_iterator<Iter> &lhs, const reverse_iterator<Iter2> &rhs)
{
    return ((lhs.base() == rhs.base()));
}

template <class Iter, class Iter2>
bool operator!=(const reverse_iterator<Iter> &lhs, const reverse_iterator<Iter2> &rhs)
{
   return ((lhs.base()) != (rhs.base()));
}

template <class Iter, class Iter2>
bool operator<=(const reverse_iterator<Iter> &lhs, const reverse_iterator<Iter2> &rhs)
{
    return ((lhs.base()) >= (rhs.base()));
}

template <class Iter, class Iter2>
bool operator>(const reverse_iterator<Iter> &lhs, const reverse_iterator<Iter2> &rhs)
{
    return ((lhs.base()) < (rhs.base()));
}

template <class Iter, class Iter2>
bool operator>=(const reverse_iterator<Iter> &lhs, const reverse_iterator<Iter2> &rhs)
{
    return ((lhs.base()) <= (rhs.base()));
}

template <class Iter>
reverse_iterator<Iter> operator+(reverse_iterator<Iter> a, typename reverse_iterator<Iter>::difference_type b)
{
    reverse_iterator<Iter> temp(a);

    temp._base -= b;
    return (temp);
}

template <class Iter>
reverse_iterator<Iter> operator+(typename reverse_iterator<Iter>::difference_type a, reverse_iterator<Iter> b)
{
    reverse_iterator<Iter> temp(b);

    temp._base -= a;
    return (temp);
}

template <class Iter>
reverse_iterator<Iter> operator-(reverse_iterator<Iter> a, typename reverse_iterator<Iter>::difference_type b)
{
    reverse_iterator<Iter> temp(a);

    temp._base += b;
    return (temp);
}

template <typename T, typename U>
typename reverse_iterator<T>::difference_type  operator-(reverse_iterator<T> a, reverse_iterator<U> b)
{
    typename    reverse_iterator<T>::difference_type diff;
    diff = b._base - a._base;
    return (diff);
}

template <class Iter>
reverse_iterator<Iter> operator-(typename reverse_iterator<Iter>::difference_type a, reverse_iterator<Iter> b)
{
    reverse_iterator<Iter> temp(b);
    temp = b._base - a;

    return (temp);
}


template <class Iter>
reverse_iterator<Iter> &reverse_iterator<Iter>::operator=(const reverse_iterator<Iter> &ref )
{
    // cout << "Copy assignment operator= called" << endl;
    this->_base = ref._base;
    return (*this);
}

#endif