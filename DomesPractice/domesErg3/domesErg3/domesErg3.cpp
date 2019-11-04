
#include "pch.h"
#include <iostream>

#include "Stack.h"
#include "Node.h"


int main()
{
	std::cout << "Hello World!\n";
	int nums[5] = { 1, 2, 3, 4, 5 };
	Stack *myStack = new Stack();
	for (int i = 0; i < 5; i++) {
		Node *n = new Node(nums[i]);
		myStack->insertNode(n);
	}
	std::cout << "myStack (" << myStack << "): ";
	myStack->print();

	Stack newStack = myStack->copyStack();
	std::cout << "newStack (" << &newStack << "): ";
	newStack.print();
}

