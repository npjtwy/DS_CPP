#pragma once
/************************************************************************
* 二叉树节点的后序遍历迭代版                                                                   
************************************************************************/

template <typename T>
static void gotoHLVFL(Stack<BinNodePosi(T)> s)
{
	while (BinNodePosi(T) x = s.top())
	{
		if (HasLChild(*x))
		{
			if (HasRChild(*x))	//若有右孩子 
			{
				s.push(x->rChild);	//优先入栈
			}
			s.push(x->lChild);	//然后左孩子入栈 
		}
		else
		{
			s.push(x->rChild);
		}
	}
	s.pop();	//弹出栈顶的空节点
}


template <typename T, typename VST>
//后序遍历迭代版
void travPost_I(BinNodePosi(T) x, VST &visit)
{
	Stack<BinNodePosi(T)> s;
	if (x) s.push(x);	//根节点首先入栈

	while (!s.empty())
	{
		if (s.top() != x->parent)	//若栈顶元素不是当前节点的父节点
			gotoHLVFL(s);	//则 在以其右兄弟为根的子树中 找到HLVFL
		x = s.pop();
		visit(x->data);
	}
}



