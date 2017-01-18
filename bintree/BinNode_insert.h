#pragma once
/************************************************************************
* BinNodePosi(T) insertAsLC(T const&); //��Ϊ��ǰ�ڵ�����Ӳ����½ڵ�
* BinNodePosi(T) insertAsRC(T const&); //��Ϊ��ǰ�ڵ���Һ��Ӳ����½ڵ�
************************************************************************/

template <typename T>
BinNodePosi(T) BinNode<T>::insertAsLC(T const &e)
{
	return lChild = new BinNode(e, this);	//����һ���µĽڵ� ֵΪe ���ڵ�ָ��this
}

template <typename T>
BinNodePosi(T) BinNode<T>::insertAsRC(T const& e)
{
	return rChild = new BinNode(e, this);
}