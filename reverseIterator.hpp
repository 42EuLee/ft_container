#ifndef REVERSEITERATOR_HPP
# define REVERSEITERATOR_HPP

#include <iostream>
#include "iterator_traits.hpp"

using std::cout;
using std::endl;

namespace ft
{
    template <class Iter>
    class reverse_iterator
    {
		public:
			typedef Iter													iterator_type;
			typedef typename ft::iteratorTraits<Iter>::difference_type		difference_type;
			typedef typename ft::iteratorTraits<Iter>::value_type			value_type;
			typedef typename ft::iteratorTraits<Iter>::pointer				pointer;
			typedef typename ft::iteratorTraits<Iter>::reference			reference;
			typedef typename ft::iteratorTraits<Iter>::iterator_category	iterator_category;

			explicit reverse_iterator();
			explicit reverse_iterator(iterator_type iter);

			template<class U>
			reverse_iterator (const reverse_iterator<U> &ref);

			reference operator*();
			pointer operator->();

			reverse_iterator& operator++();
			reverse_iterator operator++(int);

		
			reverse_iterator& operator--();
			reverse_iterator operator--(int);

			reverse_iterator& operator+=(difference_type);
			reverse_iterator& operator-=(difference_type);

			reference operator[](difference_type);
			reverse_iterator &operator=(const reverse_iterator &ref );
			
			// bool operator<(reverse_iterator<Iter> &ops);
			// bool operator>(reverse_iterator<Iter> &ops);
			// bool operator<=(reverse_iterator<Iter> &ops);
			// bool operator>=(reverse_iterator<Iter> &ops);
			// bool operator==(reverse_iterator<Iter> &ops);
			// bool operator!=(const reverse_iterator &ops) { cout << "1" << endl; return (this->base() != ops.base()); }

			iterator_type base() const;
		private:
			iterator_type _base;

    };


}

# include "reverseIterator.tpp"

#endif