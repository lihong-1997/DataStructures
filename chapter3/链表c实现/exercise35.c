#define _CRT_SECURE_NO_WARNINGS 1
#include"list.h"

List Union(List L1, List L2)
{
	List UnionList = MakeEmpty();
	Position EndNode = UnionList;

	Position L1Node = First(L1);
	Position L2Node = First(L2);

	Position tmpNode;
	int sameValue, differValue;
	while (L1Node && L2Node)
	{
		if (Retrieve(L1Node) < Retrieve(L2Node))
		{
			differValue = Retrieve(L1Node);
			Insert(differValue, UnionList, EndNode);
			L1Node = Advance(L1Node);
		}
		else if (Retrieve(L2Node) < Retrieve(L1Node))
		{
			differValue = Retrieve(L2Node);
			Insert(differValue, UnionList, EndNode);
			L2Node = Advance(L2Node);
		}
		else
		{
			sameValue = Retrieve(L1Node);
			Insert(sameValue, UnionList, EndNode);
			L1Node = Advance(L1Node);
			L2Node = Advance(L2Node);
		}
		EndNode = Advance(EndNode);
	}
	
	tmpNode = L1Node ? L1Node : L2Node;
	while (tmpNode)
	{
		differValue = Retrieve(tmpNode);
		Insert(differValue, UnionList, EndNode);
		EndNode = Advance(EndNode);
		tmpNode = Advance(tmpNode);
	}

	return UnionList;
}

int main11()
{
	int pArray[5] = { 0,3,4,6,9 };
	int lArray[7] = { 1,2,3,4,5,6,7 };
	List P = LinkedListCreateFromArray(pArray, 5);  //0 3 4 6 9
	List L = LinkedListCreateFromArray(lArray, 7);  //1 2 3 4 5 6 7

	List UnionList = Union(P, L);
	PrintList(UnionList);

	return 0;
}
