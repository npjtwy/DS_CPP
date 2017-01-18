#include "Queue.h"
#include "Customer.h"

/************************************************************************
* simulate 函数用来模拟银行排队服务模型                                                                   
************************************************************************/

int bestWindow(Queue<Customer>* windows, int nWin);

void simulate(int nWin, int serveTime)	//按照指定的窗口数量和服务时间模拟
{
	Queue<Customer>* windows = new Queue<Customer>[nWin];	//为每个窗口创建一个队列

	for ( int time = 0; time < serveTime; ++time)	//每个单位时间 服务一次
	{
		if (rand() % (1 + nWin))	//顾客在每个单位时间以一定概率到达 p = nWin/(1+nWin)
		{
			Customer cus; cus.time = 1 + rand() % 98; //顾客的服务时间随机确定
			cus.window = bestWindow(windows, nWin);	//确定服务窗口
			windows[cus.window].enqueue(cus);	//进入对应窗口的队列
		}

		for (int i = 0; i < nWin; i++)	//每个窗口为当前顾客服务
		{
			if (!windows[i].empty())	//若队列非空
				if (--windows[i].front().time <= 0)	//若队首顾客服务时间用完
					windows[i].dequeue();	//则从队列中删除
		}
	}//for

	delete[] windows;
}

//寻找最佳服务窗口
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
