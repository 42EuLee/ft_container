#ifndef RBT_TPP
# define RBT_TPP

using namespace ft;

/*-------------Red Black Tree---------------*/
/* My default constructor */
template <class T, class Compare, class Alloc> 
RBT<T, Compare, Alloc>::RBT(const node_alloc& alloc, const val_compare& compare) : _node_alloc(alloc) , _comp(compare)
{
    // cout << GRN << "RBT constructor called" << RESET << endl;

    this->_sentinel = this->_node_alloc.allocate(1);
    this->_node_alloc.construct(this->_sentinel, Node<T>());
    this->_sentinel->_isNil = true;
    this->_sentinel->_color = BLK;
    this->_sentinel->_right = this->_sentinel;
    this->_sentinel->_left = this->_sentinel;
    this->_root = this->_sentinel;
    this->_size = 0;
    // cout << " donezo" << endl;
}

template <class T, class Compare, class Alloc>  
RBT<T, Compare, Alloc>::~RBT()
{
    // cout << RED << "RBT destructor called" << RESET << endl;
    this->deleteAll();
}

template <class T, class Compare, class Alloc> 
RBT<T, Compare, Alloc>::RBT(const RBT& x) : _comp(Compare())
{
    // cout << GRN << "RBT copy constructor called" << RESET << endl;

    ft::Node<T> *node;
    ft::Node<T> *node2;

    createRoot(x._root->_data);
    node = this->_root;
    node2 = x._root;
    // cout << "duplicate tree" << endl;
    duplicateTreeHelper(node, node2);
}

template <class T, class Compare, class Alloc> 
void    RBT<T, Compare, Alloc>::swap(RBT &rbt)
{
    std::swap(this->_sentinel, rbt._sentinel);
    std::swap(this->_root, rbt._root);
    std::swap(this->_alloc, rbt._alloc);
    std::swap(this->_node_alloc, rbt._node_alloc);
    std::swap(this->_comp, rbt._comp);
    std::swap(this->_size, rbt._size);

}

template <class T, class Compare, class Alloc> 
void    RBT<T, Compare, Alloc>::duplicateTreeHelper(Node<T> *copy)
{
    if (copy->_isNil == 0)
    {
        insertion(*(copy->_data));
        duplicateTreeHelper(copy->_right);
        duplicateTreeHelper(copy->_left);
    }
}

template <class T, class Compare, class Alloc> 
void    RBT<T, Compare, Alloc>::createRoot(const value_type &value)
{

    ft::Node<T> *node;
    node = this->_node_alloc.allocate(1);
    node->_data = this->_alloc.allocate(1);
    this->_alloc.construct(node->_data, value);
    this->_root = node;
    this->_root->_color = BLK;
    this->_root->_isNil = false;
    this->_root->_parent = this->_sentinel;
    this->_root->_right = this->_sentinel;
    this->_root->_left = this->_sentinel;
}

template <class T, class Compare, class Alloc> 
Node<T>    *RBT<T, Compare, Alloc>::treeSearch(Node<T> *node, const value_type &value) const
{
    if (node == this->_sentinel)
        return (node);
    if (this->_comp(value, *(node->_data)))
        return (treeSearch(node->_left, value));
    else if (this->_comp(*(node->_data), value))
        return (treeSearch(node->_right, value));
    return (node);
}

template <class T, class Compare, class Alloc> 
void    RBT<T, Compare, Alloc>::rightRotate(Node<T> *node)
{
    Node<T> *temp;
    // cout << "right rotate" << endl;
    temp = node->_left;
    node->_left = temp->_right;
    if (temp->_right != this->_sentinel) // check 
        temp->_right->_parent = node;
    temp->_parent = node->_parent;
    if (node->_parent == this->_sentinel)
        this->_root = temp;
    else if (node == node->_parent->_right)
        node->_parent->_right = temp;
    else
        node->_parent->_left = temp;
    temp->_right = node;
    node->_parent = temp;
}

template <class T, class Compare, class Alloc> 
void    RBT<T, Compare, Alloc>::leftRotate(Node<T> *node)
{
    Node<T> *temp;
    // cout << "left rotate" << endl;
    temp = node->_right;
    node->_right = temp->_left;
    if (temp->_left != this->_sentinel) // check
        temp->_left->_parent = node;
    temp->_parent = node->_parent;
    if (node->_parent == this->_sentinel)
        this->_root = temp;
    else if (node == node->_parent->_left)
        node->_parent->_left = temp;
    else
        node->_parent->_right = temp;
    temp->_left = node;
    node->_parent = temp;
}

