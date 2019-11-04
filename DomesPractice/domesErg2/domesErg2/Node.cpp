#include "pch.h"
#include "Node.h"


Node::Node()
{
	rightChild = leftChild = 0;
}


Node::Node(const char data) 
{
	this->data = data;
}

Node::~Node()
{
}
