#include <iostream>
#include "bst.h"


int main()
{

	{
		BST<int> bst;
		bst.insert(3);
		std::cout << bst.search(1) << std::endl;
		bst.breadthFirst();
		bst.iterativePreorder();
		bst.iterativePostorder();
		bst.iterativeInorder();
		bst.MorrisInorder();
		//bst.deleteByMerging();
	}

	std::cin.get();
	return 0;
}