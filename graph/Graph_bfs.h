#pragma once
#include "../Queue/Queue.h"

//������������㷨 
template <typename Tv, typename Te>
void Graph<Tv, Te>::bfs(int s)
{
	//��ʼ��
	reset();
	int clock = 0;
	int v = s;

	//��һ������ж���
	do 
	{
		if (status(v) == UNDISCOVERED)	//����û�б����ֵĵ�
			BFS(v, clock);		//��Ӵ˵����  ִ��һ�� BFS
	} while (s != (v = (++v % n)));
}

template <typename Tv, typename Te>
void Graph<Tv, Te>::BFS(int v, int& clock)
{
	Queue<int> Q;	//��������
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
				status(u) = DISCOVERED;		//���u��δ������ ���� u ״̬Ϊ���֣�Ȼ�����
				Q.enqueue(u);
				status(v, u) = TREE;	//���� v -> u����������״̬Ϊ TREE
			}
			else
			{
				status(v, u) = CROSS;	//	����u�ѱ����֣������ѷ��ʣ���v->u��Ϊ���
			}
		}
		status(v) = VISITED;	//����v�������
	}
}
