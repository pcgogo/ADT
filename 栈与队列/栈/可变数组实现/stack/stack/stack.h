#ifndef STACK_VECTOR_H_
#define STACK_VECTOR_H_

#include <vector>

template<class T,int capacity = 30>
class Stack
{
private:
	std::vector<T> pool;
public:
	Stack(){ pool.reserve(capacity); }
	void clear(){ pool.clear(); }
	bool isEmpty()const { return pool.empty(); }
	T& topEl(){ return pool.back(); }
	//const T & topEl()const{ return pool.back(); }
	void push(const T & el){ pool.push_back(el); }
	T pop(){ T el = pool.back(); pool.pop_back(); return el; }

};




#endif