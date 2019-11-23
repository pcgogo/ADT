#ifndef SKIPLIST_H_
#define SKIPLIST_H_

template<class T>
class SkilList
{
protected:
	static const int maxLevel = 4;
	class Node
	{
		T info;
		Node **next;
		Node(){}
	};
	typedef Node *nodePtr;
	nodePtr root[maxLevel];
	int powers[maxLevel];
public:

};


#endif