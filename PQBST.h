#pragma once
#include "Human.h"
struct Node
{
	Human info;
	Node * left;
	Node * right;
	Node() { left = nullptr, right = nullptr;  }
	Node(Human value): info(value), left(nullptr), right(nullptr){}
	Node(Human value, Node* left, Node* right) : info(value), left(left), right(right) {}
	Node& operator=(const Node& n)
	{
		info = n.info;
		left = n.left;
		right = n.right;

		return *this;
	}

	Human getInfo() const { return info; }
	Node* getLeft() { return left; }
	Node* getRight() { return right;  }
	~Node() { };
};

class PQBST
{
private:
	Node * root;
	int m; //spaceship size - given by the user

public:
	PQBST() { root = nullptr; }
	PQBST(int m) : root(nullptr), m(m) {}
	PQBST(Node* root, int m);
	~PQBST();
	int getM() const { return m; }
	Node* getRoot() const { return root; }
	void setM(int m);
	void push(Human);
//	void push(Human, Node *);
	Human pop();
//	Human pop(Node * node, Node * parent);
	void destroy();
	void destroy(Node * node);
	bool isEmpty() const;
	bool isFull();
	Human top();
private:
	Human pop(Node * node, Node * parent);
	void push(Human, Node *);
};