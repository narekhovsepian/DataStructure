#pragma once
#include"Exceptions.h"


namespace adt
{


	template<typename Elem>
	class Stack;

	template<typename Elem>
	struct Node
	{
		friend class Stack<Elem>;
		Elem _info{ nullptr };

		Node<Elem> *_link;
		Node() { }
		Node(const Elem &info = Elem()) :
			_info(info), _link(nullptr) { }


	};

	template<typename Elem>
	class Stack
	{
		int _count = -1;
		friend struct Node<Elem>;
		Node<Elem> *_top;
	public:
		Stack() :_top(0) { }
		~Stack();
		void  push(const Elem&);
		Elem &top() const;// { return _top->_info; }
		void pop();
		bool isEmpty()const { return _top == nullptr; }
		int size() const { return _count + 1; }

	};

	template<typename Elem>
	inline Elem &Stack<Elem>::top() const
	{
		if (isEmpty())
			throw UnderflowException();
		return _top->_info;

	}


	template<typename Elem>
	void Stack<Elem>::push(const Elem &elem)
	{
		Node<Elem> *ptr = new Node<Elem>(elem);
		ptr->_info = elem;
		ptr->_link = _top;
		_top = ptr;
		++_count;
	}

	template<typename Elem>
	void Stack<Elem>::pop()
	{
		if (isEmpty())
			throw UnderflowException();
		Node<Elem> *tmp = _top;
		_top = _top->_link;
		delete tmp;
		--_count;
		return;

	}



	template<typename Elem>
	Stack<Elem>::~Stack()
	{
		while (_top)
		{
			Node<Elem> *ptr;
			ptr = _top;
			_top = _top->_link;
			delete ptr;
		}

	}

}


