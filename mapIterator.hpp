#ifndef MAPITERATOR_HPP
# define MAPITERATOR_HPP

#include <iostream>
#include <algorithm>
#include "iterator_traits.hpp"

using std::cout;
using std::endl;

namespace ft
{    

    template <typename T>
    struct mapIterator
    {
        typedef typename ft::iteratorTraits<T *>::difference_type difference_type;
        typedef typename ft::iteratorTraits<T *>::value_type value_type;
        typedef typename ft::iteratorTraits<T *>::pointer pointer;
        typedef typename ft::iteratorTraits<T *>::reference reference;
	    typedef typename ft::iteratorTraits<T *>::iterator_category iterator_category;

        pointer _ptr;

        vectorIterator();
        vectorIterator(pointer);
        vectorIterator(const vectorIterator &ref);

        ~vectorIterator();

        reference operator*();
        pointer operator->();

        vectorIterator& operator++();
        vectorIterator operator++(int);

    
        vectorIterator& operator--();
        vectorIterator operator--(int);

        vectorIterator& operator+=(difference_type);
        vectorIterator& operator-=(difference_type);

        reference operator[](difference_type);
        vectorIterator &operator=(const vectorIterator &ref );
        
        // bool operator<(vectorIterator<T> &ops);
        // bool operator>(vectorIterator<T> &ops);
        // bool operator<=(vectorIterator<T> &ops);
        // bool operator>=(vectorIterator<T> &ops);
        // bool operator==(vectorIterator<T> &ops);
        // bool operator!=(const vectorIterator &ops) { return (this->_ptr != ops._ptr); };

    };
    // template <typename T>
    // vectorIterator<T> operator -(vectorIterator<T> a, typename vectorIterator<T>::difference_type b);

    // template <typename T>
    // vectorIterator<T> operator -(typename vectorIterator<T>::difference_type a, vectorIterator<T> b);
}

# include "vectorIterator.tpp"

#endif