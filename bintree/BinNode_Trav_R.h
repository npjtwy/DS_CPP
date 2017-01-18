#pragma once

/************************************************************************
* ���������ֱ����ĵݹ�汾                                                                   
************************************************************************/

//��������ݹ��
template <typename T, typename VST>
void travPre_R(BinNodePosi(T) x, VST& visit)
{
	if (!x) return;	//��xΪ�սڵ� ���� �ݹ��
	visit(x->data);
	travPre_R(x->lChild, visit);
	travPre_R(x->rChild, visit);
}

//�������
template <typename T, typename VST>
void travPost_R(BinNodePosi(T) x, VST& visit)
{
	if (!x) return;	//��xΪ�սڵ� ���� �ݹ��
	travPost_R(x->lChild, visit);
	travPost_R(x->rChild, visit);
	visit(x->data);
}

//�������
template <typename T, typename VST>
void travIn_R(BinNodePosi(T) x, VST& visit)
{
	if (!x) return;	//��xΪ�սڵ� ���� �ݹ��
	travIn_R(x->lChild, visit);
	visit(x->data);
	travIn_R(x->rChild, visit);
}