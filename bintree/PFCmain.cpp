
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "PFC_code.h"

using  namespace std;
int main(int argc, char* argv[])
{
	PFCForest* forest = initForest();	//��ʼ�� PFCɭ��
	PFCTree* tree = generateTree(forest); release(forest);	//���ɱ�����
	PFCTable* table = generateTable(tree);

	for (int i = 1; i < argc; i++)
	{
		Bitmap codeString;	//�����Ʊ��봮
		int n = encode(table, codeString, argv[i]);//
		decode(tree, codeString, n); 
	}

	release(table);
	release(tree);

	system("pause");
	return 0;
}