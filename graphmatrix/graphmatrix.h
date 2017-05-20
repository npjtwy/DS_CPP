#pragma once
#include "../vector/Vector.h"
#include "../graph/Graph.h"
/************************************************************************
* 邻接矩阵实现图的抽象数据结构                                                                   
************************************************************************/

//顶点类
template <typename Tv>
struct Vertex {
	Tv data;
	int inDegree;
	int outDegree;
	VStatus status;
	int dTime, fTime;	//时间标签 dTime 发现时间  fTime 访问完毕时间
	int parent;		//在遍历树中癿父节点、优先级数
	int priority;	//构造新顶点

	Vertex(Tv const& d = (Tv)0) :
		data(d), inDegree(0), outDegree(0), status(UNDISCOVERED),
		dTime(-1), fTime(-1), parent(-1), priority(INT_MAX) {}
};

//边对象
template <typename Te>
struct Edge
{
	Te data; 
	int weight;
	EStatus status;	//数据 权重 状态
	
	//构造新边
	Edge(Te const& d, int w) : data(d), weight(w), status(UNDETERMINED) {}

};

//基于向量 以邻接矩阵实现的图
template <typename Tv, typename Te>
class GraphMatrix : public Graph<Tv, Te>
{
private:
	Vector<Vertex<Tv>> V;	//顶点集
	Vector<Vector<Edge<Te> *>> E;	//边集
public:
	GraphMatrix() { n = e = 0; }
	//析构， 对所有动态创建的边 逐条清除
	~GraphMatrix()
	{
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				delete E[i][j];
	}

	virtual int firstNbr(int i) { return nextNbr(i, n); }	//求第一个邻接点 
	virtual int nextNbr(int i, int j)	//当当前节点i的邻接点为j时，求下一个邻接点
	{
		while ((-1 < j) && !exists(i, --j));	//从j开始遍历邻接表i行 直到i,j之间存在边
		return j;
	}
	
	virtual bool exists(int i, int j)	//判断i, j之间是否存在边
	{ return (i >= 0) && (j >= 0) && (i < n) && (j < n) && E[i][j] != NULL; }

	virtual Te& edge(int i, int j) {
		return E[i][j]->data;
	} //边(v, u)的数据（该边的确存在）
	virtual int& weight(int i, int j)  //边(i, j)的权重
	{
		return E[i][j]->weight;
	}
	virtual EStatus status(int i, int j) 	//边的状态
	{
		return E[i][j]->status;
	}
	virtual void insert(Te const& edge, int w, int i, int j) //在顶点v和u之间插入权重为w的边e
	{
		if (exists(i, j)) return;
		E[i][j] = new Edge<Te>(edge, w);
		e++;
		V[i].outDegree++;	//更新节点出入度
		V[j].inDegree++;

	}
	virtual Te remove(int i, int j) //删除顶点i和j之间的边e，返回该边信息
	{
		if (!exists(i, j)) return 0;
		Te edgeBak = this->edge(i,	j);
		delete E[i][j];
		E[i][j] = NULL;
		e--;
		V[i].outDegree--;
		V[j].inDegree--;
		return edgeBak;
	}

	virtual int insert(Tv const& v)  //插入顶点，返回编号
	{
		for (int i = 0; i < n; n++)
		{
			E[i].insert(NULL);	//增加邻接矩阵行向量
			n++;	//更新顶点总数
		}
		E.insert(Vector<Edge<Te> *>(n, n, (Edge<Te> *)NULL));	//插入列
		
		return V.insert(Vertex<Tv> (v));		//更新顶点集
	}

	virtual Tv remove(int i) //删除顶点及其关联边，返回该顶点信息
	{
		Tv vBak = V[i].data;	//备份顶点信息
		//删除顶点有关联的边
		for (int j = 0; j < n; ++j)	//删除出边
		{
			if (exists(i, j))
			{
				delete E[i][j];
				V[j].inDegree--;
			}
		}
		E.remove(i);	n--;//删除行向量中的 第i 行
		//然后从向量中删除顶点
		for (int j = 0; j < n; j--)
		{
			if (exists(j, i))
			{
				delete E[j].remove(i);
				V[j].outDegree--;
			}
		}
		
		V.remove(i);
		return vBak;
	}

	virtual Tv& vertex(int v) { return V[v].data; } //顶点v的数据（该顶点的确存在）
	virtual int inDegree(int v) //顶点v的入度（该顶点的确存在）
	{
		return V[v].inDegree;
	}  
	virtual int outDegree(int v) //顶点v的出度（该顶点的确存在）
	{
		return V[v].outDegree;
	}
	virtual VStatus& status(int v) //顶点v的状态
	{
		return V[v].status;
	}

	virtual int& dTime(int v)  //顶点v的时间标签dTime
	{
		return V[v].dTime;
	}
	virtual int& fTime(int v) //顶点v的时间标签fTime
	{
		return V[v].fTime;
	}
	virtual int& parent(int v)//顶点v在遍历树中的父亲
	{
		return V[v].parent;
	}
	virtual int& priority(int v) //顶点v在遍历树中的优先级数
	{
		return V[v].priority;
	}
									// 边：这里约定，无向边均统一转化为方向互逆的一对有向边，从而将无向图视作有向图的特例
};


