/************************************************************************
* 深度优先搜索                                                                   
***********************************************************************
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
*/

template <typename Tv,typename Te> //深度优先搜索DFS算法（全图）
void Graph<Tv,Te>::dfs(int s) { //assert: 0 <= s < n
	reset(); int clock = 0; int v = s; //初始化
	do //逐一检查所有顶点
		if (UNDISCOVERED == status(v)) //一旦遇到尚未发现的顶点
			DFS(v, clock); //即从该顶点出发启动一次DFS
	while (s != (v = (++v % n))); //按序号检查，故不漏不重
}

template <typename Tv, typename Te> //深度优先搜索DFS算法（单个连通域）
void Graph<Tv, Te>::DFS(int v, int& clock) { //assert: 0 <= v < n
	dTime(v) = ++clock; status(v) = DISCOVERED; //发现当前顶点v
	for (int u = firstNbr(v); -1 < u; u = nextNbr(v, u)) //枚举v的所有邻居u
		switch (status(u)) { //并视其状态分别处理
		case UNDISCOVERED: //u尚未发现，意味着支撑树可在此拓展
			status(v, u) = TREE; parent(u) = v; DFS(u, clock); break;
		case DISCOVERED: //u已被发现但尚未访问完毕，应属被后代指向的祖先
			status(v, u) = BACKWARD; break;
		default: //u已访问完毕（VISITED，有向图），则视承袭关系分为前向边或跨边
			status(v, u) = (dTime(v) < dTime(u)) ? FORWARD : CROSS; break;
		}
	status(v) = VISITED; fTime(v) = ++clock; //至此，当前顶点v方告访问完毕
}