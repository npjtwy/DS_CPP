#pragma once
/*
 *	对有序列表唯一化
*/

template <typename T>
int List<T>::uniquify()
{
	//int oldSize = _size;
	//Rank r = 0;
	//ListNodePosi p = first();
	//ListNodePosi q = p->succ;
	//while (q != trailer)
	//{
	//	if (q->data != p->data)
	//	{
	//		(p = p->succ)->data = q->data;	//遇到与p的值不同的节点时，p指向下一节点，然后将q指的节点值赋给p
	//		r++;
	//	}
	//	q = q->succ;	//q继续寻找下一个与p的值不同的节点
	//}
	////此时 p 指向最后一个不重复的节点，p到trailer之间的都需要删除
	////我决定将需要删除的节点重新创建一个链表，然后再将其销毁。。。有没有更好的办法呢？

	//List<T>* newlist = new List<T>;
	//newList->_size = r + 1;
	//newList->header->succ = p->succ;
	//newList->trailer->pred = this->trailer->pred;
	////让待删除节点与源列表断开关系
	//p->succ->pred = newList->header;
	//trailer->pred->succ = newList->trailer;
	//p->succ = trailer;
	//trailer->pred = p;
	//
	//delete newList;
	//_size = r + 1;	//r为删除后的列表最后一个节点的秩，因此size为r+1
	//return oldSize - _size;	

	//太笨了！！
	//以下

	if (_size < 2) return 0;
	int oldSize = _size;
	ListNodePosi(T) p;
	ListNodePosi(T) q;
	for (p = header, q = p->succ; q != trailer; p = q, q = q->succ)
	{
		if (p->data == q->data)
		{
			remove(q);
			q = p;
		}
	}

	return oldSize - _size;
}