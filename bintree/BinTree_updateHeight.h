#pragma once
/************************************************************************
* ���¶������ڵ�߶�                                                                   
************************************************************************/
#define max(a,b) (((a)>(b))?(a):(b))
template <typename T>
int BinTree<T>::updateHeight(BinNodePosi(T) x)	//���½ڵ�x�ĸ߶�
{
	return x->height = 1 +
		max(stature(x->lChild), stature(x->rChild));
}

template <typename T>
void BinTree<T>::updateHeightAbove(BinNodePosi(T) x)	//����x�����ȵĸ߶�
{
	while (x)
	{
		updateHeight(x);
		x = x->parent;
	}
}