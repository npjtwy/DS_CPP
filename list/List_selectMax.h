#pragma once
/*
 * //��p����n-1�������ѡ�������
 *	ListNodePosi(T) selectMax(ListNodePosi(T) p, int n); 
*/

template <typename T>
ListNodePosi(T) List<T>::selectMax(ListNodePosi(T) p, int n)
{
	auto maxp = p;
	while (n-- > 0)
	{
		if (p->data >= maxp->data) maxp = p;	//���ڵ��ڱ�֤�ȶ�����
		p = p->succ;
	}
	return maxp;
}