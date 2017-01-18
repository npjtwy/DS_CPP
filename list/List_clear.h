#pragma once
/*
 *	清处列表结点 返回列表大小
*/
template <typename T>
int List<T>::clear()
{
	int oldSize = _size;
	while (_size-- > 0)
	{
		remove(header->succ);	//反复删除首节点 直至列表为空
	}
	return oldSize;
}
