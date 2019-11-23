#ifndef SLLIST_H_
#define SLLIST_H_

#include <iostream>
#include <string>

template <class T>
class SLList
{
private:
	class Node
	{
	public:
		T info;
		Node * next;
		Node(){ next = 0; }
		Node(T t, Node * pn = 0){ info = t; next = pn; }
	};
	Node * head;
	Node * tail;
public:
	SLList(){ head = tail = 0; }
	~SLList();
	bool isEmpty()const{ return head == 0; }
	bool addToHead(const T & item);
	bool addToTail(const T & item);
	bool deleteFromHead(T & item);
	bool deleteFromTail(T & item);
	bool deleteNode(const T & item);
	bool isInList(const T & item)const;
};

template<class T>
SLList<T>::~SLList()
{
	Node * temp;
	while (head != 0)
	{
		temp = head;
		head = head->next;
		delete temp;
	}
}

template<class T>
bool SLList<T>::addToHead(const T & item)
{
	head = new Node(item);
	if (tail == 0)
		tail = head;
	return true;
}

template<class T>
bool SLList<T>::addToTail(const T & item)
{
	if (!isEmpty())
	{
		tail->next = new Node(item);
		tail = tail->next;
	}
	else
		head = tail = new Node(item);
	return true;
}

template<class T>
bool SLList<T>::deleteFromHead(T & item)
{
	if (isEmpty())
		return false;
	Node * temp = head;
	item = head->info;
	head = head->next;
	delete temp;
	if (head == 0)
		tail = 0;
	return true;
}

template<class T>
bool SLList<T>::deleteFromTail(T & item)
{
	if (isEmpty())
		return false;
	item = tail->info;
	if (head == tail)
	{
		delete tail;
		head = tail = 0;
		return true;
	}
	else
	{
		Node * temp;
		for (temp = head; temp->next != tail; temp = temp->next);
		delete tail;
		tail = temp;
		tail->next = 0;
		return true;
	}
}

template<class T>
bool SLList<T>::deleteNode(const T & item)
{
	if (isEmpty())
		return false;
	else if (head == tail && item == head->info)
	{
		delete head;
		head = tail = 0;
		return true;
	}
	else if (item == head->info)
	{
		Node * temp = head;
		head = head->next;
		delete temp;
		return true;
	}
	else
	{
		Node *temp, *pred;
		for (pred = head, temp = head->next; temp != 0 && item != temp->info; pred = pred->next, temp = temp->next);
		pred->next = temp->next;
		if (temp == tail)
			tail = pred;
		delete temp;
		return true;
	}
}

template<class T>
bool SLList<T>::isInList(const T & item)const
{
	if (isEmpty())
		return false;
	Node *temp;
	for ( temp = head; temp->info != item; temp = temp->next);
	return temp != 0;//最后一个节点的next为空指针
}






#endif