#pragma once
/*
 *	���ƽڵ�
 *void copyNodes(ListNodePosi(T), int); //�����б�����λ��p���n��
*/
template <typename T>

void List<T>::copyNodes(ListNodePosi(T) p, int n) //�����б�����λ��p���n��
{
	this->init();	//����ͷβ�ڵ� ����ʼ��
	while (0 < n--)
	{
		//����β�巨����
		insertAsLast(p->data);
		p = p->succ;
	}
}