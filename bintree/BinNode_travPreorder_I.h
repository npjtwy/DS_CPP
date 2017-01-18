#pragma once
/************************************************************************
* 二叉树先序遍历迭代算法                                                                   
************************************************************************/
//版本1
//利用先序遍历尾递归 引入栈

#include "../stack/Stack.h"

template <typename T, typename VST>
void travPre_I1(BinNodePosi(T) x, VST& visit)
{
	Stack<BinNodePosi(T)> s;	//引入栈
	if (!x)
		s.push(x);
	while (!s.empty())
	{
		//栈不为空时
		visit(s.pop()->data);	//逐个出栈遍历
		if (HasRChild(*x))
			s.push(x->rChild);	//若有右孩子  入栈
		if (HasLChild(*x))
			s.push(x->lChild);
	}

}

//版本2， 沿二叉树最左侧 遍历 再沿右孩子向上遍历
template <typename T, typename VST>
static void visitAlongLeftBranch(BinNodePosi(T) x, VST& visit, Stack<BinNodePosi(T)>& S)
//沿着左侧分之不断深入
{
	while (x)
	{
		visit(x->data);
		if (HasRChild(*x)) S.push(x->rChild);
		x = x->lChild;
	}
}



template <typename T, typename VST>
void travPre_I2(BinNodePosi(T) x, VST& visit)
{
	Stack<BinNodePosi(T)> s;
	while (true)
	{
		visitAlongLeftBranch(x, visit, s);
		if (s.empty()) break;	//如果栈空 则遍历完
		x = s.pop();
	}
}