#pragma once


template <typename NodePosi>
inline
void attachAsLchild(NodePosi p, NodePosi v) //��v��Ϊp�����ӽ���
{
	p->lChild = v;
	if ( v ) v->parent = p;
}

template <typename NodePosi>
inline
void attachAsRchild(NodePosi p, NodePosi v)//��v��Ϊp���Һ��ӽ���
{
	p->rChild = v;
	if ( v ) v->parent = p;
}

template <typename T>
BinNode<T>* Splay<T>::splay(BinNode<T>* v)
{
	if (!v)return NULL;
	BinNodePosi(T) p; //���ڵ�
	BinNodePosi(T) g; //�游�ڵ�
	while (((p = v->parent)) && (g = p->parent))
	{ //���¶��ϣ�������*v��˫����չ
		BinNodePosi(T) gg = g->parent; //ÿ���Ժ� *v ����ԭ���游��great-grand parent��Ϊ��
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
			attachAsRChild(g, p->lChild);
			attachAsRChild(p, v->lChild);
			attachAsLChild(p, g);
			attachAsLChild(v, p);
		}
		else
		{ //zag-zig
			attachAsRChild(p, v->lChild);
			attachAsLChild(g, v->rChild);
			attachAsRChild(v, g);
			attachAsLChild(v, p);
		}
		if (!gg) //���v��ԭ���游������ �� v����Ӧ��Ϊ����
			v->parent = NULL;
		else
		{ //����*gg�˺�Ӧڹ��*v��Ϊ����Һ���
			(g == gg->lChild) ? attachAsLChild(gg, v) : attachAsRChild(gg, v);
			updateHeight(g);
			updateHeight(p);
			updateHeight(v);
		}
	}
	if (p = v->parent)
	{ //��p����ǿգ����������һ�ε���
		if (IsLChild(*v))
		{
			attachAsLChild(p, v->rChild);
			attachAsRChild(v, p);
		}
		else
		{
			attachAsRChild(p, v->lChild);
			attachAsLChild(v, p);
		}
		updateHeight(p);
		updateHeight(v);
	}
	v->parent = NULL;
	return v;
}
