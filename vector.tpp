#ifndef VECTOR_TPP
# define VECTOR_TPP

using namespace ft;

/* My default constructor */
template < class T, class Alloc > 
vector<T, Alloc>::vector(const allocator_type& alloc) : _alloc(alloc)
{
    cout << GRN << "vector default constructor called" << RESET << endl;
    this->_capacity = 0;
    this->_size = 0;
    this->_vector = this->_alloc.allocate(0);
}

/* Fill vector constructor */
template < class T, class Alloc >
vector<T, Alloc>::vector(size_t n, const value_type& val, const allocator_type& alloc) : _alloc(alloc)
{
    cout << GRN << "vector fill constructor called" << RESET << endl;
    this->_size = n;
    if (this->_size > 0) // to prevent memleaks of ft::vector<int> realvector(0,100);
        this->_vector = this->_alloc.allocate(n);
    for (size_t i = 0; i < this->_size; i++)
        this->_alloc.construct(this->_vector + i, val);
    this->_capacity = n;
}

/* Range vector constructor */
template < class T, class Alloc > 
template <class InputIterator> 
vector<T, Alloc>::vector(InputIterator first, InputIterator last, const allocator_type& alloc, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type*) : _alloc(alloc)
{
    cout << GRN << "vector range constructor called" <<  RESET << endl;

    this->_capacity = 0;
    this->_size = (size_type)(last - first);
    this->_capacity = (size_type)(last - first);
    if (this->_size > 0) // to prevent memleaks of ft::vector<int> realvector(0,100);
        this->_vector = this->_alloc.allocate(this->_size);
    for (size_t i = 0; i < this->_size; i++)
        this->_alloc.construct(this->_vector + i, *(first + i));
}

/* Copy vector constructor */
template < class T, class Alloc > 
vector<T, Alloc >::vector (const vector& x)
{
    // cout << "Copy constructor called" << endl;
    for (size_t i = 0; i < this->_size; i++)
        this->_alloc.destroy(this->_vector + i);
    if (this->_capacity > 0)
        this->_alloc.deallocate(this->_vector, this->_capacity); // check tmr
    this->_alloc = x.get_allocator();
    this->_vector = this->_alloc.allocate(this->_capacity);
    this->_capacity = x._capacity;
    this->_size = x._size;
    for (size_t i = 0; i < this->_size; i++)
        this->_alloc.construct(this->_vector + i, x._vector + i);
}

/* Vector destructor */
template < class T, class Alloc > 
vector<T, Alloc>::~vector()
{
    cout << RED << "vector destructor called" << RESET << endl;
    for (size_t i = 0; i < this->_size; i++)
        this->_alloc.destroy(this->_vector + i);
    this->_alloc.deallocate(this->_vector, this->_capacity);
}

/*  1. range assign()
    - We first destroy everything that is in the initial vector
    - We then reserve to a large space if needed
    - The numbers from first to last are then constructed to the vector
*/
template < class T, class Alloc >
template <class InputIterator>
void vector<T, Alloc>::assign(InputIterator first, InputIterator last)
{
    cout << "range assign member function" << endl;
    difference_type n = last - first;

    for (size_t i = 0; i < this->_size; i++)
        this->_alloc.destroy(this->_vector + i);
    if ((long)this->_size < n)
    {
        this->reserve(n);
        this->_capacity = n;
    }
    for (long i = 0; i < n ; i++)
        this->_alloc.construct(this->_vector + i, *(first + i));
    this->_size = n;
}

/*  2. Fill assign()
    - We first destroy everything that is in the initial vector
    - We then reserve to a large space if needed
    - The vector is constructed with the same number, n amount of times
*/
template < class T, class Alloc > 
void vector<T, Alloc>::assign(size_type n, const value_type& val)
{
    cout << "fill assign member function" << endl;
    for (size_t i = 0; i < this->_size; i++)
        this->_alloc.destroy(this->_vector + i);
    if ((long)this->_size < n)
    {
        this->reserve(n);
        this->_capacity = n;
    }
    for (unsigned long i = 0; i < n ; i++)
        this->_alloc.construct(this->_vector + i, val);
    this->_size = n;
}

