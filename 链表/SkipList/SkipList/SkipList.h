#ifndef SKIPLIST_H_
#define SKIPLIST_H_

template<class T>
class SkipList
{
protected:
	static const int maxLevel = 4;
	class Node
	{
	public:
		T info;
		Node **next;
		Node(){}
	};
	typedef Node *nodePtr;
	nodePtr root[maxLevel];
	int powers[maxLevel];
public:
	SkipList();
	bool isEmpty()const;
	void choosePowers();
	int chooseLevel();
	T* skiplistSearch(const T & t);
	void skiplistInsert(const T & t);
};

template<class T>
SkipList<T>::SkipList()
{
	for (int i = 0; i < maxLevel; i++)
		root[i] = 0;
}

template<class T>
bool SkipList<T>::isEmpty()const
{
	return root[0] == 0;
}

template<class T>
void SkipList<T>::choosePowers()
{
	powers[maxLevel - 1] = (2 << (maxLevel - 1)) - 1;		//2^maxLevel - 1
	for (int i = maxLevel - 2, j = 0; i >= 0;i--,j++)
		powers[i] = powers[i + 1] - (2 << j);				//2^(j+1)
}

template<class T>
int SkipList<T>::chooseLevel()
{
	int i, r = rand() % powers[maxLevel - 1] + 1;
	for (i = 1; i < maxLevel; i++)
	{
		if (r < powers[i])
			return i - 1;
	}
	return i - 1;
}

template<class T>
T* SkipList<T>::skiplistSearch(const T & t)
{
	if (isEmpty())
		return 0;
	nodePtr prev, curr;
	int lvl;
	for (lvl = maxLevel - 1; lvl >= 0 && !root[lvl]; lvl--);
	prev = curr = root[lvl];
	while (1)
	{
		if (t == curr->info)
			return &curr->info;
		else if (t < curr->info)
		{
			if (lvl == 0)
				return 0;
			else if (curr == root[lvl])
				curr = root[--lvl];
			else
				curr = *(prev->next + --lvl);
		}
		else
		{
			prev = curr;
			if (*(curr->next + lvl) != 0)
				curr = *(curr->next + lvl);
			else
			{
				for (lvl--; lvl >= 0 && *(curr->next + lvl) == 0; lvl--);
				if (lvl >= 0)
					curr = *(curr->next + lvl);
				else
					return 0;
			}
		}
	}
}

template<class T>
void SkipList<T>::skiplistInsert(const T & t)
{
	nodePtr curr[maxLevel], prev[maxLevel], newNode;
	int lvl, i;
	curr[maxLevel - 1] = root[maxLevel - 1];
	prev[maxLevel - 1] = 0;
	for (lvl = maxLevel - 1; lvl >= 0; lvl--)
	{
		while (curr[lvl] && curr[lvl]->info < t)
		{
			prev[lvl] = curr[lvl];
			curr[lvl] = *(curr[lvl]->next + lvl);
		}
		if (curr[lvl] && curr[lvl]->info == t)
			return;
		if (lvl > 0){
			if (prev[lvl] == 0)
			{
				curr[lvl - 1] = root[lvl - 1];
				prev[lvl - 1] = 0;
			}
			else
			{
				curr[lvl - 1] = *(prev[lvl]->next + lvl - 1);
				prev[lvl - 1] = prev[lvl];
			}
		}
		lvl = SkipList<T>::chooseLevel();
		newNode = new Node;
		newNode->next = new nodePtr[sizeof(nodePtr)*lvl];
		newNode->info = t;
		for (i = 0; i < lvl; i++)
		{
			newNode->next[i] = curr[i];
			if (prev[i] == 0)
				root[i] = newNode;
			else
				prev[i]->next[i] = newNode;
		}
	}
}

#endif