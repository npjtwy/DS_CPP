#pragma once
/*
 *	�б�Ĺ鲢�����㷨�� ����ʼ�� p �� n ��Ԫ������
*/

template <typename T>
void List<T>::mergeSort(ListNodePosi(T)& p, int n)
{
	if (n < 2) return;
	int mid = n >> 1;	//�ҵ��е�
	ListNodePosi(T) q = p;
	for ( int i = 0; i < mid; i++)
	{
		q = q->succ;
	}
	// ��ǰ���б�ֱ�����
	mergeSort(p, mid);
	mergeSort(q, n - mid);
	//merge
	merge(p, mid, *this, q, n - mid);
}