#pragma once
/************************************************************************
* 基于DFS的拓扑排序                                                                   
***********************************************************************/

template <typename Tv, typename Te>
Stack<Tv>* Graph<Tv, Te>::tSort(int i)	//拓扑排序入口
{
	reset();
	int clock = 0;
	int v = i;

	Stack<Tv> *S = new Stack<Tv>;		//辅助栈

	do 
	{
		if (status(v) == UNDISCOVERED)
		{
			if (!TSort(v, clock, S))
			{
				while (!S->empty())
				{
					S->pop();
				}
				break;		//若拓扑排序失败 清空栈
			}
		}
	} while (i != (v = (++v % n)));

	return S;
}

template<typename Tv, typename Te>
bool Graph<Tv, Te>::TSort(int v, int& clock, Stack<Tv> *s){
	status(v) = DISCOVERED;
	for (int u = firstNbr(c); -1 < u; u = nextNbr(v))
	{
		switch (status(u))
		{
		case UNDISCOVERED:
			parent(u) = v; status(v, u) = TREE;
			if (!TSort(u, clock, s)) return 0;
			break;
		case DISCOVERED:
			status(u, v) = BACKWARD;
			return 0;
			break;
		default:
			status(u, v) = (dTime(v) < dTime(u)) ? FORWARD : CROSS;	
			//若u已经访问完成 根据时间标签标记v,u关系，然后v也访问完成
			break;
		}
	}

	status(v) = VISITED;
	s->push(vertex(v));
	return 1;
}
