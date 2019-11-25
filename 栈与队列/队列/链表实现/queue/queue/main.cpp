#include <iostream>
#include "queue.h"

int main()
{
	using std::cout;
	using std::endl;
	{
		Queue<int> q;
		for (int i = 1; i <= 10; i++)
			q.enqueue(i);
		for (int i = 1; i <= 10; i++)
			cout << q.dequeue() << endl;
	}

	std::cin.get();
	return 0;
}