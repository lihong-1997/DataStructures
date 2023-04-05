#ifndef DOUBLE_STACK_H
#define DOUBLE_STACK_H


#include <iostream>

template <typename T>
class Double_Stack
{
private:
	int left;           // left左边代表一个栈
	int right;          // right右边代表一个栈
	int capacity;       // 数组申请的空间
	T* head = nullptr;  // 数组头地址
public:
	Double_Stack() :left(0), right(0), capacity(0) {}
	Double_Stack(const Double_Stack&);
	~Double_Stack();
	Double_Stack(int cap);
public:
	bool leftpush(T value);
	bool leftpop();
	bool rightpush(T value);
	bool rightpop();
	void destroy();

	int lsize();
	int rsize();
	int size();
};

#endif

template<typename T>
inline Double_Stack<T>::Double_Stack(const Double_Stack& ds)
{
	capacity = ds.capacity;
	left = ds.left;
	right = ds.right;
	head = new T[capacity];
	for (int i = 0;i < capacity;i++)
		head[i] = ds.head[i];
	
}

template<typename T>
inline Double_Stack<T>::~Double_Stack()
{
	destroy();
}

template<typename T>
inline Double_Stack<T>::Double_Stack(int cap)
{
	left = 0;
	right = cap - 1;
	capacity = cap;
	head = new T[cap];
}

template<typename T>
inline bool Double_Stack<T>::leftpush(T value)
{
	if (left >= right + 1)
	{
		std::cout << "overflow" << std::endl;
		return false;
	}
		
	head[left++] = value;
	return true;
}
template<typename T>
bool Double_Stack<T>::leftpop()
{
	if (left == 0)
	{
		std::cout << "empty stack" << std::endl;
		return false;
	}
	--left;
	return true;
}
template<typename T>
bool Double_Stack<T>::rightpush(T value)
{
	if (left >= right + 1)
	{
		std::cout << "overflow" << std::endl;
		return false;
	}

	head[right--] = value;
	return true;
}
template<typename T>
bool Double_Stack<T>::rightpop()
{
	if (right == capacity - 1)
	{
		std::cout << "empty stack" << std::endl;
		return false;
	}
		
	++right;
	return true;
}

template<typename T>
inline void Double_Stack<T>::destroy()
{
		delete[] head;
		head = nullptr;
		left = right = capacity = 0;
}

template<typename T>
inline int Double_Stack<T>::lsize()
{
	return left;
}

template<typename T>
inline int Double_Stack<T>::rsize()
{
	return capacity - right - 1;
}

template<typename T>
inline int Double_Stack<T>::size()
{
	return lsize() + rsize();
}
