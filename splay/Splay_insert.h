#pragma once
/*
 * ��չ���Ĳ����㷨
 * �ڲ���֮ǰ��ȻҪ����һ��searc����
 * ����search֮�󷵻صĽڵ��Ȼ�Ѿ���չ��������λ��
 * ���Կ��Ը�������� ֱ��������λ�ý��µĽڵ���룬�����½ڵ���Ϊ����
 */

template <typename T>
BinNode<T>* Splay<T>::insert(const T& e)
{
	if (!_root)
	{
		_size++;
		return _root = new BinNode<T>(e);
	}

	if ( e == search(e)->data ) return _root;//ȷ���²���Ľڵ㲻����

	_size++; BinNodePosi(T) t = _root;
	//����½ڵ�ֵ����ԭ�� ��t��Ϊ�½ڵ�����ӣ� t���Һ�����Ϊ�½ڵ���Һ��ӣ� �½ڵ��Ϊ��
	if(_root->data < e)
	{
		t->parent = _root = new BinNode<T>(e, NULL, t, t->rChild);
		if ( HasRChild(*t) )
		{
			t->rChild->parent = _root;
			t->rChild = NULL;
		}
	}
	else//��һ��������ƴ���
	{
		t->parent = _root = new BinNode<T>(e, NULL, t->lChild, t);
		if (HasLChild(*t))
		{
			t->lChild->parent = _root;
			t->lChild = NULL;
		}
	}

	updateHeightAbove(t);//����t�������ȸ߶�
	return _root;
}
