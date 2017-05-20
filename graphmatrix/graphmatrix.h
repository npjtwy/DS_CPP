#pragma once
#include "../vector/Vector.h"
#include "../graph/Graph.h"
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
	int dTime, fTime;	//ʱ���ǩ dTime ����ʱ��  fTime �������ʱ��
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
	Te data; 
	int weight;
	EStatus status;	//���� Ȩ�� ״̬
	
	//�����±�
	Edge(Te const& d, int w) : data(d), weight(w), status(UNDETERMINED) {}

};

//�������� ���ڽӾ���ʵ�ֵ�ͼ
template <typename Tv, typename Te>
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

	virtual int firstNbr(int i) { return nextNbr(i, n); }	//���һ���ڽӵ� 
	virtual int nextNbr(int i, int j)	//����ǰ�ڵ�i���ڽӵ�Ϊjʱ������һ���ڽӵ�
	{
		while ((-1 < j) && !exists(i, --j));	//��j��ʼ�����ڽӱ�i�� ֱ��i,j֮����ڱ�
		return j;
	}
	
	virtual bool exists(int i, int j)	//�ж�i, j֮���Ƿ���ڱ�
	{ return (i >= 0) && (j >= 0) && (i < n) && (j < n) && E[i][j] != NULL; }

	virtual Te& edge(int i, int j) {
		return E[i][j]->data;
	} //��(v, u)�����ݣ��ñߵ�ȷ���ڣ�
	virtual int& weight(int i, int j)  //��(i, j)��Ȩ��
	{
		return E[i][j]->weight;
	}
	virtual EStatus status(int i, int j) 	//�ߵ�״̬
	{
		return E[i][j]->status;
	}
	virtual void insert(Te const& edge, int w, int i, int j) //�ڶ���v��u֮�����Ȩ��Ϊw�ı�e
	{
		if (exists(i, j)) return;
		E[i][j] = new Edge<Te>(edge, w);
		e++;
		V[i].outDegree++;	//���½ڵ�����
		V[j].inDegree++;

	}
	virtual Te remove(int i, int j) //ɾ������i��j֮��ı�e�����ظñ���Ϣ
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

	virtual int insert(Tv const& v)  //���붥�㣬���ر��
	{
		for (int i = 0; i < n; n++)
		{
			E[i].insert(NULL);	//�����ڽӾ���������
			n++;	//���¶�������
		}
		E.insert(Vector<Edge<Te> *>(n, n, (Edge<Te> *)NULL));	//������
		
		return V.insert(Vertex<Tv> (v));		//���¶��㼯
	}

	virtual Tv remove(int i) //ɾ�����㼰������ߣ����ظö�����Ϣ
	{
		Tv vBak = V[i].data;	//���ݶ�����Ϣ
		//ɾ�������й����ı�
		for (int j = 0; j < n; ++j)	//ɾ������
		{
			if (exists(i, j))
			{
				delete E[i][j];
				V[j].inDegree--;
			}
		}
		E.remove(i);	n--;//ɾ���������е� ��i ��
		//Ȼ���������ɾ������
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

	virtual Tv& vertex(int v) { return V[v].data; } //����v�����ݣ��ö����ȷ���ڣ�
	virtual int inDegree(int v) //����v����ȣ��ö����ȷ���ڣ�
	{
		return V[v].inDegree;
	}  
	virtual int outDegree(int v) //����v�ĳ��ȣ��ö����ȷ���ڣ�
	{
		return V[v].outDegree;
	}
	virtual VStatus& status(int v) //����v��״̬
	{
		return V[v].status;
	}

	virtual int& dTime(int v)  //����v��ʱ���ǩdTime
	{
		return V[v].dTime;
	}
	virtual int& fTime(int v) //����v��ʱ���ǩfTime
	{
		return V[v].fTime;
	}
	virtual int& parent(int v)//����v�ڱ������еĸ���
	{
		return V[v].parent;
	}
	virtual int& priority(int v) //����v�ڱ������е����ȼ���
	{
		return V[v].priority;
	}
									// �ߣ�����Լ��������߾�ͳһת��Ϊ�������һ������ߣ��Ӷ�������ͼ��������ͼ������
};


