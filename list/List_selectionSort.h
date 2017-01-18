#pragma once

/*
 *	选择排序  对从 p 开始的n个节点进行选择排序
 * void selectionSort(ListNodePosi(T), int); //对从p开始连续的n个节点选择排序
*/
template <typename T>
void List<T>::selectionSort(ListNodePosi(T) p, int n)
{
	
	//现在n个节点中选出最大的节点
	//auto beginPos = p;	//存储起始位置   ///当最大者刚好是p时会删掉beginpos导致崩溃
	//因此储存p的前驱
	auto head = p->pred;
	auto tail = p;
	//定位到待排序区间 之后 的位置
	for (int i = 0; i < n; i++) tail = tail->succ;
	while (n > 1)
	{
		auto q = selectMax(head->succ, n);
		insertB(tail, q->data);	//插入有序序列最前端
		remove(q);	//删除旧节点
		tail = tail->pred;
		n--;
	}

}