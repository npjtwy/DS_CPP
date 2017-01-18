#pragma once
#include "../_share/release.h"
/************************************************************************
* int remove(BinNodePosi(T) x); //删除以位置x处节点为根的子树，返回该子树原先的规模                                                                   
************************************************************************/


template <typename T>
int BinTree<T>::remove(BinNodePosi(T) x)
{
	FromParentTo(*x) = NULL;	//与父节点切断关系
	updateHeightAbove(x->parent);	//更新祖先高度
	int n = removeAt(x); _size -= n;	//删除子树
	return n;
}

template <typename T>
static int removeAt(BinNodePosi(T) x)
{
	if (!x) return 0;	//递归基
	int n = 1 + removeAt(x->lChild) + removeAt(x->lChild);	//递归删除左右子树
	//delete(x->data); 
	delete x;
	return n;
}