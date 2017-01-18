#pragma once
/*
 *	List 插入接口
*/

template <typename T>

ListNodePosi(T) List<T>::insertAsFirst(T const& e)
{
	_size++;
	return header->insertAsSucc(e);
}

template <typename T>

ListNodePosi(T) List<T>::insertAsLast(T const & e)
{
	_size++;
	return trailer->insertAsPred(e);
}

template <typename T>

ListNodePosi(T) List<T>::insertA(ListNodePosi(T) p, T const& e)//将e当作p的后继插入
{
	_size++;
	return p->insertAsSucc(e);
}

template <typename T>

ListNodePosi(T) List<T>::insertB(ListNodePosi(T) p, T const& e)//e作为p的前驱插入
{
	_size++;
	return p->insertAsPred(e);
}