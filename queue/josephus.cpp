#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using  namespace std;
/************************************************************************
* josephus ������ ���ÿ����ɱ��λ��                                                                   
************************************************************************/

void josephus(int n, int k)	//��n����  ���� k ������ɱ
{
	vector<int> people(n, 1);	//��ʼ�� ÿ����λ����Ϊ1 ��������Ϊ0

	int p = n;	//��������
	int pos = -1;
	int i = 0;
	while (p > 1)
	{
		while (i != k)	
		{
			pos = (pos + 1) % n;	//λ�ü�1

			if (people[pos] == 1)	//����ǰλ����û�� ����+1
				i++;
		}
		people[pos] = 0;	//��ǰλ������ɱ ��Ϊ0
		p--;		//������Ŀ��һ
		cout << pos  << " ";	//�����ǰ��ɱλ��

		i = 0;
	}
	for (i = 0; i < n; i++)
	{
		if (people[i] == 1)
		{
			cout << "\n" << "�Ҵ�����" << i << endl;
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