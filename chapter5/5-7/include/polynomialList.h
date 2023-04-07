#ifndef _POLYNOMIALLIST_H
#define _POLYNOMIALLIST_H
#include <iostream>
#include <vector>
#include <algorithm>
#include "prime.h"

#define Error( str ) FatalError( str )
#define FatalError( str ) fprintf(stderr, "%s\n", str), exit(1)

#define MinTableSize 5

typedef unsigned int Index;
typedef Index Position;

struct HashTbl;
typedef struct HashTbl* HashTable;

struct Node
{
	int coe;
	int exp;
	Node* Next;

	Node() :coe(0), exp(0), Next(nullptr){}
	Node(int coe_, int exp_) :coe(coe_), exp(exp_), Next(nullptr) {}
};

typedef Node ElementType;

class Polynomial {
	friend std::istream& operator>>(std::istream&, Polynomial&);
	friend std::ostream& operator<<(std::ostream&, const Polynomial&);
	friend Polynomial operator+(const Polynomial&, const Polynomial&);
	friend Polynomial PolyMulti(const Polynomial&, const Polynomial&);
	friend Polynomial PolyMultiHash(const Polynomial&, const Polynomial&);
	friend Polynomial operator*(const Polynomial&, const Polynomial&);
	friend void CreatePoly(const std::vector<int>&, Polynomial&);
	friend void PolySort(Polynomial&);

public:
	Polynomial(): header(new Node), len(0) {};
	Polynomial(const Polynomial&);
    ~Polynomial();
	Polynomial& operator=(Polynomial);
	Polynomial& operator+=(const Polynomial&);
	unsigned int Size() {return len;}
	//Polynomial& operator*=(const Polynomial&);

private:
	Node* header; //header
	unsigned int len;
};

Index Hash(ElementType Key, int TableSize);
HashTable InitializeTable(int TableSize, int FLAG);
void DestroyTable(HashTable H);
Position FindSquare(int Exp, HashTable H);
void InsertSquare(int Coe, int Exp, HashTable H);
























#endif /* _LIST_H */
