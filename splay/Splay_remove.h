#pragma once
/*
 * 删除算法与插入算法类似
 * 经过查找待删除节点后， 待删除节点已经伸展至树根
 * 因此只需让根节点的后继替代根节点即可
 */

template <typename T>
bool Splay<T>::remove(const T& e)
{
	if ( !_root || (e != search(e)->data) )
		return false;
	BinNodePosi(T) w = _root;
	if(!HasLChild(*_root))//无左右子树直接删除
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

		//将左子树切除 保留右子树
		lTree->parent = NULL;
		_root->lChild = NULL;
		_root = _root->rChild;
		_root->parent = NULL;

		//以原树根为目标查找 目的是将原子树的后继伸展到树根位置
		search(w->data);
		// 至此，右子树中最小节点必伸展至根，且（因无雷同节点）其左子树必空，亍是
		_root->lChild = lTree; lTree->parent = _root; //叧需将原左子树接回原位即可
		
	}
	
	release(w->data); release(w); _size--; //释放节点，更新规模
	if ( _root ) updateHeight(_root); //此后，若树非空，则树根的高度需要更新
	return true; //返回成功标志
}
