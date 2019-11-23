#ifndef DOUBLY_LINKED_LIST_H_
#define DOUBLY_LINKED_LIST_H_

template<class T>
class DoublyLinkedList
{
protected:
	class Node
	{
	public:
		T info;
		Node *prev;
		Node *next;
		Node(){ next = prev = 0; }
		Node(const T & t, Node *n = 0, Node *p = 0) :info(t), next(n), prev(p){}
	};
	Node *head;
	Node *tail;
public:
	DoublyLinkedList(){ head = tail = 0; }
	~DoublyLinkedList();
	bool isEmpty()const{ return head == 0; }
	bool addToTail(const T & item);
	bool deleteFromTail(T & item);
};

template<class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
	Node *temp;
	while (head != 0)
	{
		temp = head;
		head = head->next;
		delete temp;
	}
}

template<class T>
bool DoublyLinkedList<T>::addToTail(const T & item)
{
	if (isEmpty())
		head = tail = new Node(item);
	else
	{
		tail = new Node(item, 0, tail);
		tail->prev->next = tail; //将前一个节点的next链接到最后一个节点
	}
	return true;
}

template<class T>
bool DoublyLinkedList<T>::deleteFromTail(T & item)
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
		tail = tail->prev;
		delete tail->next;
		tail->next = 0;
		return true;
	}
}



#endif