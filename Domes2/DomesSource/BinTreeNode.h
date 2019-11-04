#pragma once
#include "BinTree.h"

/* ������ ��� �������� ������� �� 2 CONSTRUCTORS */

template<class T>
class BinTree;

template<class T>
class BinTreeNode {
	friend BinTree<T>;

public: 
	BinTreeNode() { LeftChild = RightChild = 0; } // �������� ����� ��� ����� ��� ������������ �������.
	BinTreeNode(const T& e) { // �������� ����� ��� ����� ��� ������������ �������� ��� �������.
		data = e; 
		LeftChild = RightChild = 0; 
	} 
	
	T data; //������ ������.
 
private:

	BinTreeNode<T> *LeftChild, *RightChild; //������� ���� �������� ��� ���� �����.
		
};