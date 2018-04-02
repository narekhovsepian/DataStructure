#pragma once
#include<iostream>


namespace bts {

	template<typename Elem>
	class BinaryTreeSearch;


	template<typename Elem>
	struct Node {
	private:
		friend class BinaryTreeSearch<Elem>;
		Elem _info{ nullptr };
		Node<Elem>  *left_child, *right_child;
		Node() {  }
		Node(const Elem &info = Elem()) :
			_info(info), left_child(nullptr), right_child(nullptr) { }

	};


	template<typename Elem>
	class BinaryTreeSearch {

	private:
		friend struct Node<Elem>;
		Node<Elem> *_root{ nullptr };
		void  remove_root(const Elem&);
		void   inorderRecursiveTraversal_LNR(Node<Elem>*);
		void  remove_value(Node<Elem>*&, const Elem&);
		void insert_value(const Elem&, Node<Elem>*);
		void left_chilf_leaf(Node<Elem>*, Node<Elem>*);
		bool searchBst(Node<Elem>*, const Elem&) const;
		void Release(Node<Elem>*);
	public:
		BinaryTreeSearch() :_root(0) { };
		BinaryTreeSearch(const BinaryTreeSearch&);
		~BinaryTreeSearch();
		BinaryTreeSearch& operator = (const BinaryTreeSearch&);
		bool empty() const { return _root == 0; }
		void search(const Elem&);
		void insert(const Elem&);
		void remove(const Elem&);
		void print();
		Elem &max_value();
		Elem &min_value();
	};

	template<typename Elem>
	void BinaryTreeSearch<Elem>::left_chilf_leaf(Node<Elem> *leaf, Node<Elem> *subtree)
	{
		while (subtree->left_child)
		{
			subtree = subtree->left_child;
		}

		subtree->left_child = leaf;
	}



	template<typename Elem>
	void BinaryTreeSearch<Elem>::remove_value(Node<Elem> *&prev, const Elem &elem) {

		if (elem < prev->_info)
		{
			if (prev->left_child)
				remove_value(prev->left_child, elem);
			else return;
		}
		else if (elem > prev->_info)
		{
			if (prev->right_child)
				remove_value(prev->right_child, elem);
			else return;
		}
		else //find
		{
			Node<Elem> *tmp = prev;

			if (prev->right_child)
			{
				prev = prev->right_child;
				left_chilf_leaf(tmp->left_child, prev);
			}
			else
				prev = prev->left_child;

			delete tmp;


		}

	}

	template<typename Elem>
	void BinaryTreeSearch<Elem>::remove(const Elem& elem)
	{
		if (elem == _root->_info)

		{
			remove_root(elem);
		}
		else
		{
			remove_value(_root, elem);
		}

	}

	template<typename Elem>
	void BinaryTreeSearch<Elem>::remove_root(const Elem& elem)
	{
		Node<Elem> *pre_root = _root;
		if (_root->right_child)
		{
			_root = _root->right_child;
			left_chilf_leaf(pre_root->left_child, _root);
		}
		else
			_root = _root->left_child;

		delete pre_root;

	}


	template<typename Elem>
	void del(const Elem &elem, Node<Elem>* tree) {

		remove_value(tree, elem);

	}



	template<typename Elem>
	BinaryTreeSearch<Elem>::~BinaryTreeSearch<Elem>() {

		Release(_root);
	}


	template<typename Elem>
	void BinaryTreeSearch<Elem>::insert_value(const Elem& elem, Node<Elem>* root)
	{
		if (elem == root->_info)
			return;
		else

			if (elem < root->_info) {


				if (root->left_child)

					insert_value(elem, root->left_child);

				else

					root->left_child = new Node<Elem>(elem);
			}
			else
			{
				if (root->right_child)

					insert_value(elem, root->right_child);
				else

					root->right_child = new Node<Elem>(elem);

			}

	}


	template<typename Elem>
	void BinaryTreeSearch<Elem>::insert(const Elem& elem)
	{
		if (!_root)

			_root = new Node<Elem>(elem);

		else

			insert_value(elem, _root);



	}




	template<typename Elem>
	void  BinaryTreeSearch<Elem>::inorderRecursiveTraversal_LNR(Node<Elem>* tree) {

		if (tree == 0) return;

		inorderRecursiveTraversal_LNR(tree->left_child);

		std::cout << tree->_info << "  ";

		inorderRecursiveTraversal_LNR(tree->right_child);

	}



	template<typename Elem>
	void BinaryTreeSearch<Elem>::print() {

		inorderRecursiveTraversal_LNR(_root);

	}


	template<typename Elem>
	bool BinaryTreeSearch<Elem>::searchBst(Node<Elem> *root, const Elem& elem) const
	{
		Node<Elem> *vertex = _root;

		if (_root == nullptr)
		{
			std::cout << "Not find" << std::endl;
			return false;
		}
		while (vertex)
		{
			if (elem == vertex->_info)
			{
				std::cout << "Find" << std::endl;
				return true;
			}
			else if (elem < vertex->_info) {

				vertex = vertex->left_child;
			}
			else
				vertex = vertex->right_child;
		}
		std::cout << "No find" << std::endl;

		return false;

	}

	template<typename Elem>
	void  BinaryTreeSearch<Elem>::search(const Elem &elem)
	{
		if (_root->_info != elem) {

			searchBst(_root, elem);
		}

	}

	template<typename Elem>
	Elem &BinaryTreeSearch<Elem>::max_value()
	{
		Elem &key = _root->_info;
		Node<Elem> *vertex = _root;
		while (vertex)
		{
			if (vertex->right_child) {

				vertex = vertex->right_child;

			}
			else if (vertex->left_child)
			{
				if (vertex->right_child) {

					vertex = vertex->right_child;
				}
				else
					vertex = vertex->left_child;
			}
			if (!vertex->right_child) break;
		}
		return vertex->_info;
	}

	template<typename Elem>
	void BinaryTreeSearch<Elem>::Release(Node<Elem> *root)
	{
		if (root != nullptr)
		{
			Release(root->left_child);
			Release(root->right_child);
			delete root;
		}

	}

	template<typename Elem>
	Elem &BinaryTreeSearch<Elem>::min_value()
	{
		Node<Elem> *vertex = _root;
		Elem &elem = vertex->_info;

		while (vertex)
		{
			if (vertex->left_child) {
				vertex = vertex->left_child;
			}
			else if (vertex->right_child)
			{
				if (vertex->left_child) {

					vertex = vertex->left_child;
				}
			}
			if (!vertex->left_child) break;
		}

		return vertex->_info;
	}







}