#define _CRT_SECURE_NO_WARNINGS 1
#include"list.h"

List Intersect(List L1, List L2)
{
	List IntersectionList = MakeEmpty();
	Position EndNode = IntersectionList;

	Position L1Node = First(L1);
	Position L2Node = First(L2);
	int sameValue;
	while (L1Node && L2Node)
	{
		if (Retrieve(L1Node) < Retrieve(L2Node))
			L1Node = Advance(L1Node);
		else if (Retrieve(L2Node) < Retrieve(L1Node))
			L2Node = Advance(L2Node);
		else
		{
			sameValue = Retrieve(L1Node);
			Insert(sameValue, IntersectionList, EndNode);
			EndNode = Advance(EndNode);

			L1Node = Advance(L1Node);
			L2Node = Advance(L2Node);
		}
	}

	return IntersectionList;
}

int main6()
{
	int pArray[3] = { 3,4,6 };
	int lArray[7] = { 1,2,3,4,5,6,7 };
	List P = LinkedListCreateFromArray(pArray, 3);  //3 4 6
	List L = LinkedListCreateFromArray(lArray, 7);  //1 2 3 4 5 6 7

	List Intersection = Intersect(P, L);
	PrintList(Intersection);

	return 0;
}
