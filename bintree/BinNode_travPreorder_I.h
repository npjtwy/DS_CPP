#pragma once
/************************************************************************
* ������������������㷨                                                                   
************************************************************************/
//�汾1
//�����������β�ݹ� ����ջ

#include "../stack/Stack.h"

template <typename T, typename VST>
void travPre_I1(BinNodePosi(T) x, VST& visit)
{
	Stack<BinNodePosi(T)> s;	//����ջ
	if (!x)
		s.push(x);
	while (!s.empty())
	{
		//ջ��Ϊ��ʱ
		visit(s.pop()->data);	//�����ջ����
		if (HasRChild(*x))
			s.push(x->rChild);	//�����Һ���  ��ջ
		if (HasLChild(*x))
			s.push(x->lChild);
	}

}

//�汾2�� �ض���������� ���� �����Һ������ϱ���
template <typename T, typename VST>
static void visitAlongLeftBranch(BinNodePosi(T) x, VST& visit, Stack<BinNodePosi(T)>& S)
//��������֮��������
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
		if (s.empty()) break;	//���ջ�� �������
		x = s.pop();
	}
}