template <class T, class Compare, class Alloc> 
void    RBT<T, Compare, Alloc>::transplant(Node<T> *a, Node<T> *b)
{
    if (a->_parent == this->_sentinel)
        this->_root = b;
    else if (a == a->_parent->_left)
        a->_parent->_left = b;
    else
        a->_parent->_right = b;
    b->_parent = a->_parent;
}

template <class T, class Compare, class Alloc> 
Node<T>    *RBT<T, Compare, Alloc>::treeMaximum(Node<T> *node) const
{
    while (node != this->_sentinel && node->_right != this->_sentinel)
        node = node->_right;
    return (node);
}

template <class T, class Compare, class Alloc> 
Node<T>    *RBT<T, Compare, Alloc>::treeMinimum(Node<T> *node) const
{
    while (node->_left != this->_sentinel && node != this->_sentinel)
        node = node->_left;
    return (node);
}

template <class T, class Compare, class Alloc> 
void    RBT<T, Compare, Alloc>::deleteFixUp(Node<T> *node)
{
    Node<T> *temp;

    while (node != this->_root && node->_color == BLK)
    {
        if (node == node->_parent->_left)
        {
            temp = node->_parent->_right;
            if (temp->_color == RD)
            {
                temp->_color = BLK;
                node->_parent->_color = RD;
                leftRotate(node->_parent);
                temp = node->_parent->_right;
            }
            if (temp->_left->_color == BLK && temp->_right->_color == BLK)
            {
                temp->_color = RD;
                node = node->_parent;
            }
            else
            { 
                if (temp->_right->_color == BLK)
                {
                    temp->_left->_color = BLK;
                    temp->_color = RD;
                    rightRotate(temp);
                    temp = node->_parent->_right;
                }
                temp->_color = node->_parent->_color;
                node->_parent->_color = BLK;
                temp->_right->_color = BLK;
                leftRotate(node->_parent);
                node = this->_root;
            }
        }
        else
        {
            temp = node->_parent->_left;
            if (temp->_color == RD)
            {
                temp->_color = BLK;
                node->_parent->_color = RD;
                rightRotate(node->_parent);
                temp = node->_parent->_left;
            }
            if (temp->_right->_color == BLK && temp->_left->_color)
            {   
                temp->_color = RD;
                node = node->_parent;
            }
            else
            {
                if (temp->_left->_color == BLK)
                {
                    temp->_right->_color = BLK;
                    temp->_color = RD;
                    leftRotate(temp);
                    temp = node->_parent->_left;
                }
                temp->_color = node->_parent->_color;
                node->_parent->_color = BLK;
                temp->_left->_color = BLK;
                rightRotate(node->_parent);
                node = this->_root;
            }
        }
    }
    node->_color = BLK;
}

template <class T, class Compare, class Alloc> 
void		RBT<T, Compare, Alloc>::deleteAll()
{
    this->_size = 0;
    while (this->_root != this->_sentinel)
        nodeDelete(this->_root);
    return ;
}


template <class T, class Compare, class Alloc>
size_t		RBT<T, Compare, Alloc>::deletion(const value_type &value)
{
    ft::Node<T> *to_del;

    to_del = this->treeSearch(this->_root, value);
    if (to_del->_isNil == 1)
        return (0);
    this->_size--;
    nodeDelete(to_del);
    this->_alloc.destroy(to_del->_data);
    this->_alloc.deallocate(to_del->_data, 1);
    this->_node_alloc.deallocate(to_del, 1);
    return (1);
}

template <class T, class Compare, class Alloc> 
void    RBT<T, Compare, Alloc>::nodeDelete(Node<T> *node)
{
    Node<T> *temp;
    Node<T> *temp2;

    temp = node;
    Color temp_c = temp->_color;

    if (node->_left == this->_sentinel)
    {
        temp2 = node->_right;
        transplant(node, node->_right);
    }
    else if (node->_right == this->_sentinel)
    {
        temp2 = node->_left;
        transplant(node, node->_left);
    }
    else
    {
        temp = treeMinimum(node->_right);
        temp_c = temp->_color;
        temp2 = temp->_right;
        if (temp->_parent == node)
            temp2->_parent = temp;
        else
        {

            transplant(temp, temp->_right);
            temp->_right = node->_right;
            temp->_right->_parent = temp;
        }
        transplant(node, temp);
        temp->_left = node->_left;
        temp->_left->_parent = temp;
        temp->_color = node->_color;
        if (temp_c == BLK)
            deleteFixUp(temp2);
    }
    this->_sentinel->_right = this->treeMaximum(this->_root);
    this->_sentinel->_left = this->treeMinimum(this->_root);
}

