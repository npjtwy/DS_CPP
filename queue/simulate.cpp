#include "Queue.h"
#include "Customer.h"

/************************************************************************
* simulate ��������ģ�������Ŷӷ���ģ��                                                                   
************************************************************************/

int bestWindow(Queue<Customer>* windows, int nWin);

void simulate(int nWin, int serveTime)	//����ָ���Ĵ��������ͷ���ʱ��ģ��
{
	Queue<Customer>* windows = new Queue<Customer>[nWin];	//Ϊÿ�����ڴ���һ������

	for ( int time = 0; time < serveTime; ++time)	//ÿ����λʱ�� ����һ��
	{
		if (rand() % (1 + nWin))	//�˿���ÿ����λʱ����һ�����ʵ��� p = nWin/(1+nWin)
		{
			Customer cus; cus.time = 1 + rand() % 98; //�˿͵ķ���ʱ�����ȷ��
			cus.window = bestWindow(windows, nWin);	//ȷ�����񴰿�
			windows[cus.window].enqueue(cus);	//�����Ӧ���ڵĶ���
		}

		for (int i = 0; i < nWin; i++)	//ÿ������Ϊ��ǰ�˿ͷ���
		{
			if (!windows[i].empty())	//�����зǿ�
				if (--windows[i].front().time <= 0)	//�����׹˿ͷ���ʱ������
					windows[i].dequeue();	//��Ӷ�����ɾ��
		}
	}//for

	delete[] windows;
}

//Ѱ����ѷ��񴰿�
int bestWindow(Queue<Customer>* windows, int nWin)
{
	int pos = 0;
	int minSize = windows[0].size();
	for ( int i = 1; i < nWin; i++)
	{
		if (minSize > windows[i].size())
		{
			minSize = windows[i].size();
			pos = i;
		}
	}
	return pos;
}
