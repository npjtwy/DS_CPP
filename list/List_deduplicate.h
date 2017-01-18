#pragma once
/*
 *	删除列表中的重复元素 返回删除的元素数
 * int deduplicate(); //无序去重
*/
template <typename T>
int List<T>::deduplicate()
{
	int oldSize = _size;
	ListNodePosi(T)  p = header;
	Rank r = 0;	//记录当前的秩， find函数要用
	while ((p = p->succ) != trailer)
	{
		ListNodePosi(T) q = find(p->data, r, p);
		q ? remove(q) : r++;	//找到相同的删掉 没找到秩+1
	}

	return oldSize - _size;
}