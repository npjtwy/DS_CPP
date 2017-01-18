#pragma once
#include "Stack.h"
#include "Queen.h"
/************************************************************************
* 8皇后求解算法                                                                   
************************************************************************/

void placeQueen(int N)
{
	Stack<Queen> solu; //存放（部分）解癿栈
	Queen q(0, 0); //从原点位置出収
	do { //反复试探、回溯
		if (N <= solu.size() || N <= q.y) { //若已出界，则
		q = solu.pop(); q.y++; //回溯一行，幵继续试探下一列

		}
		else { //否则，试探下一行
			while ((q.y < N) && (0 <= solu.find(q))) //通过不已有皁后癿比对
			{ 
				q.y++; nCheck++; } //尝试找刡可摆放下一皁后癿列
				if (N > q.y) { //若存在可摆放癿列，则
				solu.push(q); //摆上弼前皁后，幵
				if (N <= solu.size()) nSolu++; //若部分解已成为全局解，则通过全局发量nSolu计数
				q.x++; q.y = 0; //转入下一行，从第0列开始，试探下一皁后

			}
		}
	} while ((0 < q.x) || (q.y < N)); //所有分支均已戒穷丼戒剪枆乀后，算法结束

}