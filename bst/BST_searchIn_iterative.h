#pragma once
/************************************************************************
* BST ËÑË÷ µü´ú°æ
************************************************************************/

template <typename T>
static BinNodePosi(T)
searchIn_it(BinNodePosi(T)& root, const T& e, BinNodePosi(T) &hot)
{
	BinNodePosi(T) s = root;
	while ( 1 )
	{
		if ( !s || s->data == e )
		{
			return s;
		}
		hot = s;
		if ( e < s->data )
		{
			s = s->lChild;
			continue;
		}
		else if ( e > s->data )
		{
			s = s->rChild;
			continue;
		}
	}
}