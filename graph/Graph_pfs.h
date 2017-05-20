#pragma once

#ifdef WIN32
#pragma execution_character_set("utf-8")
#endif


template<typename Tv, typename Te>
template <typename PU> 
void Graph<Tv,Te>::pfs(int s, PU prioUpdater)		//引入函数对象 prioUpdater 更新顶点的优先级
{
	reset(); int v = s;
	do 
	{
		if (UNDISCOVERED == status(v))
		{
			PFS(v, prioUpdater);
		}
	} while (s != (v = (++v % n)));
}

template<typename Tv, typename Te>
template <typename PU>
void Graph<Tv, Te>::PFS(int v, PU prioUpdater)
{
	priority(v) = 0; parent(v) = -1;
	status(v) = DISCOVERED;

	while (1)
	{
		//更新以当前顶点为起点的单连通域所有顶点的优先级
		for (int u = firstNbr(v) ; -1 < u; u = nextNbr(v))
		{
			prioUpdater(this, v, u);	//根据函数对象所定义的规则来更新优先级
		}

		for (int shortest = INT_MAX, u = 0; u < n; ++u)	//遍历其他所有顶点，找到优先级最高的
		{
			if (shortest > priority(u))
			{
				shortest = u;
				v = u;	//更新优先级最高的顶点
			}
		}

		if (VISITED == status(v)) break;
		//每次找到最高优先级顶点 加入 PFS 树
		status(v) = VISITED; status(parent(v), v) = TREE;
	}


}