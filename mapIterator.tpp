#ifndef MAPITERATOR_TPP
# define MAPITERATOR_TPP

using namespace ft;

namespace ft
{
    template <class T>
    mapIterator<T>::mapIterator()
    {
        // cout << "mapIterator constructor called" << endl;
    }

    template <class T>
    mapIterator<T>::mapIterator(node_ptr *node)
    {
        // cout << GRN << "mapiterator constructor called" << RESET << endl;
        this->_node = node;
        this->_base = this->_node->_data;
    }

    template<class T>
    mapIterator<T>::mapIterator(mapIterator<typename ft::remove_const<value_type>::type> const &ref)
    {
        // mapIterator copy constructor called 
        this->_node = ref._node;
        this->_base = this->_node->_data;
    }

    template <class T>
    mapIterator<T>::~mapIterator()
    {
        // cout << RED << "mapIterator destructor called" << RESET << endl;
    }

    template <class T>
    typename mapIterator<T>::reference mapIterator<T>::operator*() const
    {

        // return (*this->_base);
        return (*this->_node->_data);

    }

    template <class T>
    typename mapIterator<T>::pointer mapIterator<T>::operator->() const
    {

        // return (this->_base);
        return (this->_node->_data);
    }

    template <class T>
    mapIterator<T> mapIterator<T>::operator-(int n) const
    {
        mapIterator<T> temp(this->_node);
        // cout << " - " << endl;

        // cout << n << endl;
        for (int i = 0; i < n ; i++)
            temp--;
        // cout << "WHAT\n";
        return (temp);

    }

    template <class T>
    mapIterator<T> mapIterator<T>::operator+(int n) const
    {
        mapIterator<T> temp(this->_node);
    
        for (int i = 0; i < n ; i++)
            temp++;
        return (temp);
    }

    template <class T>
    mapIterator<T>& mapIterator<T>::operator++()
    {
        // cout << "postincrement op" << endl;
        if (this->_node->_isNil == true)
            this->_node = this->_node->_left;
        else if (this->_node->_right->_isNil != true)
        {
            this->_node = this->_node->_right;
            while (this->_node->_left->_isNil != true)
                this->_node = this->_node->_left;
        }
        else
        {
            node_ptr *p = this->_node->_parent;

            while (p->_isNil != true && this->_node == p->_right)
            {
                this->_node = p;
                p = p->_parent;
            }
            this->_node = p;
        }
        this->_base = this->_node->_data;
        return (*this);
    }

    template <class T>
    mapIterator<T> mapIterator<T>::operator++(int)
    {
        // cout << "preincrement op" << endl;
        mapIterator  tmp = *this;

        ++(*this);
        return (tmp); 
    }

    template <class T>
    mapIterator<T>& mapIterator<T>::operator--()
    {
        if (this->_node->_isNil == true)
            this->_node = this->_node->_right;
        else if (this->_node->_left->_isNil != true)
        {
            this->_node = this->_node->_left;
            while (this->_node->_right->_isNil != true)
                this->_node = this->_node->_right;
        }
        else
        {
            node_ptr *p = this->_node->_parent;

            while (p->_isNil != true && this->_node == p->_left)
            {
                this->_node = p;
                p = p->_parent;
            }
            this->_node = p;
        }
        this->_base = this->_node->_data;
        return (*this);
    }

    template <class T>
    mapIterator<T> mapIterator<T>::operator--(int)
    {
        mapIterator  tmp(this->_node);
        --(*this);
        return (tmp);
    }

    template <typename T, typename U>
    bool operator<(const mapIterator<T> &lhs, const mapIterator<U> &rhs)
    {
        return (lhs._node < rhs._node);
    }

    template <typename T, typename U>
    bool operator==(const mapIterator<T> &lhs, const mapIterator<U> &rhs)
    {
        return (lhs._node == rhs._node);
    }

    template <typename T, typename U>
    bool operator!=(const mapIterator<T> &lhs, const mapIterator<U> &rhs)
    {
    return (lhs._node != rhs._node);
    }

    template <typename T, typename U>
    bool operator<=(const mapIterator<T> &lhs, const mapIterator<U> &rhs)
    {
        return (lhs._node <= rhs._node);
    }

    template <typename T, typename U>
    bool operator>(const mapIterator<T> &lhs, const mapIterator<U> &rhs)
    {
        return (lhs._node > rhs._node);
    }

    template <typename T, typename U>
    bool operator>=(const mapIterator<T> &lhs, const mapIterator<U> &rhs)
    {
        return (lhs._node >= rhs._node);
    }


    template <class T>
    mapIterator<T> &mapIterator<T>::operator=(mapIterator<typename ft::remove_const<T>::type> const &ref)
    {
        // cout << "Copy assignment operator called" << endl;
        this->_node = ref._node;
        this->_base = this->_node->_data;
        return (*this);
    }

}

#endif