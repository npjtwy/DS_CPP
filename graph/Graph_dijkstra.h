#pragma once
/************************************************************************
* Dijkstra 算法 使用和 prim同样的框架                                                                   
************************************************************************/

template<typename Tv, typename Te>
void Graph<Tv, Te>::dijkstra(int s)
{
	reset();
	priority(s) = 0;	//置开始节点的优先级为最高
						

	for (int i = 0; i < n; ++i)	//n个顶点
	{
		status(s) = VISITED;	//每次循环开始时的s顶点都是已经完成访问的
		if (-1 != parent(s))
		{
			status(parent(s), s) = TREE;	
		}

		for (int j = firstNbr(s); -1 < j; j = nextNbr(s, j))
		{
			if (status(j) == UNDISCOVERED && priority(j) > weight(s, j) + priority(s))
			{
				priority(j) = weight(s, j) + priority(s);	
				parent(j) = s;
			}
		}

		for (int shortest = INT_MAX, u = 0; u < n; ++u)
		{
			if (shortest > priority(u) && status(u) == UNDISCOVERED)		//找出当前未访问节点中优先级最高的
				shortest = priority(u);		
		}

		s = u;	//更新下次起始顶点  
	}


}