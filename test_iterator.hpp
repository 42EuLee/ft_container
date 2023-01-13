#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>

using std::cout;
using std::endl;

template <typename T>
class vec_iterator
{
    typedef std::ptrdiff_t difference_type;
    typedef T value_type;
    typedef T* pointer;
    typedef T& reference;
    typedef std::random_access_iterator_tag iterator_category;

    vec_iterator();

    reference operator*();
    pointer operator->();

    vec_iterator& operator++();
    vec_iterator operator++(int);
    vec_iterator& operator--();
    vec_iterator operator--(int);

    vec_iterator& operator+=(difference_type);
    vec_iterator& operator-=(difference_type);

    reference operator[](difference_type);
};

template <typename T>
bool operator ==(vec_iterator<T>, vec_iterator<T>);
template <typename T>
bool operator !=(vec_iterator<T>, vec_iterator<T>);

template <typename T>
bool operator <(vec_iterator<T>, vec_iterator<T>);
template <typename T>
bool operator <=(vec_iterator<T>, vec_iterator<T>);
template <typename T>
bool operator >(vec_iterator<T>, vec_iterator<T>);
template <typename T>
bool operator >=(vec_iterator<T>, vec_iterator<T>);

template <typename T>
vec_iterator<T> operator +(vec_iterator<T>, typename vec_iterator<T>::difference_type);
template <typename T>
vec_iterator<T> operator +(typename vec_iterator<T>::difference_type, vec_iterator<T>);

template <typename T>
vec_iterator<T> operator -(vec_iterator<T>, typename vec_iterator<T>::difference_type);
template <typename T>
vec_iterator<T> operator -(typename vec_iterator<T>::difference_type, vec_iterator<T>);

#endif