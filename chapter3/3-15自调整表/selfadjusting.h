#ifndef SELFADJUSTING_H
#define SELFADJUSTING_H
#include <iostream>

template <typename T>
class SelfAdjusting
{

public:
	SelfAdjusting() : size(0), capacity(0), array(nullptr){}
	~SelfAdjusting() = default;
	SelfAdjusting(int N)
	{
		array = new T[N];
		size = 0;
		capacity = N;
	}
	void Find(T value);
	void Insert(T value);
	void Print();

private:
	int size;
	int capacity;
    T* array;
};

template<typename T>
void SelfAdjusting<T>::Find(T value)
{
	int index = -1;
	for (int i = 0; i < size; ++i)
	{
		if (array[i] == value)
		{
			index = i;
			break;
		}
	}
	T temp = array[index];
	for (int i = index; i > 0; --i)
	{
		array[i] = array[i - 1];
	}
	array[0] = temp;
}

template<typename T>
inline void SelfAdjusting<T>::Insert(T value)
{
	for (int i = size; i > 0; --i)
	{
		array[i] = array[i - 1];
	}
	array[0] = value;
	++size;

}
template<typename T>
inline void SelfAdjusting<T>::Print()
{
	std::cout << "header ";
	for (int i = 0; i < size; ++i)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

#endif