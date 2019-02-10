#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<iostream>
#include<stack>
#include<queue>
#include<map>
using namespace std;
const int INFIN = 0x3f3f3f3f;

typedef enum { UNDISCOVERED, DISCOVERED, VISITED } VStatus; //顶点状态
typedef enum { UNDETERMINED, TREE, CROSS, FORWARD, BACKWARD } EType; //边在遍历树中所属的类型

template <typename T>
struct vertex { //顶点对象（为简化起见，并未严格封装）
	T data; int inDegree, outDegree; VStatus status; //数据、出入度数、状态
	int parent; int dist; 
	int index;//在图中的索引位置
	vertex(T const& d = (T)0) : //构造新顶点
		data(d), inDegree(0), outDegree(0), status(UNDISCOVERED),
		parent(-1), dist(INFIN), index(-1){}

	bool operator<(const vertex &tmp)const {
		return dist > tmp.dist;
	}

};

struct edge { //边对象（为简化起见，并未严格封装）
	 int weight; EType type; //数据、权重、类型
	edge(int w) : weight(w), type(UNDETERMINED) {} //构造
};


template <typename Tv>
class  GraphMatrix
{
public:
	int vertexnum;
	int edgenum;
	vector<vector<edge *>> edgematrix;
	vector<vertex<Tv>> vertexs;
	~GraphMatrix() { //析构
		for (int j = 0; j < vertexnum; j++) //所有动态创建的
			for (int k = 0; k < vertexnum; k++) //边记录
				delete edgematrix[j][k]; //逐条清除
	}

	void initdist()
	{
		for(int i=0;i< vertexnum;i++)
			dist.push_back(INFIN);
	}

	vector<int> dist;

	// 顶点的动态操作
	virtual void insertvertex(Tv const& vertexdata) { //插入顶点，返回编号
		vertex<Tv> v(vertexdata);
		v.index = vertexnum;
		for (int j = 0; j < vertexnum; j++) 
			edgematrix[j].push_back(NULL); 
		vertexnum++; //各顶点预留一条潜在的关联边
		
		vector<edge *> newvector;
		for (int j = 0; j < vertexnum; j++)
			newvector.push_back(NULL);
		edgematrix.push_back(newvector); //创建新顶点对应的边向量
		
		vertexs.push_back(v);//顶点向量增加一个顶点
	}
	virtual Tv removevertex(int i) { //删除第i个顶点及其关联边（0 <= i < n）
		for (int j = 0; j < vertexnum; j++) //所有出边
			if (exists(i, j)) { delete edgematrix[i][j]; vertexs[j].inDegree--; } //逐条删除
		edgematrix.erase(edgematrix.begin()+i); vertexnum--; //删除第i行
		Tv vBak = get_vertex(i); vertexs.erase(vertexs.begin()+i); //删除顶点i
		for (int j = 0; j < vertexnum; j++) //所有入边
		{
			auto it = edgematrix[j].erase(edgematrix[j].begin() + i);
			if (it!= edgematrix[j].end())
			{
				delete *it; vertexs[j].outDegree--;
			} //逐条删除
		}
			
		return vBak; //返回被删除顶点的信息
	}


	// 顶点的基本操作：查询第i个顶点（0 <= i < vertexnum）
	virtual Tv& get_vertex(int i) { return vertexs[i].data; } //数据
	virtual int inDegree(int i) { return vertexs[i].inDegree; } //入度
	virtual int outDegree(int i) { return vertexs[i].outDegree; } //出度
	virtual int& parent(int i) { return vertexs[i].parent; } //在遍历树中的父亲
	virtual int firstNbr(int i) { return nextNbr(i, vertexnum); } //首个邻接顶点
	virtual int nextNbr(int i, int j) //相对于顶点j的下一邻接顶点（改用邻接表可提高效率）
	{
		while ((-1 < j) && (!exists(i, --j))); return j;
	} //逆向线性试探
	virtual VStatus& status(int i) { return vertexs[i].status; } //状态
	// 边的确认操作
	virtual bool exists(int i, int j) //边(i, j)是否存在
	{
		return (0 <= i) && (i < vertexnum) && (0 <= j) && (j < vertexnum) && edgematrix[i][j] != NULL;
	}
	// 边的基本操作：查询顶点i与j之间的联边（0 <= i, j < n且exists(i, j)）
	virtual EType & type(int i, int j) { return edgematrix[i][j]->type; } //边(i, j)的类型
	//virtual Tedge& edge(int i, int j) { return edgematrix[i][j]->data; } //边(i, j)的数据
	virtual int& weight(int i, int j) { return edgematrix[i][j]->weight; } //边(i, j)的权重


