#pragma once
#include "ListNode.h"

template <typename T> 
class List
{
private:
	int _size; ListNodePosi(T) header; ListNodePosi(T) trailer;	//��ģ ͷ�ڱ� β�ڱ�

protected:
	void init(); //�б���ʱ�ĳ�ʼ��
	
	void copyNodes(ListNodePosi(T) p, int n); //�����б�����λ��p���n��
	void merge(ListNodePosi(T)& p, int n, List<T>& L, ListNodePosi(T) q, int m); //�鲢
	void mergeSort(ListNodePosi(T)&p, int n); //�Դ�p��ʼ������n���ڵ�鲢����
	void selectionSort(ListNodePosi(T) p, int n); //�Դ�p��ʼ������n���ڵ�ѡ������
	void insertionSort(ListNodePosi(T) p, int n); //�Դ�p��ʼ������n���ڵ��������

public:
	// ���캯��
	int clear(); //������нڵ�
	List() { init(); } //Ĭ��
	List(List<T> const& L); //���帴���б�L
	List(List<T> const& L, Rank r, int n); //�����б�L���Ե�r�����n��
	List(ListNodePosi(T) p, int n); //�����б�����λ��p���n��
									// ��������
	~List(); //�ͷţ�����ͷ��β�ڱ����ڵģ����нڵ�
			 // ֻ�����ʽӿ�
	Rank size() const { return _size; } //��ģ
	bool empty() const { return _size <= 0; } //�п�
	T& operator[] (Rank r) const; //���أ�֧��ѭ�ȷ��ʣ�Ч�ʵͣ�
	ListNodePosi(T) first() const { return header->succ; } //�׽ڵ�λ��
	ListNodePosi(T) last() const { return trailer->pred; } //ĩ�ڵ�λ��
	bool valid(ListNodePosi(T) p) //�ж�λ��p�Ƿ����Ϸ�
	{
		return p && (trailer != p) && (header != p);
	} //��ͷ��β�ڵ��ͬ��NULL
	//int disordered() const; //�ж��б��Ƿ�������
	ListNodePosi(T) find(T const& e) const //�����б����
	{
		return find(e, _size, trailer);
	}
	ListNodePosi(T) find(T const& e, int n, ListNodePosi(T) p) const; //�����������
	ListNodePosi(T) search(T const& e) const //�����б����
	{
		return search(e, _size, trailer);
	}
	ListNodePosi(T) search(T const& e, int n, ListNodePosi(T) p) const; //�����������
	ListNodePosi(T) selectMax(ListNodePosi(T) p, int n); //��p����n-1�������ѡ�������
	ListNodePosi(T) selectMax() { return selectMax(header->succ, _size); } //���������
																		   // ��д���ʽӿ�
	ListNodePosi(T) insertAsFirst(T const& e); //��e�����׽ڵ����
	ListNodePosi(T) insertAsLast(T const& e); //��e����ĩ�ڵ����
	ListNodePosi(T) insertA(ListNodePosi(T) p, T const& e); //��e����p�ĺ�̲���
	ListNodePosi(T) insertB(ListNodePosi(T) p, T const& e); //��e����p��ǰ������
	T remove(ListNodePosi(T) p); //ɾ���Ϸ�λ��p���Ľڵ�,���ر�ɾ���ڵ�
	void merge(List<T>& L) { merge(first(), size, L, L.first(), L._size); } //ȫ�б�鲢
	void sort(ListNodePosi(T) p, int n); //�б���������
	void sort() { sort(first(), _size); } //�б���������
	int deduplicate(); //����ȥ��
	int uniquify(); //����ȥ��
	void reverse(); //ǰ���ã�ϰ�⣩
					// ����
	void traverse(void(*visit)(T &));
	//����������ʵʩvisit����������ָ�룬ֻ����ֲ����޸ģ�
	template <typename VST> //������
	void traverse(VST& visit);
	//����������ʵʩvisit�������������󣬿�ȫ�����޸ģ�

}; //List

#include "List_implementation.h"

//template <typename T>
//inline
//T& List<T>::operator[](Rank r) const
//{
//	ListNodePosi(T) p = fist();
//	while (0 < r--) p = p->succ;
//	return p;
//}
//
//template <typename T>
//inline
//void List<T>::init()
//{
//	header = new ListNode<T>;
//	trailer = new ListNode<T>;	//����ͷβ���
//	header->pred = NULL;  trailer->pred = header;
//	header->succ = trailer; trailer->succ = NULL;
//	_size = 0;
//}
//
///*
//*	���ƽڵ�
//*/
//template <typename T>
//inline
////void copyNodes(ListNodePosi(T), int); //�����б�����λ��p���n��
//void List<T>::copyNodes(ListNodePosi(T) p, int n) //�����б�����λ��p���n��
//{
//	init();	//����ͷβ�ڵ� ����ʼ��
//	while (0 < n--)
//	{
//		//����β�巨����
//		insertAsLast(p->data);
//		p = p->succ;
//	}
//}
//
//   /*
//   *	List(List<T> const& L); //���帴���б�L
//   *	List(List<T> const& L, Rank r, int n); //�����б�L���Ե�r�����n��
//   *	List(ListNodePosi(T) p, int n); //�����б�����λ��p���n��
//   */
//template <typename T>
//inline
//List<T>::List(List<T> const& L)
//{
//	this->copyNodes(L.fist(), L._size);
//}
//
//
///*
//*	�����������  ȫ�ֲ���Ϊǰ�ߵ�һ������
//*  �������б�֮�ڵĽ�� p �� n ��ǰ���в��� ���� e �����һ�����
//*/
//
//template <typename T>
//inline
//ListNodePosi(T) List<T>::find(T const& e, int n, ListNodePosi(T) p) const
//{
//	while (0 < n--)
//	{
//		if (e == (p = p->pred)->data)
//		{
//			return p;
//		}
//	}
//	return NULL;
//}
//
//
//
///*
//*	List ����ӿ�
//*/
//
//template <typename T>
//inline
//ListNodePosi(T) List<T>::insertAsFirst(T const& e)
//{
//	_size++;
//	return header->insertAsSucc(e);
//}
//
//template <typename T>
//inline
//ListNodePosi(T) List<T>::insertAsLast(T const & e)
//{
//	_size++;
//	return trailer->insertAsPred(e);
//}
//
//template <typename T>
//inline
//ListNodePosi(T) List<T>::insertA(ListNodePosi(T) p, T const& e)//��e����p�ĺ�̲���
//{
//	_size++;
//	return p->insertAsSucc(e);
//}
//
//template <typename T>
//inline
//ListNodePosi(T) List<T>::insertB(ListNodePosi(T) p, T const& e)//e��Ϊp��ǰ������
//{
//	_size++;
//	return p->insertAsPred(e);
//}
//
