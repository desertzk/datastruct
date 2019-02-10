#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<iostream>
#include<stack>
#include<queue>
#include<map>
using namespace std;
const int INFIN = 0x3f3f3f3f;

typedef enum { UNDISCOVERED, DISCOVERED, VISITED } VStatus; //����״̬
typedef enum { UNDETERMINED, TREE, CROSS, FORWARD, BACKWARD } EType; //���ڱ�����������������

template <typename T>
struct vertex { //�������Ϊ���������δ�ϸ��װ��
	T data; int inDegree, outDegree; VStatus status; //���ݡ����������״̬
	int parent; int dist; 
	int index;//��ͼ�е�����λ��
	vertex(T const& d = (T)0) : //�����¶���
		data(d), inDegree(0), outDegree(0), status(UNDISCOVERED),
		parent(-1), dist(INFIN), index(-1){}

	bool operator<(const vertex &tmp)const {
		return dist > tmp.dist;
	}

};

struct edge { //�߶���Ϊ���������δ�ϸ��װ��
	 int weight; EType type; //���ݡ�Ȩ�ء�����
	edge(int w) : weight(w), type(UNDETERMINED) {} //����
};


template <typename Tv>
class  GraphMatrix
{
public:
	int vertexnum;
	int edgenum;
	vector<vector<edge *>> edgematrix;
	vector<vertex<Tv>> vertexs;
	~GraphMatrix() { //����
		for (int j = 0; j < vertexnum; j++) //���ж�̬������
			for (int k = 0; k < vertexnum; k++) //�߼�¼
				delete edgematrix[j][k]; //�������
	}

	void initdist()
	{
		for(int i=0;i< vertexnum;i++)
			dist.push_back(INFIN);
	}

	vector<int> dist;

	// ����Ķ�̬����
	virtual void insertvertex(Tv const& vertexdata) { //���붥�㣬���ر��
		vertex<Tv> v(vertexdata);
		v.index = vertexnum;
		for (int j = 0; j < vertexnum; j++) 
			edgematrix[j].push_back(NULL); 
		vertexnum++; //������Ԥ��һ��Ǳ�ڵĹ�����
		
		vector<edge *> newvector;
		for (int j = 0; j < vertexnum; j++)
			newvector.push_back(NULL);
		edgematrix.push_back(newvector); //�����¶����Ӧ�ı�����
		
		vertexs.push_back(v);//������������һ������
	}
	virtual Tv removevertex(int i) { //ɾ����i�����㼰������ߣ�0 <= i < n��
		for (int j = 0; j < vertexnum; j++) //���г���
			if (exists(i, j)) { delete edgematrix[i][j]; vertexs[j].inDegree--; } //����ɾ��
		edgematrix.erase(edgematrix.begin()+i); vertexnum--; //ɾ����i��
		Tv vBak = get_vertex(i); vertexs.erase(vertexs.begin()+i); //ɾ������i
		for (int j = 0; j < vertexnum; j++) //�������
		{
			auto it = edgematrix[j].erase(edgematrix[j].begin() + i);
			if (it!= edgematrix[j].end())
			{
				delete *it; vertexs[j].outDegree--;
			} //����ɾ��
		}
			
		return vBak; //���ر�ɾ���������Ϣ
	}


	// ����Ļ�����������ѯ��i�����㣨0 <= i < vertexnum��
	virtual Tv& get_vertex(int i) { return vertexs[i].data; } //����
	virtual int inDegree(int i) { return vertexs[i].inDegree; } //���
	virtual int outDegree(int i) { return vertexs[i].outDegree; } //����
	virtual int& parent(int i) { return vertexs[i].parent; } //�ڱ������еĸ���
	virtual int firstNbr(int i) { return nextNbr(i, vertexnum); } //�׸��ڽӶ���
	virtual int nextNbr(int i, int j) //����ڶ���j����һ�ڽӶ��㣨�����ڽӱ�����Ч�ʣ�
	{
		while ((-1 < j) && (!exists(i, --j))); return j;
	} //����������̽
	virtual VStatus& status(int i) { return vertexs[i].status; } //״̬
	// �ߵ�ȷ�ϲ���
	virtual bool exists(int i, int j) //��(i, j)�Ƿ����
	{
		return (0 <= i) && (i < vertexnum) && (0 <= j) && (j < vertexnum) && edgematrix[i][j] != NULL;
	}
	// �ߵĻ�����������ѯ����i��j֮������ߣ�0 <= i, j < n��exists(i, j)��
	virtual EType & type(int i, int j) { return edgematrix[i][j]->type; } //��(i, j)������
	//virtual Tedge& edge(int i, int j) { return edgematrix[i][j]->data; } //��(i, j)������
	virtual int& weight(int i, int j) { return edgematrix[i][j]->weight; } //��(i, j)��Ȩ��


	// �ߵĶ�̬����
	virtual void insertedge(int w, int i, int j) { //����Ȩ��Ϊw�ı�e = (i, j)
		if (exists(i, j)) return; //ȷ���ñ��в�����
		edgematrix[i][j] = new edge(w); //�����±�
		edgenum++; vertexs[i].outDegree++; vertexs[j].inDegree++; //���±߼������������Ķ���
	}
	virtual void removeedge(int i, int j) { //ɾ������i��j֮������ߣ�exists(i, j)��
		/*Te eBak = edge(i, j);*/ delete edgematrix[i][j]; edgematrix[i][j] = NULL; //���ݺ�ɾ���߼�¼
		edgenum--; vertexs[i].outDegree--; vertexs[j].inDegree--; //���±߼������������Ķ���
		//return eBak; //���ر�ɾ���ߵ���Ϣ
	}


