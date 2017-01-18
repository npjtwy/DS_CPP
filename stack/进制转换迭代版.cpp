#define _CRT_SECURE_NO_WARNINGS
#include "stack.h"
#include <iostream>
#include <stdio.h>
using  namespace std;
/************************************************************************
* ��ʮ���� n ת��Ϊ base ���ƣ� ����ջ                                                                   
************************************************************************/
void convert(Stack<char>& s, __int64 n, int base)
{
	// n > 0, 1 < base <= 16
	static char digit[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8',
	'9', 'A', 'B', 'C', 'D', 'E', 'F' };
	while (n > 0)
	{
		int remainder = (int)(n % base);
		s.push(digit[remainder]);//������ջ 
		n /= base;	
	}
	//ջ�д��ϵ��� ������base�������ĸ�λ����λ
}
