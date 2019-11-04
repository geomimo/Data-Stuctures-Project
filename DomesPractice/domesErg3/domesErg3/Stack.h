#pragma once
#include "Node.h"
class Stack
{
public:
	Node *top;

	Stack& insertNode(Node *n);
	Stack& copyStack();
	void print();
	Stack();
	~Stack();
};

