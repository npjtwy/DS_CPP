#pragma once


template <typename Tv, typename Te>
struct PrimePu		//用于Prime算法的函数对象 
{
	virtual void operator()(Graph<Tv, Te>* g, int v, int u)
	{
		if (g->status(u) == UNDISCOVERED)
		{
			if (g->priority(u) > g->weight(v, u))	//更新最小树之外的所有节点的优先级
			{
				g->priority(u) = g->weight(v, u);	//跟新优先级
				g->parent(u) = v;	//更新父节点
			}
		}
	}
};