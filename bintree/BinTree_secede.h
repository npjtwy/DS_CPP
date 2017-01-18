#pragma once
/************************************************************************
* 子树分离                                                                   
************************************************************************/

template <typename T>
BinTree<T>* BinTree<T>::secede(BinNodePosi(T) x)
{
	FromParentTo(x) = NULL;	//与祖先断开关系
	updateHeightAbove(x->parent);	//更新祖先高度

	_size -= x->size();	//更新规模
	BinTree<T>* newTree = new BinTree<T>;
	newTree->_root = x; //新的树以x为根节点
	newTree->_size = x->size();	//并且规模等于x的规模
	x->parent = NULL;
	return newTree;
}