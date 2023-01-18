#ifndef RBT_TPP
# define RBT_TPP

using namespace ft;


/*-------------Red Black Tree---------------*/
/* My default constructor */
template <class T, class Alloc> 
RBT<T, Alloc>::RBT(const val_alloc& alloc) : _alloc(alloc)
{
    cout << GRN << "RBT constructor called" << RESET << endl;

    // this->root = this->_node_alloc.allocate(0);
    this->root = NULL;
}

template <class T, class Alloc> 
RBT<T, Alloc>::~RBT()
{
    cout << RED << "RBT destructor called" << RESET << endl;
}

template <class T, class Alloc>
void RBT<T, Alloc>::testmymom()
{
    cout << "Testing mom" << endl;
}


template <class T, class Alloc>
Node<T> *RBT<T, Alloc>::if_grandparent(Node<T> *n)
{
    if (n != nullptr && n->parent != nullptr) 
        return (n->parent->parent);
    else 
        return (nullptr);
}

template <class T, class Alloc>
Node<T>* RBT<T, Alloc>::if_sibling(Node<T> *n)
{
    if (n == n->parent->left)
        return (n->parent->right);
    else
        return (n->parent->left);
}

template <class T, class Alloc>
void    RBT<T, Alloc>::insert(value_type value)
{
    Node<T> *newnode = this->_node_alloc.allocate(1);
    Node<T> *iter;
    Node<T> *iter2;
    newnode->_data = value;
 
    iter = root;
    iter2 = NULL;

    if (this->root == NULL)
    {
           root = newnode;
           this->root->_parent = NULL;
    }
    else
    {
        while(iter != NULL)
        {
            iter2 = iter;
            if(iter->_data < newnode->_data)
                iter = iter->_right;
            else
                iter = iter->_left;
        }
        newnode->_parent = iter2;
        if(iter2->_data < newnode->_data)
            iter2->_right = newnode;
        else
            iter2->_left = newnode;
        cout << "wee" << endl;
    }

}

#endif