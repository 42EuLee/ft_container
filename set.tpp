#ifndef SET_TPP
# define SET_TPP

using namespace ft;

/* My default constructor */
template <class T, class Compare, class Alloc> 
set<T, Compare, Alloc>::set(const key_compare &comp, const allocator_type& alloc) : _alloc(alloc) , _compare(comp), rbt(alloc, _compare)
{
    // cout << GRN << "set default constructor called" << RESET << endl;
}

template <class T, class Compare, class Alloc> 
template <class InputIterator>
set<T, Compare, Alloc>::set(InputIterator first, InputIterator last, const key_compare &comp, const allocator_type& alloc) : _alloc(alloc) , _compare(comp), rbt(alloc, comp)
{
    // cout << GRN << "set range constructor called" <<  RESET << endl;

    while (first != last)
        this->insert(*first++);
}

template <class T, class Compare, class Alloc> 
set<T, Compare, Alloc>::set (const set& x) : rbt(x._alloc, x._compare)
{
    // cout << GRN << "set copy constructor called" <<  RESET << endl;
    this->rbt = x.rbt;
}


/* set destructor */
template <class T, class Compare, class Alloc> 
set<T, Compare, Alloc>::~set()
{
    // cout << RED << "set destructor called" << RESET << endl;
}

template <class T, class Compare, class Alloc> 
typename set<T, Compare, Alloc>::iterator      set<T, Compare, Alloc>::begin()
{

    typename set<T, Compare, Alloc>::iterator it(this->rbt._sentinel->_left);

    return(it);
}

template <class T, class Compare, class Alloc> 
typename set<T, Compare, Alloc>::const_iterator    set<T, Compare, Alloc>::begin() const
{
    typename set<T, Compare, Alloc>::const_iterator it(this->rbt._sentinel->_left);
    return(it);
}

template <class T, class Compare, class Alloc> 
void    set<T, Compare, Alloc>::clear()
{   
    this->rbt.deleteAll();
}

template <class T, class Compare, class Alloc> 
size_t     set<T, Compare, Alloc>::count(const value_type& k) const
{
    ft::Node< typename set<T, Compare, Alloc>::value_type> *temp;

    temp = this->rbt.treeSearch(this->rbt._root, k);
    return (temp->_isNil == 0); 
}

template < class T, class Compare, class Alloc>
bool       set<T, Compare, Alloc>::empty() const
{
    return (this->rbt._size < 1);
}

template <class T, class Compare, class Alloc> 
typename set<T, Compare, Alloc>::iterator     set<T, Compare, Alloc>::end()
{

    typename set<T, Compare, Alloc>::iterator it(this->rbt._sentinel);
    return(it);
}

template < class T, class Compare, class Alloc>
typename set<T, Compare, Alloc>::const_iterator    set<T, Compare, Alloc>::end() const
{
    typename set<T, Compare, Alloc>::const_iterator it(this->rbt.treeMaximum(this->rbt._root));
    it++;
    return(it);
}

template <class T, class Compare, class Alloc> 
ft::pair<typename set<T, Compare, Alloc>::const_iterator, typename set<T, Compare, Alloc>::const_iterator> set<T, Compare, Alloc>::equal_range(const key_type& k) const
{
    return(ft::make_pair(this->lower_bound(k), this->upper_bound(k)));
}

template <class T, class Compare, class Alloc>
ft::pair<typename set<T, Compare, Alloc>::iterator, typename set<T, Compare, Alloc>::iterator> set<T, Compare, Alloc>::equal_range(const key_type& k)
{
    return(ft::make_pair(this->lower_bound(k), this->upper_bound(k)));
}

template <class T, class Compare, class Alloc>
void    set<T, Compare, Alloc>::erase(iterator position)
{
    this->erase(*position);
}

template <class T, class Compare, class Alloc>
size_t   set<T, Compare, Alloc>::erase (const value_type& k)
{
    return (this->rbt.deletion(k));
}
template <class T, class Compare, class Alloc>
void    set<T, Compare, Alloc>::erase(iterator first, iterator last)
{
    while (first != last)
        this->erase(first++);
}


