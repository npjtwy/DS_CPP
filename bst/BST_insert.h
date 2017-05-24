#pragma once
template <typename T>
BinNodePosi(T) BST<T>::insert(const T& e) //����
{
	if ( _size == 0 ) //����
	{
		BinNodePosi(T) newNode = insertAsRoot(e);
		_hot = _root;
		return newNode;
	}

	BinNodePosi(T)  & newNode = search(e);
	if ( newNode != NULL) 	return newNode;//���ҵ�ֵΪ e �ĵ㷵��

	newNode = new BinNode<T>(e, _hot);	//�����½ڵ㣬�丸�ڵ�Ϊ _hot
	_size++;	//���¶�����״̬
	if ( e < _hot->data )
		_hot->lChild = newNode;
	if ( e > _hot->data )
		_hot->rChild = newNode;
	
	updateHeightAbove(newNode);
	return newNode;
}