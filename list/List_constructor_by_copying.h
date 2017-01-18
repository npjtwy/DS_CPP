#pragma once
/*
*	List(List<T> const& L); //整体复制列表L
*	List(List<T> const& L, Rank r, int n); //复制列表L中自第r项起的n项
*	List(ListNodePosi(T) p, int n); //复制列表中自位置p起的n项
*/
template <typename T>
List<T>::List(List<T> const& L)
{
	this->copyNodes(L.first(), L._size);
}

template <typename T>
List<T>::List(List<T> const& L, Rank r, int n)
{
	ListNodePosi(T) p = L.first();
	while (r-- > 0)
	{
		p = p->succ;
	}
	this->copyNodes(p, n);
}

template <typename T>
List<T>::List(ListNodePosi(T) p, int n)
{
	copyNodes(p, n);
}
