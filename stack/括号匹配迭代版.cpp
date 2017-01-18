#define _CRT_SECURE_NO_WARNINGS

#include "Stack.h"
#include <stdio.h>
using  namespace std;

/************************************************************************
* ����ƥ���⺯��  ��� ���ʽ ���� [low, high] �����Ƿ�ƥ��                                                                   
************************************************************************/

void pushhtml(Stack<char>& s, const char exp[], int &i)
{
	while (exp[i] != '>')
		s.push(exp[i++]);
	s.push(exp[i]);	//�� <>��ǩ��ջ
}

int  pophtml(Stack<char>& s, const char exp[], int &i)
{
	while (exp[++i] != '>');//��λ����ǩβ��

	int pos = i;	//��¼i�ĵ�ǰλ��
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
			s.push(exp[i]);		//���������ͳͳ��ջ
			break;
		case '<':
			if (exp[i + 1] != '/')
				pushhtml(s, exp, i);
			else
				if (!pophtml(s, exp, i))
					return 0;
			break;
		case ')':
			if (s.empty() || (s.pop() != '('))  return 0; break;	//�����Ų�ƥ�� ����ʽ��ƥ��
		case ']':
			if (s.empty() || (s.pop() != '['))  return 0; break;
		case '}':
			if (s.empty() || (s.pop() != '{'))  return 0; break;
		default:	//�����ַ�����
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

