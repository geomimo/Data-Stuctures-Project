#pragma once
#include "BinTreeNode.h"
#include "Chain.h"
#include "ChainIterator.h"

/* ����� �������� �������. */

template<class T>
class BinTree {

public:
	BinTree() { root = 0; } //CONSTRUCTOR ��� ������������ �����. ��� ������� ����� ������.

	BinTreeNode<T>* Root() { //��������� �����.
		return root;
	}

	bool Search(int k, BinTreeNode<T>* e) const { //������ ������ �� ������ k ��� ��������� ��� ��� e.
		BinTreeNode<T> *p = root;
		while (p) {
			if (k < p->data) {
				p = p->LeftChild;
			}
			else if( k > p->data ){
				p = p->RightChild;
			}
			else {
				e = p;
				return true;
			}
		}
		return false;
	}

	void Insert(const T& e, Chain<T>& path) { //���������� ������ �� ������ e, ���������� ��� ������ ��� ����� ����		
		BinTreeNode<T> *p = root, *pp = 0;	  //��� ���������� ��� ��������� ������ �� �� �������� ��� �� ���� ����
		while (p) {							  //����������� �����.
			path.Insert(0, p->data);
			pp = p;
			if (e < p->data) {
				p = p->LeftChild;
			}
			else if (e > p->data) {
				p = p->RightChild;
			}
		}
		BinTreeNode<T> *r = new BinTreeNode<T>(e);
		if (root) {
			if (e < pp->data) {
				pp->LeftChild = r;
			}
			else {
				pp->RightChild = r;
			}
		}
		else {
			root = r;
		}
		path.Insert(0, e);
	}

	BinTree<T>& Insert(const T& e) {	//���������� ������ �� ������ e ��� ���������� ��� ������.
		BinTreeNode<T> *p = root, *pp = 0;
		while (p) {
			pp = p;
			if (e <= p->data) {
				p = p->LeftChild;
			}
			else if (e > p->data) {
				p = p->RightChild;
			}
		}
		BinTreeNode<T> *r = new BinTreeNode<T>(e);
		if (root) {
			if (e < pp->data) {
				pp->LeftChild = r;
			}
			else {
				pp->RightChild = r;
			}
		}
		else {
			root = r;
		}
		return *this;
	}


	BinTree<T>& Delete(const T& k, T& e) {//������ ������ �� ������ e � ������ ��� �������� ����������� ��� ���������
		BinTreeNode<T> *p = root, *pp = 0;//�������� ���� ��� e.
		while (p && p->data != k) {
			pp = p;
			if (k < p->data) {
				p = p->LeftChild;
			}
			else {
				p = p->RightChild;
			}
		}
		e = p ->data;
		if (p->LeftChild && p->RightChild) {
			BinTreeNode<T> *s = p->LeftChild, *ps = p;
			while (s->RightChild) {
				ps = s;
				s = s->RightChild;
			}
			p->data = s->data;
			p = s;
			pp = ps;
		}
		BinTreeNode<T> *c;
		if (p->LeftChild) {
			c = p->LeftChild;
		}
		else {
			c = p->RightChild;
		}
		if (p == root) {
			root = c;
		}
		else {
			if (p == pp->LeftChild) {
				pp->LeftChild = c;
			}
			else {
				pp->RightChild = c;
			}
		}
		delete p;
		return *this;
	}	

	int Height(BinTreeNode<T> *t) const {//��������� ����� ��� ���������� �� ���� t.
		if (!t) {
			return 1;
		}
		int h1 = Height(t->LeftChild);
		int h2 = Height(t->RightChild);
		return h1 > h2 ? (++h1) : (++h2);
	}

	int Depth(int k) const {//��������� ������ ��� ������ �� ������ k.
		BinTreeNode<T> *p = root;
		int i = 1;
		while (p->data != k) {
			if (p->data < k) {
				p = p->RightChild;
			}
			else if (p->data > k) {
				p = p->LeftChild;
			}
			i++;
		}
		return i;
	}

	void PreOrder(BinTreeNode<T> *t) {//�������� ������� �� ����������.
		if (t) {
			cout << t->data << " ";
			PreOrder(t->LeftChild);
			PreOrder(t->RightChild);
		}
	}

	void PostOrder(BinTreeNode<T> *t) {//�������� ������� �� �����������.
		if (t) { 
			PostOrder(t->LeftChild); 
			PostOrder(t->RightChild); 
			cout << t->data << " ";
		}
	}

	void InOrder(BinTreeNode<T> *t) {//�������� ������� �� �����������.
		if (t) {
			InOrder(t->LeftChild);
			cout << t->data << " ";
			InOrder(t->RightChild);
		}
	}

	void InOrder(BinTreeNode<T> *t, Chain<T>& chain) {//���������� �������� ��� ������ ��� ���������� �� ����� t ����  
		if (t) {									 // ����� chain �� �����������. ���� ��� ����� ��� �������� ������� ��� ���	
			InOrder(t->LeftChild,chain);			 // ��� ���	�����������, �� ������� ������������� �� ������� �����.
			chain.Append(t->data);
			InOrder(t->RightChild,chain);
		}
	}
	
	void Delete(BinTreeNode<T> *t) {//�������� ���� ��� ������ ��� ���������� �� ���� t.
		if (t) {
			Delete(t->LeftChild);
			Delete(t->RightChild);
			delete t;
		}
	}

	int Count(int k) {//��������� ��� ������� ��� ������ ��� ��������� �� ���� ��� ����� �� ������ k.
		int i = 1;
		BinTreeNode<T> *s = 0;
		bool f = Search(k, s);
		if (s) {
			Count((s->LeftChild)->data);
			Count((s->RightChild)->data);
			i++;
		}
		return i;
	}

	void Rebuild(BinTreeNode<T> *r) {//������������ ���������� �� ���� �� r. ��������������� ��� ����� allNodes ���
		Chain<T> allNodes;			// �������� ����� ���� ������� ��� ���������� �� ���� �� r �� ������� �����(!)
		this->InOrder(r, allNodes);	// ��� ������������ �� ��������� ����, ������������� ��� ��� ��������� �� �� �������� ���� ��� 
		int mid = (int)((allNodes.Length())/ 2); //�������� ���� ��� ������������ ��� ������ ������.
		BinTree<T> newTree;
		int newKey=0;
		while (allNodes.Length()>0) {//���������� ���� ���� �� ������ ��� ��������� ��� ���� ��� ������, ��� ������������
			allNodes.Delete(mid,newKey);//��� ��� ���������, ������������� � ���������� ���� �������������� �������
			BinTreeNode<T> *newNode = new BinTreeNode<T>(newKey);
			newTree.Insert(newNode->data);
			mid = (int)(ceil((allNodes.Length() - 1) / 2));
		}
		BinTreeNode<T> *p = this->root, *pp = 0;
		while (p) {//������ ��� ������ ���� �� ������������ �� ��� ���������.
			pp = p;
			if (r->data < p->data) {
				p = p->LeftChild;
			}
			else if (r->data > p->data) {
				p = p->RightChild;
			}
			else {
				break;
			}
		}
		if (p == root) {
			this->root = newTree.Root();
		}
		this->Delete(p);//�������� ����������� ���������� ��� ���������� ����.
		if (newTree.Root()->data <= pp->data) {
			pp->LeftChild = newTree.Root();
		}
		else if(newTree.Root()->data > pp->data) {
			pp->RightChild = newTree.Root();
		}
	}
	
 private:
	BinTreeNode<T> *root; // ���� �������
};