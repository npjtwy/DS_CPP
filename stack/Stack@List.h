#pragma once
/************************************************************************
* �� LIst ʵ��ջ                                                                   
************************************************************************/
#include "../list/List.h"

template <typename T>
class Stack : public List<T>
{
public:
	void push(T const& e) { insertAsLast(e); }
	T pop() { return remove(last()); }
	T& top() { return this->last()->data; }
};