#include "Stack.h"
#include <math.h>
#include <stdio.h>
#include <string>
/************************************************************************
* 输入表达式，计算表达式结果， 输入表达式不能含有空格                                                                   
************************************************************************/
#define N_OPTR 9 //定义9种运算符

typedef enum{ADD, SUB, MUL, DIV, POW, FAC, L_P, R_P, EOE} Operator;
//运算符集合 对应加， 减 ， 乘 ， 除， 乘方， 阶乘，(,  )，  结束符'\0'

//定义运算符的优先级关系
const char pri[N_OPTR][N_OPTR] = { //运算符优先等级 [栈顶] [弼前]
	/* |-------------- 当前运算符 --------------| */
	/*         +     -    *    /    ^    !    (    )   \0 */
	/* -- + */ '>', '>', '<', '<', '<', '<', '<', '>', '>',
	/* |  - */ '>', '>', '<', '<', '<', '<', '<', '>', '>',
	/* 栈 * */ '>', '>', '>', '>', '<', '<', '<', '>', '>',
	/* 顶 / */ '>', '>', '>', '>', '<', '<', '<', '>', '>',
	/* 运 ^ */ '>', '>', '>', '>', '<', '<', '<', '>', '>',
	/* 算 ! */ '>', '>', '>', '>', '>', '>', ' ', '>', '>',
	/* 符 ( */ '<', '<', '<', '<', '<', '<', '<', '=', ' ',
	/* |  ) */ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
	/* --\0 */ '<', '<', '<', '<', '<', '<', '<', ' ', '='
	 };
//对于实际优先级相等的运算符 采用 谁先入栈谁的优先级高

Operator optr2rank(char op);
//比较优先级
char orderBetween(char op1, char op2);
//解析数值
void readnumber(char* &, Stack<float>&);
float fac(float n);	//阶乘求解
float calc(char op, float val);	//一元运算符求值
float calc(char op, float lval, float rval);	//二元运算符求值

void append(string &, char);	//将表达式转换成 逆波兰式 RPN
void append(string &, float);	//将表达式转换成 逆波兰式 RPN

//普通求值算法 
float evaluate(char *str, string & RPN)	//对表达式求值（无空格）  并转换为逆波兰式 RPN
{
	Stack<float> opval; Stack<char> optr;	//两个栈分别保存运算数和运算符
	optr.push('\0');	//作为和结束符匹配 首先入栈
	while (!optr.empty())	//运算符非空，逐个处理表达式中的各个字符
	{
		if (isdigit(*str))	//如果是操作数  则入栈
		{
			readnumber(str, opval);	//readnumber 读入str 并解析出数字 并将其入栈，处理多位数字
			append(RPN, opval.top());	//读入操作数 将其接至RPN末尾
		}
		else //若为操作符 则要进行判断 与 之前的操作符比较优先级来确定对栈顶的运算符执行还是暂不处理
		{
			switch (orderBetween(optr.top(), *str))
			{
				case '<':	//栈顶运算符优先级更低 则 暂不处理之前的运算符
					optr.push(*str++);
					break;
				case '=':	//运算符优先级相等 说明为)或者结束符
					optr.pop(); str++;	//弹出(
					break;
				case '>':	//栈顶运算符优先级高  则要先运算栈顶的运算符
				{
					char op = optr.pop();
					append(RPN, op);	//栈顶运算符出栈 并续接至RPN末尾
					if (op == '!')	//如果是一元运算符
					{
						float val = opval.pop();
						opval.push(calc(op, val));
					}
					else
					{
						float rval = opval.pop();	//相继弹出右边和左边运算数
						float lval = opval.pop();
						opval.push(calc(op, lval, rval));	//将计算结果入栈
					}
					break;
				}
				default:
					exit(-1);
			}//switch
		}//else
	}//while
	return opval.pop();//返回计算结果
}

//逆波兰表达式算法
/************************************************************************
* 使用逆波兰表达式来对算数表达式求值 简单！
************************************************************************/
float rpnEvaluation(char *exp)
{
	Stack<float> opval;
	while (*exp != '\0')
	{
		if (isdigit(*exp))
		{
			readnumber(exp, opval);//若是操作数 入栈
		}
		else
		{
			if (*exp == '!')	//遇到一目运算符 栈中必有一个操作数
			{
				
				opval.push(fac(opval.pop()));
				exp++;
			}
			else
			{
				
				float rval = opval.pop();	//相继弹出右边和左边运算数
				float lval = opval.pop();
				opval.push(calc(*exp, lval, rval));	//将计算结果入栈
			}
		}
	}
	return opval.top();
}
//将输入的表达式运算符转译成编号
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

void readnumber(char* &p, Stack<float>& opval)	//将s解析为数值并入栈
{
	opval.push((float)(*p - '0'));	//将当前字符对应的数值入栈
	while (isdigit(*(++p)))	//若其后含有数字字符
	{
		opval.push(opval.pop() * 10 + (float)(*p - '0'));	//将之前入栈的高位数值弹出，加上当前数字再入栈
	}

	if (*p != '.') //若没有小数点，则操作完成
		return;

	//若有小数点
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
		printf("未知运算符\n");
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
		RPN.push_back(*it);	//将操作数续接至RPN末尾
	}
}

