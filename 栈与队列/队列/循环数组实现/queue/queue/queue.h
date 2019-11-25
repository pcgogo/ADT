#ifndef ARRAY_QUEUE_H_
#define ARRAY_QUEUE_H_

template<class T,int size = 100>
class Queue
{
private:
	int first, last;
	T storage[size];
public:
	Queue(){ first = last = -1; }
	void clear(){ first = last = -1; }
	bool isFull()const{ return first == 0 && last == size - 1 || first == last + 1; }
	bool isEmpty()const{ return first == -1; }
	void enqueue(const T & el);
	T dequeue();
	const T & frontEl()const;
};

template<class T, int size = 100>
void Queue<T, size>::enqueue(const T & el)
{
	if (!isFull())
	{
		if (last == size - 1 || last == -1)
		{
			last = 0;
			storage[0] = el;
			if (first == -1)
				first = 0;
		}
		else
			storage[++last] = el;
	}
	else
		throw "Full";
}

template<class T, int size = 100>
T Queue<T, size>::dequeue()
{
	if (!isEmpty())
	{
		T temp = storage[first];
		if (first == last)
		{
			first = last = -1;
		}
		else if (first == size -1)
		{
			 first == 0;
		}
		else
		{
			first++;
		}
		return temp;
	}
	else
		throw "Empty";
}

template<class T, int size = 100>
const T & Queue<T, size>::frontEl()const
{
	if (!isEmpty())
		return storage[first];
	else
		throw "Empty";
}


#endif