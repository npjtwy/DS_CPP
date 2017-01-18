#pragma once
/*
 *	列表的插入排序 借助于有序序列查找函数找到插入位置
*/
template <typename T>
void List<T>::insertionSort(ListNodePosi(T) p, int n)
{
	Rank r = 0;
	ListNodePosi(T) q;
	while (r++ < n)
	{
		q = search(p->data, r, p);	//在p之前的 r 个节点找到不大于 p 的最后一个节点位置 q
		insertA(q, p->data);	//在 q 之后插入 p
		p = p->succ; 
		remove(p->pred);
	}
}