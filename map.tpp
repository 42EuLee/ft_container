#ifndef MAP_TPP
# define MAP_TPP


using namespace ft;

/* My default constructor */
template < class Key, class T, class Compare, class Alloc> 
map<Key, T, Compare, Alloc>::map(const key_compare &comp, const allocator_type& alloc) : _alloc(alloc) , _compare(comp), rbt(alloc, _compare)
{
    // cout << GRN << "map default constructor called" << RESET << endl;
}

template < class Key, class T, class Compare, class Alloc> 
template <class InputIterator>
map<Key, T, Compare, Alloc>::map(InputIterator first, InputIterator last, const key_compare &comp, const allocator_type& alloc) : _alloc(alloc) , _compare(comp), rbt(alloc, comp)
{
    // cout << GRN << "map range constructor called" <<  RESET << endl;

    while (first != last)
        this->insert(*first++);
}

template < class Key, class T, class Compare, class Alloc> 
map<Key, T, Compare, Alloc>::map (const map& x) : rbt(x._alloc, x._compare)
{
    // cout << GRN << "map copy constructor called" <<  RESET << endl;
    this->rbt = x.rbt;
    // cout << " testing " << endl;
}


/* map destructor */
template < class Key, class T, class Compare, class Alloc> 
map<Key, T, Compare, Alloc>::~map()
{
    // cout << RED << "map destructor called" << RESET << endl;
}

template < class Key, class T, class Compare, class Alloc> 
typename map<Key, T, Compare, Alloc>::iterator      map<Key, T, Compare, Alloc>::begin()
{
    typename map<Key, T, Compare, Alloc>::iterator it(this->rbt._sentinel->_left);
    return(it);
}

template < class Key, class T, class Compare, class Alloc> 
typename map<Key, T, Compare, Alloc>::const_iterator    map<Key, T, Compare, Alloc>::begin() const
{
    typename map<Key, T, Compare, Alloc>::const_iterator it(this->rbt._sentinel->_left);
    return(it);
}

template < class Key, class T, class Compare, class Alloc> 
typename map<Key, T, Compare, Alloc>::mapped_type &map<Key, T, Compare, Alloc>::at (const key_type& k)
{
    ft::Node< typename map<Key, T, Compare, Alloc>::value_type> *temp;
    
    temp = this->rbt.treeSearch(this->rbt._root, ft::make_pair(k, T()));
    if (temp->_isNil == 1)
        throw std::out_of_range(" Out of range bitch");
    return (temp->_data->second);  
}

template < class Key, class T, class Compare, class Alloc> 
const typename map<Key, T, Compare, Alloc>::mapped_type &map<Key, T, Compare, Alloc>::at (const key_type& k) const
{
    ft::Node< typename map<Key, T, Compare, Alloc>::value_type> *temp;

    temp = this->rbt.treeSearch(this->rbt._root, ft::make_pair(k, T()));
    if (temp->_isNil == 1)
        throw std::out_of_range(" Out of range bitch");
    return (temp->_data->second);  
}


template < class Key, class T, class Compare, class Alloc> 
void    map<Key, T, Compare, Alloc>::clear()
{   
    this->rbt.deleteAll();
}

template < class Key, class T, class Compare, class Alloc> 
size_t     map<Key, T, Compare, Alloc>::count(const key_type& k) const
{
    ft::Node< typename map<Key, T, Compare, Alloc>::value_type> *temp;

    temp = this->rbt.treeSearch(this->rbt._root, ft::make_pair(k,T()));
    return (temp->_isNil == 0); 
}

template < class Key, class T, class Compare, class Alloc>
bool       map<Key, T, Compare, Alloc>::empty() const
{
    return (this->rbt._size < 1);
}

template < class Key, class T, class Compare, class Alloc> 
typename map<Key, T, Compare, Alloc>::iterator     map<Key, T, Compare, Alloc>::end()
{
    typename map<Key, T, Compare, Alloc>::iterator it(this->rbt._sentinel);
    return(it);
}

template < class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::const_iterator    map<Key, T, Compare, Alloc>::end() const
{
    typename map<Key, T, Compare, Alloc>::const_iterator it(this->rbt.treeMaximum(this->rbt._root));
    it++;
    return(it);
}

