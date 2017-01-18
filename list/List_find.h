#pragma once
/*
 *	�����������  ȫ�ֲ���Ϊǰ�ߵ�һ������
 *  �������б�֮�ڵĽ�� p �� n ��ǰ���в��� ���� e �����һ�����
*/

template <typename T>

ListNodePosi(T) List<T>::find(T const& e, int n, ListNodePosi(T) p) const
{
	while (0 < n--)
	{
		if (e == (p = p->pred)->data)
		{
			return p;
		}
	}
	return NULL;
}