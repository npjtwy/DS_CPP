
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "VST.h"
#include "BinTree.h"
#include "BinTree_Ex.h"

template <typename T>
bool isCGTP(BinNodePosi(T) root);

template <typename T>
void RplaceData(BinNodePosi(T) root);


int main()
{
	BinTree<int> bt;
	VST<int> visit;
	bt.insertAsRoot(5);
	auto p = bt.insertAsLC(bt.root(), 8);
	bt.insertAsRC(bt.root(), 7);
	
	bt.insertAsLC(p, 13);

	printf("%d\n", isCGTP<int>(bt.root()));
	RplaceData<int>(bt.root());

	SetValue_Iter<int>(bt.root());

	bt.travPre(visit);
	printf("\n");
	system("pause");
	return 0;
}

