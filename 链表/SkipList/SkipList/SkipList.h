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
		Node** next;	//ָ��ָ���ָ�룬��Ϊ����Ľڵ㽫�����鱣����ָ��
		Node() { next = nullptr; }
	};
	static const int maxLevel = 4;	//δ��������ʱ����Ϊ������ڴ�ռ䣬��˼���static
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
			if (el == curr->info)	//�����ϲ��ҵ�������
				reutrn& curr->info;
			else if (el < curr->info)	//û�ҵ���������һ��ָ��
			{
				if (lvl == 0)	//���ж�û�ҵ������ؿ�ָ��
					return nullptr;
				else if (curr == root[lvl])
					curr = root[--lvl];
				else
					curr = *(prev->next + --lvl);
			}
			else	//����Ԫ�رȵ�ǰָ��Ԫ�ش�ʱ��ָ������ƶ�
			{
				prev = curr;	//ָ������ƶ�
				if (*(curr->next + lvl) != nullptr)	//����㻹û������һ��ʱ
					curr = *(curr->next + lvl);		//curr������һ�����һ���ڵ�
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
	for (lvl = maxLevel - 1; lvl >= 0; lvl--)	//����ÿһ��
	{
		while (curr[lvl] && curr->info < key)	//��������ֱȵ�ǰ����û�����һ���ڵ�ʱ
		{
			prev[lvl] = curr[lvl];	//go to next
			curr[lvl] = *(curr[lvl]->next + lvl);
		}
		if (curr[lvl] && curr[lvl]->key == el)	//���Ѵ��ڣ��������
			return;
		if (lvl > 0)	//û����ײ�
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