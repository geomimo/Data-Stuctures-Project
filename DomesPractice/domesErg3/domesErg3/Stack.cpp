#include "pch.h"
#include <iostream>
#include "Stack.h"
#include "Node.h"




Stack& Stack::insertNode(Node * n)
{
	if (this->top) {
		n->next = this->top;
	}
	else {
		n->next = 0;
	}
	this->top = n;
	return *this;
}

Stack& Stack::copyStack()
{
	Stack *newStackReversed = new Stack();
	Stack *newStack = new Stack();
	Node *currentTop = this->top;
	while (currentTop) {
		Node *copyNode = new Node(currentTop->data);
		newStackReversed->insertNode(copyNode);
		currentTop = currentTop->next;
	}
	
	currentTop = newStackReversed->top;
	while (currentTop) {
		Node *copyNode = new Node(currentTop->data);
		newStack->insertNode(copyNode);
		currentTop = currentTop->next;
	}

	return *newStack;
}

void Stack::print() {
	Node *currentTop = top;
	std::cout << "top-> ";
	while (currentTop) {
		std::cout << currentTop->data << " ";
		currentTop = currentTop->next;
		
	}
	std::cout << "\n";
}

Stack::Stack()
{
	this->top = 0;
}


Stack::~Stack()
{
}
