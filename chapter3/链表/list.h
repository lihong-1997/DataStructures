#ifndef _LIST_H
#define _LIST_H

struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode List;     // list header
typedef PtrToNode Position; // list element

List MakeEmpty();                         //创建表头
List LinkedListCreate();                  //尾插法建立链表
void DeleteList(List L);                  //删除链表
int IsEmpty(List L);                      //判断链表是否为空
int IsLast(Position p, List L);           //判断节点是否为链表末尾节点

Position Find(int X, List L);             //找到元素 X 所在节点的指针
Position FindKth(int K, List L);          //找到第 K 个节点的指针
Position FindPrevious(int X, List L);     //找到元素 X 所在节点的前一个节点的指针
void Delete(int X, List L);               //删除元素 X 所在节点
void Insert(int X, List L, Position p);   //从位置p后插入元素

int Length(List L);                       //链表长度
int Retrieve(Position p);                 //由指针获取元素值
int getIndex(Position p, List L);         //由指针获取索引值

void PrintList(List L);                   //打印链表

//Position Header(List L);
//Position First(List L);

#endif /* _LIST_H */
