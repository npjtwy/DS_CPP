#pragma once
/************************************************************************
* 定义银行服务模型 customer 类                                                                   
************************************************************************/
class Customer
{
public:
	int window;		//所属窗口  ： 即 队列
	unsigned int time;	//服务时长
};