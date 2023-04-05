#ifndef DOUBLE_LINKLIST_H
#define DOUBLE_LINKLIST_H

#include <iostream>

template <class T>
struct Node
{
	Node<T>() : Next(nullptr), Pre(nullptr) {}
	Node<T>(const T& data_) : Next(nullptr), Pre(nullptr) ,data(data_) {}
	Node<T>* Next;
	Node<T>* Pre;
	T data;
};

template <class T>
class DList
{
public:
	DList<T>();
	~DList<T>();
public:
	void Push(T data);
	T Pop();
	void Inject(T data);
	T Eject();
	void Traverse();
private:
	Node<T>* front;
	Node<T>* rear;
	int len;
};

#endif

template<class T>
inline DList<T>::DList()
{
	front = nullptr;
	rear = nullptr;
	len = 0;
}

template<class T>
inline DList<T>::~DList()
{
	front = nullptr;
	rear = nullptr;
	len = 0;
}

template<class T>
inline void DList<T>::Push(T data)
{
	Node<T>* pnew = new Node<T>(data);
	if (len == 0)
		front = rear = pnew;
	
	else
	{
		pnew->Next = front;
		front->Pre = pnew;
		front = pnew;
	}
	++len;
}

template<class T>
inline T DList<T>::Pop()
{
	if (len == 0)
		return 0;

	Node<T>* p = front;
	if (len == 1)
		front = rear = nullptr;
	else
	{
		front = front->Next;
		front->Pre = nullptr;
	}
	T temp = p->data;
	delete p;
	--len;

	return temp;
}

template<class T>
inline void DList<T>::Inject(T data)
{
	Node<T>* pnew = new Node<T>(data);
	if (len == 0)
		front = rear = pnew;

	else
	{
		pnew->Pre = rear;
		rear->Next = pnew;
		rear = pnew;
	}
	++len;
}

template<class T>
inline T DList<T>::Eject()
{
	if (len == 0)
		return 0;

	Node<T>* p = rear;
	if (len == 1)
		front = rear = nullptr;
	else
	{
		rear = rear->Pre;
		rear->Next = nullptr;
	}
	T temp = p->data;
	delete p;
	--len;
	return temp;
}

template<class T>
inline void DList<T>::Traverse()
{
	Node<T>* p = front;
	while (p != nullptr)
	{
		std::cout << p->data << " ";
		p = p->Next;
	}
	std::cout << std::endl;
}
