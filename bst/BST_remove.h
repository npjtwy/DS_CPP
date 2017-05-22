#pragma once
#include "BST_removeAt.h"

template <typename T>
bool BST<T>::remove(const T& e) //删除
{
	auto x = search(e);
	if (!x) return false;	//确认节点是否存在
	removeAt(x, _hot);
	_size--;
	updateHeightAbove(_hot);	//更新祖先高度
	return true;
}