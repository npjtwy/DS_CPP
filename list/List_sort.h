#pragma once
#include <stdlib.h>
#include <time.h>
/*
 * 统一排序接口
*/

template <typename T>
void List<T>::sort(ListNodePosi(T) p, int n)
{
	srand((unsigned)time(NULL));	//重设随机数种子 
	switch (rand() % 3)
	{
		
	case 1: insertionSort(p, n); cout << "插入排序\n";  break;
	case 2: selectionSort(p, n); cout << "选择排序\n"; break;
	default:
		mergeSort(p, n);
		cout << "归并排序\n";
		break;
	}
}