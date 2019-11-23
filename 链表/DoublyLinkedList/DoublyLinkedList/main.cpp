#include <iostream>
#include "DoublyLinkedList.h"

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	{
		int temp;
		DoublyLinkedList<int> dl;
		for (int i = 0; i < 5; i++)
			dl.addToTail(i);
		for (int i = 0; i < 5; i++)
		{
			dl.deleteFromTail(temp);
			cout << temp << "\t";
		}
	}

	cin.get();
}