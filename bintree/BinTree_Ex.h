#pragma once
#include "BinTree.h"

//判断该树中所有节点的数值均不小于其真祖先的数值之和
template <typename T>
bool isCGTP(BinNodePosi(T) root)
{

	if (root)
	{
		Stack<BinNodePosi(T)> s;	//用来前序遍历存放节点
		Stack<float> sf;		//存放节点真祖先值得和 与同时存入s的节点对应
		if (root->data <= 0) return false;
		s.push(root);	//root节点入栈
		sf.push(0);		//存入root节点祖先值得和 即 0

		while (!s.empty())
		{
			BinNodePosi(T) p = s.pop();	//弹出栈顶节点
			float sum_of_parent = sf.pop();	//弹出p对应祖先值的和

			if (p->data < sum_of_parent)	//比较p的值和其真祖先的值的和
				return false;
			sum_of_parent += p->data;	//更新祖先值的和
			if (HasRChild(*p))
			{
				s.push(p->rChild);	//若有右孩子  入栈	
				sf.push(sum_of_parent);	//对应于入栈节点的祖先值的和也入栈
			}
			if (HasLChild(*p))
			{
				s.push(p->lChild);
				sf.push(sum_of_parent);
			}
		}
		return true;
	}

	else {
		printf("invalid node\n");
		return false;
	}
}

//用孩子中的最大值替换节点的值 递归版  迭代版利用后续遍历迭代版增加一些操作即可
template <typename T>
void RplaceData(BinNodePosi(T) root)
{
	if ((!root) || (!HasLChild(*root) && !HasRChild(*root)))
		return;	//空节点或者没有孩子节点 返回    递归基
	RplaceData(root->lChild);
	RplaceData(root->rChild);

	if (HasLChild(*root) && HasRChild(*root))	//若有两个孩子 则节点值为两个孩子中较大的一个
		root->data = max(root->lChild->data, root->rChild->data);
	//只有一个孩子  。。。。
	else
		root->data = (HasLChild(*root)) ? root->lChild->data : root->rChild->data;
}

//实现递归算法 树根为0 对于数值为k的节点 其左孩子数值为2k+1 右孩子为2k+2
template <typename T>
void SetValue(BinNodePosi(T) root)
{
	if (!root)
		return;	//递归基
	if (IsLChild(*root))
		root->data = 2 * root->parent->data + 1;
	else if (IsRChild(*root))
	{
		root->data = 2 * root->parent->data + 2;
	}
	else
		root->data = 0;

	SetValue(root->lChild);
	SetValue(root->rChild);
}

//迭代版
#include "../stack/Stack.h"
template <typename T>
void SetValue_Iter(BinNodePosi(T) root)
{
	Stack<BinNodePosi(T)> s;

	if (!root)
	{
		printf("invalid node\n");
		return;
	}

	s.push(root);

	while (!s.empty())
	{
		auto p = s.pop();
		if (IsRoot(*p))
			p->data = 0;	//若为根节点 设为0
		if (IsLChild(*p))
			p->data = p->parent->data * 2 + 1;
		if (IsRChild(*p))
			p->data = p->parent->data * 2 + 2;
		if (HasRChild(*p))
			s.push(p->rChild);	//若有右孩子  入栈
		if (HasLChild(*p))
			s.push(p->lChild);
	}

}