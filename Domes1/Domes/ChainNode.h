#pragma once
#include "./Chain.h"

/*	йолбос тгс сумдеделемгс кистас опоу DATA TO пеяиеволемо йаи 
	LINK деийтгс стом еполемо йолбо.*/

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



