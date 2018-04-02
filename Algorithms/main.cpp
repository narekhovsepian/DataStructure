#include <iostream>
//#include"BinaryTreeSearch.h"
#include "Stack.h"

int main() {

	adt::Stack<int> b;
	adt::Stack<char> c;

	for (int i = 0; i < 10; ++i)
	{
		b.push(i);
	}


	while (!b.isEmpty())
	{
		std::cout << b.top();
		b.pop();
	}

	std::cout << "\n\n\n\n";


	std::cout << b.size() << "   " << c.size();


	/*
		bts::BinaryTreeSearch<int> a;
		a.insert(50);
		a.insert(20);
		a.insert(10);
		a.insert(40);
		a.insert(30);
		a.insert(15);
		a.insert(70);
		a.insert(80);
		a.insert(60);
		a.insert(80);
		a.insert(75);
		a.insert(8);
		a.print();
		std::cout << "\n\n\n\n ";
		std::cout << a.max_value();
		std::cout << "\n\n\n\n ";
		std::cout << a.min_value();

			a.remove(60);
			std::cout << "\n\n\n";

			std::cout << "\n\n\n";
			a.search(70);
			//std::cout << a;


			//a.print();
	*/
	system("pause");

	return 0;
}

