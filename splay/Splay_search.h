#pragma once
template <typename T>
BinNode<T>* & Splay<T>::search(const T& e)
{
	//����BST���ڲ��ӿڶ�λĿ��ڵ�
	BinNodePosi(T) & p = searchIn_it(_root, e, _hot = NULL);
	_root = splay(p ? p : _hot);
	return _root;  //���Ƿ�������
}