/* 3. at() */
template < class T, class Alloc > 
typename vector<T, Alloc>::reference   vector<T, Alloc>::at(size_t n)
{
    if (n >= this->_size) 
        throw std::out_of_range("Index out of bounds");
    return(this->_vector[n]);
}

/* 4. at() const */
template < class T, class Alloc > 
typename vector<T, Alloc>::const_reference   vector<T, Alloc>::at(size_t n) const
{
    if (n >= this->_size) 
        throw std::out_of_range("Index out of bounds");
    return(this->_vector[n]);
}

/* 5. back() */
template < class T, class Alloc > 
typename vector<T, Alloc>::reference   vector<T, Alloc>::back()
{
    return(this->_vector[this->_size - 1]);
}

/* 6. back() const */
template < class T, class Alloc > 
typename vector<T, Alloc>::const_reference   vector<T, Alloc>::back() const
{
    return(this->_vector[this->_size - 1]);
}

/* 7. begin() const */
template < class T, class Alloc > 
typename vector<T, Alloc>::iterator     vector<T, Alloc>::begin()
{
    // cout << "BEGINA()IDA)D" << endl;
    return(iterator(this->_vector));
}

/* 8. begin() const */
template < class T, class Alloc > 
typename vector<T, Alloc>::const_iterator     vector<T, Alloc>::begin() const
{
    return(const_iterator(this->_vector));
}

/* 9. begin() const */
template < class T, class Alloc >
size_t vector<T, Alloc>::capacity() const
{
    return(this->_capacity);
}

/* 10. clear() const */
template < class T, class Alloc >
void    vector<T, Alloc>::clear() const
{
    for (size_t i = 0; i < this->_size; i++)
        this->_alloc.destroy(this->_vector + i);
    this->_alloc.deallocate(this->_vector, this->_size);
    this->_size = 0;
}

/* 11. empty() const */
template < class T, class Alloc >
bool vector<T, Alloc>::empty() const
{
    return(this->_size > 0);
}

/* 12. end() const */
template < class T, class Alloc > 
typename vector<T, Alloc>::iterator     vector<T, Alloc>::end()
{
    return(iterator(this->_vector + this->_size));
}

/* 13. end() const */
template < class T, class Alloc > 
typename vector<T, Alloc>::const_iterator     vector<T, Alloc>::end() const
{
    return(const_iterator(this->_vector + this->_size));
}

/* 14. position erase() */
template < class T, class Alloc >
typename vector<T, Alloc>::iterator    vector<T, Alloc>::erase(iterator position)
{
    for (iterator it = position; it < this->end() - 1; it++)
        *it = *(it + 1);
    this->_alloc.destroy(this->_vector + this->_size);
    this->_size--;
    return (this->begin() + this->_size);
}

/* 15. range erase() */
template < class T, class Alloc >
typename vector<T, Alloc>::iterator    vector<T, Alloc>::erase(iterator first, iterator last)
{

    difference_type diff = last - first;

    for (iterator it = last; it < this->end(); it++)
        *(it - diff) = *it;
    for (difference_type i = 0; i < diff; i++)
        this->_alloc.destroy(this->_vector + --this->_size);
    return (this->begin() + this->_size);
}

/* 16. front() */
template < class T, class Alloc >
typename vector<T, Alloc>::reference   vector<T, Alloc>::front()
{
    return(*(this->_vector));
}

/* 17. front() const */
template < class T, class Alloc >
typename vector<T, Alloc>::const_reference   vector<T, Alloc>::front() const
{
    return(*(this->_vector));
}

/* 18. get_allocator() */
template < class T, class Alloc > 
typename vector<T, Alloc>::allocator_type   vector<T, Alloc>::get_allocator() const
{
	return(this->_alloc);
}

/* 19. single element insert() */
template < class T, class Alloc >
typename vector<T, Alloc>::iterator     vector<T, Alloc>::insert(iterator position, const value_type& val)
{    
    difference_type diff = position - this->begin();
    this->insert(position, 1, val);
    return (this->begin() + diff);
}

