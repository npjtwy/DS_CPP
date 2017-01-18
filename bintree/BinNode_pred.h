#pragma once
/************************************************************************
* ����������ڵ��ǰ��                                                                   
************************************************************************/
template <typename T>
BinNodePosi(T) BinNode<T>::pred()
{
	//����succ()����
	BinNodePosi(T) s = this;

	if (HasLChild(*this))	//���������
	{
		s = this->lChild;
		while (HasRChild(*s))
			s = s->rChild;		//����ǰ���ڵ�Ϊ ��������Ϊ���ڵ�������������½ڵ�
	}
	else
	{
		//��û������ 
		while (IsLChild(*s)) s = s->parent;	//�����в����� ֱ��s����ĳ���ڵ������
		s = s->parent;	//������һ���ڵ�
	}

}