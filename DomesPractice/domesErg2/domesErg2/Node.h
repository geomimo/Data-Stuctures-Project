#pragma once
#include "BST.h"


class Node
{
	
public:
	char data;
	Node *leftChild;
	Node *rightChild;


	Node();
	Node(const char data);
	~Node();
};

