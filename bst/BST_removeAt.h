#pragma once
#include "../_share/release.h"
/************************************************************************
* ʵʩ����Ķ�����������ɾ������
* ���ر�ɾ���ڵ�Ľ�����
************************************************************************/

template <typename T>
static BinNodePosi(T)
removeAt(BinNodePosi(T)& x, BinNodePosi(T)& hot) //ɾ��
{
	BinNodePosi(T) w = x;	//Ҫɾ���Ľڵ�
	BinNodePosi(T) succ = nullptr;	//Ҫɾ���Ľڵ�ļ�����
	
	if (!HasLChild(*x))	//���û�����ӣ� succָ���Һ���
		succ = x = x->rChild;
	else if (!HasRChild(*x))	//�Գ����
		succ = x = x->lChild;
	else if(HasBothChild(*x))	//���û�к���
	{
		w = w->succ();
		std::swap(w->data, x->data);	//������ɾ���ڵ�����̵�ֵ ת��ɾ������
		BinNodePosi(T) u = w->parent;
		((u == x) ? u->rChild : u->lChild) = succ = w->rChild;	//��̽ڵ�ĸ��ڵ�ָ����һ�����ӣ�����ΪNULL��
	}

	hot = w->parent;
	if (succ) succ->parent = hot;	
	//�о������� ���ڵ�������ֻ�ǽ������ߵĸ��ڵ�ָ����w�ĸ��ڵ㣬��w���ڵ��childָ���أ����ͳ�NULL�ˣ���
	//�����������д����� w �ĸ��ڵ�ĺ���ָ��succ
	if (IsRChild(*w)) hot->rChild = succ;
	else hot->lChild = succ;

	release(w->data);
	release(w);
	return succ;
}