#pragma once
/************************************************************************
* 统计以当前节点为根的树的规模                                                                   
************************************************************************/

template <typename T>
int BinNode<T>::size()
{
	int s = 1;
	if (lChild) s += lChild->size();
	if (rChild) s += rChild->size();
	return s;
}