#pragma once
#include<iostream>


template <class Elem>
struct Node {
	Elem info;
	Node<Elem>* link;

};

template <class Elem>
class List {
private:
	Node<Elem>* first;
	int size;
public:
	List();
	List(const List&);
	~List();
	bool IsEmpty() const;
	int GetLength() const;
	Node<Elem>* GetFirst() const;
	void InsertAfter(Node<Elem>* p, Elem item);
	void InsertAt(int n, Elem item);
	void DeleteAfter(Node<Elem>* p);
	void DeleteAt(int n);
	Elem & GetData(Node<Elem>* p);
};

template<class Elem>
List<Elem>::List() :size(0), first(NULL) {};



template<class Elem>
List<Elem>::List(const List& aList) {
	Node<Elem>* p = new Node<Elem>, *pl = aList.first;
	GetData(p) = aList.GetData(pl);
	first = p; first->link = NULL;
	for (int i = 0; i < aList.GetLength() - 1; ++i) {
		pl = pl->link;
		InsertAfter(p, aList.GetData(pl));
		p = p->link;
	}
	size = aList.size;

};

template <class Elem>
List<Elem>::~List() {
	if (first) {
		while (first->link)
			DeleteAfter(first);
		delete first;
		first = 0;
	}
	size = 0;

};

template<class Elem>
bool List<Elem>::IsEmpty() const {
	return size = 0;
};


template <class Elem>
int List<Elem>::GetLength() const {
	return size;
};

template <class Elem>
Node<Elem>* List<Elem>::GetFirst() const {
	return first;
};

template <class Elem>
void List<Elem>::InsertAfter(Node<Elem>* p, Elem item) {
	Node<Elem>*  q = new Node<Elem>;
	q->info = item;
	q->link = p->link;
	p->link = q;
	++size;

};

template<class Elem>
void List<Elem>::InsertAt(int n, Elem item) {
	if (n < 0 || n>GetLength())
		throw "position is out of range";
	if (n == 0) {
		Node <Elem>* q = new Node<Elem>;
		q->info = item;
		q->link = first;
		first = q;
		++size;
		return;
	}
	Node<Elem>* p = first;
	for (int i = 0; i < n - 1; ++i)
		p = p->link;
	InsertAfter(p, item);

};

template<class Elem>
void List<Elem>::DeleteAfter(Node<Elem>* p) {
	if (IsEmpty()) {
		throw "List is empty";
	}
	if (p->link == NULL) {
		throw"No element to delete";

	}
	Node<Elem>* q = p->link;
	p->link = q->link;
	delete q;
	--size;
	return;
};

template <class Elem>
void List<Elem>::DeleteAt(int n) {
	if (n < 0 || n >= GetLength()) {
		throw "position is out of range";

	}
	if (n == 0 && GetLength != 0) {
		Node<Elem>* q = first;
		first = first->link;
		delete q;
		--size;
		return;
	}
	Node<Elem>* p = first;
	for (int i = 0; i < n - 1; ++i)
		p = p->link;
	DeleteAfter(p, item);

};

template<class Elem>
Elem& List<Elem>::GetData(Node<Elem>* p) {
	return p->info;
};




