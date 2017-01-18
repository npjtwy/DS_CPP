#pragma once
/************************************************************************
* ������������汾1                                                                   
************************************************************************/

//������������֧��ջ
template <typename T, typename VST>
static void visitAlongLeftBranch(BinNodePosi(T) x, Stack<BinNodePosi(T)> s, VST& visit)
{
	while (x)
	{
		s.push(x);
		x = x->lChild;
	}
}

template <typename T, typename VST>
void travIn_I1(BinNodePosi(T) x, VST& visit)
{
	Stack<BinNodePosi(T)> s;
	while (true)
	{
		visitAlongLeftBranch(x, s, visit);
		if (s.empty()) break;
		x = s.pop();
		visit(x->data);
		x = x->rChild;	//ת���Һ���
	}
}