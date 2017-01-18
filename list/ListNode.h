#pragma once
typedef int Rank;	//��
/*
template <typename T>
using	ListNodePosi = ListNode<T>*;	//error ԭ��δ֪
//����*/
#define ListNodePosi(T) ListNode<T>*

template <typename T>
struct ListNode 
{
	T data;
	ListNodePosi(T) pred;	//ǰ��
	ListNodePosi(T) succ;	//���

	ListNode(){}
	ListNode(T e, ListNodePosi(T) p = NULL, ListNodePosi(T) s = NULL)
		: data(e), pred(p), succ(s){}

	//�����ӿ�
	ListNodePosi(T) insertAsPred(T const& e);	//��Ϊǰ������
	ListNodePosi(T) insertAsSucc(T const& e);	//��Ϊ��̲���
};

template<typename T>
inline ListNodePosi(T) ListNode<T>::insertAsPred(T const & e)
{
	/*ListNodePosi(T) p = new ListNode;
	p->data = e;
	p->succ = this;
	p->pred = this->pred;
	this->pred->succ = p;
	this->pred = p;*/  //̫����
	ListNodePosi(T) p = new ListNode(e, pred, this);
	//�½���� ����ǰ����ǰ����Ϊ�½ڵ�ǰ������ǰ�ڵ㼴Ϊ�½ڵ�ĺ��

	this->pred->succ = p; this->pred = p;
	//��ǰ�ڵ��ǰ���ĺ����Ϊ p ��ǰ�ڵ��ǰ����Ϊ p
	return p;
	//���ز���λ��
}

template<typename T>
inline ListNodePosi(T) ListNode<T>::insertAsSucc(T const & e)
{
	/*ListNodePosi(T) p = new ListNode;
	p->data = e;
	p->pred = this;
	p->succ = this->succ;
	this->succ->pred = p;
	this->succ = p;*/

	ListNodePosi(T) p = new ListNode(e, this, this->succ);
	this->succ->pred = p;
	this->succ = p;

	return p;
}
