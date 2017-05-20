#pragma once


template <typename Tv, typename Te>
struct PrimePu		//����Prime�㷨�ĺ������� 
{
	virtual void operator()(Graph<Tv, Te>* g, int v, int u)
	{
		if (g->status(u) == UNDISCOVERED)
		{
			if (g->priority(u) > g->weight(v, u))	//������С��֮������нڵ�����ȼ�
			{
				g->priority(u) = g->weight(v, u);	//�������ȼ�
				g->parent(u) = v;	//���¸��ڵ�
			}
		}
	}
};