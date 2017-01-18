#include "List.h"
#pragma once

template <typename T> 

void List<T>::init()
{
	header = new ListNode<T>;
	trailer = new ListNode<T>;	//����ͷβ���
	header->pred = NULL;  trailer->pred = header;
	header->succ = trailer; trailer->succ = NULL;
	_size = 0;
}

