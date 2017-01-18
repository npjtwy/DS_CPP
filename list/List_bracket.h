#pragma once
/*
 *	通过秩访问 list 元素 
*/
template <typename T>
T& List<T>::operator [](Rank r) const
{
	ListNodePosi(T) p = first();
	while (0 < r--) p = p->succ;
	return p->data;
}