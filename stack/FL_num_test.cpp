#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Stack.h"
#include <math.h>
using namespace std;

/************************************************************************
* ��˷���� ����-�������շֽ�    T_T  ����
************************************************************************/

int sum_solu(Stack<int> solu)
{
	int sum = 0;
	while (!solu.empty())
	{
		sum += pow(solu.pop(), 2);
	}
	return sum;
}	//��ջ��Ԫ�����

Stack<int> FL_num(int N)
{
	Stack<int> solu;
	int max_elem = floor(sqrt(N));

	while (max_elem > 0)

	{
		solu.push(max_elem);
		while (solu.size() <= 4)
		{
			int iter = 0;
			while (sum_solu(solu) + iter < N)
			{
				iter++;
			}
			if (sum_solu(solu) + iter == N)
			{
				break;
			}
			solu.push(--iter);
		}
		if (sum_solu(solu) == N)
		{
			break;
		}
		solu.clear();
		max_elem--;
	}
	return solu;
}

int main()
{
	Stack<int> s;
	s = FL_num(30);
	
	cout << sum_solu(s) << endl;



	system("pause");
	return 0;
}