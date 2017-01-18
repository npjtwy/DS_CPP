#pragma once
/************************************************************************
* �������������3                                                                   
************************************************************************/

template <typename T, typename VST>
void travIn_I3(BinNodePosi(T) x, VST &visit)
{
	bool backtrack = false;	//���û��ݱ�־
	while (true)
	{
		if (!backtrack && HasLChild(*x))	//��û�л��� ���������� ��������ǰ��
			x = x->lChild;
		else
		{
			//���ǻ��ݻ��� û������
			visit(x->data);
			if (HasRChild(*x))	//������Һ��� ��ת���ұ�
			{
				x = x->rChild;
				backtrack = false;
			}
			else
			{
				//û���Һ��� ��ת���̣������ݣ�
				if (!(x = x->succ())) break;
				backtrack = true;	//���û���
			}
		}
	}
}