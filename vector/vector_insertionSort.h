#pragma once
/************************************************************************
* �����Ĳ�������                                                                   
************************************************************************/
template <typename T>
void Vector<T>::insertionSort(Rank lo, Rank hi)
{
	if (hi - lo == 0) return;
	Rank r = lo + 1;
	while (r < hi)
	{
		Rank in = this->find(_elem[r], lo, r) + 1;	
		//�ҵ�����λ�� find���ص��ǲ����� _elem[r] �����һ��λ��
		// Ӧ�ò����λ��֮��
		insert(in, remove(_elem[r]));	//�������
		r++;
	}
}