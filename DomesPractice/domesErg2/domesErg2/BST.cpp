#include "pch.h"
#include <iostream>
#include "BST.h"

using namespace std;

BST::BST()
{
	root = 0;
}


BST::~BST()
{

}


BST& BST::insertNode(Node *n)
{
	Node *p = this->root;
	Node *pp = 0;

	while (p) {
		pp = p;
		if (n->data <= p->data) {
			p = p->leftChild;
		}
		else if (n->data > p->data) {
			p = p->rightChild;
		}
	}
	if (root) {
		if (n->data <= pp->data) {
			pp->leftChild = n;
		}
		else {
			pp->rightChild = n;
		}
	}
	else {
		this->root = n;
	}

	return *this;
}

int BST::BSTDepth(Node *n)
{
	if (!n) {
		return 0;
	}
	else {
		int leftDepth = BSTDepth(n->leftChild);
		int rightDepth = BSTDepth(n->rightChild);

		return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
	}
}

void BST::printPreorder(Node * n)
{
	if (n) {
		cout << n->data << " ";
		printPreorder(n->leftChild);
		printPreorder(n->rightChild);
	}
}


