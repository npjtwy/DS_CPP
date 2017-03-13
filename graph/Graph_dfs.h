/************************************************************************
* 深度优先搜索                                                                   
************************************************************************/
#pragma once

template <typename Tv, typename Te>
void Graph<Tv, Te>::dfs(int s)
{
	//初始化
	reset();
	int clock = 0;
	int v = s;
	//检查所有顶点 遇到没有访问的 执行 DFS
	do 
	{
		if (status(v) == UNDISCOVERED)
			DFS(v, clock);

	} while (s ！= (v = (++v % n)));
}

template <typename Tv, typename Te>
void Graph<Tv, Te>::DFS(int v, int & clock)
{
	status(v) = DISCOVERED;
	dTime(v) = ++clock;		//将v的发现时刻更新

	//DFS 
	for (int u = firstNbr(v); -1 < u; u = nextNbr(v, u))	//遍历v的所有邻接顶点
	{
		switch (status(u))
		{
		case UNDISCOVERED:
			status(v, u) = TREE;
			parent(u) = v;
			DFS(u, clock); break;
		case DISCOVERED:
			status(v, u) = BACKWARD;
			break;
		default:
			status(v, u) = (dTime(v) < dTime(u)) ? FORWARD : CROSS;
			break;
		}
	}

	status(v) = VISITED;
	fTime(v) = ++clock;
}

