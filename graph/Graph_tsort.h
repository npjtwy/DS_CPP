/************************************************************************
* 基于DFS的拓扑排序                                                                   
************************************************************************/

#pragma once

template <typename Tv, typename Te>
Stack<TV>* Graph<Tv, Te>::tSort(int s)
{
	//初始化
	reset();
	int v = s;
	int clock = 0;
	Stack<Tv>* S = new Stack<Tv>;

	//用栈来保存拓扑排序顶点
	do 
	{
		if (UNDISCOVERED == status(v))
		{
			if (!TSort(v, clock, S))
			{
				while (!S->empty())
					S->pop();
				break;
			}
		}
	} while (s != (v = (++v % n);
	return S;	//若存在拓扑排序 则顺序为从栈底向上 否则栈为空
}

//基于DFS的拓扑排序算法

template <typename Tv, typename Te>
bool Graph<Tv, Te>::TSort(int v, int clock, Stack<Tv>* S)
{
	dTime(v) = ++clock;
	status(v) = DISCOVERED;
	for (int u = firstNbr(v); -1 < u; u = nextNbr(v, u))
	{
		switch (status(u))
		{
		case UNDISCOVERED:
			parent(u) = v;
			status(v, u) = TREE;
			if (!TSort(u, clock, S))
				return false;		//若u及其后代不能拓扑排序 则全图亦然
			break;
		case DISCOVERED:
			status(v, u) = BACKWARD;	//发现后向边 则无拓扑排序
			return false;
		default:
			status(v, u) = (dTime(v) < dTime(u)) ? FORWARD : CROSS;
			break;
		}
	}

	status(v) = VISITED;
	S->push(vertex(v));
	return true;
}