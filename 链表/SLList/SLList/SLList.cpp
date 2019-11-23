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
		string str;
		SLList<string> sl;
		sl.addToHead("1");
		sl.addToTail("2");
		sl.addToTail("3");
		sl.deleteFromHead(str);
		cout << str << endl;
		sl.deleteFromTail(str);
		cout << str << endl;
		sl.deleteNode("2");
		cout << sl.isInList("2") << endl;
		
	}

	cin.get();

}