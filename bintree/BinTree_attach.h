#pragma once
/************************************************************************
* BinNodePosi(T) attachAsLC ( BinNodePosi(T) x, BinTree<T>* &T ); //T��Ϊx����������
* BinNodePosi(T) attachAsRC ( BinNodePosi(T) x, BinTree<T>* &T ); //T��Ϊx����������
************************************************************************/

template <typename T>
BinNodePosi(T) BinTree<T>::attachAsLC(BinNodePosi(T) x, BinTree<T>* &S)
{
	if (x->lChild = S->_root) x->lChild->parent = x;
	_size += S->_size;
	updateHeightAbove(x);
	S->_root = NULL;
	S->_size = 0;
	release(S);		//�ͷ�ԴS�����нڵ� 
	S = NULL;
	return x;
}

template <typename T>
BinNodePosi(T) BinTree<T>::attachAsRC(BinNodePosi(T) x, BinTree<T>* &S)
{
	if (x->rChild = S->_root) x->rChild->parent = x;
	_size += S->_size;
	updateHeightAbove(x);
	S->_root = NULL;
	S->_size = 0;
	release(S);		//�ͷ�ԴS�����нڵ� 
	S = NULL;
	return x;
}