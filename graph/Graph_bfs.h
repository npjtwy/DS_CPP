#pragma once
#include "../Queue/Queue.h"

//广度优先搜索算法 
template <typename Tv, typename Te>
void Graph<Tv, Te>::bfs(int s)
{
	//初始化
	reset();
	int clock = 0;
	int v = s;

	//逐一检查所有顶点
	do 
	{
		if (status(v) == UNDISCOVERED)	//遇到没有被发现的点
			BFS(v, clock);		//便从此点出发  执行一次 BFS
	} while (s != (v = (++v % n)));
}

template <typename Tv, typename Te>
void Graph<Tv, Te>::BFS(int v, int& clock)
{
	Queue<int> Q;	//辅助队列
	status(v) = DISCOVERED;
	Q.enqueue(v);

	while (Q.empty())
	{
		int v= Q.dequeue();
		dTime(v) = ++clock;

		for (int u = firstNbr(v); -1 < u; u = nextNbr(v, u))
		{
			if (status(u) == UNDISCOVERED)
			{
				status(u) = DISCOVERED;		//如果u尚未被发现 则置 u 状态为发现，然后入队
				Q.enqueue(u);
				status(v, u) = TREE;	//更新 v -> u两个顶点间的状态为 TREE
			}
			else
			{
				status(v, u) = CROSS;	//	若是u已被发现，或者已访问，则v->u归为跨边
			}
		}
		status(v) = VISITED;	//顶点v访问完毕
	}
}
