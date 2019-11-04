#pragma once
#include "BinTreeNode.h"
#include "Chain.h"
#include "ChainIterator.h"

/* йкасг дуадийоу демтяоу. */

template<class T>
class BinTree {

public:
	BinTree() { root = 0; } //CONSTRUCTOR йаи аявийопоигсг яифас. дем упаявеи айола йолбос.

	BinTreeNode<T>* Root() { //епистяосг яифас.
		return root;
	}

	bool Search(int k, BinTreeNode<T>* e) const { //еуяесг йолбоу ле йкеидг k йаи епистяожг тоу сто e.
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

	void Insert(const T& e, Chain<T>& path) { //дглиоуяциа йолбоу ле йкеиди e, топохетгсг сто демтяо стг сыстг хесг		
		BinTreeNode<T> *p = root, *pp = 0;	  //йаи дглиоуяциа йаи епистяожг кистас ле то ломопати апо тг яифа стом
		while (p) {							  //меоеисавхем йолбо.
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

	BinTree<T>& Insert(const T& e) {	//дглиоуяциа йолбоу ле йкеиди e йаи топохетгсг сто демтяо.
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


	BinTree<T>& Delete(const T& k, T& e) {//еуяесг йолбоу ле йкеиди e о опоиос стг сумевеиа диацяажетаи йаи епистяожг
		BinTreeNode<T> *p = root, *pp = 0;//йкеидиоу лесы тоу e.
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

	int Height(BinTreeNode<T> *t) const {//епистяожг уьоус тоу уподемтяоу ле яифа t.
		if (!t) {
			return 1;
		}
		int h1 = Height(t->LeftChild);
		int h2 = Height(t->RightChild);
		return h1 > h2 ? (++h1) : (++h2);
	}

	int Depth(int k) const {//епистяожг бахоус тоу йолбоу ле йкеиди k.
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

	void PreOrder(BinTreeNode<T> *t) {//ейтупысг демтяоу се пяодиатанг.
		if (t) {
			cout << t->data << " ";
			PreOrder(t->LeftChild);
			PreOrder(t->RightChild);
		}
	}

	void PostOrder(BinTreeNode<T> *t) {//ейтупысг демтяоу се летадиатанг.
		if (t) { 
			PostOrder(t->LeftChild); 
			PostOrder(t->RightChild); 
			cout << t->data << " ";
		}
	}

	void InOrder(BinTreeNode<T> *t) {//ейтупысг демтяоу се емдодиатанг.
		if (t) {
			InOrder(t->LeftChild);
			cout << t->data << " ";
			InOrder(t->RightChild);
		}
	}

	void InOrder(BinTreeNode<T> *t, Chain<T>& chain) {//топохетгсг йкеидиым тым йолбым тоу уподемтяоу ле йолбо t стгм  
		if (t) {									 // киста chain се емдодиатанг. коцы тгс жусгс тоу дуадийоу демтяоу йаи тгм	
			InOrder(t->LeftChild,chain);			 // йаи тгм	емдодиатанг, та йкеидиа топохетоумтаи се ауноуса сеияа.
			chain.Append(t->data);
			InOrder(t->RightChild,chain);
		}
	}
	
	void Delete(BinTreeNode<T> *t) {//диацяажг окым том йолбым тоу уподемтяоу ле яифа t.
		if (t) {
			Delete(t->LeftChild);
			Delete(t->RightChild);
			delete t;
		}
	}

	int Count(int k) {//епистяожг тоу пкгхоус тым йолбым сто уподемтяо ле яифа том йолбо ле йкеиди k.
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

	void Rebuild(BinTreeNode<T> *r) {//амайатасйеуг уподемтяоу ле яифа то r. вягсилопоиымтас тгм киста allNodes поу
		Chain<T> allNodes;			// пеяиевеи окоус тоус йолбоус тоу уподемтяоу ле яифа то r се ауноуса сеияа(!)
		this->InOrder(r, allNodes);	// йаи диацяажомтас то уподемтяо ауто, дглиоуяцеитаи ема мео уподемтяо ле то екависто уьос йаи 
		int mid = (int)((allNodes.Length())/ 2); //екависто уьос йаи топохетеитаи сто аявийо демтяо.
		BinTree<T> newTree;
		int newKey=0;
		while (allNodes.Length()>0) {//паиямомтас йахе жояа то йкеиди поу бяисйетаи стг лесг тгс кистас, йаи топохетымтас
			allNodes.Delete(mid,newKey);//сто мео уподемтяо, епитуцваметаи г дглиоуяциа емос исояяопоилемоу демтяоу
			BinTreeNode<T> *newNode = new BinTreeNode<T>(newKey);
			newTree.Insert(newNode->data);
			mid = (int)(ceil((allNodes.Length() - 1) / 2));
		}
		BinTreeNode<T> *p = this->root, *pp = 0;
		while (p) {//еуяесг тоу йолбоу опоу ха топохетеихеи то мео уподемтяо.
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
		this->Delete(p);//диацяажг амисояяопоу уподемтяоу йаи топохетгсг меоу.
		if (newTree.Root()->data <= pp->data) {
			pp->LeftChild = newTree.Root();
		}
		else if(newTree.Root()->data > pp->data) {
			pp->RightChild = newTree.Root();
		}
	}
	
 private:
	BinTreeNode<T> *root; // яифа демтяоу
};