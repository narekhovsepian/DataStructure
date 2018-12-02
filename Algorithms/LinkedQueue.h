#pragma once
#include<iostream>

namespace adtLQ
{
	template<typename T>
	class LinkedQueue
	{
		/*template<typename T>
		friend std::ostream& operator<<(std::ostream& c,
			const LinkedQueue<T>& q)
	*/

		template<typename T>
		struct Node
		{
			T _info;
			Node<T> *_link;
			Node(const T &info = T()) :_info(info), _link(0) {}
		};
		int _size;
		Node<T> *head;
		Node<T> *rear;
	public:
		LinkedQueue();
		LinkedQueue(const LinkedQueue<T>&);
		~LinkedQueue();
		void enqueue_push(const T&);
		inline int size() const { return _size; }
		void dequeue_pop();
		inline	T &Front()const { return rear->_info; }
		inline T &Back() const { return head->_info; }
		bool isEmpty() const { return head->_link == 0; }
		void print();

	};

	template<typename T>
	LinkedQueue<T>::LinkedQueue() :_size(0)
	{
		head = new Node<T>();
		rear = head;
	}

	template<typename T>
	LinkedQueue<T>::LinkedQueue(const LinkedQueue<T> &other) :
		_size(other._size)
	{
		head = new Node<T>();
		rear = head;
		Node<T> *temp = other.head;
		while (temp->_link != 0)
		{
			enqueue_push(temp->info);
			temp = temp->_link;
		}

	}

	template<typename T>
	LinkedQueue<T>::~LinkedQueue()
	{
		while (head->_link != 0)
		{
			dequeue_pop();
		}
		delete head;
		head = nullptr;
		_size = 0;
	}



	template<typename T>
	void LinkedQueue<T>::enqueue_push(const T& item)
	{
		Node<T> * p = new Node<T>(item);
		rear->_link = p;
		rear = p;
		++_size;
	}

	template<typename T>
	void LinkedQueue<T>::dequeue_pop()
	{
		Node<T> *temp = head->_link;
		head->_link = temp->_link;
		if (rear == temp)
			rear = head;
		delete temp;
		--_size;
	}



	template<typename T>
	void LinkedQueue<T>::print()
	{
		Node<T> *temp = head->_link;
		while (temp != 0)
		{
			std::cout << temp->_info << "  ";
			temp = temp->_link;
		}

	}






}