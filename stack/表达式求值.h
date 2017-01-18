#include "Stack.h"
#include <math.h>
#include <stdio.h>
#include <string>
/************************************************************************
* ������ʽ��������ʽ����� ������ʽ���ܺ��пո�                                                                   
************************************************************************/
#define N_OPTR 9 //����9�������

typedef enum{ADD, SUB, MUL, DIV, POW, FAC, L_P, R_P, EOE} Operator;
//��������� ��Ӧ�ӣ� �� �� �� �� ���� �˷��� �׳ˣ�(,  )��  ������'\0'

//��������������ȼ���ϵ
const char pri[N_OPTR][N_OPTR] = { //��������ȵȼ� [ջ��] [��ǰ]
	/* |-------------- ��ǰ����� --------------| */
	/*         +     -    *    /    ^    !    (    )   \0 */
	/* -- + */ '>', '>', '<', '<', '<', '<', '<', '>', '>',
	/* |  - */ '>', '>', '<', '<', '<', '<', '<', '>', '>',
	/* ջ * */ '>', '>', '>', '>', '<', '<', '<', '>', '>',
	/* �� / */ '>', '>', '>', '>', '<', '<', '<', '>', '>',
	/* �� ^ */ '>', '>', '>', '>', '<', '<', '<', '>', '>',
	/* �� ! */ '>', '>', '>', '>', '>', '>', ' ', '>', '>',
	/* �� ( */ '<', '<', '<', '<', '<', '<', '<', '=', ' ',
	/* |  ) */ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
	/* --\0 */ '<', '<', '<', '<', '<', '<', '<', ' ', '='
	 };
//����ʵ�����ȼ���ȵ������ ���� ˭����ջ˭�����ȼ���

Operator optr2rank(char op);
//�Ƚ����ȼ�
char orderBetween(char op1, char op2);
//������ֵ
void readnumber(char* &, Stack<float>&);
float fac(float n);	//�׳����
float calc(char op, float val);	//һԪ�������ֵ
float calc(char op, float lval, float rval);	//��Ԫ�������ֵ

void append(string &, char);	//�����ʽת���� �沨��ʽ RPN
void append(string &, float);	//�����ʽת���� �沨��ʽ RPN

//��ͨ��ֵ�㷨 
float evaluate(char *str, string & RPN)	//�Ա��ʽ��ֵ���޿ո�  ��ת��Ϊ�沨��ʽ RPN
{
	Stack<float> opval; Stack<char> optr;	//����ջ�ֱ𱣴��������������
	optr.push('\0');	//��Ϊ�ͽ�����ƥ�� ������ջ
	while (!optr.empty())	//������ǿգ����������ʽ�еĸ����ַ�
	{
		if (isdigit(*str))	//����ǲ�����  ����ջ
		{
			readnumber(str, opval);	//readnumber ����str ������������ ��������ջ�������λ����
			append(RPN, opval.top());	//��������� �������RPNĩβ
		}
		else //��Ϊ������ ��Ҫ�����ж� �� ֮ǰ�Ĳ������Ƚ����ȼ���ȷ����ջ���������ִ�л����ݲ�����
		{
			switch (orderBetween(optr.top(), *str))
			{
				case '<':	//ջ����������ȼ����� �� �ݲ�����֮ǰ�������
					optr.push(*str++);
					break;
				case '=':	//��������ȼ���� ˵��Ϊ)���߽�����
					optr.pop(); str++;	//����(
					break;
				case '>':	//ջ����������ȼ���  ��Ҫ������ջ���������
				{
					char op = optr.pop();
					append(RPN, op);	//ջ���������ջ ��������RPNĩβ
					if (op == '!')	//�����һԪ�����
					{
						float val = opval.pop();
						opval.push(calc(op, val));
					}
					else
					{
						float rval = opval.pop();	//��̵����ұߺ����������
						float lval = opval.pop();
						opval.push(calc(op, lval, rval));	//����������ջ
					}
					break;
				}
				default:
					exit(-1);
			}//switch
		}//else
	}//while
	return opval.pop();//���ؼ�����
}

//�沨�����ʽ�㷨
/************************************************************************
* ʹ���沨�����ʽ�����������ʽ��ֵ �򵥣�
************************************************************************/
float rpnEvaluation(char *exp)
{
	Stack<float> opval;
	while (*exp != '\0')
	{
		if (isdigit(*exp))
		{
			readnumber(exp, opval);//���ǲ����� ��ջ
		}
		else
		{
			if (*exp == '!')	//����һĿ����� ջ�б���һ��������
			{
				
				opval.push(fac(opval.pop()));
				exp++;
			}
			else
			{
				
				float rval = opval.pop();	//��̵����ұߺ����������
				float lval = opval.pop();
				opval.push(calc(*exp, lval, rval));	//����������ջ
			}
		}
	}
	return opval.top();
}
//������ı��ʽ�����ת��ɱ��
Operator optr2rank(char op)
{
	switch (op)
	{
	case '+':
		return ADD; break;
	case  '-':
		return SUB; break;
	case '*':
		return MUL; break;
	case '/':
		return DIV; break;
	case  '^':
		return POW; break;
	case  '!':
		return FAC; break;
	case '(':
		return L_P; break;
	case  ')':
		return R_P; break;
	case '\0':
		return EOE; break;
	default:
		exit(-1);
	}
}

char orderBetween(char op1, char op2)
{
	return pri[optr2rank(op1)][optr2rank(op2)];
}

void readnumber(char* &p, Stack<float>& opval)	//��s����Ϊ��ֵ����ջ
{
	opval.push((float)(*p - '0'));	//����ǰ�ַ���Ӧ����ֵ��ջ
	while (isdigit(*(++p)))	//������������ַ�
	{
		opval.push(opval.pop() * 10 + (float)(*p - '0'));	//��֮ǰ��ջ�ĸ�λ��ֵ���������ϵ�ǰ��������ջ
	}

	if (*p != '.') //��û��С���㣬��������
		return;

	//����С����
	float fraction = 1;
	while (isdigit(*(++p)))
	{
		opval.push(opval.pop() + (float)(*p - '0')*(fraction /= 10));
	}
}

float fac(float n)
{
	if (n == 0) return 1;
	
	float ni = 1;
	while (n >= 1)
	{
		ni *= n;
		n--;
	}
	return ni;
}

float calc(char op, float val)
{
	switch (op)
	{
	case '!':
		return fac(val);
		break;
	default:
		break;
	}
	return 0;
}

float calc(char op, float lval, float rval)
{
	switch (op)
	{
	case '+':
		return lval + rval;
	case '-':
		return lval - rval;
	case '*':
		return lval*rval;
	case '/':
		return lval / rval;
	case '^':
		return powf(lval, rval);
	default:
		printf("δ֪�����\n");
		exit(-1);
	}
}

inline void append(string &RPN, char op)
{
	RPN.push_back(op);
}
inline void append(string &RPN, float op)
{
	string opstring = to_string(op);
	for (auto it = opstring.begin(); it != opstring.end(); ++it)
	{
		RPN.push_back(*it);	//��������������RPNĩβ
	}
}

