#pragma once
//针对dijkstra算法的 优先级更新器
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
				//与prim的不同之处在于，每次跟新顶点的优先级是用当前顶点到源顶点的权重之和来更新的
				g->parent(u) = v;
			}
	}
};