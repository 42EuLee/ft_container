#ifndef RBT_TPP
# define RBT_TPP

using namespace ft;


/* My default constructor */
template <class T, class Alloc> 
RBT<T, Alloc>::RBT()
{
    cout << GRN << "RBT constructor called" << RESET << endl;
}

template <class T, class Alloc> 
RBT<T, Alloc>::~RBT()
{
    cout << RED << "RBT destructor called" << RESET << endl;
}

template <class T, class Alloc>
void RBT<T, Alloc>::testmymom()
{
    ;
}

template <class T, class Alloc>
RBT<T, Alloc>::Node* RBT<T, Alloc>::if_grandparent(RBT<T, Alloc>::Node *n)
{
    if (n != nullptr && n->parent != nullptr) 
        return n->parent->parent;
    else 
        return nullptr;
}

template <class T, class Alloc>
RBT<T, Alloc>::Node* RBT<T, Alloc>::if_uncle(RBT<T, Alloc>::Node *n)
{
    Node *g = grandparent(n);
    if (g == nullptr)
        return nullptr;
    if (n->parent == g->left)
        return g->right;
    else
        return g->left;
}

template <class T, class Alloc>
RBT<T, Alloc>::Node* RBT<T, Alloc>::if_sibling(RBT<T, Alloc>::Node *n)
{
    if (n == n->parent->left)
        return n->parent->right;
    else
        return n->parent->left;
}



#endif