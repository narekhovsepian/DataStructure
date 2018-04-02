#pragma once

namespace BinaryTreeIteractive {

	template<typename Elem>
	struct Node {
	public:
		Elem info_;
		Node<Elem> *father_, *left_, right_;

		Node(const Elem info = Elem()) :
			info_(info), father_(0), left_(0), right_(0) { }

	};
/*
	template<typename Elem>
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
	}*/



}
