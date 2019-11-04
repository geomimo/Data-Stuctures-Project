#pragma once
#include "Node.h"

class Node;

class BST
{
	
public:
	Node *root;

	BST();
	~BST();
	BST& insertNode(Node *n);
	int BSTDepth(Node *n);
	void printPreorder(Node *n);
};

