#pragma once
/************************************************************************
* 中序遍历迭代版3                                                                   
************************************************************************/

template <typename T, typename VST>
void travIn_I3(BinNodePosi(T) x, VST &visit)
{
	bool backtrack = false;	//设置回溯标志
	while (true)
	{
		if (!backtrack && HasLChild(*x))	//若没有回溯 并且有左孩子 继续向左前进
			x = x->lChild;
		else
		{
			//若是回溯或者 没有左孩子
			visit(x->data);
			if (HasRChild(*x))	//如果有右孩子 则转向右边
			{
				x = x->rChild;
				backtrack = false;
			}
			else
			{
				//没有右孩子 则转向后继（即回溯）
				if (!(x = x->succ())) break;
				backtrack = true;	//设置回溯
			}
		}
	}
}