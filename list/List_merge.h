#pragma once
/*
 * 列表的二路归并 
 * 当前列表中自 p 起的 n 个元素 与列表 L 中自 q 起的 m 个元素进行归并
*/
template <typename T>
void List<T>::merge(ListNodePosi(T) &p, int n, List<T> &L, ListNodePosi(T) q, int m)
/*
* this.valid(p) && rank(p) + n <= _size  &&  this.sorted(p, n)
* L 同上
*/
{
	auto pp = p->pred;	//记录p的前驱
	while (m > 0)
	{
		if ((0 < n) && (p->data <= q->data))	//p起的n个节点未遍历完
		{
			if (q == (p = p->succ)) break;	//这里考虑的是this和L是同一个list 当q 为p的后继时，归并已经完成
			n--;
		}

		else  //p已经超界  或者 p->data > q->data
		{
			//将q插入到p之前 删除掉q旧节点
			insertB(p, L.remove((q = q->succ)->pred));
			m--;
		}
	}
	p = pp->succ;	//归并后区间的起点
}