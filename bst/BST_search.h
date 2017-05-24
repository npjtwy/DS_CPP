#pragma once

template <typename T>
BinNodePosi(T) & BST<T>::search(const T& e)
{
	return searchIn_it(_root, e, _hot);
}