#pragma once

/************************************************************************
* 二叉树各种遍历的递归版本                                                                   
************************************************************************/

//先序遍历递归版
template <typename T, typename VST>
void travPre_R(BinNodePosi(T) x, VST& visit)
{
	if (!x) return;	//若x为空节点 返回 递归基
	visit(x->data);
	travPre_R(x->lChild, visit);
	travPre_R(x->rChild, visit);
}

//后序遍历
template <typename T, typename VST>
void travPost_R(BinNodePosi(T) x, VST& visit)
{
	if (!x) return;	//若x为空节点 返回 递归基
	travPost_R(x->lChild, visit);
	travPost_R(x->rChild, visit);
	visit(x->data);
}

//中序遍历
template <typename T, typename VST>
void travIn_R(BinNodePosi(T) x, VST& visit)
{
	if (!x) return;	//若x为空节点 返回 递归基
	travIn_R(x->lChild, visit);
	visit(x->data);
	travIn_R(x->rChild, visit);
}