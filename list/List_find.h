#pragma once
/*
 *	无序区间查找  全局查找为前者的一个特例
 *  在无序列表之内的结点 p 的 n 个前驱中查找 等于 e 的最后一个结点
*/

template <typename T>

ListNodePosi(T) List<T>::find(T const& e, int n, ListNodePosi(T) p) const
{
	while (0 < n--)
	{
		if (e == (p = p->pred)->data)
		{
			return p;
		}
	}
	return NULL;
}