	//�����������BFS�㷨��������ͨ��
	void BFS(int v) { //assert: 0 <= v < n
		queue<int> Q; //���븨������
		status(v) = DISCOVERED; Q.push(v); //��ʼ�����
		while (!Q.empty()) { //��Q���֮ǰ������
			int v = Q.front(); Q.pop(); //dTime(v) = ++clock; //ȡ�����׶���v
			for (int u = firstNbr(v); -1 < u; u = nextNbr(v, u)) //ö��v�������ھ�u
				if (UNDISCOVERED == status(u)) { //��u��δ�����֣���
					status(u) = DISCOVERED; Q.push(u); //���ָö���
					type(v, u) = TREE; parent(u) = v; //����������չ֧����
				}
				else { //��u�ѱ����֣����������ѷ�����ϣ���
					type(v, u) = CROSS; //��(v, u)�����ڿ��
				}
			status(v) = VISITED; //���ˣ���ǰ����������
		}
	}

	

	void dijkstra(int source) { //assert: 0 <= v < n
		priority_queue<vertex<Tv>> Q; //���븨������ ����ȡ��Сֵ
		vertexs[source].dist = 0;
		status(source) = DISCOVERED; Q.push(vertexs[source]); //��ʼ�����
		while (!Q.empty()) { //��Q���֮ǰ������
			vertex<Tv> v = Q.top(); Q.pop(); //dTime(v) = ++clock; //ȡ�����׶���vҲ������v����Ķ��㣬���ж����е���С��
			//�����±��������±ֱ꣬�Ӹ�ֵv,��ֵ����ʵ��һ������
			status(v.index) = VISITED;
			for (int u = firstNbr(v.index); -1 < u; u = nextNbr(v.index, u)) //ö��v�������ھ�u
			{
				if (VISITED != status(u) && (vertexs[u].dist > v.dist + weight(v.index, u))) //���ڽӶ���u���ɳ� dist u���³ɸ�С����
				{
					vertexs[u].dist = v.dist + weight(v.index, u);
					parent(u) = v.index;
					status(u)= DISCOVERED;
					Q.push(vertexs[u]);
				} //��Prim�㷨Ψһ�Ĳ�֮ͬ��
			}
			
		}
	}

	int vtxtimes[1000] = {0};
	int allrescue[1000] = { 0 };

	void dijkstra_ex(int source,int to) { //assert: 0 <= v < n
		//initallrescue();
		allrescue[source] = vertexs[source].data;
		vtxtimes[source] = 1;//��ʼ·������Ϊ1��
		priority_queue<vertex<Tv>> Q; //���븨������ ����ȡ��Сֵ
		vertexs[source].dist = 0;
		status(source) = DISCOVERED; Q.push(vertexs[source]); //��ʼ�����
		while (!Q.empty()) { //��Q���֮ǰ������
			vertex<Tv> v = Q.top(); Q.pop(); //dTime(v) = ++clock; //ȡ�����׶���vҲ������v����Ķ��㣬���ж����е���С��
			//�����±��������±ֱ꣬�Ӹ�ֵv,��ֵ����ʵ��һ������
			status(v.index) = VISITED;
			for (int u = firstNbr(v.index); -1 < u; u = nextNbr(v.index, u)) //ö��v�������ھ�u
			{
				if (VISITED != status(u) && (vertexs[u].dist > v.dist + weight(v.index, u))) //���ڽӶ���u���ɳ� dist u���³ɸ�С����
				{
					
					vertexs[u].dist = v.dist + weight(v.index, u);
					parent(u) = v.index;
					status(u) = DISCOVERED;
					
					allrescue[u] = vertexs[u].data + allrescue[v.index];
					vtxtimes[u] = vtxtimes[v.index];
					Q.push(vertexs[u]);
					
				}
				else if(vertexs[u].dist==v.dist + weight(v.index, u)){
					//int ucost = 
					if(vertexs[u].data +allrescue[v.index] > allrescue[u])
						allrescue[u]= vertexs[u].data + allrescue[v.index];/**/
					vtxtimes[u]+= vtxtimes[v.index];
				}
			}

		}


		cout << vtxtimes[to] << " " << allrescue[to];
	}

	void initallrescue()
	{
		for (int i = 0; i < vertexnum;i++)
			allrescue[i]= vertexs[i].data;
	}


	int calcrescue(int to)
	{
		int allrescue = 0;
		allrescue += vertexs[to].data;
		for (int i = vertexs[to].parent; i != -1; i = vertexs[i].parent)
		{
			allrescue += vertexs[i].data;
		}
		return allrescue;
	}



};

struct Rescue
{
	int rescueteam;
	int times;
};

int main_testgraph()
{
	GraphMatrix<int> g;
	g.insertvertex(1);
	g.insertvertex(2);
	g.insertvertex(3);
	g.insertvertex(4);
	g.insertvertex(5);
	g.insertvertex(6);
	g.insertvertex(7);
	//1
	g.insertedge(2, 0, 1);
	g.insertedge(1, 0, 3);
	//2
	g.insertedge(3, 1, 3);
	g.insertedge(10, 1, 4);
	//3
	g.insertedge(4, 2, 0);
	g.insertedge(5, 2, 5);
	//4
	g.insertedge(2, 3, 2);
	g.insertedge(2, 3, 4);
	g.insertedge(8, 3, 5);
	g.insertedge(4, 3, 6);
	//5
	g.insertedge(6, 4, 6);
	//6
	//7
	g.insertedge(1, 6, 5);

	//g.initdist();
	g.dijkstra(0);


	return 0;
}


