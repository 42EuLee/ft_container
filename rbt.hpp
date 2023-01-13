#ifndef RBT_HPP
# define RBT_HPP

#include <iostream>
#include <map>
#include <memory>

using std::cout;
using std::endl;

namespace ft
{
	enum Color {RD, BLK};

	template <class T, class Alloc = std::allocator<T> >
	class RBT
	{
		private:
			struct Node
			{
				// K key;
				// V value;
				T       *data;
				Color   color;
				Node    *left;
				Node    *right; 
				Node    *parent;

				Node(T *data, Color color, Node *left, Node *right, Node *parent) :
					data(data),
					color(color),
					left(left),
					right(right),
					parent(parent)
				{}
			};

		public:

            RBT();
            ~RBT();
			typedef Alloc                       					val_alloc;
			typedef typename Alloc::template rebind<Node>::other	node_alloc;


			Node *root;

			void testmymom();
			Node* if_grandparent(Node *n);
			Node* if_uncle(Node *n);
			Node* if_sibling(Node *n);
		

			void rotateLeft(Node *n)
			{
				Node *nnew = n->right;

				n->right = nnew->left;
				nnew->left = n;
				nnew->parent = n->parent;
				n->parent = nnew;
			}

			void rotateRight(Node *n)
			{
				Node *nnew = n->left;

				n->left = nnew->right;
				nnew->right = n;
				nnew->parent = n->parent;
				n->parent = nnew;
			}

			void insertCase1(Node *n)
			{
				if (n->parent == nullptr)
					n->color = BLK;
				else
					insertCase2(n);
			}

			void insertCase2(Node *n)
			{
				if (n->parent->color == BLK)
					return;
				else
					insertCase3(n);
			}

			void insertCase3(Node *n){
				Node *u = uncle(n), *g;

				if ((u != nullptr) && (u->color == RD)) {
					n->parent->color = BLK;
					u->color = BLK;
					g = grandparent(n);
					g->color = RD;
					insertCase1(g);
				} else {
					insertCase4(n);
				}
			}

	};
}

#include "rbt.tpp"

#endif