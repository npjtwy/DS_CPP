#pragma once

#include "Graph.h"
#include "Graph_prim_PU.h"
#include "Graph_pfs.h"

template<typename Tv, typename Te>
void Graph<Tv, Te>::prim(int s) //��С֧����Prim�㷨
{
	reset();
	priority(s) = 0;	//�ÿ�ʼ�ڵ�����ȼ�Ϊ���
						//�˴�����������д洢�Ⱥ������ϵĶ��㣬����С���Ĺ���˳��

	for (int i = 0; i < n; ++i)	//n������
	{
		status(s) = VISITED;	//ÿ��ѭ����ʼʱ��s���㶼���Ѿ���ɷ��ʵ�
		if (-1 != parent(s))
		{
			status(parent(s), s) = TREE;	//��s���ǿ�ʼ���� ��������С����
		}

		for (int j = firstNbr(s); -1 < j ; j = nextNbr(s, j))	
		{
			if (status(j) == UNDISCOVERED && priority(j) > weight(s, j))
			{
				priority(j) = weight(s, j);	//����s��ÿ���ھӣ� ���������ȼ�Ϊ s->j ��Ȩ��
				parent(j) = s;		//��Ҫ ����
			}
		}

		for (int shortest = INT_MAX, u = 0; u < n; ++u)
		{
			if (shortest > priority(u) && status(u) == UNDISCOVERED)		//�ҳ���ǰδ���ʽڵ������ȼ���ߵ�
				shortest = priority(u);		//�������뵱ǰ��С�������ж���Ȩ����С��
		}

		s = u;	//�����´���ʼ����  
	}


}