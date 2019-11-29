#include <iostream>
#include "bst.h"


int main()
{

	{
		BST<int> bst;
		bst.breadthFirst();
		bst.search(1);
		bst.iterativePreorder();
		bst.iterativePostorder();
		bst.iterativeInorder();
		bst.MorrisInorder();
	}

	std::cin.get();
	return 0;
}