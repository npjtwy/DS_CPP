#pragma once
/*
 *	�崦�б��� �����б��С
*/
template <typename T>
int List<T>::clear()
{
	int oldSize = _size;
	while (_size-- > 0)
	{
		remove(header->succ);	//����ɾ���׽ڵ� ֱ���б�Ϊ��
	}
	return oldSize;
}
