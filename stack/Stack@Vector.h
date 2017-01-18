#pragma once
/************************************************************************
* 使用向量实现栈结构                                                                   
************************************************************************/
#include "../vector/vector.h"

template <typename T>
class Stack : public Vector<T>
{
public:
	//empty() size() 可以直接用 Vector 的
	void push(T const& e) { insert(size(), e); }	//入栈操作 即将元素插入到末尾
	T pop() { return remove(size() - 1); }	//出栈
	T& top() { return this->_elem[size() - 1]; }	//返回栈顶元素
};