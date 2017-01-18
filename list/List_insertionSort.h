#pragma once
/*
 *	�б�Ĳ������� �������������в��Һ����ҵ�����λ��
*/
template <typename T>
void List<T>::insertionSort(ListNodePosi(T) p, int n)
{
	Rank r = 0;
	ListNodePosi(T) q;
	while (r++ < n)
	{
		q = search(p->data, r, p);	//��p֮ǰ�� r ���ڵ��ҵ������� p �����һ���ڵ�λ�� q
		insertA(q, p->data);	//�� q ֮����� p
		p = p->succ; 
		remove(p->pred);
	}
}