	// 边的动态操作
	virtual void insertedge(int w, int i, int j) { //插入权重为w的边e = (i, j)
		if (exists(i, j)) return; //确保该边尚不存在
		edgematrix[i][j] = new edge(w); //创建新边
		edgenum++; vertexs[i].outDegree++; vertexs[j].inDegree++; //更新边计数与关联顶点的度数
	}
	virtual void removeedge(int i, int j) { //删除顶点i和j之间的联边（exists(i, j)）
		/*Te eBak = edge(i, j);*/ delete edgematrix[i][j]; edgematrix[i][j] = NULL; //备份后删除边记录
		edgenum--; vertexs[i].outDegree--; vertexs[j].inDegree--; //更新边计数与关联顶点的度数
		//return eBak; //返回被删除边的信息
	}


	//广度优先搜索BFS算法（单个连通域）
	void BFS(int v) { //assert: 0 <= v < n
		queue<int> Q; //引入辅助队列
		status(v) = DISCOVERED; Q.push(v); //初始化起点
		while (!Q.empty()) { //在Q变空之前，不断
			int v = Q.front(); Q.pop(); //dTime(v) = ++clock; //取出队首顶点v
			for (int u = firstNbr(v); -1 < u; u = nextNbr(v, u)) //枚举v的所有邻居u
				if (UNDISCOVERED == status(u)) { //若u尚未被发现，则
					status(u) = DISCOVERED; Q.push(u); //发现该顶点
					type(v, u) = TREE; parent(u) = v; //引入树边拓展支撑树
				}
				else { //若u已被发现，或者甚至已访问完毕，则
					type(v, u) = CROSS; //将(v, u)归类于跨边
				}
			status(v) = VISITED; //至此，当前顶点访问完毕
		}
	}

	

	void dijkstra(int source) { //assert: 0 <= v < n
		priority_queue<vertex<Tv>> Q; //引入辅助队列 用于取最小值
		vertexs[source].dist = 0;
		status(source) = DISCOVERED; Q.push(vertexs[source]); //初始化起点
		while (!Q.empty()) { //在Q变空之前，不断
			vertex<Tv> v = Q.top(); Q.pop(); //dTime(v) = ++clock; //取出队首顶点v也就是离v最近的顶点，所有顶点中的最小者
			//能用下标的最好用下标，直接赋值v,赋值的其实是一个拷贝
			status(v.index) = VISITED;
			for (int u = firstNbr(v.index); -1 < u; u = nextNbr(v.index, u)) //枚举v的所有邻居u
			{
				if (VISITED != status(u) && (vertexs[u].dist > v.dist + weight(v.index, u))) //对邻接顶点u做松弛 dist u更新成更小的量
				{
					vertexs[u].dist = v.dist + weight(v.index, u);
					parent(u) = v.index;
					status(u)= DISCOVERED;
					Q.push(vertexs[u]);
				} //与Prim算法唯一的不同之处
			}
			
		}
	}

	int vtxtimes[1000] = {0};
	int allrescue[1000] = { 0 };

	void dijkstra_ex(int source,int to) { //assert: 0 <= v < n
		//initallrescue();
		allrescue[source] = vertexs[source].data;
		vtxtimes[source] = 1;//起始路径设置为1条
		priority_queue<vertex<Tv>> Q; //引入辅助队列 用于取最小值
		vertexs[source].dist = 0;
		status(source) = DISCOVERED; Q.push(vertexs[source]); //初始化起点
		while (!Q.empty()) { //在Q变空之前，不断
			vertex<Tv> v = Q.top(); Q.pop(); //dTime(v) = ++clock; //取出队首顶点v也就是离v最近的顶点，所有顶点中的最小者
			//能用下标的最好用下标，直接赋值v,赋值的其实是一个拷贝
			status(v.index) = VISITED;
			for (int u = firstNbr(v.index); -1 < u; u = nextNbr(v.index, u)) //枚举v的所有邻居u
			{
				if (VISITED != status(u) && (vertexs[u].dist > v.dist + weight(v.index, u))) //对邻接顶点u做松弛 dist u更新成更小的量
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


