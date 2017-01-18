#pragma once
#include "BinTree.h"

//�жϸ��������нڵ����ֵ����С���������ȵ���ֵ֮��
template <typename T>
bool isCGTP(BinNodePosi(T) root)
{

	if (root)
	{
		Stack<BinNodePosi(T)> s;	//����ǰ�������Žڵ�
		Stack<float> sf;		//��Žڵ�������ֵ�ú� ��ͬʱ����s�Ľڵ��Ӧ
		if (root->data <= 0) return false;
		s.push(root);	//root�ڵ���ջ
		sf.push(0);		//����root�ڵ�����ֵ�ú� �� 0

		while (!s.empty())
		{
			BinNodePosi(T) p = s.pop();	//����ջ���ڵ�
			float sum_of_parent = sf.pop();	//����p��Ӧ����ֵ�ĺ�

			if (p->data < sum_of_parent)	//�Ƚ�p��ֵ���������ȵ�ֵ�ĺ�
				return false;
			sum_of_parent += p->data;	//��������ֵ�ĺ�
			if (HasRChild(*p))
			{
				s.push(p->rChild);	//�����Һ���  ��ջ	
				sf.push(sum_of_parent);	//��Ӧ����ջ�ڵ������ֵ�ĺ�Ҳ��ջ
			}
			if (HasLChild(*p))
			{
				s.push(p->lChild);
				sf.push(sum_of_parent);
			}
		}
		return true;
	}

	else {
		printf("invalid node\n");
		return false;
	}
}

//�ú����е����ֵ�滻�ڵ��ֵ �ݹ��  ���������ú�����������������һЩ��������
template <typename T>
void RplaceData(BinNodePosi(T) root)
{
	if ((!root) || (!HasLChild(*root) && !HasRChild(*root)))
		return;	//�սڵ����û�к��ӽڵ� ����    �ݹ��
	RplaceData(root->lChild);
	RplaceData(root->rChild);

	if (HasLChild(*root) && HasRChild(*root))	//������������ ��ڵ�ֵΪ���������нϴ��һ��
		root->data = max(root->lChild->data, root->rChild->data);
	//ֻ��һ������  ��������
	else
		root->data = (HasLChild(*root)) ? root->lChild->data : root->rChild->data;
}

//ʵ�ֵݹ��㷨 ����Ϊ0 ������ֵΪk�Ľڵ� ��������ֵΪ2k+1 �Һ���Ϊ2k+2
template <typename T>
void SetValue(BinNodePosi(T) root)
{
	if (!root)
		return;	//�ݹ��
	if (IsLChild(*root))
		root->data = 2 * root->parent->data + 1;
	else if (IsRChild(*root))
	{
		root->data = 2 * root->parent->data + 2;
	}
	else
		root->data = 0;

	SetValue(root->lChild);
	SetValue(root->rChild);
}

//������
#include "../stack/Stack.h"
template <typename T>
void SetValue_Iter(BinNodePosi(T) root)
{
	Stack<BinNodePosi(T)> s;

	if (!root)
	{
		printf("invalid node\n");
		return;
	}

	s.push(root);

	while (!s.empty())
	{
		auto p = s.pop();
		if (IsRoot(*p))
			p->data = 0;	//��Ϊ���ڵ� ��Ϊ0
		if (IsLChild(*p))
			p->data = p->parent->data * 2 + 1;
		if (IsRChild(*p))
			p->data = p->parent->data * 2 + 2;
		if (HasRChild(*p))
			s.push(p->rChild);	//�����Һ���  ��ջ
		if (HasLChild(*p))
			s.push(p->lChild);
	}

}