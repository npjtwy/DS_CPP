#pragma once
/*
 *	�������б�Ψһ��
*/

template <typename T>
int List<T>::uniquify()
{
	//int oldSize = _size;
	//Rank r = 0;
	//ListNodePosi p = first();
	//ListNodePosi q = p->succ;
	//while (q != trailer)
	//{
	//	if (q->data != p->data)
	//	{
	//		(p = p->succ)->data = q->data;	//������p��ֵ��ͬ�Ľڵ�ʱ��pָ����һ�ڵ㣬Ȼ��qָ�Ľڵ�ֵ����p
	//		r++;
	//	}
	//	q = q->succ;	//q����Ѱ����һ����p��ֵ��ͬ�Ľڵ�
	//}
	////��ʱ p ָ�����һ�����ظ��Ľڵ㣬p��trailer֮��Ķ���Ҫɾ��
	////�Ҿ�������Ҫɾ���Ľڵ����´���һ������Ȼ���ٽ������١�������û�и��õİ취�أ�

	//List<T>* newlist = new List<T>;
	//newList->_size = r + 1;
	//newList->header->succ = p->succ;
	//newList->trailer->pred = this->trailer->pred;
	////�ô�ɾ���ڵ���Դ�б�Ͽ���ϵ
	//p->succ->pred = newList->header;
	//trailer->pred->succ = newList->trailer;
	//p->succ = trailer;
	//trailer->pred = p;
	//
	//delete newList;
	//_size = r + 1;	//rΪɾ������б����һ���ڵ���ȣ����sizeΪr+1
	//return oldSize - _size;	

	//̫���ˣ���
	//����

	if (_size < 2) return 0;
	int oldSize = _size;
	ListNodePosi(T) p;
	ListNodePosi(T) q;
	for (p = header, q = p->succ; q != trailer; p = q, q = q->succ)
	{
		if (p->data == q->data)
		{
			remove(q);
			q = p;
		}
	}

	return oldSize - _size;
}