#pragma once
#include "../_share/release.h"
/************************************************************************
* 实施具体的二叉搜索树的删除操作
* 返回被删除节点的接替者
************************************************************************/

template <typename T>
static BinNodePosi(T)
removeAt(BinNodePosi(T)& x, BinNodePosi(T)& hot) //删除
{
	BinNodePosi(T) w = x;	//要删除的节点
	BinNodePosi(T) succ = nullptr;	//要删除的节点的继任者
	
	if (!HasLChild(*x))	//如果没有左孩子， succ指向右孩子
		succ = x = x->rChild;
	else if (!HasRChild(*x))	//对称情况
		succ = x = x->lChild;
	else if(HasBothChild(*x))	//如果没有孩子
	{
		w = w->succ();
		std::swap(w->data, x->data);	//交换待删除节点和其后继的值 转而删除其后继
		BinNodePosi(T) u = w->parent;
		((u == x) ? u->rChild : u->lChild) = succ = w->rChild;	//后继节点的父节点指向另一个孩子（可能为NULL）
	}

	hot = w->parent;
	if (succ) succ->parent = hot;	
	//感觉有问题 单节点的情况下只是将继任者的父节点指向了w的父节点，那w父节点的child指向呢？不就成NULL了？？
	//加了下面两行代码让 w 的父节点的孩子指向succ
	if (IsRChild(*w)) hot->rChild = succ;
	else hot->lChild = succ;

	release(w->data);
	release(w);
	return succ;
}