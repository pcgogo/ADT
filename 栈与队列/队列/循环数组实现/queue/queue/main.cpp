#include <iostream>
#include "queue.h"

int main()
{
	using std::cout;
	using std::endl;
	{
		Queue<int> q;
		for (int i = 1; i <= 10; i++)
		{
			try
			{
				q.enqueue(i);
			}
			catch (const char * s)
			{
				cout << s << endl;
			}
		}
		q.clear();
		for (int i = 1; i <= 10; i++)
		{
			try
			{
				cout << q.dequeue() << endl;
			}
			catch (const char * s)
			{
				cout << s << endl;
			}
		}
	}
	std::cin.get();
	return 0;
}