/* 20. fill insert() */
template < class T, class Alloc >
void    vector<T, Alloc>::insert(iterator position, size_type n, const value_type& val)
{
    T           *temp;
    size_t      count;

    difference_type start = position - this->begin();
    difference_type end = position - this->begin() + n;
    count = 0;
    if (n < 0)
        return ;
    if (this->_size <= 0)
    {
        cout << "zsh: segmentation fault  ./vector" << endl;
        exit (1);
    }
    temp = this->_alloc.allocate(this->_size);
    for (size_t i = 0; i < this->_size; i++)
        this->_alloc.construct(temp + i, this->_vector[i]);
    if (this->_size + n > this->_capacity)
        this->reserve(std::max(this->_capacity * 2, (this->_capacity * 2) + n));
    this->_size += n;
    for (size_t i = 0; i < this->_size; i++)
    { 
        // please later comment if not won't understand
        if (count == n)
        {
            this->_alloc.destroy(this->_vector + i);
            this->_alloc.construct(this->_vector + i, temp[i - count]);
        }
        else if (i >= (size_t)start && i <= (size_t)end)
        {
            this->_alloc.destroy(this->_vector + i);
            this->_alloc.construct(this->_vector + i, val);
            count++;
        }
    }
    for (size_t i = 0; i < this->_size; i++)
        this->_alloc.destroy(temp + i);
    this->_alloc.deallocate(temp, this->_size - n);

}

/* 21. range insert() */
template < class T, class Alloc >
template <class InputIterator> 
void    vector<T, Alloc>::insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type*)
{
    T                   *temp;
    difference_type     count;
    difference_type     diff = last - first;
    difference_type     start = position - this->begin();
    difference_type     end = position - this->begin() + diff;
    if (first >= last)
    {
        return ;
    }

    temp = this->_alloc.allocate(this->_size);
    for (size_t i = 0; i < this->_size; i++)
        this->_alloc.construct(temp + i, this->_vector[i]);
    // for (int i = 0; i < diff; i++)
    //     this->_alloc.construct(temp + i, *(first + i));

    if (this->_size + diff > this->_capacity)
    {
        cout << "reserve" << endl;
        this->reserve(std::max(this->_capacity * 2, (this->_capacity * 2) + diff));
    }
    count = 0;
    this->_size += diff;
    for (size_t i = 0; i < this->_size; i++)
    { 
        // please later comment if not won't understand
        if (count == diff)
        {
            cout << "1" << endl;
            this->_alloc.destroy(this->_vector + i);
            this->_alloc.construct(this->_vector + i, temp[i - diff]);
        }
        else if (i >= (size_t)start && i <= (size_t)end)
        {
            cout << "2" << endl;
            this->_alloc.destroy(this->_vector + i);
            this->_alloc.construct(this->_vector + i, *(first + i)); // not workin
            count++;
        }
        else
            cout << "3" << endl;
    }

    for (size_t i = 0; i < this->_size; i++)
        this->_alloc.destroy(temp + i);
    this->_alloc.deallocate(temp, this->_size - diff);
    // destructing old vector and pointing it to the temp (replacing in a way )

}

/* 22. max_size() */
template < class T, class Alloc >
size_t vector<T, Alloc>::max_size() const
{
    return(this->_alloc.max_size());
}

/* 23. pop_back() */
template < class T, class Alloc > 
void    vector<T, Alloc>::pop_back()
{
        this->_alloc.destroy(this->_vector + this->_size);
        this->_size--;
}

/* 24. push_back() */
template < class T, class Alloc > 
void    vector<T, Alloc>::push_back(const value_type& val)
{
    if (this->_capacity == 0)
    {
        this->_capacity = 1;
        this->_vector = this->_alloc.allocate(this->_capacity);
        this->_alloc.construct(this->_vector, val);
    }
    else if (this->_size < this->_capacity)
        this->_alloc.construct(this->_vector + this->_size, val);
	else if (this->_size == this->_capacity)
    {
		this->_capacity = this->_capacity * 2;
        T   *temp;
        temp = this->_alloc.allocate(this->_capacity);
        for (size_t i = 0; i < this->_size; i++)
        {
            this->_alloc.construct(temp + i, this->_vector[i]);
            this->_alloc.destroy(this->_vector + i);
        }
        this->_alloc.construct(temp + this->_size, val);
        this->_alloc.deallocate(this->_vector, this->_size);
        this->_vector = temp;
    }
    this->_size++;
}

