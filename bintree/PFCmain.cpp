
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "PFC_code.h"

using  namespace std;
int main(int argc, char* argv[])
{
	PFCForest* forest = initForest();	//初始化 PFC森林
	PFCTree* tree = generateTree(forest); release(forest);	//生成编码树
	PFCTable* table = generateTable(tree);

	for (int i = 1; i < argc; i++)
	{
		Bitmap codeString;	//二进制编码串
		int n = encode(table, codeString, argv[i]);//
		decode(tree, codeString, n); 
	}

	release(table);
	release(tree);

	system("pause");
	return 0;
}