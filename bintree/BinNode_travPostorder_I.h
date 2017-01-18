#pragma once
/************************************************************************
* �������ڵ�ĺ������������                                                                   
************************************************************************/

template <typename T>
static void gotoHLVFL(Stack<BinNodePosi(T)> s)
{
	while (BinNodePosi(T) x = s.top())
	{
		if (HasLChild(*x))
		{
			if (HasRChild(*x))	//�����Һ��� 
			{
				s.push(x->rChild);	//������ջ
			}
			s.push(x->lChild);	//Ȼ��������ջ 
		}
		else
		{
			s.push(x->rChild);
		}
	}
	s.pop();	//����ջ���Ŀսڵ�
}


template <typename T, typename VST>
//�������������
void travPost_I(BinNodePosi(T) x, VST &visit)
{
	Stack<BinNodePosi(T)> s;
	if (x) s.push(x);	//���ڵ�������ջ

	while (!s.empty())
	{
		if (s.top() != x->parent)	//��ջ��Ԫ�ز��ǵ�ǰ�ڵ�ĸ��ڵ�
			gotoHLVFL(s);	//�� ���������ֵ�Ϊ���������� �ҵ�HLVFL
		x = s.pop();
		visit(x->data);
	}
}



