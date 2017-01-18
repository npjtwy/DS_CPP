#pragma once
/************************************************************************
* 向量的插入排序                                                                   
************************************************************************/
template <typename T>
void Vector<T>::insertionSort(Rank lo, Rank hi)
{
	if (hi - lo == 0) return;
	Rank r = lo + 1;
	while (r < hi)
	{
		Rank in = this->find(_elem[r], lo, r) + 1;	
		//找到插入位置 find返回的是不大于 _elem[r] 的最后一个位置
		// 应该插入此位置之后
		insert(in, remove(_elem[r]));	//插入完成
		r++;
	}
}