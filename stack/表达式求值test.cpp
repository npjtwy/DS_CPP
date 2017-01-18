#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Stack.h"
#include <stdio.h>
#include "表达式求值.h"
using  namespace std;



int main()
{
	
	char exp[1024];
	string RPN;
	scanf("%s", exp);

	cout << evaluate(exp, RPN) << endl;
	cout << RPN << endl;
	system("pause");
	return 0;
}