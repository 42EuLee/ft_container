#ifndef MAPITERATOR_HPP
# define MAPITERATOR_HPP

#include <iostream>
#include <algorithm>
#include "iterator_traits.hpp"
#include "remove_const.hpp"
#include "rbt.hpp"
// #include "map.hpp"

using std::cout;
using std::endl;

namespace ft
{

    template <class T>
    struct mapIterator
    {
        typedef bidirectional_iterator_tag                          iterator_category;
        typedef ptrdiff_t                                           difference_type;
        typedef T                                                   value_type;
        // typedef Node<typename ft::remove_const<value_type>::type>   node_ptr;
        typedef Node<typename ft::remove_const<value_type>::type>   node_ptr;
        typedef T*                                                  pointer;
        typedef T&                                                  reference;

        mapIterator();
        // mapIterator(pointer ref);
        mapIterator(node_ptr *node);
        mapIterator(mapIterator<typename ft::remove_const<value_type>::type> const &ref);

        ~mapIterator();

        reference operator*() const;
        pointer operator->() const;

        mapIterator operator-(int) const;
        mapIterator operator+(int) const;

        mapIterator& operator++();
        mapIterator operator++(int);

    
        mapIterator& operator--();
        mapIterator operator--(int);

        mapIterator& operator+=(difference_type);
        mapIterator& operator-=(difference_type);

        reference operator[](difference_type);
        mapIterator &operator=(mapIterator<typename ft::remove_const<T>::type> const &ref);

        node_ptr        *_node;
        T               *_base;

    };
}

# include "mapIterator.tpp"

#endif