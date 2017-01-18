#pragma once
/*
*	List(List<T> const& L); //���帴���б�L
*	List(List<T> const& L, Rank r, int n); //�����б�L���Ե�r�����n��
*	List(ListNodePosi(T) p, int n); //�����б�����λ��p���n��
*/
template <typename T>
List<T>::List(List<T> const& L)
{
	this->copyNodes(L.first(), L._size);
}

template <typename T>
List<T>::List(List<T> const& L, Rank r, int n)
{
	ListNodePosi(T) p = L.first();
	while (r-- > 0)
	{
		p = p->succ;
	}
	this->copyNodes(p, n);
}

template <typename T>
List<T>::List(ListNodePosi(T) p, int n)
{
	copyNodes(p, n);
}
