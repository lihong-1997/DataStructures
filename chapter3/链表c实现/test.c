#include"list.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    List list = LinkedListCreate();  //2 4 3 6 9 7

    PrintList(list);
    printf("\n");
    PrintList_recursion(list);
    ////链表长度
    //int len = Length(list);
    //printf("list length: %d\n", len);

    //// 索引元素
    //int index = 5;
    //Position p = FindKth(index, list);
    //int elem = Retrieve(p);
    //printf("node value: %d\n", elem);

    ////查找元素
    //int num = 3;
    //Position p2 = Find(num, list);
    //Position p3 = FindPrevious(num, list);
    //int preElem = Retrieve(p3);
    //int re = getIndex(p2, list);
    //printf("node index: %d\npre node value: %d\n", re, preElem);

    ////删除元素
    //int deleteItem = 3;
    //Delete(deleteItem, list);
    //len = Length(list);
    //printf("list length: %d\n", len);
    //PrintList(list);
    //printf("\n");

    ////插入元素
    //int insertAfter = 2;
    //int insertValue = 11;
    //Position insertP = FindKth(insertAfter, list);
    //Insert(insertValue, list, insertP);

    //len = Length(list);
    //printf("list length: %d\n", len);
    //PrintList(list);
    //printf("\n");

    //DeleteList(list);
    //int IsEmp = IsEmpty(list);
    //printf("empty?: %d\n", IsEmp);
    //len = Length(list);
    //printf("list length: %d\n", len);

    return 0;
}