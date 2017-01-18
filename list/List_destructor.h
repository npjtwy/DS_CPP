#pragma once
/*
 *	析构函数  
*/

template <typename T>
List<T>::~List()
{
	clear();
	delete header;
	delete trailer;	//先清除列表结点  再删除头尾节点
}