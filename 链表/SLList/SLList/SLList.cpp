#include <iostream>
#include "SLList.h"
#include <string>

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::string;

	{
		SLList<int> list;
		list.addToTail(1);
		list.addToTail(2);
		list.deleteFromHead();
		list.deleteFromHead();
		cout << list.isEmpty() << endl;
	}

	cin.get();

}