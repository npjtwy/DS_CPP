#pragma once
/*
* AVL����ת������  ��Ҫȷ��a, b, c�����ڵ������˳��
* ����AVL�� ����ʧ��ǰ��ʲô���ӣ���������Ϊʲô����ʧ��
* �ڵ�������ʧ������������̬��������Ϊ t1 a t2 b t3 c t4
* ���� a, b, cΪAVL��ʧ�������ĸ��ڵ�(G)�����ڵ����ߺ���(P)�� ���ڵ���������(V) ���ߵ�һ�����
* ��� ���ж�AVL������ת���������Գ���Ϊһ������״̬
* �˺�����ȷ������˳�� ����Ϊ���� ���� connect34()��������յ�ƽ������
*/

template<typename T>
BinNodePosi(T) 
BST<T>::rotateAt( BinNodePosi(T) v )
{
	BinNodePosi(T) p = v->parent;
	BinNodePosi(T) g = p->parent;
	if ( IsLChild( *p ) )
	{
		if ( IsLChild(*v) ) {//p v ������ ��һ����
			// �� a = v, b = p, c = g
			p->parent = g->parent; //�������� 
			return connect34(v, p, g, v->lChild, v->rChild, p->rChild, g->rChild);
		}
		else
		{
			v->parent = g->parent;
			return connect34(p, v, g, p->lChild, v->lChild, v->rChild, g->rChild);
		}
	}
	else
	{
		if ( IsLChild(*v) ) //������ g v p
		{
			v->parent = g->parent;
			return connect34(g, v, p, g->lChild, v->lChild, v->rChild, p->rChild);
		}
		else
		{
			p->parent = g->parent;
			return connect34(g, p, v, g->lChild, p->lChild, v->lChild, v->rChild);
		}
	}

}