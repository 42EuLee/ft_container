// template < class T, class Alloc >
// typename vector<T, Alloc>::iterator     vector<T, Alloc>::insert(iterator position, const value_type& val)
// {    
//     difference_type diff = position - this->begin();
//     this->insert(position, 1, val);
//     return (this->begin() + diff);
// }

// template < class T, class Alloc >
// void    vector<T, Alloc>::insert(iterator position, size_type n, const value_type& val)
// {
//     T           *temp;
//     size_t      count;

//     difference_type start = position - this->begin(); // do I need the this->begin()?
//     difference_type end = position - this->begin() + n;

//     if (this->_capacity + n >= this->_size)
//         this->reserve(std::max(this->_capacity * 2, this->_capacity + n));

//     temp = this->_alloc.allocate(this->_capacity);
//     count = 0;
//     for (size_t i = 0; i < this->_size; i++)
//     { 
//         // please later comment if not won't understand
//         if (count == n)
//             this->_alloc.construct(temp + i + count, this->_vector[i]);
//         else if (i >= (size_t)start && i <= (size_t)end)
//         {
//             this->_alloc.construct(temp + i + count, val);
//             count++;
//             i--;
//         }
//         else
//             this->_alloc.construct(temp + i, this->_vector[i]);
//     }
//     // destructing old vector and pointing it to the temp (replacing in a way )
//     for (size_t i = 0; i < this->_size; i++)
//         this->_alloc.destroy(this->_vector + i);
//     this->_alloc.deallocate(this->_vector, this->_size);
//     this->_vector = temp;
//     this->_size += n;
// }

// template < class T, class Alloc >
// template <class InputIterator> 
// void    vector<T, Alloc>::insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type*)
// {
//     T                   *temp;
//     T                   *temp2;
//     difference_type     count;
//     difference_type     diff = last - first;
//     difference_type     start = position - this->begin(); // do I need the this->begin()?
//     difference_type     end = position - this->begin() + diff;
    

//     if (first >= last)
//     {
//         exit(0);
//     }
//     count = 0;

//     temp2 = this->_alloc.allocate(diff);
//     for (int i = 0; i < diff; i++)
//         this->_alloc.construct(temp2 + i, *first + i);
//     if (this->_capacity + diff >= this->_size)
//         this->reserve(this->_capacity * 2);
//     temp = this->_alloc.allocate(this->_capacity);
//     for (size_t i = 0; i < this->_size; i++)
//     {
//         // please later comment if not won't understand
//         if (count == diff)
//             this->_alloc.construct(temp + i + count, this->_vector[i]);
//         else if (i >= (size_t)start && i <= (size_t)end)
//         {
//             this->_alloc.construct(temp + i + count, temp2[count]); // has to be count = 0 to work
//             count++;
//             i--;
//         }
//         else
//             this->_alloc.construct(temp + i, this->_vector[i]);
//     }
//     // destructing old vector and pointing it to the temp (replacing in a way )
//     for (size_t i = 0; i < this->_size; i++)
//         this->_alloc.destroy(this->_vector + i);
//     this->_alloc.deallocate(this->_vector, this->_size);

//     for (int i = 0; i < diff; i++)
//         this->_alloc.destroy(temp2 + i);
//     this->_alloc.deallocate(temp2, diff);
//     this->_vector = temp;
//     this->_size += diff;
// }