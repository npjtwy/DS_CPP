#pragma once
//���dijkstra�㷨�� ���ȼ�������
#include "Graph.h"
template <typename Tv, typename Te>
struct DijkstraPu
{
	virtual void operator()(Graph<Tv, Te>* g, int v, int u)
	{
		if (g->status(u) == UNDISCOVERED)
			if (g->priority(u) > g->priority(v) + g->weight(v, u))
			{
				g->priority(u) = g->priority(v) + g->weight(v, u);	
				//��prim�Ĳ�֮ͬ�����ڣ�ÿ�θ��¶�������ȼ����õ�ǰ���㵽Դ�����Ȩ��֮�������µ�
				g->parent(u) = v;
			}
	}
};