#include "hashtable.h"
#include <cstdio>
#include <iostream>


int main(int argc, char* argv[])
{
	std::shared_ptr<hashTable> hash (new hashTable());
	std::vector<int> data = { 19 ,14 ,23 ,01, 68, 20, 84, 27, 55, 11, 10, 79 };
	for ( auto i : data )
	{
		hash->insert(i);
	}

	hash->print_hash( );

	system("pause");
	return 0;
}
