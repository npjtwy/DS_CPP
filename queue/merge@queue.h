#pragma once
#include "Queue.h"
/************************************************************************
* 队列实现两个有序序列的归并    假设有序序列为链表                                                               
************************************************************************/

template <typename T>
Queue<T>& merge_by_using_queue(List<T> L1, List<T> L2)
{
	Queue<T> result;
	while (L1.size() && L2.size())
	{
		if (L1.first()->data >= L2.first()->data)
			result.enqueue(L1.remove(L1.first()))
		else
			result.enqueue(L2.remove(L2.first()))
	}
	while (L1.size())
		result.enqueue(L1.remove(L1.first()));
	while (L2.size())
		result.enqueue(L2.remove(L2.first()));
	return result;
}
