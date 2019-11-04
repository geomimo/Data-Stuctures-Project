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
	T* Initialize( Chain<T>& c) {	//������������ POINTER ��� ����� �������� ��� ������ ��� ��������� ���
		location = c.first;
		if (location) {
			return &location->data;
		}
		return 0;
	}
	
	T* Next() {	//���������� ��� ������� �������� ��� ������ ��� ��������� ���
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

