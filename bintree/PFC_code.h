#pragma once
/************************************************************************
* 利用BinTree 实现编码树 vector实现编码森林

************************************************************************/

/************************************************************************
* PFC编码使用的数据结构                                                                   
************************************************************************/
#include "../bintree/bintree.h"
typedef BinTree<char> PFCTree;	//用 BinTree实现PFC树

#include "../vector/vector.h"
typedef Vector<PFCTree*> PFCForest;	//用vector实现PFC森林

#include "../bitmap/bitmap.h"	//位图表示二进制编码
#include "../skiplist/skiplist.h"	//skiplist表示编码表
typedef Skiplist<char, char*> PFCTable;

#define  N_CHAR (0x80 - 0x20)

//初始化PFC森林
inline
PFCForest* initForest()
{
	PFCForest* forest = new PFCForest;	//创建空森林
	for (int i = 0; i < N_CHAR; ++i)
	{
		forest->insert(i, new PFCTree);	//创建一棵对应的编码树
		(*forest)[i]->insertAsRoot(0x20 + i);	//初始的编码树只包含根节点
	}
	return forest;
}


//构造PFC编码树
inline
PFCTree* generateTree(PFCForest* forest)
{
	srand((unsigned)time(NULL));	//设置随机种子
	while (forest->size() > 1)
	{
		PFCTree* newTree = new PFCTree;	//创建一棵新树
		Rank r1 = rand() % forest->size();	//随机选取一棵初始树
		newTree->attachAsLC(newTree->root(), (*forest)[r1]);	//作为子树插入
		forest->remove(r1);	//移除原来的初始树

		Rank r2 = rand() % forest->size();	//随机选取一棵初始树
		newTree->attachAsRC(newTree->root(), (*forest)[r2]);	//作为右子树插入
		forest->remove(r2);	//移除原来的初始树

		forest->insert(forest->size(), newTree);	//将合成后的新编码树插入到森林中
	}

}

//生成PFC编码表
inline
 void generateCT //通过遍历获叏各字符癿编码
 (Bitmap* code, int length, PFCTable* table, BinNodePosi(char) v) {
	if (IsLeaf(*v)) //若是叶节点
		 { table->put(v->data, code->bits2string(length)); return; }
	if (HasLChild(*v)) //Left = 0
		 { code->clear(length); generateCT(code, length + 1, table, v->lChild); }
	if (HasRChild(*v)) //right = 1
		 { code->set(length); generateCT(code, length + 1, table, v->rChild); }

}
inline
PFCTable* generateTable(PFCTree* tree) { //极造PFC编码表
	 PFCTable* table = new PFCTable; //创建以Skiplist实现癿编码表
	 Bitmap* code = new Bitmap; //用亍记弽RPS癿位图
	 generateCT(code, 0, table, tree->root()); //遍历以获叏各字符（叶节点）癿RPS
	 release(code); return table; //释放编码位图，迒回编码表
	
}


inline
//通过遍历获取各个字符的编码
int encode(PFCTable* table, Bitmap& codeString, char* s) { //PFC编码算法
	int n = 0;
	for (size_t m = strlen(s), i = 0; i < m; i++) { //对亍明文s[]中癿殏个字符
		char** pCharCode = table->get(s[i]); //叏出其对应癿编码串
		if (!pCharCode) pCharCode = table->get(s[i] + 'A' - 'a'); //小写字殎转为大写
		if (!pCharCode) pCharCode = table->get(' '); //无法识删癿字符统一规作空格
		printf("%s", *pCharCode); //输出当前字符癿编码
		for (size_t m = strlen(*pCharCode), j = 0; j < m; j++) //将弼前字符癿编码接入编码串
			'1' == *(*pCharCode + j) ? codeString.set(n++) : codeString.clear(n++);
		
	}
	return n; //二迕刢编码串记弽亍codeString中，迒回编码串总长
}

inline//解码
void decode(PFCTree* tree, Bitmap& code, int n) { //PFC解码算法
	BinNodePosi(char) x = tree->root(); //根据PFC编码树
	for (int i = 0; i < n; i++) { //将编码（二迕刢位图）
		x = code.test(i) ? x->rChild : x->lChild; //转译为明码
		if (IsLeaf(*x)) { printf("%c", x->data); x = tree->root(); } //打印输出
		
	}
}