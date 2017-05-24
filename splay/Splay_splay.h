#pragma once


template <typename NodePosi>
inline
void attachAsLchild(NodePosi p, NodePosi v) //将v作为p的左孩子接入
{
	p->lChild = v;
	if ( v ) v->parent = p;
}

template <typename NodePosi>
inline
void attachAsRchild(NodePosi p, NodePosi v)//将v作为p的右孩子接入
{
	p->rChild = v;
	if ( v ) v->parent = p;
}

template <typename T>
BinNode<T>* Splay<T>::splay(BinNode<T>* v)
{
	if (!v)return NULL;
	BinNodePosi(T) p; //父节点
	BinNodePosi(T) g; //祖父节点
	while (((p = v->parent)) && (g = p->parent))
	{ //自下而上，反复对*v做双局伸展
		BinNodePosi(T) gg = g->parent; //每轮以后 *v 都以原曾祖父（great-grand parent）为父
		if (IsLChild(*v))
		{
			if (IsLChild(*p))
			{
				attachAsLchild(g, p->rChild);
				attachAsLchild(p, v->rChild);
				attachAsRchild(p, g);
				attachAsRchild(v, p);
			}
			else
			{
				attachAsLchild(p, v->rChild);
				attachAsRchild(g, v->lChild);
				attachAsLchild(v, g);
				attachAsRchild(v, p);
			}
		}
		else if (IsRChild(*p))
		{ //zag-zag
			attachAsRchild(g, p->lChild);
			attachAsRchild(p, v->lChild);
			attachAsLchild(p, g);
			attachAsLchild(v, p);
		}
		else
		{ //zag-zig
			attachAsRchild(p, v->lChild);
			attachAsLchild(g, v->rChild);
			attachAsRchild(v, g);
			attachAsLchild(v, p);
		}
		if (!gg) //如果v的原曾祖父不存在 则 v现在应该为树根
			v->parent = NULL;
		else
		{ //否则，*gg此后应诠以*v作为左戒右孩子
			(g == gg->lChild) ? attachAsLchild(gg, v) : attachAsRchild(gg, v);
			updateHeight(g);
			updateHeight(p);
			updateHeight(v);
		}
	}
	if (p = v->parent)
	{ //若p果真非空，则额外再做一次单旋
		if (IsLChild(*v))
		{
			attachAsLchild(p, v->rChild);
			attachAsRchild(v, p);
		}
		else
		{
			attachAsRchild(p, v->lChild);
			attachAsLchild(v, p);
		}
		updateHeight(p);
		updateHeight(v);
	}
	v->parent = NULL;
	return v;
}