template <class T, class Compare, class Alloc>
typename set<T, Compare, Alloc>::iterator      set<T, Compare, Alloc>::find(const key_type& k)
{
    for (iterator it = this->begin() ; it != this->end() ; it++)
    {
        if (*it == k)
            return (it);
    }
    return (this->end());
}

template <class T, class Compare, class Alloc>
typename set<T, Compare, Alloc>::const_iterator      set<T, Compare, Alloc>::find(const key_type& k) const
{
    for (const_iterator it = this->begin() ; it != this->end() ; it++)
    {
        if (*it == k)
            return (it);
    }
    return (this->end());
}

template <class T, class Compare, class Alloc>
size_t  set<T, Compare, Alloc>::size() const
{
    return (this->rbt._size);
}

template <class T, class Compare, class Alloc> 
void set<T, Compare, Alloc>::swap(set& x)
{
    std::swap(this->_alloc, x._alloc);
    std::swap(this->_compare, x._compare);
    this->rbt.swap(x.rbt);
}

template <class T, class Compare, class Alloc>
Compare set<T, Compare, Alloc>::key_comp() const
{
    return(this->_compare);
}

template <class T, class Compare, class Alloc> 
typename set<T, Compare, Alloc>::const_iterator  set<T, Compare, Alloc>::lower_bound(const value_type& k) const
{
    for (const_iterator it = this->begin() ; it != this->end() ; it++)
    {
        if (*it >= k)
            return (it);
    }
    return (this->end());
}


template <class T, class Compare, class Alloc> 
typename set<T, Compare, Alloc>::iterator  set<T, Compare, Alloc>::lower_bound(const value_type& k)
{
    for (iterator it = this->begin() ; it != this->end() ; it++)
    {
        if (*it >= k)
            return (it);
    }
    return (this->end());
}

template <class T, class Compare, class Alloc> 
size_t set<T, Compare, Alloc>::max_size() const
{
    return ((std::numeric_limits<std::size_t>::max() / sizeof(typename set<T, Compare, Alloc>::value_type)) / 2);
}

template <class T, class Compare, class Alloc> 
typename set<T, Compare, Alloc>::iterator  set<T, Compare, Alloc>::upper_bound(const key_type& k)
{
    for (iterator it = this->begin() ; it != this->end() ; it++)
    {
        if (*it > k)
            return (it);
    }
    return (this->end());
}

template <class T, class Compare, class Alloc> 
typename set<T, Compare, Alloc>::const_iterator  set<T, Compare, Alloc>::upper_bound(const key_type& k) const
{
    for (const_iterator it = this->begin() ; it != this->end() ; it++)
    {
        if (*it > k)
            return (it);
    }
    return (this->end());
}

template <class T, class Compare, class Alloc> 
typename set<T, Compare, Alloc>::value_compare     set<T, Compare, Alloc>::value_comp() const
{
    return(this->_compare);
}

template <class T, class Compare, class Alloc> 
ft::pair<typename set<T, Compare, Alloc>::iterator,bool>   set<T, Compare, Alloc>::insert(const value_type& val)
{
    ft::Node< typename set<T, Compare, Alloc>::value_type> *temp;
    typename ft::set<T, Compare, Alloc>::iterator it;
    bool    is_true;

    temp = this->rbt.treeSearch(rbt._root, val);
    if (temp->_isNil == 1)
    {
        this->rbt.insertion(val);
        it._node = this->rbt.treeSearch(rbt._root, val);
        is_true = true;
    }
    else
    {
        it._node = temp;
        is_true = false;
    }
    return (ft::make_pair(it, is_true));
}

template <class T, class Compare, class Alloc> 
typename set<T, Compare, Alloc>::iterator  set<T, Compare, Alloc>::insert(iterator position, const value_type& val)
{

    ft::Node< typename set<T, Compare, Alloc>::value_type> *temp;
    typename ft::set<T, Compare, Alloc>::iterator it;
    bool    is_true;

    (void)position;
    temp = this->rbt.treeSearch(rbt._root, val);

    if (temp->_isNil == 1)
    {
        this->rbt.insertion(val);
        it._node = this->rbt.treeSearch(rbt._root, val);
        is_true = false;
    }
    else
    {
        it._node = temp;
        is_true = true;
    }
    return (it);
}

