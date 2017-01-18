#pragma once
/************************************************************************
* �������������������2                                                                   
************************************************************************/
template <typename T, typename VST>
void travIn_I2(BinNodePosi(T) x, VST& visit)
{
	Stack<BinNodePosi(T)> s;
	while (x || !s.empty())	//x��Ϊnull�� s��Ϊ�� ѭ��
	{
		if (x)
		{
			s.push(x);		//�����ȫ����ջ
			x = x->lChild;
		}
		else
		{
			x = s.pop();		//�����սڵ� �����丸�ڵ� ���ʺ�ת��������
			visit(x->data);
			x = x->rChild;
		}
	}
}