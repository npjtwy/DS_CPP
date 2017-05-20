#pragma once
/************************************************************************
* ����DFS����������                                                                   
***********************************************************************/

template <typename Tv, typename Te>
Stack<Tv>* Graph<Tv, Te>::tSort(int i)	//�����������
{
	reset();
	int clock = 0;
	int v = i;

	Stack<Tv> *S = new Stack<Tv>;		//����ջ

	do 
	{
		if (status(v) == UNDISCOVERED)
		{
			if (!TSort(v, clock, S))
			{
				while (!S->empty())
				{
					S->pop();
				}
				break;		//����������ʧ�� ���ջ
			}
		}
	} while (i != (v = (++v % n)));

	return S;
}

template<typename Tv, typename Te>
bool Graph<Tv, Te>::TSort(int v, int& clock, Stack<Tv> *s){
	status(v) = DISCOVERED;
	for (int u = firstNbr(c); -1 < u; u = nextNbr(v))
	{
		switch (status(u))
		{
		case UNDISCOVERED:
			parent(u) = v; status(v, u) = TREE;
			if (!TSort(u, clock, s)) return 0;
			break;
		case DISCOVERED:
			status(u, v) = BACKWARD;
			return 0;
			break;
		default:
			status(u, v) = (dTime(v) < dTime(u)) ? FORWARD : CROSS;	
			//��u�Ѿ�������� ����ʱ���ǩ���v,u��ϵ��Ȼ��vҲ�������
			break;
		}
	}

	status(v) = VISITED;
	s->push(vertex(v));
	return 1;
}
