#pragma once
#include "BST_removeAt.h"

template <typename T>
bool BST<T>::remove(const T& e) //ɾ��
{
	BinNodePosi(T)& x = search(e);
	if (x == NULL) return false;	//ȷ�Ͻڵ��Ƿ����
	removeAt(x, _hot);
	_size--;
	updateHeightAbove(_hot);	//�������ȸ߶�
	return true;
}