#pragma once
template <typename T>
BinNodePosi(T) BST<T>::insert(const T& e) //插入
{
	if ( _size == 0 ) //空树
	{
		BinNodePosi(T) newNode = insertAsRoot(e);
		_hot = _root;
		return newNode;
	}

	BinNodePosi(T)  & newNode = search(e);
	if ( newNode != NULL) 	return newNode;//若找到值为 e 的点返回

	newNode = new BinNode<T>(e, _hot);	//建立新节点，其父节点为 _hot
	_size++;	//更新二叉树状态
	if ( e < _hot->data )
		_hot->lChild = newNode;
	if ( e > _hot->data )
		_hot->rChild = newNode;
	
	updateHeightAbove(newNode);
	return newNode;
}