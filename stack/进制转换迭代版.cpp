#define _CRT_SECURE_NO_WARNINGS
#include "stack.h"
#include <iostream>
#include <stdio.h>
using  namespace std;
/************************************************************************
* 将十进制 n 转换为 base 进制， 利用栈                                                                   
************************************************************************/
void convert(Stack<char>& s, __int64 n, int base)
{
	// n > 0, 1 < base <= 16
	static char digit[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8',
	'9', 'A', 'B', 'C', 'D', 'E', 'F' };
	while (n > 0)
	{
		int remainder = (int)(n % base);
		s.push(digit[remainder]);//余数入栈 
		n /= base;	
	}
	//栈中从上到下 保存着base进制数的高位到低位
}
