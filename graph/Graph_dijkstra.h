#pragma once
/************************************************************************
* Dijkstra �㷨 ʹ�ú� primͬ���Ŀ��                                                                   
************************************************************************/

template<typename Tv, typename Te>
void Graph<Tv, Te>::dijkstra(int s)
{
	reset();
	priority(s) = 0;	//�ÿ�ʼ�ڵ�����ȼ�Ϊ���
						

	for (int i = 0; i < n; ++i)	//n������
	{
		status(s) = VISITED;	//ÿ��ѭ����ʼʱ��s���㶼���Ѿ���ɷ��ʵ�
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
			if (shortest > priority(u) && status(u) == UNDISCOVERED)		//�ҳ���ǰδ���ʽڵ������ȼ���ߵ�
				shortest = priority(u);		
		}

		s = u;	//�����´���ʼ����  
	}


}