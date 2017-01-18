#pragma once
#include "List.h"

/*
 *	��������
*/

template <typename T>
void List<T>::traverse(void (*visit) (T&))	//���ú���ָ������������
{
	for (ListNodePosi(T) p = first(); p != trailer; p=p->succ)
	{
		visit(p->data);
	}
}

template <typename T> template <typename VST>
void List<T>::traverse(VST& visit)	//���ú�������
{

	for (ListNodePosi(T) p = first(); p != trailer; p = p->succ)
	{
		visit(p->data);
	}
}