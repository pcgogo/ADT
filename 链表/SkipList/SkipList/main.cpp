#include <iostream>
#include "SkipList.h"

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	{
		SkipList<int> sl;
		sl.choosePowers();
		sl.chooseLevel();
		sl.skiplistInsert(1);
		cout << (sl.skiplistSearch(1)) << endl;

	}
	cin.get();
}