#pragma once
#include<iostream>

namespace BinaryTreeIterativeTraversal {

	template<typename T>
	struct Node {

		T _info;
		Node<T> *_father, *_left, *_right;
		Node(const T& info = T()) : _info(info), _father(0), _left(0), _right(0) { }



	};

	template<typename T>
	void PreorderIterative_NLR(Node<T> *tree) {
		if (tree == 0) return;
		Node<T> *vertex = tree, *father;
		while (1) {
			std::cout << vertex->_info << "  ";
			if (vertex->_left) { vertex = vertex->_left; continue; }
			if (vertex->_right) { vertex = vertex->_right; continue; }

			for (father = vertex->_father; father != 0; vertex = father, father = vertex->_father)

				if (father->_left == vertex && father->_right != 0) break;

			if (father == 0) return;
			vertex = father->_right;
		}

	}

	template<typename T>
	void InorderIterative_LNR(Node<T> *tree) {
		if (tree == 0) return;
		Node<T> *vertex = tree, *father;

		while (1) {
			if (vertex->_left) { vertex = vertex->_left; continue; }
			std::cout << vertex->_info << "  ";
			if (vertex->_right) { vertex = vertex->_right; continue; }

			for (father = vertex->_father; father != 0; vertex = father, father = vertex->_father)


				if (father->_left == vertex) {

						std::cout << father->_info << "  ";
					if (father->_right) break;
				}

			if (father == 0) return;

			vertex = father->_right;

		}
	}

	/*
		template<typename Elem>
		void PostorderIterative_LRN(ExtendenNode<Elem> *tree) {
			if (tree == 0) return;
			ExtendenNode<Elem> *vertex = tree, *father;
			while (1) {
				if (vertex->_left) { vertex = vertex->_left; contiune; }
				if (vertex->_right) { vertex = vertex->_right; contiune; }
				std::cout << vertex->_info << "  ";

				for (father = vertex->_father; father != 0; vertex = father, father = vertex->_father)

					if (father->_left == vertex) {



					}


			}



		}
		*/




}