template < class Key, class T, class Compare, class Alloc> 
ft::pair<typename map<Key, T, Compare, Alloc>::const_iterator, typename map<Key, T, Compare, Alloc>::const_iterator> map<Key, T, Compare, Alloc>::equal_range(const key_type& k) const
{
    return(ft::make_pair(this->lower_bound(k), this->upper_bound(k)));
}

template < class Key, class T, class Compare, class Alloc>
ft::pair<typename map<Key, T, Compare, Alloc>::iterator, typename map<Key, T, Compare, Alloc>::iterator> map<Key, T, Compare, Alloc>::equal_range(const key_type& k)
{
    return(ft::make_pair(this->lower_bound(k), this->upper_bound(k)));
}

template < class Key, class T, class Compare, class Alloc>
void    map<Key, T, Compare, Alloc>::erase(iterator position)
{
    this->erase(position->first);
}

template < class Key, class T, class Compare, class Alloc>
size_t   map<Key, T, Compare, Alloc>::erase (const key_type& k)
{
    return (this->rbt.deletion(ft::make_pair(k, T())));
}
template < class Key, class T, class Compare, class Alloc>
void    map<Key, T, Compare, Alloc>::erase(iterator first, iterator last)
{
    while (first != last)
        this->erase(first++);
}


template < class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::iterator      map<Key, T, Compare, Alloc>::find(const key_type& k)
{
    for (iterator it = this->begin() ; it != this->end() ; it++)
    {
        if (it->first == k)
            return (it);
    }
    return (this->end());
}

template < class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::const_iterator      map<Key, T, Compare, Alloc>::find(const key_type& k) const
{
    for (const_iterator it = this->begin() ; it != this->end() ; it++)
    {
        if (it->first == k)
            return (it);
    }
    return (this->end());
}

template < class Key, class T, class Compare, class Alloc>
size_t  map<Key, T, Compare, Alloc>::size() const
{
    return (this->rbt._size);
}

template < class Key, class T, class Compare, class Alloc> 
void map<Key, T, Compare, Alloc>::swap(map& x)
{
    std::swap(this->_alloc, x._alloc);
    std::swap(this->_compare, x._compare);
    this->rbt.swap(x.rbt);
}

template < class Key, class T, class Compare, class Alloc>
Compare map<Key, T, Compare, Alloc>::key_comp() const
{
    return(this->_compare);
}

template < class Key, class T, class Compare, class Alloc> 
typename map<Key, T, Compare, Alloc>::const_iterator  map<Key, T, Compare, Alloc>::lower_bound(const key_type& k) const
{
    for (const_iterator it = this->begin() ; it != this->end() ; it++)
    {
        if (it->first >= k)
            return (it);
    }
    return (this->end());
}


template < class Key, class T, class Compare, class Alloc> 
typename map<Key, T, Compare, Alloc>::iterator  map<Key, T, Compare, Alloc>::lower_bound(const key_type& k)
{
    for (iterator it = this->begin() ; it != this->end() ; it++)
    {
        if (it->first >= k)
            return (it);
    }
    return (this->end());
}

template < class Key, class T, class Compare, class Alloc> 
size_t map<Key, T, Compare, Alloc>::max_size() const
{
    return ((std::numeric_limits<std::size_t>::max() / sizeof(typename map<Key, T, Compare, Alloc>::value_type)) / 2);
}

template < class Key, class T, class Compare, class Alloc> 
typename map<Key, T, Compare, Alloc>::iterator  map<Key, T, Compare, Alloc>::upper_bound(const key_type& k)
{
    for (iterator it = this->begin() ; it != this->end() ; it++)
    {
        if (it->first > k)
            return (it);
    }
    return (this->end());
}

template < class Key, class T, class Compare, class Alloc> 
typename map<Key, T, Compare, Alloc>::const_iterator  map<Key, T, Compare, Alloc>::upper_bound(const key_type& k) const
{
    for (const_iterator it = this->begin() ; it != this->end() ; it++)
    {
        if (it->first > k)
            return (it);
    }
    return (this->end());
}

