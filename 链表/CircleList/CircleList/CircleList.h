#ifndef CIRCLELIST_H_
#define CIRCLELIST_H_

template <typename T>
class CircleList
{
private:
	class Node
	{
	public:
		T info;
		Node* next;
		Node() { next = nullptr; }
		Node(T el, Node* n= nullptr) { info = el; next = n; }
	};
	Node* tail;	//�̶�ָ��

public:
	CircleList();
	~CircleList();
	bool isEmpty();
	void addToHead(const T & el);
	void addToTail(const T & el);
	T deleteFromHead();
	T deleteFromTail();
	void deleteNode(const T & el);
	bool isInList(const T& el)const;
};

template <typename T>
CircleList<T>::CircleList()
{
	tail = nullptr;
}

template <typename T>
CircleList<T>::~CircleList()
{
	for (Node* temp = tail; tail != tail->next;)
	{
		temp = tail->next;
		tail->next = tail->next->next;
		delete temp;
	}
	delete tail;
	tail = nullptr;
}

template <typename T>
bool CircleList<T>::isEmpty()
{
	return tail == nullptr;
}

template <typename T>
void CircleList<T>::addToHead(const T & el)
{
	if (tail == nullptr)
	{
		tail = new Node(el);
		tail->next = tail;
	}
	else
		tail->next = new Node(el, tail->next->next);
}

template <typename T>
void CircleList<T>::addToTail(const T& el)
{
	if (tail == nullptr)
	{
		tail = new Node(el);
		tail->next = tail;
	}
	else
	{
		Node* temp;
		for (temp = tail->next; temp->next != tail; temp = temp->next);
		tail = new Node(el, tail->next);
		temp->next = tail;
	}
}

template <typename T>
T CircleList<T>::deleteFromHead()
{
	if (tail == nullptr)	//��ѭ������Ϊ��ʱ
		throw("List is Empty");
	else if (tail == tail->next)	//��ѭ���б�ֻ��һ���ڵ�ʱ
	{
		T el = tail->info;
		delete tail;
		return el;
	}
	else
	{
		T el = tail->next->info;
		Node* temp = tail->next;
		tail->next = tail->next->next;
		delete temp;
		return el;
	}
}

template <typename T>
T CircleList<T>::deleteFromTail()
{
	if (tail == nullptr)
		throw("List is Empty");
	else if (tail == tail->next)
	{
		T el = tail->info;
		delete tail;
		tail = nullptr;
		return el;
	}
	else
	{
		T el = tail->info;
		Node* temp = nullptr;
		for (Node* temp = tail->next; temp->next != tail; temp = temp->next);
		delete tail;
		tail = temp;
		return el;
	}
}

template <typename T>
void CircleList<T>::deleteNode(const T & el)
{
	if (tail != nullptr)	//������Ϊ��ʱ��������
	{
		if (tail->next == tail && el == tail->info)	//��ѭ��������ֻ��һ���ڵ��ҽ���ɾ��ʱ
		{
			delete tail;
			tail == nullptr;
		}
		else if (el == tail->info) //��ѭ����������һ���ڵ㽫��ɾ��ʱ
		{
			Node* temp = nullptr;
			for (temp = tail->next; temp->next != tail; temp = temp->next);
			delete tail;
			tail = temp;
		}
		else
		{
			Node* temp = nullptr;
			Node* prev = nullptr;
			for (temp = tail->next, prev = tail; el!=temp->info && temp->next != tail; temp = temp->next, prev = prev->next);
			prev->next = temp->next;
			delete temp;
		}
	}
}

template <typename T>
bool CircleList<T>::isInList(const T & el)const
{
	Node* temp = nullptr;
	for (temp = tail; temp->next != tail; temp = temp->next)
	{
		if (el == temp->info)
			return true;
	}
	return false;
}

#endif