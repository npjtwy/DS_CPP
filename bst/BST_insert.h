#pragma once
template <typename T>
BinNodePosi(T) BST<T>::insert(const T& e) //插入
{
	auto newNode = search(e);	
	if (newNode) return newNode;	//若找到值为 e 的点 不用插入

	newNode = new BinNode<T>(e, _hot);	//建立新节点，其父节点为 _hot
	_size++;	//更新二叉树状态
	updateHeightAbove(newNode);
	return newNode;
}