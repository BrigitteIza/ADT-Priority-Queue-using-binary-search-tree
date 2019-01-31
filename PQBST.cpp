#include "PQBST.h"
#include <iostream>

using namespace std;

PQBST::PQBST(Node * root, int m)
{
	this->root = root;
	this->m = m;
}

PQBST::~PQBST()
{
	destroy();
}

void PQBST::setM(int m)
{
	this->m = m;
}

void PQBST::push(Human value)
{
	if (root == nullptr)
	{
		root = new Node(value);
	}
	else
	{
		push(value, root);
	}
}

void PQBST::push(Human value, Node* node)
{ 
	if (value < node->info)
	{
		if (node->left != NULL)
		{
			push(value, node->left);
		}
		else
		{
			node->left = new Node(value);
		}
	}
	else
	{
		if (node->right != NULL)
		{
			push(value, node->right);
		}
		else
		{
			node->right = new Node(value);
		}
	}

}

Human PQBST::pop()
{
	Human value;
	if (root != nullptr)
	{
		if (root->right != nullptr)
		{
			value = pop(root->right, root);
		}
		else
		{
			value = root->info;
			if (root->left != nullptr)
			{
				Node * temp = root;
				root = root->left;
				delete temp;
			}
			else
			{
				delete root;
				root = nullptr;
			}
		}
	}
	else
	{
		throw "PQBST is empty!";
	}
	return value;
}

Human PQBST::pop(Node * node, Node * parent)
{
	Human value;
	if (node->right != nullptr)
	{
		value = pop(node->right, node);
	} 
	else
	{
		value = node->info;
		if (node->left != nullptr)
		{
			parent->right = node->left;
		}
		else
		{
			parent->right = nullptr;
		}
		delete node;
	}
	return value;
}


inline void PQBST::destroy()
{
	if (root)
		destroy(root);
}

void PQBST::destroy(Node* node)
{
	if (!node) return;
	destroy(node->left);
	destroy(node->right);
	delete node;
	node = nullptr;
}

bool PQBST::isEmpty() const
{
	return (root == nullptr);
}

bool PQBST::isFull()
{
	return false;
}


Human PQBST::top()
{
	if (root == nullptr)
		throw ("The PQBST is empty");
	else
	{
		Node* currentNode = root;
		while (currentNode->right != nullptr)
		{
			currentNode = currentNode->right;
		}
		return currentNode->info;
	}
}
