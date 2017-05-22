#pragma once
#include "../bintree/BinTree.h" //引入BinTree

template <typename T> 
class BST : public BinTree<T> { //由BinTree派生BST模板类
protected:
	BinNodePosi(T) _hot; //“命中”节点的父亲
	BinNodePosi(T) connect34( //按照“3 + 4”结构，联接3个节点及四棵子树
		BinNodePosi(T) a, BinNodePosi(T) b, BinNodePosi(T) c,
		BinNodePosi(T) t1, BinNodePosi(T) t2, BinNodePosi(T) t3, BinNodePosi(T) t4);
	BinNodePosi(T) rotateAt(BinNodePosi(T) x); //对x及其父亲、祖父做统一旋转调整

public: //基本接口：以virtual修饰，强制要求所有派生类（BST变种）根据各自的规则对其重写
	virtual BinNodePosi(T)  search(const T& e); //查找
	virtual BinNodePosi(T) insert(const T& e); //插入
	virtual bool remove(const T& e); //删除
};

#include "BST_implementation.h"