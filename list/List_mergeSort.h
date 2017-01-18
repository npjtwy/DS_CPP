#pragma once
/*
 *	列表的归并排序算法： 对起始于 p 的 n 个元素排序
*/

template <typename T>
void List<T>::mergeSort(ListNodePosi(T)& p, int n)
{
	if (n < 2) return;
	int mid = n >> 1;	//找到中点
	ListNodePosi(T) q = p;
	for ( int i = 0; i < mid; i++)
	{
		q = q->succ;
	}
	// 对前后列表分别排序
	mergeSort(p, mid);
	mergeSort(q, n - mid);
	//merge
	merge(p, mid, *this, q, n - mid);
}