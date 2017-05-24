#pragma once
#include "../bst/BST.h"


template <typename T>
class Splay :  public BST<T>
{
protected:

	BinNodePosi(T) splay(BinNodePosi(T) v);  //将节点伸展至根
public:
	BinNodePosi(T) & search(const T& e);
	BinNodePosi(T) insert(const T& e);
	bool remove(const T& e);
};

#include "splay_implementation.h"