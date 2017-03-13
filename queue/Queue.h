	#pragma once
/************************************************************************
* ����list ʵ�ֵ� queue
************************************************************************/

#include "..\list\List.h"

template <typename T>
class Queue : public List<T>
{
public:
	void enqueue(const T& e)	//��� ���뵽��β
	{
		insertAsLast(e);
	}
	T dequeue()	//����  ɾ������Ԫ��
	{
		return this->remove(first());
	}

	T& front()	//���ö���Ԫ��
	{
		return this->first()->data;
	}
};