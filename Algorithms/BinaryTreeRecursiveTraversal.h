#pragma once
#include<iostream>

namespace BinaryTreeRecursiveTraversal {

	template<typename Elem>
	struct Node {
	public:
		Elem m_info;
		Node<Elem> *m_left, *m_right;
		Node(const Elem& info = Elem()) :
			m_info(info), m_left(0), m_right(0) { }

	};



	template<typename Elem>
	void PreorderRecursive_NLR(Node<Elem> *tree) {
		if (tree == 0) return;
		std::cout << tree->m_info << "  ";
		PreorderRecursive_NLR(tree->m_left);
		PreorderRecursive_NLR(tree->m_right);

	}


	template<typename Elem>
	void InorderRecursive_LNR(Node<Elem> *tree) {
		if (tree == 0) return;
		InorderRecursive_LNR(tree->m_left);
		std::cout << tree->m_info << "  ";
		InorderRecursive_LNR(tree->m_right);
	}

	template<typename Elem>
	void PostorderRecursive_LRN(Node<Elem> *tree) {
		if (tree == 0) return;
		PostorderRecursive_LRN(tree->m_left);
		PostorderRecursive_LRN(tree->m_right);
		std::cout << tree->m_info << "  ";
	}



	/*template<typename Elem>
	void PreorderIterative_NLR(Node<Elem> *tree) {
		if (tree == 0) return;
		Node<Elem> *vertex = tree;
		Node<Elem>	*parent;
		while (1) {
			std::cout << vertex->m_info << "  ";
			if (vertex->m_left) { vertex = vertex->m_left; continue; }
			if (vertex->m_right) { vertex = vertex->m_right; continue; }

			for (parent = vertex->m_father; parent != 0; vertex = parent, parent->m_father)
				if (parent->m_left == vertex && parent->m_right != 0) break;

			if (parent == 0) return;
			vertex = parent->m_right;
		}
	}
	*/



}