template <class T, class Compare, class Alloc> 
void    RBT<T, Compare, Alloc>::insertFixUp(Node<T> *node)
{
    Node<T> *temp;

    while (node->_parent->_color == RD)
    {
        if (node->_parent == node->_parent->_parent->_right)
        {   
            temp = node->_parent->_parent->_left;
            // case 1
            if (temp->_color == RD)
            {
                temp->_color = BLK;
                node->_parent->_color = BLK;
                node->_parent->_parent->_color = RD;
                node = node->_parent->_parent;
            }
            else
            {
                if (node == node->_parent->_left)
                {
                    node = node->_parent;
                    rightRotate(node);
                }
                node->_parent->_color = BLK;
                // cout << (node->_parent == _sentinel) << endl;
                node->_parent->_parent->_color = RD;
                leftRotate(node->_parent->_parent);
            }
        }
        else
        {
            temp = node->_parent->_parent->_right;
            if (temp->_color == RD)
            {
                temp->_color = BLK;
                node->_parent->_color = BLK;
                node->_parent->_parent->_color = RD;
                node = node->_parent->_parent;
            }
            else 
            {
                if (node == node->_parent->_right)
                {
                    node = node->_parent;
                    leftRotate(node);
                }
                node->_parent->_color = BLK;
                node->_parent->_parent->_color = RD;
                rightRotate(node->_parent->_parent);
            }
        }
        // if (node == this->_root)
        //     break ;
    }
    this->_root->_color = BLK;
}

template <class T, class Compare, class Alloc> 
void    RBT<T, Compare, Alloc>::nodeInsert(Node<T> *node)
{
    ft::Node<T> *temp = this->_sentinel;
    ft::Node<T> *temp2 = this->_root;

    while (temp2 != this->_sentinel)
    {
        temp = temp2;
        if (this->_comp(*(node->_data), *temp->_data))
            temp2 = temp2->_left;
        else
            temp2 = temp2->_right;
    }

    node->_parent = temp;
    if (temp == this->_sentinel)
        this->_root = node;
    else if (this->_comp(*(node->_data), *temp->_data))
        temp->_left = node;
    else
        temp->_right = node;

    node->_left = this->_sentinel;
    node->_right = this->_sentinel;
    node->_color = RD;

    if (node->_parent == this->_sentinel)
    {
        node->_color = BLK;
        return;
    }

    if (node->_parent->_parent == this->_sentinel)
        return;

    insertFixUp(node);
}

template <class T, class Compare, class Alloc> 
void    RBT<T, Compare, Alloc>::insertion(const value_type &value)
{
    ft::Node<T> *node;
    ft::Node<T> *to_insert;

    // cout << RED <<" INSERTION " <<  RESET << endl;
    to_insert = this->treeSearch(this->_root, value);
    // cout << " Search " << endl;
    if (to_insert->_isNil == 1)
    {
        this->_size++;
        node = this->_node_alloc.allocate(1);
        this->_node_alloc.construct(node, Node<T>());
        node->_isNil = false;
        node->_data = this->_alloc.allocate(1);
        // cout << " here " << endl;
        // cout << node->_data << endl;
        // cout << "value gg :  "<< value << endl;

        this->_alloc.construct(node->_data, value);
        // cout << " construct donezo " << endl;
        if (this->_sentinel->_left == this->_sentinel || this->_comp(value, *(this->_sentinel->_left->_data))) {
            this->_sentinel->_left = node;
        }
        if (this->_sentinel->_right == this->_sentinel || this->_comp(*(this->_sentinel->_right->_data), value)) {
            this->_sentinel->_right = node;
        }
        nodeInsert(node);
        return ; 
    }
    return ;
    // cout << " INSERTION DONEZO" << endl;
}

template <class T, class Compare, class Alloc>
void RBT<T, Compare, Alloc>::printBT(const std::string& prefix, Node<T>* node, bool isRight)
{
    // cout << "printBT" << endl;
    if (node != this->_sentinel)
    {
        std::cout << prefix;
        std::cout << (isRight ? "├──" : "└──");
        // std::cout << (node->_color ? WHT : RED);
        std::cout << *(node->_data) << endl;
        // cout << RESET;
        // enter the next tree level - left and right branch
        printBT(prefix + (isRight ? "│   " : "    "), node->_right, true);
        printBT(prefix + (isRight ? "│   " : "    "), node->_left, false);
    }
}

template <class T, class Compare, class Alloc>
RBT<T, Compare, Alloc>      &RBT<T, Compare, Alloc>::operator=(const RBT& x)
{
    // copy assignment operator
    // cout << "RBT copy assignment operator=" << endl;
    this->deleteAll();
    this->duplicateTreeHelper(x._root);

    return(*this);
}

template <class T, class Compare, class Alloc>
void RBT<T, Compare, Alloc>::printTree()
{
    printBT("" ,this->_root, false);
}

#endif
