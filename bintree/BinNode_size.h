#pragma once
/************************************************************************
* ͳ���Ե�ǰ�ڵ�Ϊ�������Ĺ�ģ                                                                   
************************************************************************/

template <typename T>
int BinNode<T>::size()
{
	int s = 1;
	if (lChild) s += lChild->size();
	if (rChild) s += rChild->size();
	return s;
}