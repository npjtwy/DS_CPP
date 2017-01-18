#pragma once
#include "..\Queue\Queue.h"

/************************************************************************
* ��α��� ʹ�ö���                                                                    
************************************************************************/

template <typename T>
template<typename VST>
void BinNode<T>::travLevel(VST& visit)
{
	Queue<BinNodePosi(T)> q;	//��������
	q.enqueue(this); //���ڵ������

	while (!q.empty())
	{
		BinNodePosi(T) x = q.dequeue();
		visit(x->data);
		if (HasLChild(*x))
			q.enqueue(x->lChild);
		if (HasRChild(*x))
			q.enqueue(x->rChild);
	}
}