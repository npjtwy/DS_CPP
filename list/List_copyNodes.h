#pragma once
/*
 *	复制节点
 *void copyNodes(ListNodePosi(T), int); //复制列表中自位置p起的n项
*/
template <typename T>

void List<T>::copyNodes(ListNodePosi(T) p, int n) //复制列表中自位置p起的n项
{
	this->init();	//创建头尾节点 并初始化
	while (0 < n--)
	{
		//采用尾插法复制
		insertAsLast(p->data);
		p = p->succ;
	}
}