template < class Key, class T, class Compare, class Alloc> 
typename map<Key, T, Compare, Alloc>::value_compare     map<Key, T, Compare, Alloc>::value_comp() const
{
    return(this->rbt._comp);
}

template < class Key, class T, class Compare, class Alloc> 
ft::pair<typename map<Key, T, Compare, Alloc>::iterator,bool>   map<Key, T, Compare, Alloc>::insert(const value_type& val)
{
    ft::Node< typename map<Key, T, Compare, Alloc>::value_type> *temp;
    typename ft::map<Key, T, Compare, Alloc>::iterator it;
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

template < class Key, class T, class Compare, class Alloc> 
typename map<Key, T, Compare, Alloc>::iterator  map<Key, T, Compare, Alloc>::insert(iterator position, const value_type& val)
{
    ft::Node< typename map<Key, T, Compare, Alloc>::value_type> *temp;
    typename ft::map<Key, T, Compare, Alloc>::iterator it;
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

template < class Key, class T, class Compare, class Alloc> 
template <class InputIterator>
void map<Key, T, Compare, Alloc>::insert(InputIterator first, InputIterator last)
{
    while (first != last)
        this->insert(*first++);
}


template < class Key, class T, class Compare, class Alloc> 
typename map<Key, T, Compare, Alloc>::allocator_type       map<Key, T, Compare, Alloc>::get_allocator() const
{
    return(this->_alloc);
}

template < class Key, class T, class Compare, class Alloc> 
typename map<Key, T, Compare, Alloc>::reverse_iterator map<Key, T, Compare, Alloc>::rbegin()
{
    typename map<Key, T, Compare, Alloc>::reverse_iterator rit(this->rbt._sentinel);
    return (rit);
}

template < class Key, class T, class Compare, class Alloc> 
typename map<Key, T, Compare, Alloc>::const_reverse_iterator map<Key, T, Compare, Alloc>::rbegin() const
{
    return(reverse_iterator(this->end()));

}


template < class Key, class T, class Compare, class Alloc> 
typename map<Key, T, Compare, Alloc>::reverse_iterator      map<Key, T, Compare, Alloc>::rend()
{
    return(reverse_iterator(this->begin()));
}

template < class Key, class T, class Compare, class Alloc> 
typename map<Key, T, Compare, Alloc>::const_reverse_iterator     map<Key, T, Compare, Alloc>::rend() const
{
    return(const_reverse_iterator(this->begin()));
}

template < class Key, class T, class Compare, class Alloc> 
T &map<Key, T, Compare, Alloc>::operator[](const key_type& k)
{
    value_type pair = ft::make_pair(k, mapped_type());
    ft::Node< typename map<Key, T, Compare, Alloc>::value_type> *temp;

    temp = this->rbt.treeSearch(rbt._root, pair);

    if (temp->_isNil == 1)
    {
        ft::pair<iterator,bool> ret = this->insert(pair);
        return (ret.first->second);
    }
    return (temp->_data->second);
}

template < class Key, class T, class Compare, class Alloc> 
map<Key, T, Compare, Alloc> &map<Key, T, Compare, Alloc>::operator=(const map& x)
{
    this->rbt = x.rbt;
    return(*this);
}

namespace ft
{
    template <class Key, class T, class Compare, class Alloc>  
    void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y)
    {
        x.swap(y);
    }

    template < class Key, class T, class Compare, class Alloc> 
    bool operator==(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
    {
        return((rhs.rbt._size == lhs.rbt._size) && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
    }

    template < class Key, class T, class Compare, class Alloc> 

    bool operator!=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
    {
        return(!(lhs == rhs));
    }

    template < class Key, class T, class Compare, class Alloc> 

    bool operator<(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
    {
        return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    }
    template < class Key, class T, class Compare, class Alloc> 

    bool operator<=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
    {
        return (!(rhs < lhs));
    }

    template < class Key, class T, class Compare, class Alloc> 

    bool operator>(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
    {
        return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
    }
        
    template < class Key, class T, class Compare, class Alloc> 

    bool operator>=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
    {
        return (!(rhs > lhs));
    }
}

#endif