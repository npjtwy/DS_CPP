#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using  namespace std;
/************************************************************************
* josephus 环问题 求出每个自杀的位置                                                                   
************************************************************************/

void josephus(int n, int k)	//有n个人  数到 k 的人自杀
{
	vector<int> people(n, 1);	//初始化 每个人位置设为1 死亡后设为0

	int p = n;	//活人数量
	int pos = -1;
	int i = 0;
	while (p > 1)
	{
		while (i != k)	
		{
			pos = (pos + 1) % n;	//位置加1

			if (people[pos] == 1)	//若当前位置人没死 计数+1
				i++;
		}
		people[pos] = 0;	//当前位置人自杀 置为0
		p--;		//活人数目减一
		cout << pos  << " ";	//输出当前自杀位置

		i = 0;
	}
	for (i = 0; i < n; i++)
	{
		if (people[i] == 1)
		{
			cout << "\n" << "幸存者是" << i << endl;
			break;
		}
	}
}



int main()
{
	josephus(5, 2);
	
	system("pause");
	return 0;
}