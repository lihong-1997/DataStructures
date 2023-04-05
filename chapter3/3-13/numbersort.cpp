/*
 * 社会安全号码由9位构成 000-000-000
 * 每次比较三位数，利用1000个桶，分三次即可完成排序
 * 用链表解决三位数相等的情况
 */
#include "linkedlist.h"
#include <iostream>
#define BASE 1000 //基数

using namespace linkedlist;
template class List<int>; //

void bucketsort(int ssn[], int n)
{
	List<int>* lower_three_digits_bucket = new List<int>[1000]; //低三位的桶

	for (int i = 0; i < n; ++i)
	{
		//每个号码存放在桶对应的低三位位置
		lower_three_digits_bucket[ssn[i] % 1000].Insert(ssn[i]);
	}

	List<int>* middle_three_digits_bucket = new List<int>[1000]; //中三位的桶
	for (int i = 0; i < BASE; ++i)
	{
		if (!lower_three_digits_bucket[i].empty())
		{
			Node<int>* node = lower_three_digits_bucket[i].First();
			for (;node!=nullptr; node = node->next)
				middle_three_digits_bucket[node->data / 1000 % 1000].Insert(node->data);
			
		}
	}
	delete[] lower_three_digits_bucket;

	List<int>* first_three_digits_bucket = new List<int>[1000]; //高三位的桶
	for (int i = 0; i < BASE; ++i)
	{
		if (!middle_three_digits_bucket[i].empty())
		{
			Node<int>* node = middle_three_digits_bucket[i].First();
			for (; node != nullptr; node = node->next)
				first_three_digits_bucket[node->data / 1000000 % 1000].Insert(node->data);
		}
	}
	delete[] middle_three_digits_bucket;

	//将桶里的数据输出
	int pos = 0, i = 0;
	while (pos < n)
	{
		if (!first_three_digits_bucket[i].empty())
		{
			Node<int>* node = first_three_digits_bucket[i].First();
			while (node)
			{
				ssn[pos++] = node->data;
				node = node->next;
			}
		}
		++i;
	}

	delete[] first_three_digits_bucket;

}

int main()
{
	int numbers[10] = { 111111111, 234543213, 298787536, 639383374, 212394213, 192837467, 812938745, 847920876, 908746573, 876418193 };
	bucketsort(numbers, 10);
	for (int i = 0; i < 10; ++i)
	{
		std::cout << numbers[i] << std::endl;
	}
}