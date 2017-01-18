#include "List.h"
#pragma once

template <typename T> 

void List<T>::init()
{
	header = new ListNode<T>;
	trailer = new ListNode<T>;	//创建头尾结点
	header->pred = NULL;  trailer->pred = header;
	header->succ = trailer; trailer->succ = NULL;
	_size = 0;
}

