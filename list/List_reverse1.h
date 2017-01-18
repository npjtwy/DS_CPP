#pragma once

/************************************************************************
* 原地反转列表                                                                   
************************************************************************/


template <typename T>
void List<T>::reverse()
{
	if (_size <= 1) return;

	ListNodePosi(T) p = first();
	ListNodePosi(T) q = last();
	while ((p != q) && (p->succ != q))
	{
		int temp = p->data;
		p->data = q->data;
		q->data = temp;
		p = p->succ; q = q->pred;
	}
	if (p == q)
		return;
	else
	{
		int temp = p->data;
		p->data = q->data;
		q->data = temp;
	}

	return;
}