#ifndef DLLIST_H_
#define DLLIST_H_


template <typename T>
class DLList
{
protected:
	class Node
	{
	public:
		T info;
		Node* next;
		Node* prev;
		Node() { next = prev = nullptr; }
		Node(const T& el, Node* n = nullptr, Node* p = nullptr) { info = el; next = n; prev = p; }
	};
	Node* head;
	Node* tail;

public:
	DLList();
	~DLList();
	bool isEmpty();
	void addToHead(const T& el);
	void addToTail(const T& el);
	T deleteFromHead();
	T deleteFromTail();
	void deleteNode(const T& el);
	bool isInList(const T& el)const;
};


template <typename T>
DLList<T>::DLList()
{
	head = tail = nullptr;
}

template <typename T>
DLList<T>::~DLList()
{
	for (Node* temp; head != nullptr;)
	{
		temp = head->next;
		delete head;
		head = temp;
	}
}

template <typename T>
bool DLList<T>::isEmpty()
{
	return head == nullptr;
}

template <typename T>
void DLList<T>::addToHead(const T& el)
{
	head = new Node(el, head);
	if (tail == nullptr)
		tail = head;
}

template <typename T>
void DLList<T>::addToTail(const T& el)
{
	tail = new Node(el, nullptr, tail);
	if (head == nullptr)
		head = tail;
}

//删除时需考虑删除后链表是否为空
template <typename T>
T DLList<T>::deleteFromHead()
{
	if (isEmpty())	//链表为空
		throw("DLList is Empty");
	else if (head == tail)	//	链表中只有一个元素
	{
		Node* temp = head;
		head = tail = nullptr;
		return temp->info;
	}
	else
	{
		Node* temp = head;
		head = head->next;
		return temp->el;
	}
}

template <typename T>
T DLList<T>::deleteFromTail()
{
	if (isEmpty())	//链表为空
		throw("DLList is Empty");
	else if (tail == head)	//	链表中只有一个元素
	{
		Node* temp = tail;
		tail = head = nullptr;
		return temp->info;
	}
	else
	{
		Node* temp = tail;
		tail = tail->prev;
		return temp->el;
	}
}

template <typename T>
void DLList<T>::deleteNode(const T & el)
{
	if (head != nullptr)	//当链表不为空
	{
		if (head == tail && el == head->info)	//链表只有一个元素且是被删除的元素
		{
			delete head;
			head = tail = nullptr;
		}
		else if (el == head->info)	//链表有两个以上节点，并且第一个节点被删除
		{
			Node* temp = head;
			head = head->next;
			delete temp;
		}
		else
		{
			Node* temp, * prev;
			for (prev = head, temp = head->next; temp != nullptr && el != temp->info; prev = prev->next, temp = temp->next);	//双指针
			if (temp != nullptr)
			{
				prev->next = temp->next;
				if (temp == tail)	//如果被删除的是最后一个元素，需要修改tail指针
					tail = prev;
				delete temp;
			}
		}
	}
}

template <typename T>
bool DLList<T>::isInList(const T & el)const
{
	//用一个临时变量temp来扫描链表，若不匹配temp = temp ->next，到达最后一个节点时若还没有，temp = nullptr
	for (Node* temp = head; temp != nullptr && el != temp->info; temp = temp->next);
	return temp != nullptr;
}


#endif