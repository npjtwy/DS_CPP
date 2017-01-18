#pragma once
template <typename T>
void BinTree<T>::deleteTree(BinNodePosi(T) root)
{
	if(root == NULL)
	{
		return;
	}
	auto lc = root->lChild;

	auto rc = root->rChild;
	delete root;
	root = NULL;
	if (lc)
	{
		deleteTree(lc);
	}
	if (rc)
	{
		deleteTree(rc);
	}
	return;
}