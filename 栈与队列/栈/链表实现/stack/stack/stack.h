#ifndef STACK_LL_H_
#define STACK_LL_H_

#include <list>

template<class T>
class Stack
{
private:
	std::list<T> lst;	//STL中list为普通双向链表
public:
	Stack(){}
	void clear(){ lst.clear(); }
	bool isEmpty()const{ lst.empty(); }
	T & topEl(){ return lst.back(); }
	T pop(){ T el = lst.back(); lst.pop_back(); return el; }
	void push(const T & el){ lst.push_back(el); }
};


#endif