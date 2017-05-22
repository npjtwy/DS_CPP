#pragma once
#include "../bst/BST.h"

 
#define Balanced(x) (stature((x).lChild) == stature((x).rChild)) //����ƽ������ stature Ϊ�ڵ�ĸ߶�
#define BalFac(x) (stature((x).lChild) - stature((x).rChild)) //ƽ������
#define AvlBalanced(x) ((-2 < BalFac(x)) && (BalFac(x) < 2)) //AVLƽ������

/******************************************************************************************
* �����Һ������Ҹ����ߣ����ȸߣ����븸��pͬ��������
* ��AVLƽ�����ǰ���Դδ�ȷ���ع�����
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
	//search ��ֱ���� BST ��
};

template <typename T>
bool AVL<T>::remove(const T& e)
{
	BinNodePosi(T) x = search(e);
	if ( !x ) return false; //ȷ��Ŀ��ڵ㲻����

	removeAt(x, _hot);
	_size--;

	for ( auto g = _hot; g; g = g->parent )	//�Ӹ��ڵ㿪ʼ����Ѱ��
	{
		if ( !AvlBalanced(*g) )	//������ƽ��Ľڵ�
		{
			//��ת��ƽ��״̬
			g = FromParentTo(*g) = rotateAt(tallerChild(tallerChild(g)));
		}
		updateHeight(g);	//û�в�ƽ��Ľڵ� ֱ�Ӹ��¸߶�
	}
	return true;
}
#include "AVL_insert.h"
//#include "AVL_remove.h"