/* 25. rbegin() */
template < class T, class Alloc > 
typename vector<T, Alloc>::reverse_iterator     vector<T, Alloc>::rbegin()
{
    return(reverse_iterator(this->end()));
}

/* 26. rbegin() const */
template < class T, class Alloc > 
typename vector<T, Alloc>::const_reverse_iterator     vector<T, Alloc>::rbegin() const
{
    return(const_reverse_iterator(this->end()));
}

/* 27. rend() */
template < class T, class Alloc > 
typename vector<T, Alloc>::reverse_iterator     vector<T, Alloc>::rend()
{
    return(reverse_iterator(this->begin()));
}

/* 28. rend() const */
template < class T, class Alloc > 
typename vector<T, Alloc>::const_reverse_iterator     vector<T, Alloc>::rend() const
{
    return(const_reverse_iterator(this->begin()));
}

/* 29. reserve() */
template < class T, class Alloc >
void    vector<T, Alloc>::reserve(size_t n)
{
    if (n >= this->_capacity)
    {
        T   *temp;

        temp = this->_alloc.allocate(n);
        for (size_t i = 0; i < this->_size; i++)
        {
            this->_alloc.construct(temp + i, this->_vector[i]);
            this->_alloc.destroy(this->_vector + i);
        }
        this->_alloc.deallocate(this->_vector, this->_capacity);
        this->_vector = temp;
        this->_capacity = n;
    }
}

/* 30. resize() */
template < class T, class Alloc >
void    vector<T, Alloc>::resize(size_t n, value_type val)
{
    (void)val; // wtf
    for (size_t i = n; i <= this->_size; i++)
            this->_alloc.destroy(this->_vector + i);
    this->_size = n;
}

/* 31. size()  */
template < class T, class Alloc >
size_t vector<T, Alloc>::size() const
{
    return(this->_size);
}

/* 32. swap() */
template < class T, class Alloc >
void    vector<T, Alloc>::swap(vector& x)
{
    std::swap(this->_vector, x._vector);
    std::swap(this->_alloc, x._alloc);
    std::swap(this->_size, x._size);
    std::swap(this->_capacity, x._capacity);
}

/* Operator overloads of vector*/

template < class T, class Alloc >
typename vector<T, Alloc>::reference vector<T, Alloc>::operator[](size_t n)
{
    return (this->_vector[n]);
}

template < class T, class Alloc >
typename vector<T, Alloc>::const_reference vector<T, Alloc>::operator[] (size_t n) const
{
    return (this->_vector[n]);
}

template < class T, class Alloc >
vector<T, Alloc>    &vector<T, Alloc>::operator=(const vector& x)
{
    for (size_t i = 0; i < this->_size; i++)
        this->_alloc.destroy(this->_vector + i);
    if (this->_capacity > 0)
        this->_alloc.deallocate(this->_vector, this->_capacity);
    this->_alloc = x.get_allocator();
    this->_vector = this->_alloc.allocate(this->_capacity);
    this->_capacity = x._capacity;
    this->_size = x._size;
    for (size_t i = 0; i < this->_size; i++)
        this->_alloc.construct(this->_vector + i, x._vector + i);
    return (*this);
}

template <class T, class Alloc> 
bool operator==(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs)
{
    return((lhs._size == rhs._size) && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

template <class T, class Alloc>
bool operator!=(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs)
{
    // return (!ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
    return(!(lhs == rhs));
}

template <class T, class Alloc>
bool operator<(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs)
{
    return ((lhs._size < rhs._size) && ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}
template <class T, class Alloc>
bool operator<=(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs)
{
    return (!(rhs < lhs));
}

template <class T, class Alloc>
bool operator>(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs)
{
    return ((lhs._size > rhs._size) && ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
}
	
template <class T, class Alloc>
bool operator>=(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs)
{
    return (!(rhs > lhs));
}

#endif
