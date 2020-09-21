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

//ɾ��ʱ�迼��ɾ���������Ƿ�Ϊ��
template <typename T>
T DLList<T>::deleteFromHead()
{
	if (isEmpty())	//����Ϊ��
		throw("DLList is Empty");
	else if (head == tail)	//	������ֻ��һ��Ԫ��
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
	if (isEmpty())	//����Ϊ��
		throw("DLList is Empty");
	else if (tail == head)	//	������ֻ��һ��Ԫ��
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
	if (head != nullptr)	//������Ϊ��
	{
		if (head == tail && el == head->info)	//����ֻ��һ��Ԫ�����Ǳ�ɾ����Ԫ��
		{
			delete head;
			head = tail = nullptr;
		}
		else if (el == head->info)	//�������������Ͻڵ㣬���ҵ�һ���ڵ㱻ɾ��
		{
			Node* temp = head;
			head = head->next;
			delete temp;
		}
		else
		{
			Node* temp, * prev;
			for (prev = head, temp = head->next; temp != nullptr && el != temp->info; prev = prev->next, temp = temp->next);	//˫ָ��
			if (temp != nullptr)
			{
				prev->next = temp->next;
				if (temp == tail)	//�����ɾ���������һ��Ԫ�أ���Ҫ�޸�tailָ��
					tail = prev;
				delete temp;
			}
		}
	}
}

template <typename T>
bool DLList<T>::isInList(const T & el)const
{
	//��һ����ʱ����temp��ɨ����������ƥ��temp = temp ->next���������һ���ڵ�ʱ����û�У�temp = nullptr
	for (Node* temp = head; temp != nullptr && el != temp->info; temp = temp->next);
	return temp != nullptr;
}


#endif