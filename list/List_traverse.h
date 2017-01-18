#pragma once
#include "List.h"

/*
 *	遍历操作
*/

template <typename T>
void List<T>::traverse(void (*visit) (T&))	//利用函数指针做函数参数
{
	for (ListNodePosi(T) p = first(); p != trailer; p=p->succ)
	{
		visit(p->data);
	}
}

template <typename T> template <typename VST>
void List<T>::traverse(VST& visit)	//利用函数对象
{

	for (ListNodePosi(T) p = first(); p != trailer; p = p->succ)
	{
		visit(p->data);
	}
}