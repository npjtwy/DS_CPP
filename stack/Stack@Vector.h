#pragma once
/************************************************************************
* ʹ������ʵ��ջ�ṹ                                                                   
************************************************************************/
#include "../vector/vector.h"

template <typename T>
class Stack : public Vector<T>
{
public:
	//empty() size() ����ֱ���� Vector ��
	void push(T const& e) { insert(size(), e); }	//��ջ���� ����Ԫ�ز��뵽ĩβ
	T pop() { return remove(size() - 1); }	//��ջ
	T& top() { return this->_elem[size() - 1]; }	//����ջ��Ԫ��
};