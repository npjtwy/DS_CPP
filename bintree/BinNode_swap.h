#pragma once
template <typename T>
void BinNode<T>::swap()
{
	BinNodePosi(T) s = this;
	if (IsLeaf(*this))
		return;
	lChild->swap();
	rChild->swap();
	BinNodePosi(T) temp = lChild;
	lChild = rChild;
	rChild = temp;
}