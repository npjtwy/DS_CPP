#pragma once
#include "../bst/BST.h"

 
#define Balanced(x) (stature((x).lChild) == stature((x).rChild)) //理想平衡条件 stature 为节点的高度
#define BalFac(x) (stature((x).lChild) - stature((x).rChild)) //平衡因子
#define AvlBalanced(x) ((-2 < BalFac(x)) && (BalFac(x) < 2)) //AVL平衡条件

/******************************************************************************************
* 在左、右孩子中找更高者，若等高，则与父亲p同侧者优先
* 在AVL平衡调整前，以次此确定重构方案
******************************************************************************************/
#define tallerChild(x) (\
	stature((x)->lChild) > stature((x)->rChild) ? (x)->lChild : ( \
	stature((x)->rChild) > stature((x)->lChild) ? (x)->rChild : ( \
	IsLChild(*(x)) ? (x)->lChild : (x)->rChild \
	) \
	 ) \
	 )

template <typename T>
class AVL : public BST<T>
{
public:
	virtual BinNodePosi(T) insert(const T& e);
	virtual bool remove(const T& e);
	//search 可直接用 BST 的
};

template <typename T>
bool AVL<T>::remove(const T& e)
{
	BinNodePosi(T) x = search(e);
	if ( !x ) return false; //确认目标节点不存在

	removeAt(x, _hot);
	_size--;

	for ( auto g = _hot; g; g = g->parent )	//从父节点开始向上寻找
	{
		if ( !AvlBalanced(*g) )	//遇到不平衡的节点
		{
			//旋转至平衡状态
			g = FromParentTo(*g) = rotateAt(tallerChild(tallerChild(g)));
		}
		updateHeight(g);	//没有不平衡的节点 直接更新高度
	}
	return true;
}
#include "AVL_insert.h"
//#include "AVL_remove.h"