#pragma once
/*
 * 伸展树的插入算法
 * 在插入之前必然要进行一次searc操作
 * 而在search之后返回的节点必然已经伸展到了树根位置
 * 所以可以根据情况， 直接在树根位置将新的节点插入，并将新节点作为树根
 */

template <typename T>
BinNode<T>* Splay<T>::insert(const T& e)
{
	if (!_root)
	{
		_size++;
		return _root = new BinNode<T>(e);
	}

	if ( e == search(e)->data ) return _root;//确认新插入的节点不存在

	_size++; BinNodePosi(T) t = _root;
	//如果新节点值大于原根 则将t作为新节点的左孩子， t的右孩子作为新节点的右孩子， 新节点成为根
	if(_root->data < e)
	{
		t->parent = _root = new BinNode<T>(e, NULL, t, t->rChild);
		if ( HasRChild(*t) )
		{
			t->rChild->parent = _root;
			t->rChild = NULL;
		}
	}
	else//另一种情况类似处理
	{
		t->parent = _root = new BinNode<T>(e, NULL, t->lChild, t);
		if (HasLChild(*t))
		{
			t->lChild->parent = _root;
			t->lChild = NULL;
		}
	}

	updateHeightAbove(t);//更新t及其祖先高度
	return _root;
}
