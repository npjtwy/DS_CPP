	#pragma once
/************************************************************************
* 基于list 实现的 queue
************************************************************************/

#include "..\list\List.h"

template <typename T>
class Queue : public List<T>
{
public:
	void enqueue(const T& e)	//入队 插入到队尾
	{
		insertAsLast(e);
	}
	T dequeue()	//出队  删除队首元素
	{
		return this->remove(first());
	}

	T& front()	//引用队首元素
	{
		return this->first()->data;
	}
};