#pragma once

/*
 *	ѡ������  �Դ� p ��ʼ��n���ڵ����ѡ������
 * void selectionSort(ListNodePosi(T), int); //�Դ�p��ʼ������n���ڵ�ѡ������
*/
template <typename T>
void List<T>::selectionSort(ListNodePosi(T) p, int n)
{
	
	//����n���ڵ���ѡ�����Ľڵ�
	//auto beginPos = p;	//�洢��ʼλ��   ///������߸պ���pʱ��ɾ��beginpos���±���
	//��˴���p��ǰ��
	auto head = p->pred;
	auto tail = p;
	//��λ������������ ֮�� ��λ��
	for (int i = 0; i < n; i++) tail = tail->succ;
	while (n > 1)
	{
		auto q = selectMax(head->succ, n);
		insertB(tail, q->data);	//��������������ǰ��
		remove(q);	//ɾ���ɽڵ�
		tail = tail->pred;
		n--;
	}

}