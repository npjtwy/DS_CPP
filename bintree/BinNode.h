/******************************************************************************************
* Data Structures in C++
* ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
* Junhui DENG, deng@tsinghua.edu.cn
* Computer Science & Technology, Tsinghua University
* Copyright (c) 2006-2013. All rights reserved.
******************************************************************************************/

#pragma once

#define BinNodePosi(T) BinNode<T>* //节点位置
#define stature(p) ((p) ? (p)->height : -1) //节点高度（与“空树高度为-1”的约定相统一）
typedef enum { RB_RED, RB_BLACK } RBColor; //节点颜色

template <typename T> struct BinNode { //二叉树节点模板类
									   // 成员（为简化描述起见统一开放，读者可根据需要进一步封装）
	T data; //数值
	BinNodePosi(T) parent; 
	BinNodePosi(T) lChild; 
	BinNodePosi(T) rChild; //父节点及左、右孩子
	int height; //高度（通用）
	int npl; //Null Path Length（左式堆，也可直接用height代替）
	RBColor color; //颜色（红黑树）
				   // 构造函数
	BinNode() :
		parent(NULL), lChild(NULL), rc(NULL), height(0), npl(1), color(RB_RED) { }
	BinNode(T e, BinNodePosi(T) p = 0, BinNodePosi(T) lc = 0, BinNodePosi(T) rc = 0,
		int h = 0, int l = 1, RBColor c = RB_RED) :
		data(e), parent(p), lChild(lc), rChild(rc), height(h), npl(l), color(c) { }
	// 操作接口
	int size(); //统计当前节点后代总数，亦即以其为根的子树的规模
	BinNodePosi(T) insertAsLC(T const&); //作为当前节点的左孩子插入新节点
	BinNodePosi(T) insertAsRC(T const&); //作为当前节点的右孩子插入新节点
	BinNodePosi(T) succ(); //取当前节点的直接后继
	BinNodePosi(T) pred();	//取当前节点的直接后继
	template <typename VST> void travLevel(VST&); //子树层次遍历
	template <typename VST> void travPre(VST&); //子树先序遍历
	template <typename VST> void travIn(VST&); //子树中序遍历
	template <typename VST> void travPost(VST&); //子树后序遍历
	void swap();

												 // 比较器、判等器（各列其一，其余自行补充）
	bool operator< (BinNode const& bn) { return data < bn.data; } //小于
	bool operator== (BinNode const& bn) { return data == bn.data; } //等于
	bool operator> (BinNode const& bn) { return data > bn.data; }
	bool operator<=(BinNode const& bn) { return !(this > bn); }
	bool operator>=(BinNode const& bn) { return !(this < bn); }
																	/*DSA*/
	/*DSA*/BinNodePosi(T) zig(); //顺时针旋转
	/*DSA*/BinNodePosi(T) zag(); //逆时针旋转
};

/******************************************************************************************
 * BinNode状态与性质的判断
****************************************************************************************/
#define IsRoot(x) (!((x).parent))
#define IsLChild(x) (!IsRoot(x) && (&(x) == (x).parent->lChild))
#define IsRChild(x) (!IsRoot(x) && (&(x) == (x).parent->rChild))
#define HasParent(x) (!IsRoot(x))
#define HasLChild(x) ((x).lChild)
#define HasRChild(x) ((x).rChild)
#define HasChild(x) (HasLChild(x) || HasRChild(x)) //至少拥有一个孩子
#define HasBothChild(x) (HasLChild(x) && HasRChild(x)) //同时拥有两个孩子
#define IsLeaf(x) (!HasChild(x))

/******************************************************************************************
* 与BinNode具有特定关系的节点及指针
******************************************************************************************/
#define sibling(p) (\
	IsLChild(*(p)) ? \
		(p)->parent->rChild : \
		(p)->parent->lChild \
) //兄弟

#define uncle(x) (\
	IsLChild(*((x)->parent)) ? \
			(x)->parent->parent->rChild : \
			(x)->parent->parent->lChild \
	) //叔叔

#define FromParentTo(x) (\
				IsRoot(x) ? _root : ( \
				IsLChild(x) ? (x).parent->lChild : (x).parent->rChild \
				) \
			) //来自父亲的指针


#include "BinNode_implementation.h"