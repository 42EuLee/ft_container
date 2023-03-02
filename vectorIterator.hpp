#ifndef VECTORITERATOR_HPP
# define VECTORITERATOR_HPP

#include <iostream>
#include <algorithm>
#include "iterator_traits.hpp"
#include "remove_const.hpp"

using std::cout;
using std::endl;

namespace ft
{
    template <typename T>
    struct vectorIterator
    {
        // typedef typename std::remove_const<T>::type U;
	    typedef random_access_iterator_tag  iterator_category;
        typedef ptrdiff_t                   difference_type;
        typedef T                           value_type;
        typedef T*                          pointer;
        typedef T&                          reference;
    
        pointer _ptr;

        vectorIterator();
        vectorIterator(pointer);

        vectorIterator(vectorIterator<typename ft::remove_const<value_type>::type> const &ref);

        ~vectorIterator();

        reference operator*() const;
        pointer operator->() const;

        vectorIterator& operator++();
        vectorIterator operator++(int);

    
        vectorIterator& operator--();
        vectorIterator operator--(int);

        vectorIterator& operator+=(difference_type);
        vectorIterator& operator-=(difference_type);

        reference operator[](difference_type);

        vectorIterator &operator=(vectorIterator<typename ft::remove_const<T>::type> const &ref);

    };

}

# include "vectorIterator.tpp"

#endif