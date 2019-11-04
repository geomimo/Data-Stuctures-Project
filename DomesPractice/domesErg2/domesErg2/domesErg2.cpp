

#include "pch.h"
#include <iostream>
#include "Node.h"
#include "BST.h"
#include <string>
using namespace std;

BST* createBST();

int main()
{
	cout << "Theoro oti an eisax8ei xaraktiras pou yparxei idi sto dentro" << endl
		<< "tote topo8eto ton 2o sto aristero paidi tou yparxontos xaraktira." << endl
		<< "---------------------------------" << endl;
	string word = "PROCEDURE";
	BST *myBST = createBST();
	while (word.length() != 0) {
		Node *newNode = new Node(word.front());
		word.erase(0, 1);
		*myBST = myBST->insertNode(newNode);
	}
	
	cout << endl << "To dentro se prodiataxi." << endl;
	myBST->printPreorder(myBST->root);
	cout << endl;
	cout << "Megisto bathos dentrou: " << myBST->BSTDepth(myBST->root) << endl;
	
}

BST* createBST() {
	return new BST();
}