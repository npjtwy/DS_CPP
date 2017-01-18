#pragma once
#include "../_share/release.h"
/************************************************************************
* int remove(BinNodePosi(T) x); //ɾ����λ��x���ڵ�Ϊ�������������ظ�����ԭ�ȵĹ�ģ                                                                   
************************************************************************/


template <typename T>
int BinTree<T>::remove(BinNodePosi(T) x)
{
	FromParentTo(*x) = NULL;	//�븸�ڵ��жϹ�ϵ
	updateHeightAbove(x->parent);	//�������ȸ߶�
	int n = removeAt(x); _size -= n;	//ɾ������
	return n;
}

template <typename T>
static int removeAt(BinNodePosi(T) x)
{
	if (!x) return 0;	//�ݹ��
	int n = 1 + removeAt(x->lChild) + removeAt(x->lChild);	//�ݹ�ɾ����������
	//delete(x->data); 
	delete x;
	return n;
}