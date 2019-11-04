#pragma once
#include "stdafx.h"
#include "Chain.h"
#include "ChainNode.h"

template<class T>
class ChainNode;

template<class T>
class Chain;

template<class T>
class ChainIterator
{
friend class Chain<T>;
public:
	T* Initialize( Chain<T>& c) {	//аявийопоигсг POINTER сто пяыто стоивеио тгс кистас йаи епистяожг тоу
		location = c.first;
		if (location) {
			return &location->data;
		}
		return 0;
	}
	
	T* Next() {	//летайимгсг сто еполемо стоивеио тгс кистас йаи епистяожг тоу
		if (!location) {
			return 0;
		}		
		location = location->link;
		if (location) {
			return &location->data;
		}
		return 0;
	}

private:
	ChainNode<T> *location;
};

