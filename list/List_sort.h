#pragma once
#include <stdlib.h>
#include <time.h>
/*
 * ͳһ����ӿ�
*/

template <typename T>
void List<T>::sort(ListNodePosi(T) p, int n)
{
	srand((unsigned)time(NULL));	//������������� 
	switch (rand() % 3)
	{
		
	case 1: insertionSort(p, n); cout << "��������\n";  break;
	case 2: selectionSort(p, n); cout << "ѡ������\n"; break;
	default:
		mergeSort(p, n);
		cout << "�鲢����\n";
		break;
	}
}