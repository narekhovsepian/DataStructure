#pragma once

#include<iostream>


namespace Binary_Tree {

	template<class T> class Binary_Tree;

	template<class T> class Tree_Node {
	private:
		Tree_Node<T> *left, *right;

	public:
		T info;
		Tree_Node(const T &item, Tree_Node<T> *l = 0, Tree_Node<T> *r = 0)
			:info(item), left(l), right(r) {}

		Tree_Node<T> *Left(void) const { return left; }
		Tree_Node<T> *right(void) const { return right; }

		friend class Binary_Tree<T>;


		Tree_Node<T> *GetTreeNode(T item, Tree_Node<T> *lptr = 0, Tree_Node<T>
			*rptr = 0);

		void FreeTreeNode(Tree_Node<T> *p);


	};

	template<class T>
	Tree_Node<T>  *Tree_Node<T>::GetTreeNode(T item, Tree_Node<T> *lptr = 0, Tree_Node<T> rptr = 0)
	{
		Tree_Node<T> *p;
		p = new Tree_Node<T>(item, lptr, rptr);
		if (p == NULL) {
			std::cerr << "Memory error";
			exit(1);

		}

		return p;
	}

	template<class T>
	inline Tree_Node<T>* Tree_Node<T>::GetTreeNode(T item, Tree_Node<T>* lptr, Tree_Node<T>* rptr)
	{
		return NULL;
	}

	template<class T>
	void Tree_Node::FreeTreeNode(Tree_Node<T> *p) {
		delete p;
	}







}
