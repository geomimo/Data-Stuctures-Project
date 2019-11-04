#pragma once
#include "./Chain.h"

/*	������ ��� ������������ ������ ���� DATA TO ����������� ��� 
	LINK ������� ���� ������� �����.*/

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



