#pragma once
/************************************************************************
* 二叉树中序遍历迭代版2                                                                   
************************************************************************/
template <typename T, typename VST>
void travIn_I2(BinNodePosi(T) x, VST& visit)
{
	Stack<BinNodePosi(T)> s;
	while (x || !s.empty())	//x不为null或 s不为空 循环
	{
		if (x)
		{
			s.push(x);		//先左侧全数入栈
			x = x->lChild;
		}
		else
		{
			x = s.pop();		//遇到空节点 弹出其父节点 访问后转向右子树
			visit(x->data);
			x = x->rChild;
		}
	}
}