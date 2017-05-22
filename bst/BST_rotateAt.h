#pragma once
/*
* AVL树旋转操作，  主要确定a, b, c三个节点的中序顺序
* 对于AVL树 不管失衡前是什么样子，或者是因为什么导致失衡
* 在调整后，其失衡子树最终形态都将调整为 t1 a t2 b t3 c t4
* 其中 a, b, c为AVL树失衡子树的根节点(G)，根节点的最高孩子(P)， 根节点的最高孙子(V) 三者的一种组合
* 因此 所有对AVL树的旋转操作都可以抽象为一种最终状态
* 此函数即确定三者顺序 ，作为参数 传给 connect34()来组成最终的平衡子树
*/

template<typename T>
BinNodePosi(T) 
BST<T>::rotateAt( BinNodePosi(T) v )
{
	BinNodePosi(T) p = v->parent;
	BinNodePosi(T) g = p->parent;
	if ( IsLChild( *p ) )
	{
		if ( IsLChild(*v) ) {//p v 都在左 成一条线
			// 则 a = v, b = p, c = g
			p->parent = g->parent; //向上联接 
			return connect34(v, p, g, v->lChild, v->rChild, p->rChild, g->rChild);
		}
		else
		{
			v->parent = g->parent;
			return connect34(p, v, g, p->lChild, v->lChild, v->rChild, g->rChild);
		}
	}
	else
	{
		if ( IsLChild(*v) ) //从左到右 g v p
		{
			v->parent = g->parent;
			return connect34(g, v, p, g->lChild, v->lChild, v->rChild, p->rChild);
		}
		else
		{
			p->parent = g->parent;
			return connect34(g, p, v, g->lChild, p->lChild, v->lChild, v->rChild);
		}
	}

}