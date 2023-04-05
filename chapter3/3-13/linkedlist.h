#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>

namespace linkedlist
{
	// 链表节点模板
	template <typename T>
	struct Node
	{
		Node<T>() : data(0), next(nullptr) {}
		Node<T>(const T& data_) : data(data_), next(nullptr) {}
		T data;
		Node<T>* next;
	};
	// 链表模板
	template <typename T>
	class List
	{
	public:
		List<T>();
		~List<T>();
	public:
		bool empty() const { return length == 0; }
		size_t size() const { return length; } //返回链表长度

		Node<T>* Header() const { return header; } //返回链表表头
		Node<T>* First() const { return header->next; } //返回头节点
		bool IsLast(Node<T>* positon) const;

		void Insert(T value, Node<T>* positon); //指定位置插入元素
		void Insert(T value); //链表尾部插入元素
		Node<T>* Find(T value) const; //迭代查找指定元素
		Node<T>* Find_recursive(T value) const; //递归查找指定元素
		Node<T>* Find_Kth(size_t K) const;
		Node<T>* Find_pre(T value) const;
		void Remove(T value); //删除指定元素

		void Traverse() const; //遍历并输出链表元素
		Node<T>* Advance(Node<T>* node) const; //前进一节点

		void Reverse(); //反转链表
		T Retrieve(Node<T>* node);

		void DeleteList(); //删除列表

	private:
		Node<T>* Find_re(T value, Node<T>* pos) const; //递归查找指定元素
		Node<T>* header;
		size_t length;
	};

	template<typename T>
	List<T>::List()
	{
		length = 0;
		header = new Node<T>();
	}
	template<typename T>
	List<T>::~List()
	{
		Node<T>* node = header->next;
		Node<T>* temp;
		header->next = nullptr;
		while (node != nullptr)
		{
			temp = node->next;
			delete node;
			node = temp;
		}
		length = 0;
	}
	template<typename T>
	void List<T>::Insert(T value)
	{
		Node<T>* pnew = new Node<T>(value);
		if (length == 0) header->next = pnew;
		else
		{
			Node<T>* node = header->next; //链表第一个节点
			while (node->next != nullptr)
				node = node->next;
			node->next = pnew;
		}

		++length;
	}

	template<typename T>
	Node<T>* List<T>::Find(T value) const
	{
		Node<T>* node = header->next;
		while (node != nullptr && node->data != value)
			node = node->next;

		return node;
	}

	template<typename T>
	Node<T>* List<T>::Find_recursive(T value) const
	{
		return Find_re(value, header->next);
	}

	template<typename T>
	Node<T>* List<T>::Find_re(T value, Node<T>* pos) const
	{
		if (pos == nullptr || pos->data == value)
			return pos;

		return Find_re(value, pos->next);
	}

	template<typename T>
	Node<T>* List<T>::Find_Kth(size_t K) const
	{
		if (K > length)
			return nullptr;
		size_t i = 1;
		Node<T>* node = header->next;
		while (i++ != K)
			node = node->next;
		return node;
	}

	template<typename T>
	Node<T>* List<T>::Find_pre(T value) const
	{
		Node<T>* node = header;
		while (node->next != nullptr && node->next->data != value)
			node = node->next;

		return node;
	}

	template<typename T>
	void List<T>::Remove(T value)
	{
		Node<T>* preNode = Find_pre(value);
		if (preNode == nullptr)
			return;
		Node<T>* temp = preNode->next;
		preNode->next = temp->next;
		delete temp;
		--length;
	}

	template<typename T>
	bool List<T>::IsLast(Node<T>* positon) const
	{
		return positon->next == nullptr;
	}

	template<typename T>
	void List<T>::Insert(T value, Node<T>* positon)
	{
		Node<T>* pnew = new Node<T>(value);
		pnew->next = positon->next;
		positon->next = pnew;
		++length;
	}

	template <typename T>
	void List<T>::Traverse() const
	{
		Node<T>* node = header->next;
		while (node != nullptr)
		{
			std::cout << node->data << " ";
			node = node->next;
		}
		std::cout << std::endl;
	}

	template<typename T>
	Node<T>* List<T>::Advance(Node<T>* node) const
	{
		return node->next;
	}

	template<typename T>
	void List<T>::Reverse()
	{
		Node<T>* PreNode = header;
		//交换的块，由两个标志位组成
		Node<T>* BeginFlag = header->next;
		Node<T>* EndFlag = header->next;
		//交换的节点
		Node<T>* SwapNode = EndFlag->next;

		while (SwapNode)
		{
			PreNode->next = SwapNode;
			EndFlag->next = SwapNode->next;
			SwapNode->next = BeginFlag;

			BeginFlag = header->next; //更新begin标志位
			SwapNode = EndFlag->next; //更新下一个要交换的节点
		}
	}

	template<typename T>
	T List<T>::Retrieve(Node<T>* node)
	{
		return node->data;
	}

	template<typename T>
	void List<T>::DeleteList()
	{
		Node<T>* node = header->next;
		Node<T>* temp;
		header->next = nullptr;
		while (node != nullptr)
		{
			temp = node->next;
			delete node;
			node = temp;
		}
		length = 0;
	}

}

#endif
