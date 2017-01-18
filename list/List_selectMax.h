#pragma once
/*
 * //在p及其n-1个后继中选出最大者
 *	ListNodePosi(T) selectMax(ListNodePosi(T) p, int n); 
*/

template <typename T>
ListNodePosi(T) List<T>::selectMax(ListNodePosi(T) p, int n)
{
	auto maxp = p;
	while (n-- > 0)
	{
		if (p->data >= maxp->data) maxp = p;	//大于等于保证稳定排序
		p = p->succ;
	}
	return maxp;
}