#pragma once

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
	Queue<int> Q;		//辅助队列
	status(v) = DISCOVERED;
	Q.enqueue(v);		//初始化起点
	
	while(!Q.empty())
	{
		int v = Q.dequeue();		//取出队首顶点
		dTime(v) = ++clock;

		for (int u = firstNbr; -1 < u; u = nextNbr(v, u))
		{
			if (UNDISCOVERED == status(u))	//若尚未发现
			{
				status(u) = DISCOVERED;		//发现该顶点， 将此条边加入树中
				Q.enqueue(u);
				status(v, u) = TREE; parent(u) = v;
			}
			else  //若已经发现，或者是访问完毕
			{
				status(v, u) = CROSS;	//将（v, u）归于跨边
			}
		}

		status(v) = VISITED;	//当前顶点的所有邻边访问完毕
	}
}