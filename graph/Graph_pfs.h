#pragma once

#ifdef WIN32
#pragma execution_character_set("utf-8")
#endif


template<typename Tv, typename Te>
template <typename PU> 
void Graph<Tv,Te>::pfs(int s, PU prioUpdater)		//���뺯������ prioUpdater ���¶�������ȼ�
{
	reset(); int v = s;
	do 
	{
		if (UNDISCOVERED == status(v))
		{
			PFS(v, prioUpdater);
		}
	} while (s != (v = (++v % n)));
}

template<typename Tv, typename Te>
template <typename PU>
void Graph<Tv, Te>::PFS(int v, PU prioUpdater)
{
	priority(v) = 0; parent(v) = -1;
	status(v) = DISCOVERED;

	while (1)
	{
		//�����Ե�ǰ����Ϊ���ĵ���ͨ�����ж�������ȼ�
		for (int u = firstNbr(v) ; -1 < u; u = nextNbr(v))
		{
			prioUpdater(this, v, u);	//���ݺ�������������Ĺ������������ȼ�
		}

		for (int shortest = INT_MAX, u = 0; u < n; ++u)	//�����������ж��㣬�ҵ����ȼ���ߵ�
		{
			if (shortest > priority(u))
			{
				shortest = u;
				v = u;	//�������ȼ���ߵĶ���
			}
		}

		if (VISITED == status(v)) break;
		//ÿ���ҵ�������ȼ����� ���� PFS ��
		status(v) = VISITED; status(parent(v), v) = TREE;
	}


}