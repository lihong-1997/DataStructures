#include "polynomialList.h"

//���Ŷ�ַ��ֻ�ܲ�������ɾ�����ʱ��ÿ����Ԫ��Ҫ3��״̬
enum KindOfEntry {Legitimate, Empty};

struct HashEntry
{
    int coe;
	int exp;
    enum KindOfEntry Info;
};

typedef struct HashEntry Cell;

struct HashTbl
{
    int TableSize;
    Cell* TheCells;
};

std::istream& operator>>(std::istream &is, Polynomial &poly)
{
	int coe, exp;
	Node* p = poly.header;
	while (is >> coe >> exp && coe) //��������exp
	{
		p->Next = new Node(coe, exp);
		p = p->Next;
	}

	return is;
}

void CreatePoly(const std::vector<int>& v, Polynomial& poly)
{
	Node* p = poly.header;
	for (auto item = v.begin(); item != v.end(); item+=2)
	{
		poly.len++;
		p->Next = new Node(*item, *(item+1));
		p = p->Next;
	}
}

std::ostream& operator<<(std::ostream &os, const Polynomial &poly)
{
	Node* TmpNode = poly.header->Next; //��һ��NODE
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

// �ϲ�������������
Node* merge(Node* l1, Node* l2) {
    if (l1 == NULL) {
        return l2;
    }
    if (l2 == NULL) {
        return l1;
    }

    Node* merged = NULL;
    if (l1->exp > l2->exp) {
        merged = l1;
        merged->Next = merge(l1->Next, l2);
    } else {
        merged = l2;
        merged->Next = merge(l1, l2->Next);
    }

    return merged;
}

Node* sortList(Node* head)
{
	if (head == nullptr || head->Next == nullptr) return head;
	Node* slow = head;
	Node* fast = head->Next;
	while (fast != nullptr && fast->Next != nullptr) {
        slow = slow->Next;
        fast = fast->Next->Next;
    }
	Node* mid = slow->Next;
	slow->Next = nullptr;

	Node* left = sortList(head);
	Node* right = sortList(mid);

	return merge(left, right);
}

void PolySort(Polynomial& poly)
{
	poly.header->Next = sortList(poly.header->Next);
}
/*
 * �㷨ʱ�临�Ӷ�O(M+N),������������󲢼���˼·
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
			resultPoly.len++;
			poly1FirstNode = poly1FirstNode->Next; //����1ǰ��һ�ڵ�
			p = p->Next;
		}
		else if (poly1FirstNode->exp < poly2FirstNode->exp)
		{
			p->Next = new Node(poly2FirstNode->coe, poly2FirstNode->exp);
			resultPoly.len++;
			poly2FirstNode = poly2FirstNode->Next; //����2ǰ��һ�ڵ�
			p = p->Next;
		}
		else
		{
			int coeSum = poly1FirstNode->coe + poly2FirstNode->coe;
			//���ϵ���Ͳ�Ϊ 0���������ڵ�
			if (coeSum)
			{
				p->Next = new Node(coeSum, poly2FirstNode->exp);
				resultPoly.len++;
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
		resultPoly.len++;
		p = p->Next;
		tmpNode = tmpNode->Next;
	}
	return resultPoly;
}

/*
 * �㷨���Ӷ�:O(M^2*N)
 * ˼·��
 * (1)ÿ�ν�����ΪM�������һ��,����һ��������������,ÿ�����һ����N���ڵ�������Ķ���ʽ����,O(MN);
 * (2)�������������󲢵Ĳ������������������:
 * (3)O(N+N + 2N+N +...+ (M-1)N+N)=O(M^2*N)
 */
Polynomial operator*(const Polynomial &poly1, const Polynomial &poly2)
{
	Polynomial resultPoly;
	Node* poly1Node = poly1.header->Next, *poly2Node;
	
	while (poly1Node)
	{
		//ÿ��ѭ����������һ���м����ʽ
		Polynomial tmpPoly;
		Node* tmp = tmpPoly.header;
		//���¶�λ��poly2��һ��
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

/*
 * �㷨���Ӷ�:O(MN*log(MN))
 * ˼·��
 * (1)����Ԫ��������˲��г�,����MN������ʽ;
 * (2)��MN���ʽ��ָ������O(MN*logMN)������:
 * (3)�ϲ�ͬ�ݴ�����ȫ����������
 */
struct compare{
	bool operator()(const Node& node1, const Node& node2)
	{
		return node1.exp > node2.exp;
	}
}cmp_node;

Polynomial PolyMulti(const Polynomial& poly1, const Polynomial& poly2)
{
	Polynomial resultPoly;
	unsigned int MN = poly1.len * poly2.len;
	Node* temp_array = new Node[MN];

	Node* poly1Node = poly1.header->Next, *poly2Node, * tmp;
	int i = 0;
	while (poly1Node)
	{
		//��λ��poly2��һ��
		poly2Node = poly2.header->Next;
	
		while (poly2Node)
		{
			temp_array[i].coe = poly1Node->coe * poly2Node->coe;
			temp_array[i].exp = poly1Node->exp + poly2Node->exp;
			poly2Node = poly2Node->Next;
			++i;
		}
		poly1Node = poly1Node->Next;
	}

	// �Զ���sort�������򣬱Ƚ�Node�ṹ���exp��ͬʱ�������ͷ�巨��������
	std::sort(&temp_array[0], &temp_array[MN], cmp_node);
	Node* p = resultPoly.header;
	//�ϲ�������ָ��һ����Ԫ��
	for ( i = 1; i < MN; ++i)
	{
		if (temp_array[i].exp == temp_array[i - 1].exp)
			temp_array[i].coe = temp_array[i].coe + temp_array[i - 1].coe;
		else
		{
			if (temp_array[i - 1].coe != 0)
			{
				p->Next = new Node(temp_array[i - 1].coe, temp_array[i - 1].exp);
				p = p->Next;
				++(resultPoly.len);
			}
		}
	}
	p->Next = new Node(temp_array[MN - 1].coe, temp_array[MN - 1].exp);
	p = p->Next;
	++(resultPoly.len);

	delete[] temp_array;

	return resultPoly;
}

/*
 * �㷨���Ӷ�:O(MN)
 * ˼·��
 * (1)����Ԫ��������˲��г�,����MN������ʽ;
 * (2)MN���ʽɢ������ϣ����,����ʹ����������;
 * (3)������ϣ����������,���ɶ���������
 */
Polynomial PolyMultiHash(const Polynomial& poly1, const Polynomial& poly2)
{
	Polynomial resultPoly;
	unsigned int MN = poly1.len * poly2.len;
	HashTable H;
	H = InitializeTable(2 * MN, 1);

	Node* poly1Node = poly1.header->Next, *poly2Node, * tmp, *InsertNode;
	while (poly1Node)
	{
		//��λ��poly2��һ��
		poly2Node = poly2.header->Next;
	
		while (poly2Node)
		{
			// ����Hash����,����ʱ��ɺϲ�
			InsertSquare(poly1Node->coe * poly2Node->coe, poly1Node->exp + poly2Node->exp, H);
			poly2Node = poly2Node->Next;
		}
		poly1Node = poly1Node->Next;
	}

	Node* p = resultPoly.header;
	//������ϣ��,��ռλ״̬�ĵ�Ԫ���������
	for (size_t i = 0; i < H->TableSize; i++)
	{
		if (H->TheCells[i].Info == Legitimate)
		{
			resultPoly.len++;
			p->Next = new Node(H->TheCells[i].coe, H->TheCells[i].exp);
			p = p->Next;
		}
	}

	DestroyTable(H);
	PolySort(resultPoly);

	return resultPoly;
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
	header = nullptr;
	len = 0;
	while(p)
	{
		Node* tmp = p->Next;
		delete p;
		p = tmp;
	}
}

Polynomial& Polynomial::operator=(Polynomial poly)
{
	len = poly.len;
	std::swap(header, poly.header);
	return *this;
}

Polynomial& Polynomial::operator+=(const Polynomial &poly)
{
	*this = *this + poly;
	return *this;
}

Index Hash(int Key, int TableSize)
{
    return Key % TableSize;
}

HashTable InitializeTable(int TableSize, int FLAG)
{
    if (TableSize < MinTableSize)
    {
        Error("Table size too small");
        return NULL;
    }

    HashTable H;
    H = new HashTbl;
    if (H == NULL)
        FatalError("out of space");
    
    // �ж��費��Ҫ�Ա�Ĵ�С��ȡ��������
    H->TableSize = FLAG ? NextPrime(TableSize) : TableSize;

    H->TheCells = new Cell[H->TableSize];
    if (H == NULL)
        FatalError("out of space");
    // ��ʼ���յ�Ԫ
    for (int i = 0; i < H->TableSize; i++)
        H->TheCells[i].Info = Empty;

    return H;
}

void DestroyTable(HashTable H)
{
    free(H->TheCells);
    free(H);
}

Position FindSquare(int Exp, HashTable H)
{
    Position CurrentPos;
    CurrentPos = Hash(Exp, H->TableSize);
    int CollisionNum;
    CollisionNum = 0;

    //�˳�ѭ�����������ҵ���λ���ҵ�ָ����ȵĵ�Ԫ��
    while (H->TheCells[CurrentPos].Info != Empty && H->TheCells[CurrentPos].exp != Exp)
    {
        CurrentPos += 2 * (++CollisionNum) - 1;
        if (CurrentPos >= H->TableSize) 
            CurrentPos -= H->TableSize;
    }
    
    return CurrentPos;
}

void InsertSquare(int Coe, int Exp, HashTable H)
{
    Position P;
    P = FindSquare(Exp, H);
	//û�ҵ�������������
    if (H->TheCells[P].Info != Legitimate)
    {
        H->TheCells[P].coe = Coe;
		H->TheCells[P].exp = Exp;
        H->TheCells[P].Info = Legitimate;
    }
	//�ҵ�������ϵ�����
    else
        H->TheCells[P].coe += Coe;
}