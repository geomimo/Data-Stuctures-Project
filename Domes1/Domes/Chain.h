#pragma once
#include "stdafx.h"
#include "ChainNode.h"
#include "ChainIterator.h"


template<class T>
class ChainNode;

template<class T>
class Chain
{
friend ChainIterator<T>;
public:

	Chain() {	//CONSTRUCTOR
		first = 0;
	}

	Chain(const Chain<T>& x) {	//COPY CONSTRUCTOR
		ChainNode<T> *p1 = 0;
		ChainNode<T> *p2 = 0;
		if (x.first == 0) {
			first = 0;
		}
		else {
			first = new ChainNode<T>;
			first->data = x.first->data;
			first->link = x.first->link;

			p1 = first;
			p2 = x.first->link;
		}
		while (p2) {
			p1->link = new ChainNode<T>;
			p1 = p1->link;
			p1->data = p2->data;
			p2 = p2->link;
		}
		p1->link = 0;
	}
	~Chain() {	//DESTRUCTOR
		ChainNode<T> *next;
		while (first) {
			next = first->link;
			delete first;
			first = next;
		}
	}

	Chain<T>& Append(const T& x) {	//пяосхгйг стоивеиоу x сто текос тгс кистас
		ChainNode<T> *y = new ChainNode<T>;
		y->data = x;
		y->link = 0;
		if (first) {
			last->link = y;
			last = y;
		}
		else {
			first = last = y;
		}
		return *this;

	}
	int Length() const {	//епистяожг лгйоус кистас
		ChainNode<T> *current = first;
		int len = 0;
		while (current) {
			len++;
			current = current->link;
		}
		return len;
	}

	Chain<T>& Delete(int k, T& x) {	//диацяажг K-остоу стоивеиоу апо киста йаи апохгйеусг тоу сто x
		ChainNode<T> *p = first;
		if (k == 1) {
			first = first->link;
		}
		else {
			ChainNode<T> *q = first;
			for (int index = 1; index < k - 1 && q; index++) {
				q = q->link;
			}
			p = q->link;
			if (p == last) {
				last = q;
			}
			q->link = p->link;
		}
		x = p->data;
		delete p;
		return *this;
		
	}

	Chain<T>& Insert(int k,const T& x) {	//еисацыцг стоивеиоу x стг хесг K
		ChainNode<T> *p = first;
		for (int index = 1; index < k && p; index++) {
			p = p->link;
		}
		ChainNode<T> *y = new ChainNode<T>;
		y->data = x;
		if (k) {
 			y->link = p->link;
			p->link = y;
		}
		else {
			y->link = first;
			first = y;
		}
		if (!y->link) {
			last = y;
		}
		return *this;
	}
	
private:
	ChainNode<T> *first;
	ChainNode<T> *last;

};

