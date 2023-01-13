#ifndef VECTORITERATOR_TPP
# define VECTORITERATOR_TPP

using namespace ft;

template <typename T>
vectorIterator<T>::vectorIterator()
{
    // cout << "vectorIterator constructor called" << endl;
}

template <typename T>
vectorIterator<T>::vectorIterator(pointer pntr) : _ptr(pntr)
{
    // cout << "vectorIterator constructor called" << endl;
}

template<class T>
vectorIterator<T>::vectorIterator(const vectorIterator &ref)
{
	*this = ref;
}

template <typename T>
vectorIterator<T>::~vectorIterator()
{
    // cout << "vectorIterator destructor called" << endl;
}

template <typename T>
typename vectorIterator<T>::reference vectorIterator<T>::operator*()
{
    return (*this->_ptr);
}

template <typename T>
typename vectorIterator<T>::pointer vectorIterator<T>::operator->()
{
    return (this->_ptr);
}

template <typename T>
vectorIterator<T>& vectorIterator<T>::operator++()
{
    this->_ptr++;
    return (*this);
}

template <typename T>
vectorIterator<T> vectorIterator<T>::operator++(int)
{
    vectorIterator  tmp = *this;
    ++(*this);
    return (tmp);
}

template <typename T>
vectorIterator<T>& vectorIterator<T>::operator--()
{
    this->_ptr--;
    return (*this);
}

template <typename T>
vectorIterator<T> vectorIterator<T>::operator--(int)
{
    vectorIterator  tmp = *this;
    --(*this);
    return (tmp);
}

template <typename T>
vectorIterator<T>& vectorIterator<T>::operator+=(difference_type diff)
{
    this->_ptr += diff;
    return (*this);
}

template <typename T>
vectorIterator<T>& vectorIterator<T>::operator-=(difference_type diff)
{
    this->_ptr -= diff;
    return (*this);
}

template <typename T>
typename vectorIterator<T>::reference vectorIterator<T>::operator[](difference_type diff)
{
    return (this->_ptr[diff]);
}

template <typename T> // Changing my stuff
bool operator<(vectorIterator<T> &lhs, const vectorIterator<T> &rhs)
{
    return (lhs._ptr < rhs._ptr);
}

template <typename T>
bool operator==(vectorIterator<T> &lhs, const vectorIterator<T> &rhs)
{
    return (lhs._ptr == rhs._ptr);
}

template <typename T>
bool operator!=(const vectorIterator<T> &lhs, const vectorIterator<T> &rhs)
{
   return (lhs._ptr != rhs._ptr);
}

template <typename T>
bool operator<=(vectorIterator<T> &lhs, const vectorIterator<T> &rhs)
{
    return (lhs._ptr <= rhs._ptr);
}

template <typename T>
bool operator>(vectorIterator<T> &lhs, const vectorIterator<T> &rhs)
{
    return (lhs._ptr > rhs._ptr);
}

template <typename T>
bool operator>=(vectorIterator<T> &lhs, const vectorIterator<T> &rhs)
{
    return (lhs._ptr >= rhs._ptr);
}

template <typename T>
vectorIterator<T> operator+(vectorIterator<T> a, typename vectorIterator<T>::difference_type b)
{
    vectorIterator<T> temp(a);

    temp._ptr += b;
    return (temp);
}

template <typename T>
vectorIterator<T> operator+(typename vectorIterator<T>::difference_type a, vectorIterator<T> b)
{
    return (b + a); // JUST LOOK UP AND SEE BRO
}

template <typename T>
vectorIterator<T> operator-(vectorIterator<T> a, typename vectorIterator<T>::difference_type b)
{

    vectorIterator<T> temp(a);

    temp._ptr -= b;
    return (temp);
}

template <typename T>
vectorIterator<T> operator-(typename vectorIterator<T>::difference_type a, vectorIterator<T> b)
{
    return (b - a);
}

template <typename T>
typename vectorIterator<T>::difference_type  operator-(vectorIterator<T> a, vectorIterator<T> b)
{
    typename    vectorIterator<T>::difference_type diff;
    if (a._ptr > b._ptr)
        diff = a._ptr - b._ptr;
        // return (a._ptr - b._ptr);
    else
        diff = b._ptr - a._ptr;
        // return (b._ptr - a._ptr);
    return(diff);
}


template <typename T>
vectorIterator<T> &vectorIterator<T>::operator=(const vectorIterator<T> &ref )
{
    // cout << "Copy assignment operator called" << endl;
    this->_ptr = ref._ptr;
    return (*this);
}

#endif