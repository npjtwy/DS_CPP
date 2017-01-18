#pragma once
/*
 *	����������� ���ز�����ֹ��λ��
 * ListNodePosi(T) search(T const& e, int n, ListNodePosi(T) p) const; //�����������
*/

template <typename T>
ListNodePosi(T) List<T>::search(T const& e, int n, ListNodePosi(T) p) const
{
	// 0 <= n <= rank(p) < _size
	while (n-- >= 0)	//ע����ֹ����
	{
		if ((p = p->pred)->data <= e)	//ע����ֹ���� < e�󲻱��ڽ��в�����
		{
			return p;
		}
	}
	return p;
}