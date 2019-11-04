#pragma once
#include "./Chain.h"


template<class T>
class Chain;

template<class T>
class ChainNode
{
	friend Chain<T>;
public:
	T data;
	ChainNode<T> *link;	
};



