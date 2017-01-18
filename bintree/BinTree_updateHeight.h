#pragma once
/************************************************************************
* 更新二叉树节点高度                                                                   
************************************************************************/
#define max(a,b) (((a)>(b))?(a):(b))
template <typename T>
int BinTree<T>::updateHeight(BinNodePosi(T) x)	//更新节点x的高度
{
	return x->height = 1 +
		max(stature(x->lChild), stature(x->rChild));
}

template <typename T>
void BinTree<T>::updateHeightAbove(BinNodePosi(T) x)	//更新x及祖先的高度
{
	while (x)
	{
		updateHeight(x);
		x = x->parent;
	}
}