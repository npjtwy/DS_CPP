#pragma once
template <typename T>
BinNode<T>* & Splay<T>::search(const T& e)
{
	//调用BST的内部接口定位目标节点
	BinNodePosi(T) & p = searchIn_it(_root, e, _hot = NULL);
	_root = splay(p ? p : _hot);
	return _root;  //总是返回树根
}
