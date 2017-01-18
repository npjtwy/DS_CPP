#pragma once
/************************************************************************
* 二叉树节点的插入 分为三种情况                                                                    
************************************************************************/

template <typename T>
BinNodePosi(T) BinTree<T>::insertAsRoot(T const& e)	//作为根节点插入
{
	_size = 1;
	return _root = new BinNode<T>(e);
}

template <typename T>
BinNodePosi(T) BinTree<T>::insertAsLC(BinNodePosi(T) x, T const& e)
//作为左孩子插入
{
	_size++;
	x->insertAsLC(e);	//作为当前节点左孩子插入
	updateHeightAbove(x);	//更新高度
	return x->lChild;	//返回插入的节点
}

template <typename T>
BinNodePosi(T) BinTree<T>::insertAsRC(BinNodePosi(T) x, T const& e)
//作为右孩子插入
{
	_size++;
	x->insertAsRC(e);
	updateHeightAbove(x);
	return x->rChild;
}