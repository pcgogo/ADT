#include <iostream>
#include <string>
#include "CircleList.h"


int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::string;

	{
		CircleList<int> list;
		list.addToHead(1);
		list.addToTail(2);
		list.addToTail(3);
		//list.deleteNode(2);
		cout << list.deleteFromHead() << endl;
		cout << list.deleteFromTail() << endl;
		cout << endl;
		cout << list.isEmpty() << endl;
		cin.get();
	}
	return 0;
}