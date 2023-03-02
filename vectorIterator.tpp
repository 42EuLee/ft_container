#ifndef VECTORITERATOR_TPP
# define VECTORITERATOR_TPP

using namespace ft;

namespace ft
{
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

    template <typename T>
    vectorIterator<T>::vectorIterator(vectorIterator<typename ft::remove_const<value_type>::type> const &ref)
    {
        // cout << "vectorIterator copy constructor called" << endl;
        *this = ref;
    }

    template <typename T>
    vectorIterator<T>::~vectorIterator()
    {
        // cout << "vectorIterator destructor called" << endl;
    }

    template <typename T>
    typename vectorIterator<T>::reference vectorIterator<T>::operator*() const
    {
        return (*this->_ptr);
    }

    template <typename T>
    typename vectorIterator<T>::pointer vectorIterator<T>::operator->() const
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

    template <typename T, typename U>
    bool operator<(const vectorIterator<T> &lhs, const vectorIterator<U> &rhs)
    {
        return (lhs._ptr < rhs._ptr);
    }

    template <typename T, typename U>
    bool operator==(const vectorIterator<T> &lhs, const vectorIterator<U> &rhs)
    {
        return (lhs._ptr == rhs._ptr);
    }

    template <typename T, typename U>
    bool operator!=(const vectorIterator<T> &lhs, const vectorIterator<U> &rhs)
    {
    return (lhs._ptr != rhs._ptr);
    }

    template <typename T, typename U>
    bool operator<=(const vectorIterator<T> &lhs, const vectorIterator<U> &rhs)
    {
        return (lhs._ptr <= rhs._ptr);
    }

    template <typename T, typename U>
    bool operator>(const vectorIterator<T> &lhs, const vectorIterator<U> &rhs)
    {
        return (lhs._ptr > rhs._ptr);
    }

    template <typename T, typename U>
    bool operator>=(const vectorIterator<T> &lhs, const vectorIterator<U> &rhs)
    {
        return (lhs._ptr >= rhs._ptr);
    }

    template <typename T>
    vectorIterator<T> operator+(const vectorIterator<T> a, typename vectorIterator<T>::difference_type b)
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

    template <typename T, typename U>
    typename vectorIterator<T>::difference_type  operator-(vectorIterator<T> a, vectorIterator<U> b)
    {
        typename    vectorIterator<T>::difference_type diff;
        diff = a._ptr - b._ptr;
        return(diff);
    }

    template <typename T>
    vectorIterator<T> &vectorIterator<T>::operator=(vectorIterator<typename ft::remove_const<T>::type> const &ref)
    {
        // cout << "Copy assignment operator called" << endl;
        this->_ptr = ref._ptr;
        return (*this);
    }
}

#endif