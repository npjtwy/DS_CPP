#pragma once
/************************************************************************
* BinNodePosi(T) insertAsLC(T const&); //作为当前节点的左孩子插入新节点
* BinNodePosi(T) insertAsRC(T const&); //作为当前节点的右孩子插入新节点
************************************************************************/

template <typename T>
BinNodePosi(T) BinNode<T>::insertAsLC(T const &e)
{
	return lChild = new BinNode(e, this);	//创建一个新的节点 值为e 父节点指向this
}

template <typename T>
BinNodePosi(T) BinNode<T>::insertAsRC(T const& e)
{
	return rChild = new BinNode(e, this);
}