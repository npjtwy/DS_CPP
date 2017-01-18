#define _CRT_SECURE_NO_WARNINGS

#include "Stack.h"
#include <stdio.h>
using  namespace std;

/************************************************************************
* 括号匹配检测函数  检查 表达式 区间 [low, high] 括号是否匹配                                                                   
************************************************************************/

void pushhtml(Stack<char>& s, const char exp[], int &i)
{
	while (exp[i] != '>')
		s.push(exp[i++]);
	s.push(exp[i]);	//将 <>标签入栈
}

int  pophtml(Stack<char>& s, const char exp[], int &i)
{
	while (exp[++i] != '>');//定位到标签尾部

	int pos = i;	//记录i的当前位置
	i++;
	while (s.top() == exp[--i])
		s.pop();
	if (exp[i] == '/' && s.top() == '<')
	{
		s.pop();
		i = pos;
		return 1;
	}
	else
		return 0;
}
int paren(const char exp[])
{
	Stack<char> s;
	for (int i = 0; exp[i] != '\0' ; ++i)
	{
		switch (exp[i])
		{
		case '(': case '{':case'[':
			s.push(exp[i]);		//将左侧括号统统入栈
			break;
		case '<':
			if (exp[i + 1] != '/')
				pushhtml(s, exp, i);
			else
				if (!pophtml(s, exp, i))
					return 0;
			break;
		case ')':
			if (s.empty() || (s.pop() != '('))  return 0; break;	//右括号不匹配 则表达式不匹配
		case ']':
			if (s.empty() || (s.pop() != '['))  return 0; break;
		case '}':
			if (s.empty() || (s.pop() != '{'))  return 0; break;
		default:	//其他字符跳过
			break;
		}
	}

	return s.empty();
}


int main()
{
	char exp[256];
	scanf("%s", exp);
	if (paren(exp))
		printf("success!\n");
	else
		printf("failed\n");

	system("pause");
	return 0;
}

