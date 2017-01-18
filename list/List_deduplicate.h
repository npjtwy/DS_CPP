#pragma once
/*
 *	ɾ���б��е��ظ�Ԫ�� ����ɾ����Ԫ����
 * int deduplicate(); //����ȥ��
*/
template <typename T>
int List<T>::deduplicate()
{
	int oldSize = _size;
	ListNodePosi(T)  p = header;
	Rank r = 0;	//��¼��ǰ���ȣ� find����Ҫ��
	while ((p = p->succ) != trailer)
	{
		ListNodePosi(T) q = find(p->data, r, p);
		q ? remove(q) : r++;	//�ҵ���ͬ��ɾ�� û�ҵ���+1
	}

	return oldSize - _size;
}