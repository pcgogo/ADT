#ifndef QUEUE_H_
#define QUEUE_H_

#include <list>

template <class T>
class Queue
{
private:
	std::list<T> lst;
public:
	Queue(){}
	void clear(){ lst.clear(); }
	bool isEmpty()const{ return lst.empty(); }
	void enqueue(const T & el){ lst.push_back(el); }
	T dequeue(){ T el = lst.front(); lst.pop_front(); return el; }
	const T & frontEl()const{ return lst.front(); }
};


#endif