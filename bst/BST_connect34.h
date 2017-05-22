#pragma once
/*
* 3+4 �ع� ��ʧ����������Ϊƽ������
*/

template<typename T>
BinNodePosi(T) 
BST<T>::connect34( //���ա�3 + 4���ṹ������3���ڵ㼰�Ŀ�����
	BinNodePosi(T) a, BinNodePosi(T) b, BinNodePosi(T) c,
	BinNodePosi(T) t1, BinNodePosi(T) t2, BinNodePosi(T) t3, BinNodePosi(T) t4
)
{
	a->lChild = t1; if ( t1 ) t1->parent = a;
	a->rChild = t2; if ( t2 ) t2->parent = a;
	updateHeight(a);

	c->lChild = t3; if ( t3 ) t3->parent = c;
	c->rChild = t4; if ( t4 ) t4->parent = c;
	updateHeight(c);

	a->parent = b; c->parent = b;
	b->lChild = a; b->rChild = c;
	updateHeight(b);

	return b;//�����µ��������ڵ�
}