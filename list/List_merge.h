#pragma once
/*
 * �б�Ķ�·�鲢 
 * ��ǰ�б����� p ��� n ��Ԫ�� ���б� L ���� q ��� m ��Ԫ�ؽ��й鲢
*/
template <typename T>
void List<T>::merge(ListNodePosi(T) &p, int n, List<T> &L, ListNodePosi(T) q, int m)
/*
* this.valid(p) && rank(p) + n <= _size  &&  this.sorted(p, n)
* L ͬ��
*/
{
	auto pp = p->pred;	//��¼p��ǰ��
	while (m > 0)
	{
		if ((0 < n) && (p->data <= q->data))	//p���n���ڵ�δ������
		{
			if (q == (p = p->succ)) break;	//���￼�ǵ���this��L��ͬһ��list ��q Ϊp�ĺ��ʱ���鲢�Ѿ����
			n--;
		}

		else  //p�Ѿ�����  ���� p->data > q->data
		{
			//��q���뵽p֮ǰ ɾ����q�ɽڵ�
			insertB(p, L.remove((q = q->succ)->pred));
			m--;
		}
	}
	p = pp->succ;	//�鲢����������
}