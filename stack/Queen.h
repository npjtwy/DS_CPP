#pragma once

/************************************************************************
* 8�ʺ�����                                                                   
************************************************************************/
struct Queen //�ʺ���
{
	int x, y;	//�ʺ��������ϵ�����
	Queen(int xx, int yy) :x(xx), y(yy) {};
	bool operator==(Queen const& q)	//�� == ���жϻʺ���Ƿ��ͻ
	{
		return (x == q.x) || (y == q.y)
			|| (x + y == q.x + q.y)
			|| (x - y == q.x - q.y);
	}

	bool operator!=(Queen const& q){
		return !(*this == q);
	}
};