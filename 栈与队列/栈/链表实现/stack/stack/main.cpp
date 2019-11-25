#include <iostream>
#include "stack.h"


int main()
{
	using std::cout;
	using std::endl;

	{
		Stack<int> s;	//ģ������������һ��Ĭ�Ϲ��캯��
		for (int i = 1; i <= 10; i++)
			s.push(i);
		s.topEl() = 100;
		for (int i = 1; i <= 10; i++)
			cout << s.pop() << endl;
	}

	std::cin.get();
	return 0;
}