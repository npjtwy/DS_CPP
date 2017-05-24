#pragma once
template <typename T>
BinNodePosi(T) AVL<T>::insert(const T& e)
{
	if (_size == 0) //空树
	{
		BinNodePosi(T) newNode = insertAsRoot(e);
		_hot = _root;
		return newNode;
	}

	BinNodePosi(T) & x = search(e);
	if (x != NULL) return x; //确认目标节点不存在


	x = new BinNode<T>(e, _hot);
	_size++;
	if (e < _hot->data)
		_hot->lChild = x;
	if (e > _hot->data)
		_hot->rChild = x;

	for (auto g = _hot; g; g = g->parent) //从父节点开始向上寻找
	{
		if (!AvlBalanced(*g)) //遇到不平衡的节点
		{
			//旋转至平衡状态
			FromParentTo(*g) = rotateAt(tallerChild(tallerChild(g)));
			break;
		}
		else
			updateHeight(g); //没有不平衡的节点 直接更新高度
	}
	return x;
}
