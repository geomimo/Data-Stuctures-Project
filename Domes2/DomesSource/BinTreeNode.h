#pragma once
#include "BinTree.h"

/* йолбос тоу дуадийоу демтяоу ле 2 CONSTRUCTORS */

template<class T>
class BinTree;

template<class T>
class BinTreeNode {
	friend BinTree<T>;

public: 
	BinTreeNode() { LeftChild = RightChild = 0; } // деслеусг выяоу циа йолбо йаи аявийопоигсг деийтым.
	BinTreeNode(const T& e) { // деслеусг выяоу циа йолбо йаи аявийопоигсг йкеидиоу йаи деийтым.
		data = e; 
		LeftChild = RightChild = 0; 
	} 
	
	T data; //йкеиди йолбоу.
 
private:

	BinTreeNode<T> *LeftChild, *RightChild; //деийтес стом аяистеяо йаи дени йолбо.
		
};