template <class T, class Compare, class Alloc> 
template <class InputIterator>
void set<T, Compare, Alloc>::insert(InputIterator first, InputIterator last)
{
    while (first != last)
        this->insert(*first++);
}


template <class T, class Compare, class Alloc> 
typename set<T, Compare, Alloc>::allocator_type       set<T, Compare, Alloc>::get_allocator() const
{
    return(this->_alloc);
}

template <class T, class Compare, class Alloc> 
typename set<T, Compare, Alloc>::reverse_iterator set<T, Compare, Alloc>::rbegin()
{
    typename set<T, Compare, Alloc>::reverse_iterator rit(this->rbt._sentinel);
    return (rit);
}

template <class T, class Compare, class Alloc> 
typename set<T, Compare, Alloc>::const_reverse_iterator set<T, Compare, Alloc>::rbegin() const
{
    return(reverse_iterator(this->end()));
}


template <class T, class Compare, class Alloc> 
typename set<T, Compare, Alloc>::reverse_iterator      set<T, Compare, Alloc>::rend()
{
    return(reverse_iterator(this->begin()));
}

template <class T, class Compare, class Alloc> 
typename set<T, Compare, Alloc>::const_reverse_iterator     set<T, Compare, Alloc>::rend() const
{
    return(const_reverse_iterator(this->begin()));
}

// template <class T, class Compare, class Alloc> 
// T &set<T, Compare, Alloc>::operator[](const key_type& k)
// {
//     value_type pair = ft::make_pair(k, setped_type());
//     // cout << pair->first << endl;
//     ft::Node< typename set<T, Compare, Alloc>::value_type> *temp;

//     temp = this->rbt.treeSearch(rbt._root, pair);

//     if (temp->_isNil == 1)
//     {
//         ft::pair<iterator,bool> ret = this->insert(pair);
//         return (ret.first->second);
//     }
//     return (temp->_data->second);
// }

template <class T, class Compare, class Alloc> 
set<T, Compare, Alloc> &set<T, Compare, Alloc>::operator=(const set& x)
{
    // copy assignment operator
    // this->rbt.deleteAll();
    // this->_alloc = this->get_allocator();
    // this->_compare = key_comp();
    // this->_size = x._size;
    this->rbt = x.rbt;
    return(*this);
}

template <class T, class Compare, class Alloc> 
void	set<T, Compare, Alloc>::check_max_size(size_t n)
{
    if (n > this->max_size())
        throw std::length_error("Length error bro");
    
}

namespace ft
{
    template <class T, class Compare, class Alloc>  
    void swap (set<T,Compare,Alloc>& x, set<T,Compare,Alloc>& y)
    {
        x.swap(y);
    }

    template <class T, class Compare, class Alloc> 
    bool operator==(const set<T, Compare, Alloc> &lhs, const set<T, Compare, Alloc> &rhs)
    {
        return((lhs.rbt._size == rhs.rbt._size) && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
    }

    template <class T, class Compare, class Alloc> 
    bool operator!=(const set<T, Compare, Alloc> &lhs, const set<T, Compare, Alloc> &rhs)
    {
        return(!(lhs == rhs));
    }

    template <class T, class Compare, class Alloc> 
    bool operator<(const set<T, Compare, Alloc> &lhs, const set<T, Compare, Alloc> &rhs)
    {
        return ((lhs.rbt._size < rhs.rbt._size) && ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    }

    template <class T, class Compare, class Alloc> 
    bool operator<=(const set<T, Compare, Alloc> &lhs, const set<T, Compare, Alloc> &rhs)
    {
        return (!(rhs < lhs));
    }

    template <class T, class Compare, class Alloc> 
    bool operator>(const set<T, Compare, Alloc> &lhs, const set<T, Compare, Alloc> &rhs)
    {
        return ((lhs.rbt._size > rhs.rbt._size) && ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
    }
        
    template <class T, class Compare, class Alloc> 
    bool operator>=(const set<T, Compare, Alloc> &lhs, const set<T, Compare, Alloc> &rhs)
    {
        return (!(rhs > lhs));
    }
}
#endif