#ifndef SLLIST_H_
#define SLLIST_H_

#include <iostream>
#include <string>

template <typename T>
class SLList
{
private:
	class Node
	{
	public:
		T info;
		Node* next;
		Node() { next = nullptr; }
		Node(T el, Node* nptr = nullptr) { info = el; next = nptr; }
	};
	Node* head;
	Node* tail;
public:
	SLList();
	//SLList(const SLList & list);
	~SLList();
	//SLList & operator= (const SLList & list);	//返回对象将调用复制构造函数，返回引用不会
	bool isEmpty();
	void addToHead(T el);
	void addToTail(T el);
	T deleteFromHead();
	T deleteFromTail();
	void deleteNode(T el);
	bool isInList(const T el) const; //非静态成员函数后面加const，表示成员函数隐含传入的this指针为const指针，决定了在该成员函数中，任意修改它所在的类的成员的操作都是不允许的

};


template <typename T>
SLList<T>::SLList()
{
	head = tail = nullptr;
}


template <typename T>
SLList<T>::~SLList()
{
	for (Node* temp; !isEmpty();) //先执行for循环第一个参数，然后执行第二个表达式，为True执行循环体，循环体执行完后执行第三个参数
	{
		temp = head->next;
		delete head;
		head = temp;
	}
}

template <typename T>
bool SLList<T>::isEmpty()
{
	return head == nullptr;
}

template <typename T>
void SLList<T>::addToHead(T el)
{
	head = New(el, head);
	if (tail == nullptr)
	{
		tail = head;
	}
}

template <typename T>
void SLList<T>::addToTail(T el)
{
	if (tail != nullptr) //链表不为空
	{
		tail->next = new Node(el);
		tail = tail->next;
	}
	else
	{
		head = tail = new Node(el);
	}
}

template <typename T>
T SLList<T>::deleteFromHead()
{
	T el = head->info;
	Node* temp = head;
	if (head == tail)
	{
		head = tail = nullptr;
	}
	else
		head = head->next;
	delete temp;
	return el;
}


template <typename T>
T SLList<T>::deleteFromTail()
{
	T el = tail->info;
	if (head == temp)
	{
		delete head;
		head = tail = nullptr;
	}
	else
	{
		for (Node* temp = head; temp->next != tail; temp = temp->next);
		delete tail;
		tail = temp;
		tail->next = nullptr;
	}
	return el;
}


template <typename T>
void SLList<T>::deleteNode(T el)
{
	if (head != nullptr)
	{
		if (head == tail && el == head->info)
		{
			delete head;
			head = tail = nullptr;
		}
		else if (el == head->info)
		{
			Node* temp = head;
			head = head->next;
			delete temp;
		}
		else
		{
			Node* pred, *temp;
			for (pred = head, temp = head->next; temp != nullptr && temp->info != el; pred = pred->next, temp = temp->next);
			if (temp != nullptr)
			{
				pred->next = temp->next;
				if (temp == tail)
					tail = pred;
				delete temp;
			}

		}
	}
}

template <typename T>
bool SLList<T>::isInList(const T el)const
{
	for (Node* temp = head; (!(el == head->info)) && temp != nullptr; temp = temp->next);
	return temp != nullptr;
}





#endif