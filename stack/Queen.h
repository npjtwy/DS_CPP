#pragma once

/************************************************************************
* 8皇后问题                                                                   
************************************************************************/
struct Queen //皇后类
{
	int x, y;	//皇后在棋盘上的坐标
	Queen(int xx, int yy) :x(xx), y(yy) {};
	bool operator==(Queen const& q)	//用 == 来判断皇后间是否冲突
	{
		return (x == q.x) || (y == q.y)
			|| (x + y == q.x + q.y)
			|| (x - y == q.x - q.y);
	}

	bool operator!=(Queen const& q){
		return !(*this == q);
	}
};