#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "AVL.h"
/******************************************************************************************
* ²âÊÔÖ÷Èë¿Ú
******************************************************************************************/

template <typename T>
struct VST
{
	void operator()(T& data)
	{
		printf("%d ", data);

	}
};


int main(int argc, char* argv[]) {
	auto visit = new VST<int>( );
	auto avl = new AVL<int>( );
	avl->insert(34);
	avl->insert(22);
	avl->insert(76);
	avl->insert(25);
	avl->insert(23);
	avl->travIn(*visit);

	auto found = avl->search(23);
	if ( found )
		printf("found\n");

	system("pause");
	return 0;
}