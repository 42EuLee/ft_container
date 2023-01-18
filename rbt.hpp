#ifndef RBT_HPP
# define RBT_HPP

#include <iostream>
#include <map>
#include <memory>

using std::cout;
using std::endl;

namespace ft
{

	template <class T>
	struct Node
	{
		T       _data;
		char 	_color;
		Node    *_left;
		Node    *_right; 
		Node    *_parent;

		Node()
		{
			cout << "Node constructor called" << endl;
		}
		// Node(T *data, char color, Node *left, Node *right, Node *parent) :
		// 	_data(data),
		// 	_color(color),
		// 	_left(left),
		// 	_right(right),
		// 	_parent(parent)
		// {
		// 	cout << "Node constructor called" << endl;
		// }
	};

	template <class T, class Alloc = std::allocator<T> >
	class RBT
	{
		public:
			typedef T													value_type;
			typedef Alloc												val_alloc;
			typedef typename Alloc::template rebind<Node<T> >::other	node_alloc;
		
			RBT(const val_alloc& alloc = val_alloc());
        	~RBT();
			void insert(value_type value);
			void testmymom();

			Node<T>		*root;
			val_alloc	_alloc;
			node_alloc	_node_alloc;

		private:

			Node<T>* if_grandparent(Node<T> *n);
			Node<T>* if_sibling(Node<T> *n);
	

	};
}

#include "rbt.tpp"

#endif