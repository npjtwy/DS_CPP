#pragma once
/************************************************************************
* 定义二叉树节点后继                                                                   
************************************************************************/

template <typename T>
BinNodePosi(T) BinNode<T>::succ()
{
	BinNodePosi(T) s = this;
	//1. 若节点有右孩子 则其直接后继在右子树最左下的节点
	if (rChild)
	{
		s = rChild;
		while (HasLChild(*s))
			s = s->lChild;		//寻找最左下节点即为后继
	}
	//2. 若节点没有右孩子 其直接后继为 “将当前节点包含于其左子树中的最低祖先”
	else
	{
		while (IsRChild(*s)) s = s->parent;	//不断沿着左侧上移
		s = s->parent;						//当s不再是某个节点的右孩子时 就到了包含当前节点的左子树的根节点
	}										//根节点的父节点即为当前节点的直接后继
	return s;
}