#pragma once
/************************************************************************
* �������ڵ�Ĳ��� ��Ϊ�������                                                                    
************************************************************************/

template <typename T>
BinNodePosi(T) BinTree<T>::insertAsRoot(T const& e)	//��Ϊ���ڵ����
{
	_size = 1;
	return _root = new BinNode<T>(e);
}

template <typename T>
BinNodePosi(T) BinTree<T>::insertAsLC(BinNodePosi(T) x, T const& e)
//��Ϊ���Ӳ���
{
	_size++;
	x->insertAsLC(e);	//��Ϊ��ǰ�ڵ����Ӳ���
	updateHeightAbove(x);	//���¸߶�
	return x->lChild;	//���ز���Ľڵ�
}

template <typename T>
BinNodePosi(T) BinTree<T>::insertAsRC(BinNodePosi(T) x, T const& e)
//��Ϊ�Һ��Ӳ���
{
	_size++;
	x->insertAsRC(e);
	updateHeightAbove(x);
	return x->rChild;
}