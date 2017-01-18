#pragma once
/*
 *	有序区间查找 返回查找终止的位置
 * ListNodePosi(T) search(T const& e, int n, ListNodePosi(T) p) const; //有序区间查找
*/

template <typename T>
ListNodePosi(T) List<T>::search(T const& e, int n, ListNodePosi(T) p) const
{
	// 0 <= n <= rank(p) < _size
	while (n-- >= 0)	//注意终止条件
	{
		if ((p = p->pred)->data <= e)	//注意终止条件 < e后不必在进行查找了
		{
			return p;
		}
	}
	return p;
}