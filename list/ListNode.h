#pragma once
typedef int Rank;	//秩
/*
template <typename T>
using	ListNodePosi = ListNode<T>*;	//error 原因未知
//代替*/
#define ListNodePosi(T) ListNode<T>*

template <typename T>
struct ListNode 
{
	T data;
	ListNodePosi(T) pred;	//前驱
	ListNodePosi(T) succ;	//后继

	ListNode(){}
	ListNode(T e, ListNodePosi(T) p = NULL, ListNodePosi(T) s = NULL)
		: data(e), pred(p), succ(s){}

	//操作接口
	ListNodePosi(T) insertAsPred(T const& e);	//作为前驱插入
	ListNodePosi(T) insertAsSucc(T const& e);	//作为后继插入
};

template<typename T>
inline ListNodePosi(T) ListNode<T>::insertAsPred(T const & e)
{
	/*ListNodePosi(T) p = new ListNode;
	p->data = e;
	p->succ = this;
	p->pred = this->pred;
	this->pred->succ = p;
	this->pred = p;*/  //太繁琐
	ListNodePosi(T) p = new ListNode(e, pred, this);
	//新建结点 将当前结点的前驱即为新节点前驱，当前节点即为新节点的后继

	this->pred->succ = p; this->pred = p;
	//当前节点的前驱的后继设为 p 当前节点的前驱设为 p
	return p;
	//返回插入位置
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
