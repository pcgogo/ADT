#include <iostream>
#include "stack.h"

int main()
{

	{
		Stack<int> s;
		for (int i = 1; i <= 10; i++)
			s.push(i);
		s.topEl() = 100;
		for (int i = 1; i <= 10; i++)
			std::cout << s.pop() << std::endl;
	}


	std::cin.get();
	return 0;
}