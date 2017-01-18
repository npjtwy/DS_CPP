#pragma once
/************************************************************************
* ����BinTree ʵ�ֱ����� vectorʵ�ֱ���ɭ��

************************************************************************/

/************************************************************************
* PFC����ʹ�õ����ݽṹ                                                                   
************************************************************************/
#include "../bintree/bintree.h"
typedef BinTree<char> PFCTree;	//�� BinTreeʵ��PFC��

#include "../vector/vector.h"
typedef Vector<PFCTree*> PFCForest;	//��vectorʵ��PFCɭ��

#include "../bitmap/bitmap.h"	//λͼ��ʾ�����Ʊ���
#include "../skiplist/skiplist.h"	//skiplist��ʾ�����
typedef Skiplist<char, char*> PFCTable;

#define  N_CHAR (0x80 - 0x20)

//��ʼ��PFCɭ��
inline
PFCForest* initForest()
{
	PFCForest* forest = new PFCForest;	//������ɭ��
	for (int i = 0; i < N_CHAR; ++i)
	{
		forest->insert(i, new PFCTree);	//����һ�ö�Ӧ�ı�����
		(*forest)[i]->insertAsRoot(0x20 + i);	//��ʼ�ı�����ֻ�������ڵ�
	}
	return forest;
}


//����PFC������
inline
PFCTree* generateTree(PFCForest* forest)
{
	srand((unsigned)time(NULL));	//�����������
	while (forest->size() > 1)
	{
		PFCTree* newTree = new PFCTree;	//����һ������
		Rank r1 = rand() % forest->size();	//���ѡȡһ�ó�ʼ��
		newTree->attachAsLC(newTree->root(), (*forest)[r1]);	//��Ϊ��������
		forest->remove(r1);	//�Ƴ�ԭ���ĳ�ʼ��

		Rank r2 = rand() % forest->size();	//���ѡȡһ�ó�ʼ��
		newTree->attachAsRC(newTree->root(), (*forest)[r2]);	//��Ϊ����������
		forest->remove(r2);	//�Ƴ�ԭ���ĳ�ʼ��

		forest->insert(forest->size(), newTree);	//���ϳɺ���±��������뵽ɭ����
	}

}

//����PFC�����
inline
 void generateCT //ͨ�������񅨸��ַ��m����
 (Bitmap* code, int length, PFCTable* table, BinNodePosi(char) v) {
	if (IsLeaf(*v)) //����Ҷ�ڵ�
		 { table->put(v->data, code->bits2string(length)); return; }
	if (HasLChild(*v)) //Left = 0
		 { code->clear(length); generateCT(code, length + 1, table, v->lChild); }
	if (HasRChild(*v)) //right = 1
		 { code->set(length); generateCT(code, length + 1, table, v->rChild); }

}
inline
PFCTable* generateTable(PFCTree* tree) { //����PFC�����
	 PFCTable* table = new PFCTable; //������Skiplistʵ�ְm�����
	 Bitmap* code = new Bitmap; //��ء�Ǐ�RPS�mλͼ
	 generateCT(code, 0, table, tree->root()); //�����Ի񅨸��ַ���Ҷ�ڵ㣩�mRPS
	 release(code); return table; //�ͷű���λͼ��ކ�ر����
	
}


inline
//ͨ��������ȡ�����ַ��ı���
int encode(PFCTable* table, Bitmap& codeString, char* s) { //PFC�����㷨
	int n = 0;
	for (size_t m = strlen(s), i = 0; i < m; i++) { //��ء����s[]�аm�����ַ�
		char** pCharCode = table->get(s[i]); //�������Ӧ�m���봮
		if (!pCharCode) pCharCode = table->get(s[i] + 'A' - 'a'); //Сд�֚�תΪ��д
		if (!pCharCode) pCharCode = table->get(' '); //�޷�ʶɾ�m�ַ�ͳһ�����ո�
		printf("%s", *pCharCode); //�����ǰ�ַ��m����
		for (size_t m = strlen(*pCharCode), j = 0; j < m; j++) //����ǰ�ַ��m���������봮
			'1' == *(*pCharCode + j) ? codeString.set(n++) : codeString.clear(n++);
		
	}
	return n; //���Äc���봮�Ǐ�ءcodeString�У�ކ�ر��봮�ܳ�
}

inline//����
void decode(PFCTree* tree, Bitmap& code, int n) { //PFC�����㷨
	BinNodePosi(char) x = tree->root(); //����PFC������
	for (int i = 0; i < n; i++) { //�����루���Äcλͼ��
		x = code.test(i) ? x->rChild : x->lChild; //ת��Ϊ����
		if (IsLeaf(*x)) { printf("%c", x->data); x = tree->root(); } //��ӡ���
		
	}
}