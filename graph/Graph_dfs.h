/************************************************************************
* �����������                                                                   
************************************************************************/
#pragma once

template <typename Tv, typename Te>
void Graph<Tv, Te>::dfs(int s)
{
	//��ʼ��
	reset();
	int clock = 0;
	int v = s;
	//������ж��� ����û�з��ʵ� ִ�� DFS
	do 
	{
		if (status(v) == UNDISCOVERED)
			DFS(v, clock);

	} while (s ��= (v = (++v % n)));
}

template <typename Tv, typename Te>
void Graph<Tv, Te>::DFS(int v, int& clock)	//DFS�㷨  ����ͨ��
{
	dTime(v) = ++clock;
	status(v) = DISCOVERED;
	for (int u = firstNbr(v); -1 < u; u = nextNbr(v, u))
	{
		switch (status(u))
		{
		case UNDISCOVERED:
			status(v, u) = TREE;
			parent(u) = v;
			DFS(u, clock); break;
		case DISCOVERED:
			status(u, v) = BACKWARD;
			break;
		default:
			status(v, u) = (dTime(v) < dTime(u)) ? FORWARD : CROSS;
			break;
		}
	}
	status(v) = VISITED;
	fTime(v) = ++clock;
}