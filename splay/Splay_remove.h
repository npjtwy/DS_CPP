#pragma once
/*
 * ɾ���㷨������㷨����
 * �������Ҵ�ɾ���ڵ�� ��ɾ���ڵ��Ѿ���չ������
 * ���ֻ���ø��ڵ�ĺ��������ڵ㼴��
 */

template <typename T>
bool Splay<T>::remove(const T& e)
{
	if ( !_root || (e != search(e)->data) )
		return false;
	BinNodePosi(T) w = _root;
	if(!HasLChild(*_root))//����������ֱ��ɾ��
	{
		_root = _root->rChild;
		if ( _root ) _root->parent = NULL;
	}
	else if(!HasRChild(*_root))
	{
		_root = _root->lChild;
		if ( _root ) _root->parent = NULL;
	}
	else
	{
		BinNodePosi(T) lTree = _root->lChild;

		//���������г� ����������
		lTree->parent = NULL;
		_root->lChild = NULL;
		_root = _root->rChild;
		_root->parent = NULL;

		//��ԭ����ΪĿ����� Ŀ���ǽ�ԭ�����ĺ����չ������λ��
		search(w->data);
		// ���ˣ�����������С�ڵ����չ�������ң�������ͬ�ڵ㣩���������ؿգ�ء��
		_root->lChild = lTree; lTree->parent = _root; //���轫ԭ�������ӻ�ԭλ����
		
	}
	
	release(w->data); release(w); _size--; //�ͷŽڵ㣬���¹�ģ
	if ( _root ) updateHeight(_root); //�˺������ǿգ��������ĸ߶���Ҫ����
	return true; //���سɹ���־
}
