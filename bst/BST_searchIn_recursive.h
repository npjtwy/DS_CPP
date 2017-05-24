#pragma once
/************************************************************************
* BST ���� �ݹ��                                                           
************************************************************************/

template <typename T>
static BinNodePosi(T)  &
searchIn_re(BinNodePosi(T)& root, const T& e, BinNodePosi(T) &hot)
{
	auto s = root;
	if (!s || s->data == e)
	{
		return s;
	}

	hot = s;

	if (e < s->data)
	{
		return searchIn_re(s->lChild, e, hot);
	}
	if ( e > s->data )
		return searchIn_re(s->rChild, e, hot);
	//��ʱû�д�����ȵ����
}