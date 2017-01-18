#pragma once
/************************************************************************
* ��������                                                                   
************************************************************************/

template <typename T>
BinTree<T>* BinTree<T>::secede(BinNodePosi(T) x)
{
	FromParentTo(x) = NULL;	//�����ȶϿ���ϵ
	updateHeightAbove(x->parent);	//�������ȸ߶�

	_size -= x->size();	//���¹�ģ
	BinTree<T>* newTree = new BinTree<T>;
	newTree->_root = x; //�µ�����xΪ���ڵ�
	newTree->_size = x->size();	//���ҹ�ģ����x�Ĺ�ģ
	x->parent = NULL;
	return newTree;
}