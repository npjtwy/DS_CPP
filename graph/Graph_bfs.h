#pragma once

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
	Queue<int> Q;		//��������
	status(v) = DISCOVERED;
	Q.enqueue(v);		//��ʼ�����
	
	while(!Q.empty())
	{
		int v = Q.dequeue();		//ȡ�����׶���
		dTime(v) = ++clock;

		for (int u = firstNbr; -1 < u; u = nextNbr(v, u))
		{
			if (UNDISCOVERED == status(u))	//����δ����
			{
				status(u) = DISCOVERED;		//���ָö��㣬 �������߼�������
				Q.enqueue(u);
				status(v, u) = TREE; parent(u) = v;
			}
			else  //���Ѿ����֣������Ƿ������
			{
				status(v, u) = CROSS;	//����v, u�����ڿ��
			}
		}

		status(v) = VISITED;	//��ǰ����������ڱ߷������
	}
}