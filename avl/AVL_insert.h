#pragma once
template <typename T>
BinNodePosi(T) AVL<T>::insert(const T& e)
{
	if (_size == 0) //����
	{
		BinNodePosi(T) newNode = insertAsRoot(e);
		_hot = _root;
		return newNode;
	}

	BinNodePosi(T) & x = search(e);
	if (x != NULL) return x; //ȷ��Ŀ��ڵ㲻����


	x = new BinNode<T>(e, _hot);
	_size++;
	if (e < _hot->data)
		_hot->lChild = x;
	if (e > _hot->data)
		_hot->rChild = x;

	for (auto g = _hot; g; g = g->parent) //�Ӹ��ڵ㿪ʼ����Ѱ��
	{
		if (!AvlBalanced(*g)) //������ƽ��Ľڵ�
		{
			//��ת��ƽ��״̬
			FromParentTo(*g) = rotateAt(tallerChild(tallerChild(g)));
			break;
		}
		else
			updateHeight(g); //û�в�ƽ��Ľڵ� ֱ�Ӹ��¸߶�
	}
	return x;
}
