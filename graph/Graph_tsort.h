/************************************************************************
* ����DFS����������                                                                   
************************************************************************/

#pragma once

template <typename Tv, typename Te>
Stack<TV>* Graph<Tv, Te>::tSort(int s)
{
	//��ʼ��
	reset();
	int v = s;
	int clock = 0;
	Stack<Tv>* S = new Stack<Tv>;

	//��ջ�������������򶥵�
	do 
	{
		if (UNDISCOVERED == status(v))
		{
			if (!TSort(v, clock, S))
			{
				while (!S->empty())
					S->pop();
				break;
			}
		}
	} while (s != (v = (++v % n);
	return S;	//�������������� ��˳��Ϊ��ջ������ ����ջΪ��
}

//����DFS�����������㷨

template <typename Tv, typename Te>
bool Graph<Tv, Te>::TSort(int v, int clock, Stack<Tv>* S)
{
	dTime(v) = ++clock;
	status(v) = DISCOVERED;
	for (int u = firstNbr(v); -1 < u; u = nextNbr(v, u))
	{
		switch (status(u))
		{
		case UNDISCOVERED:
			parent(u) = v;
			status(v, u) = TREE;
			if (!TSort(u, clock, S))
				return false;		//��u������������������ ��ȫͼ��Ȼ
			break;
		case DISCOVERED:
			status(v, u) = BACKWARD;	//���ֺ���� ������������
			return false;
		default:
			status(v, u) = (dTime(v) < dTime(u)) ? FORWARD : CROSS;
			break;
		}
	}

	status(v) = VISITED;
	S->push(vertex(v));
	return true;
}