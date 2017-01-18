#pragma once
/************************************************************************
* 定义二叉树节点的前驱                                                                   
************************************************************************/
template <typename T>
BinNodePosi(T) BinNode<T>::pred()
{
	//仿照succ()代码
	BinNodePosi(T) s = this;

	if (HasLChild(*this))	//如果有左孩子
	{
		s = this->lChild;
		while (HasRChild(*s))
			s = s->rChild;		//则其前驱节点为 以其左孩子为根节点的子树的最右下节点
	}
	else
	{
		//若没有左孩子 
		while (IsLChild(*s)) s = s->parent;	//沿着有侧上移 直到s不是某个节点的左孩子
		s = s->parent;	//再上移一个节点
	}

}