#pragma once
#include "BST_removeAt.h"

template <typename T>
bool BST<T>::remove(const T& e) //ɾ��
{
	auto x = search(e);
	if (!x) return false;	//ȷ�Ͻڵ��Ƿ����
	removeAt(x, _hot);
	_size--;
	updateHeightAbove(_hot);	//�������ȸ߶�
	return true;
}