#ifndef REVERSEITERATOR_TPP
# define REVERSEITERATOR_TPP

using namespace ft;

template <class Iter>
reverse_iterator<Iter>::reverse_iterator()
{
    cout << "reverseIterator constructor called" << endl;
}

template <class Iter>
reverse_iterator<Iter>::reverse_iterator(iterator_type iter)
{
	this->_base = iter - 1;
    cout << "reverseIterator  called" << endl;
}

/* rETARDED*/
template < class Iter>
template < class U > 
reverse_iterator<Iter>::reverse_iterator(const reverse_iterator<U> &ref)
{
    cout << "Copy constructor called" << endl;
	this->_base = ref._base;
}

template <class Iter>
Iter reverse_iterator<Iter>::base() const
{
	return(this->_base + 1);
}


template <class Iter>
typename reverse_iterator<Iter>::reference reverse_iterator<Iter>::operator*()
{
    return ( *this->_base);
}

template <class Iter>
typename reverse_iterator<Iter>::pointer reverse_iterator<Iter>::operator->()
{
    return (this->_base);
}

template <class Iter>
reverse_iterator<Iter>& reverse_iterator<Iter>::operator++()
{
    this->_base++;
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
    this->_base--;
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
    this->_base += diff;
    return (*this);
}

template <class Iter>
reverse_iterator<Iter>& reverse_iterator<Iter>::operator-=(difference_type diff)
{
    this->_base -= diff;
    return (*this);
}

template <class Iter>
typename reverse_iterator<Iter>::reference reverse_iterator<Iter>::operator[](difference_type diff)
{
    return (this->_base[diff]);
}

template <class Iter> // Changing my stuff
bool operator<(const reverse_iterator<Iter> &lhs, const reverse_iterator<Iter> &rhs)
{
    return ((lhs.base() - 1) < (rhs.base() - 1));
}

template <class Iter>
bool operator==(const reverse_iterator<Iter> &lhs, const reverse_iterator<Iter> &rhs)
{
    return ((lhs.base() - 1) == (rhs.base() - 1));
}

template <class Iter>
bool operator!=(const reverse_iterator<Iter> &lhs, const reverse_iterator<Iter> &rhs)
{
    cout << "2" << endl;
   return ((lhs.base() - 1) != (rhs.base() - 1));
}

template <class Iter>
bool operator<=(const reverse_iterator<Iter> &lhs, const reverse_iterator<Iter> &rhs)
{
    return ((lhs.base() - 1) <= (rhs.base() - 1));
}

template <class Iter>
bool operator>(const reverse_iterator<Iter> &lhs, const reverse_iterator<Iter> &rhs)
{
    return ((lhs.base() - 1) > (rhs.base() - 1));
}

template <class Iter>
bool operator>=(const reverse_iterator<Iter> &lhs, const reverse_iterator<Iter> &rhs)
{
    return ((lhs.base() - 1) >= (rhs.base() - 1));
}

template <class Iter>
reverse_iterator<Iter> operator+(reverse_iterator<Iter> a, typename reverse_iterator<Iter>::difference_type b)
{
    reverse_iterator<Iter> temp(a);

    temp._base += b;
    return (temp);
}

template <class Iter>
reverse_iterator<Iter> operator+(typename reverse_iterator<Iter>::difference_type a, reverse_iterator<Iter> b)
{
    return (b + a); // JUST LOOK UP AND SEE BRO
}

template <class Iter>
reverse_iterator<Iter> operator-(reverse_iterator<Iter> a, typename reverse_iterator<Iter>::difference_type b)
{

    reverse_iterator<Iter> temp(a);

    temp._base -= b;
    return (temp);
}

template <class Iter>
reverse_iterator<Iter> operator-(typename reverse_iterator<Iter>::difference_type a, reverse_iterator<Iter> b)
{
    return (b - a);
}


template <class Iter>
reverse_iterator<Iter> &reverse_iterator<Iter>::operator=(const reverse_iterator<Iter> &ref )
{
    // cout << "Copy assignment operator called" << endl;
    this->_base = ref._base;
    return (*this);
}

#endif