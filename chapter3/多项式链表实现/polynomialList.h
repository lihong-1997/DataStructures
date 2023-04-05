#ifndef _POLYNOMIALLIST_H
#define _POLYNOMIALLIST_H
#include <iostream>
/*
 * 只实现链表创建
 */
struct Node
{
	int coe;
	int exp;
	Node* Next;

	Node() :coe(0), exp(0), Next(nullptr){}
	Node(int coe_, int exp_) :coe(coe_), exp(exp_), Next(nullptr) {}
};

class Polynomial {
	friend std::istream& operator>>(std::istream&, Polynomial&);
	friend std::ostream& operator<<(std::ostream&, const Polynomial&);
	friend Polynomial operator+(const Polynomial&, const Polynomial&);
	friend Polynomial operator*(const Polynomial&, const Polynomial&);
	friend Polynomial polypower(const Polynomial&, unsigned);
	friend Polynomial polypower2(const Polynomial&, unsigned);
public:
	Polynomial() = default;
	Polynomial(const Polynomial&);
    ~Polynomial();
	Polynomial& operator=(Polynomial);
	Polynomial& operator+=(const Polynomial&);
	//Polynomial& operator*=(const Polynomial&);

private:
	Node* header = new Node; //header
};


#endif /* _LIST_H */
