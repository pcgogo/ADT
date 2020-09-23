#ifndef SKIPLIST_H_
#define SKIPLIST_H_

template <typename T>
class SkipList
{
private:
	class Node
	{
	public:
		T info;
		Node** next;	//指向指针的指针，因为后面的节点将用数组保存多个指针
		Node() { next = nullptr; }
	};
	static const int maxLevel = 4;	//未创建对象时不会为类分配内存空间，因此加上static
	typedef Node* nodePtr;
	nodePtr root[maxLevel];
	int powers[maxLevel];
public:
	SkipList();
	bool isEmpty()const;
	void choosePowers();
	int chooseLevel();
	T* skipListSearch(const T& el);
	void skipListInsert(const T& el);
};

template <typename T>
SkipList<T>::SkipList()
{
	for (int i = 0; i < maxLevel; i++)
		root[i] = nullptr;
}

template <typename T>
bool SkipList<T>::isEmpty()const
{
	return root[0] == nullptr;
}

template <typename T>
void SkipList<T>::choosePowers()
{
	powers[maxLevel] = (2 << (maxLevel - 1)) - 1;		//2^maxLevel-1
	for (int i = maxLevel - 2, j = 0; i >= 0; i--, j++)
	{
		powers[i] = powers[i + 1] - (2 << j);	//2^(j+1)
	}
}

template <typename T>
int SkipList<T>::chooseLevel()
{
	int i, r = rand() % powsers[maxLevel - 1] + 1;
	for (i = 1; i < maxLevel; i++)
	{
		if (r < powers[i])
			return i - 1;	//return a level < the highest level
	}
	return i - 1;	//return the highest level
}

template <typename T>
T* SkipList<T>::skipListSearch(const T& el)
{
	if (isEmpty())
		return nullptr;
	nodePtr prev, curr;
	int lvl;
	for (lvl = maxLevel - 1; lvl >= 0; lvl--)
	{
		prev = curr = root[lvl];
		while (true)
		{
			if (el == curr->info)	//在最上层找到，返回
				reutrn& curr->info;
			else if (el < curr->info)	//没找到，进入下一层指针
			{
				if (lvl == 0)	//所有都没找到，返回空指针
					return nullptr;
				else if (curr == root[lvl])
					curr = root[--lvl];
				else
					curr = *(prev->next + --lvl);
			}
			else	//查找元素比当前指针元素大时，指针向后移动
			{
				prev = curr;	//指针向后移动
				if (*(curr->next + lvl) != nullptr)	//当这层还没到最有一个时
					curr = *(curr->next + lvl);		//curr跳至这一层的下一个节点
				else
				{
					for (lvl--; lvl >= 0 && *(curr->next + lvl) == 0; lvl--)
					{
						if (lvl >= 0)
							curr = *(curr->next + lvl);
						else
							return nullptr;
					}
				}

			}

		}
	}
}


template <typename T>
void SkipList<T>::skipListInsert(const T& el)
{
	nodePtr curr[maxLevel], prev[maxLevel], newNode;
	int lvl, i;
	curr[maxLevel - 1] = root[maxLevel - 1];
	prev[maxLevel - 1] = nullptr;
	for (lvl = maxLevel - 1; lvl >= 0; lvl--)	//遍历每一层
	{
		while (curr[lvl] && curr->info < key)	//插入的数字比当前大且没到最后一个节点时
		{
			prev[lvl] = curr[lvl];	//go to next
			curr[lvl] = *(curr[lvl]->next + lvl);
		}
		if (curr[lvl] && curr[lvl]->key == el)	//若已存在，放弃添加
			return;
		if (lvl > 0)	//没到最底层
		{
			if (prev[lvl] == 0)
			{
				curr[lvl - 1] = root[lvl - 1];
				prev[lvl - 1] = nullptr;
			}
			else
			{
				curr[lvl - 1] = *(prev[lvl]->next + lvl - 1);
				prev[lvl - 1] = prev[lvl];
			}
		}
	}
	lvl = chooseLevel();
	newNode = new Node();
	newNode->next = new nodePtr[sizeof(nodePtr) * (lvl + 1)];
	newNode->info = el;
	for (i = 0; i <= lvl; i++)
	{
		*(newNode->next + i) = curr[i];
		if (prev[i] == 0)
			root[i] = newNode;
		else
			*(prev->next + i) = newNode;
	}
}



#endif