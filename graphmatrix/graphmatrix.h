#pragma once
#include "../vector/vector.h"
#include "../graph/graph.h"
/************************************************************************
* �ڽӾ���ʵ��ͼ�ĳ������ݽṹ                                                                   
************************************************************************/

//������
template <typename Tv>
struct Vertex {
	Tv data;
	int inDegree;
	int outDegree;
	VStatus status;
	int dTime, fTime;	//ʱ���ǩ
	int parent;		//�ڱ������аm���ڵ㡢���ȼ���
	int priority;	//�����¶���

	Vertex(Tv const& d = (Tv)0) :
		data(d), inDegree(0), outDegree(0), status(UNDISCOVERED),
		dTime(-1), fTime(-1), parent(-1), priority(INT_MAX) {}
};

//�߶���
template <typename Te>
struct Edge
{
	Te data; int weight; EStatus status;	//���� Ȩ�� ״̬
	
	//�����±�
	Edge(Te const& d, int w) : data(d), weight(w), status(UNDETERMINED) {}

};

//�������� ���ڽӾ���ʵ�ֵ�ͼ
template <typename Te, typename Tv>
class GraphMatrix : public Graph<Tv, Te>
{
private:
	Vector<Vertex<Tv>> V;	//���㼯
	Vector<Vector<Edge<Te> *>> E;	//�߼�
public:
	GraphMatrix() { n = e = 0; }
	//������ �����ж�̬�����ı� �������
	~GraphMatrix()
	{
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				delete E[i][j];
	}

	//�Զ���Ļ�������
	virtual Tv& vertex(int i) { return V[i].data; }
	virtual int inDegree(int i) { return V[i].inDegree; }
	virtual int outDegree(int i) { return V[i].outDegree; }
	virtual int firstNbr(int i) { return nextNbr(i, n); }	//�׸��ڽӶ���
	virtual int nextNbr(int i, int j) {		//�����j����һ�ڽӶ���
		while ((-1 < j) && (!exists(i, --j))); return j;
	}
	virtual VStatus& status(int i) { return V[i].status; } //״̬
	virtual int& dTime(int i) { return V[i].dTime; } //ʱ���ǩdTime
	virtual int& fTime(int i) { return V[i].fTime; } //ʱ���ǩfTime
	virtual int& parent(int i) { return V[i].parent; } //�ڱ������еĸ���
	virtual int& priority(int i) { return V[i].priority; } //�ڱ������е����ȼ���
														   // ����Ķ�̬����
	virtual int insert(Tv const& vertex) { //���붥�㣬���ر��
		for (int j = 0; j < n; j++) E[j].insert(NULL); n++; //������Ԥ��һ��Ǳ�ڵĹ�����
		E.insert(Vector<Edge<Te>*>(n, n, (Edge<Te>*) NULL)); //�����¶����Ӧ�ı�����
		return V.insert(Vertex<Tv>(vertex)); //������������һ������
	}
	virtual Tv remove(int i) { //ɾ����i�����㼰������ߣ�0 <= i < n��
		for (int j = 0; j < n; j++) //���г���
			if (exists(i, j)) { delete E[i][j]; V[j].inDegree--; } //����ɾ��
		E.remove(i); n--; //ɾ����i��
		Tv vBak = vertex(i); V.remove(i); //ɾ������i
		for (int j = 0; j < n; j++) //�������
			if (Edge<Te> * e = E[j].remove(i)) { delete e; V[j].outDegree--; } //����ɾ��
		return vBak; //���ر�ɾ���������Ϣ
	}
	// �ߵ�ȷ�ϲ���
	virtual bool exists(int i, int j) //��(i, j)�Ƿ����
	{
		return (0 <= i) && (i < n) && (0 <= j) && (j < n) && E[i][j] != NULL;
	}
	// �ߵĻ�����������ѯ����i��j֮������ߣ�0 <= i, j < n��exists(i, j)��
	virtual EType & type(int i, int j) { return E[i][j]->type; } //��(i, j)������
	virtual Te& edge(int i, int j) { return E[i][j]->data; } //��(i, j)������
	virtual int& weight(int i, int j) { return E[i][j]->weight; } //��(i, j)��Ȩ��
																  // �ߵĶ�̬����
	virtual void insert(Te const& edge, int w, int i, int j) { //����Ȩ��Ϊw�ı�e = (i, j)
		if (exists(i, j)) return; //ȷ���ñ��в�����
		E[i][j] = new Edge<Te>(edge, w); //�����±�
		e++; V[i].outDegree++; V[j].inDegree++; //���±߼������������Ķ���
	}
	virtual Te remove(int i, int j) { //ɾ������i��j֮������ߣ�exists(i, j)��
		Te eBak = edge(i, j); delete E[i][j]; E[i][j] = NULL; //���ݺ�ɾ���߼�¼
		e--; V[i].outDegree--; V[j].inDegree--; //���±߼������������Ķ���
		return eBak; //���ر�ɾ���ߵ���Ϣ
	}
};


