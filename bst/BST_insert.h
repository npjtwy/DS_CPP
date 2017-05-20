#pragma once
template <typename T>
BinNodePosi(T) BST<T>::insert(const T& e) //����
{
	auto newNode = search(e);	
	if (newNode) return newNode;	//���ҵ�ֵΪ e �ĵ� ���ò���

	newNode = new BinNode<T>(e, _hot);	//�����½ڵ㣬�丸�ڵ�Ϊ _hot
	_size++;	//���¶�����״̬
	updateHeightAbove(newNode);
	return newNode;
}