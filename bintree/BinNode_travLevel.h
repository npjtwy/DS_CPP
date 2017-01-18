#pragma once
#include "..\Queue\Queue.h"

/************************************************************************
* 层次遍历 使用队列                                                                    
************************************************************************/

template <typename T>
template<typename VST>
void BinNode<T>::travLevel(VST& visit)
{
	Queue<BinNodePosi(T)> q;	//辅助队列
	q.enqueue(this); //根节点入队列

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