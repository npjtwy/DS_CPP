#include "Splay.h"
#include <stdlib.h>

#include <stdio.h>

int main()
{
	Splay<int> sTree;

	sTree.insertAsRoot(4);
	sTree.insert(5);
	sTree.insert(34);
	sTree.insert(87);
	sTree.insert(32);
	sTree.insert(14);
	sTree.insert(56);

	printf("%d\n", sTree.root( )->data);

	system("pause");
	return 0;
}