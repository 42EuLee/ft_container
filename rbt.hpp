#ifndef RBT_HPP
# define RBT_HPP

#include <iostream>
#include <map>
#include <memory>
#include <algorithm>
#include "styling.h"

using std::cout;
using std::endl;

namespace ft
{
	enum	Color {RD, BLK};

	template <class T>
	struct Node
	{
		typedef T		data_type;
		typedef Node*	node_pointer;
		typedef Color	color;

		T       *_data;
		Color	_color;
		Node    *_left;
		Node    *_right; 
		Node    *_parent;
		bool	_isNil;

		Node() : _data(), _color(RD), _left(NULL), _right(NULL), _parent(NULL), _isNil(false)
		{
			// cout << GRN << "Node constructor called" << RESET << endl;
		}
	
		Node(T *data, Color color = RD, Node *left = NULL, Node *right = NULL, Node *parent = NULL) :
			_data(data),
			_color(color),
			_left(left),
			_right(right),
			_parent(parent)
		{
			// cout << GRN << "Node constructor called" << RESET << endl;
		}
	};

	template <class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
	class RBT
	{
		public:
			typedef T													value_type;
			typedef Alloc												val_alloc;
			typedef typename Alloc::template rebind<Node<T> >::other	node_alloc;
			typedef Compare												val_compare;
			typedef typename Alloc::difference_type						difference_type;
			typedef typename Alloc::size_type							size_type;

		
			RBT(const node_alloc& alloc = node_alloc(), const val_compare& compare = val_compare());
        	~RBT();
        	RBT(const RBT& x);


			void		insertion(const value_type &value);
			size_t		deletion(const value_type &value);
			void		nodeInsert(Node<T> *node);
			void		insertFixUp(Node<T> *node);
			void		nodeDelete(Node<T> *node);
			void    	deleteFixUp(Node<T> *node);
			void		deleteAll();
			void		swap(RBT &rbt);

			void		duplicateTreeHelper(Node<T> *copy);
			Node<T>		*treeMaximum(Node<T> *node) const;
			Node<T>		*treeMinimum(Node<T> *node) const;
			Node<T>		*treeSearch(Node<T> *node, const value_type &value) const;
			void    	transplant(Node<T> *a, Node<T> *b);
			void    	createRoot(const value_type &value);
			void    	leftRotate(Node<T> *node);
			void    	rightRotate(Node<T> *node);
			void		printBT(const std::string& prefix, Node<T>* node, bool isLeft);
			void 		printTree();

			RBT<T, Compare, Alloc> 			&operator=(const RBT& x);

			Node<T>		*_sentinel;
			Node<T>		*_root;
			val_alloc	_alloc;
			node_alloc	_node_alloc;
			val_compare	_comp;
			size_t		_size;

	};
}

#include "rbt.tpp"

#endif