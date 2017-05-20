#pragma once

#include "Graph.h"
#include "Graph_prim_PU.h"
#include "Graph_pfs.h"

template<typename Tv, typename Te>
void Graph<Tv, Te>::prim(int s) //最小支撑树Prim算法
{
	reset();
	priority(s) = 0;	//置开始节点的优先级为最高
						//此处可以引入队列存储先后访问完毕的顶点，即最小树的构造顺序

	for (int i = 0; i < n; ++i)	//n个顶点
	{
		status(s) = VISITED;	//每次循环开始时的s顶点都是已经完成访问的
		if (-1 != parent(s))
		{
			status(parent(s), s) = TREE;	//若s不是开始顶点 则置于最小树中
		}

		for (int j = firstNbr(s); -1 < j ; j = nextNbr(s, j))	
		{
			if (status(j) == UNDISCOVERED && priority(j) > weight(s, j))
			{
				priority(j) = weight(s, j);	//对于s的每个邻居， 更新其优先级为 s->j 的权重
				parent(j) = s;		//重要 勿忘
			}
		}

		for (int shortest = INT_MAX, u = 0; u < n; ++u)
		{
			if (shortest > priority(u) && status(u) == UNDISCOVERED)		//找出当前未访问节点中优先级最高的
				shortest = priority(u);		//即，距离当前最小树中所有顶点权重最小的
		}

		s = u;	//更新下次起始顶点  
	}


}