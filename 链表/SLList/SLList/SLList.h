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
	//SLList & operator= (const SLList & list);	//���ض��󽫵��ø��ƹ��캯�����������ò���
	bool isEmpty();
	void addToHead(T el);
	void addToTail(T el);
	T deleteFromHead();
	T deleteFromTail();
	void deleteNode(T el);
	bool isInList(const T el) const; //�Ǿ�̬��Ա���������const����ʾ��Ա�������������thisָ��Ϊconstָ�룬�������ڸó�Ա�����У������޸������ڵ���ĳ�Ա�Ĳ������ǲ������

};


template <typename T>
SLList<T>::SLList()
{
	head = tail = nullptr;
}


template <typename T>
SLList<T>::~SLList()
{
	for (Node* temp; !isEmpty();) //��ִ��forѭ����һ��������Ȼ��ִ�еڶ������ʽ��ΪTrueִ��ѭ���壬ѭ����ִ�����ִ�е���������
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
	if (tail != nullptr) //����Ϊ��
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