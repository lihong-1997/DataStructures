#include "polynomialList.h"

#include <algorithm>

std::istream& operator>>(std::istream &is, Polynomial &poly)
{
	int coe, exp;
	Node* p = poly.header;
	while (is >> coe >> exp && coe) //降序输入exp
	{
		p->Next = new Node(coe, exp);
		p = p->Next;
	}

	return is;
}

std::ostream& operator<<(std::ostream &os, const Polynomial &poly)
{
	Node* TmpNode = poly.header->Next; //第一个NODE
	while (TmpNode)
	{
		if (TmpNode->exp == 0)
			os << TmpNode->coe;
		else
			os << TmpNode->coe << "x^" << TmpNode->exp;

		if (TmpNode->Next && TmpNode->Next->coe > 0)
			os << "+";

		TmpNode = TmpNode->Next;
	}

	return os;
}
/*
 * 算法时间复杂度O(M+N),已排序的链表求并集的思路
 */
Polynomial operator+(const Polynomial &poly1, const Polynomial &poly2)
{
	Polynomial resultPoly;
	Node* p = resultPoly.header;
	Node* poly1FirstNode = poly1.header->Next;
	Node* poly2FirstNode = poly2.header->Next;

	while (poly1FirstNode && poly2FirstNode)
	{
		if (poly1FirstNode->exp > poly2FirstNode->exp)
		{
			p->Next = new Node(poly1FirstNode->coe, poly1FirstNode->exp);
			poly1FirstNode = poly1FirstNode->Next; //链表1前进一节点
			p = p->Next;
		}
		else if (poly1FirstNode->exp < poly2FirstNode->exp)
		{
			p->Next = new Node(poly2FirstNode->coe, poly2FirstNode->exp);
			poly2FirstNode = poly2FirstNode->Next; //链表2前进一节点
			p = p->Next;
		}
		else
		{
			int coeSum = poly1FirstNode->coe + poly2FirstNode->coe;
			//如果系数和不为 0，则新增节点
			if (coeSum)
			{
				p->Next = new Node(coeSum, poly2FirstNode->exp);
				p = p->Next;
			}
			poly1FirstNode = poly1FirstNode->Next;
			poly2FirstNode = poly2FirstNode->Next;
		}
	}
	Node* tmpNode = poly1FirstNode ? poly1FirstNode : poly2FirstNode;
	while (tmpNode)
	{
		p->Next = new Node(tmpNode->coe, tmpNode->exp);
		p = p->Next;
		tmpNode = tmpNode->Next;
	}
	return resultPoly;
}

/*
 * 假设poly1 M 项，poly2 N 项，M<N
 * 算法复杂度:O(M^2*N^2)
 * 思路：
 * (1)链表元素两两相乘并列出,产生MN个单项式;
 * (2)从第一项开始依次与其后项比较，指数相等则合并(O(M^2*N^2));
 * (3)按幂次插入链表
 *
 *
 * 算法复杂度:O(M^2*N)
 * 思路：
 * (1)每次将长度为M的链表的一项,与另一链表的所有项相乘,每次组成一个有N个节点且有序的多项式链表,O(MN);
 * (2)利用有序链表求并的操作，对两两链表求和:
 * (3)O(N+N + 2N+N +...+ (M-1)N+N)=O(M^2*N)
 *
 *
 * 算法复杂度:O(MN*log(MN))
 * 思路：
 * (1)链表元素两两相乘并列出,产生MN个单项式;
 * (2)对MN项单项式的指数进行O(MN*logMN)的排序:
 * (3)合并同幂次项，最后全部插入链表
 */
Polynomial operator*(const Polynomial &poly1, const Polynomial &poly2)
{
	Polynomial resultPoly;
	Node* poly1Node = poly1.header->Next, *poly2Node;
	
	while (poly1Node)
	{
		//每次循环重新生成一个中间多项式
		Polynomial tmpPoly;
		Node* tmp = tmpPoly.header;
		//重新定位到poly2第一项
		poly2Node = poly2.header->Next; 
		while (poly2Node)
		{
			tmp->Next = new Node(poly1Node->coe * poly2Node->coe,
				               poly1Node->exp + poly2Node->exp);
			tmp = tmp->Next;
			poly2Node = poly2Node->Next;
		}
		resultPoly += tmpPoly;
		poly1Node = poly1Node->Next;
	}

	return resultPoly;
}

Polynomial polypower(const Polynomial &poly, unsigned times)
{
	Polynomial result;
	Node* tmp = result.header;
	if (times == 0)
	{
		tmp->Next = new Node(1, 0);
		return result;
	}
	else if(times == 1)
	{
		return poly;
	}
	
	
	else if(times % 2 == 0)
	{
		return polypower(poly, times / 2) * polypower(poly, times / 2);
	}
	else if (times % 2 != 0)
	{
		return polypower(poly, times / 2) * polypower(poly, times / 2) * poly;
	}

}

Polynomial polypower2(const Polynomial& poly, unsigned times)
{
	Polynomial result;
	Node* tmp = result.header;
	if (times == 0)
	{
		tmp->Next = new Node(1, 0);
		return result;
	}

	if (times % 2 == 0)
	{
		return polypower(poly * poly, times / 2);
	}
	else if (times % 2 != 0)
	{
		return polypower(poly * poly, times / 2) * poly;
	}
}

Polynomial::Polynomial(const Polynomial &poly)
{
	Node* Src = poly.header->Next;
	Node* Dst = header;
	while (Src)
	{
		Dst->Next = new Node(Src->coe, Src->exp);
		Dst = Dst->Next;
		Src = Src->Next;
	}
}

Polynomial::~Polynomial()
{
	Node* p = header->Next;
	header->Next = nullptr;
	delete header;
	while(p)
	{
		Node* tmp = p->Next;
		delete p;
		p = tmp;
	}
}

Polynomial& Polynomial::operator=(Polynomial poly)
{
	std::swap(header, poly.header);
	return *this;
}

Polynomial& Polynomial::operator+=(const Polynomial &poly)
{
	*this = *this + poly;
	return *this;
}
