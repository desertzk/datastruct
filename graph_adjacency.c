#include"graph_adjacency.h"

#define MAXN 50
#define MAXM 100

typedef struct l_node
{
	int vertex;
	struct l_node* link;
}L_NODE;



typedef struct {
	int vertex1;
	int vertex2;
}E_NODE;

L_NODE *graph[MAXN];
int visit[MAXN];//用于标记是否访问
E_NODE e[MAXM];

int vertexnum, edgenum, u;



void create_adj_list(L_NODE *graph[], E_NODE e[], int vertexnum, int edgenum)
{
	int i, u, v;
	L_NODE *p=NULL;
	for (i = 1; i <= vertexnum; i++)
	{
		graph[i] = NULL;
	}

	//for (i = 0; i < edgenum; i++)
	//{
	//	u = e[i].vertex1;
	//	v = e[i].vertex2;
	//	//插入边时要在两个节点上都插入对应的边
	//	//顶点1
	//	p = (L_NODE *)malloc(sizeof(L_NODE));
	//	p->vertex = v;
	//	p->link = graph[u];
	//	graph[u] = p;
	//	//顶点2
	//	p = (L_NODE *)malloc(sizeof(L_NODE));
	//	p->vertex = u;
	//	p->link = graph[v];
	//	graph[v] = p;
	//}

}


void insert_edge(L_NODE *pgraph[], E_NODE e)
{
	int vertex1 = e.vertex1;
	int vertex2 = e.vertex2;

	L_NODE *pnode = NULL;

	//插入边时要在两个节点上都插入对应的边
	//顶点1
	pnode = (L_NODE *)malloc(sizeof(L_NODE));
	pnode->vertex = vertex2;
	pnode->link = pgraph[vertex1];
	pgraph[vertex1] = pnode;
	//顶点2
	pnode = (L_NODE *)malloc(sizeof(L_NODE));
	pnode->vertex = vertex1;
	pnode->link = pgraph[vertex2];
	pgraph[vertex2] = pnode;
}



void init(int vertexnum)
{
	int i;
	for (i = 1; i <= vertexnum; i++)
	{
		visit[i] = 0;
	}
}




void dfs(int u)
{
	L_NODE *t;
	visit[u] = 1;
	printf("%4d",u);
	t = graph[u];
	while (t != NULL)
	{
		if (visit[t->vertex] == 0)
			dfs(t->vertex);
		t = t->link;
	}
}


int main1203()
{
	init(9);


	E_NODE e12;
	e12.vertex1 = 1;
	e12.vertex2 = 2;

	E_NODE e13;
	e13.vertex1 = 1;
	e13.vertex2 = 3;

	E_NODE e14;
	e14.vertex1 = 1;
	e14.vertex2 = 4;

	E_NODE e15;
	e15.vertex1 = 1;
	e15.vertex2 = 5;


	/*E_NODE e21;
	e21.vertex1 = 2;
	e21.vertex2 = 1;*/

	E_NODE e24;
	e24.vertex1 =2;
	e24.vertex2 = 4;

	E_NODE e25;
	e25.vertex1 = 2;
	e25.vertex2 = 5;
	
	/*E_NODE e31;
	e31.vertex1 = 3;
	e31.vertex2 = 1;*/

	E_NODE e36;
	e36.vertex1 = 3;
	e36.vertex2 = 6;

	E_NODE e37;
	e37.vertex1 = 3;
	e37.vertex2 = 7;

	/*E_NODE e41;
	e41.vertex1 = 4;
	e41.vertex2 = 1;*/

	/*E_NODE e42;
	e42.vertex1 = 4;
	e42.vertex2 = 2;*/

	E_NODE e45;
	e45.vertex1 = 4;
	e45.vertex2 = 5;

	E_NODE e51;
	e51.vertex1 = 5;
	e51.vertex2 = 1;

	/*E_NODE e52;
	e52.vertex1 = 5;
	e52.vertex2 = 2;*/

	/*E_NODE e54;
	e54.vertex1 = 5;
	e54.vertex2 = 4;*/

	E_NODE e58;
	e58.vertex1 = 5;
	e58.vertex2 = 8;


	E_NODE e63;
	e63.vertex1 = 6;
	e63.vertex2 = 3;

	E_NODE e67;
	e67.vertex1 = 6;
	e67.vertex2 = 7;

	E_NODE e69;
	e69.vertex1 = 6;
	e69.vertex2 = 9;

	/*E_NODE e73;
	e73.vertex1 = 7;
	e73.vertex2 = 3;

	E_NODE e76;
	e76.vertex1 = 7;
	e76.vertex2 = 6;

	E_NODE e85;
	e85.vertex1 = 8;
	e85.vertex2 = 5;

	E_NODE e96;
	e96.vertex1 = 9;
	e96.vertex2 = 6;*/


	
	create_adj_list(graph, NULL, 9, 0);
	insert_edge(graph, e12);
	insert_edge(graph, e13);
	insert_edge(graph, e14);
	insert_edge(graph, e15);

	//insert_edge(graph, e21);
	insert_edge(graph, e24);
	insert_edge(graph, e25);

	//insert_edge(graph, e31);
	insert_edge(graph, e36);
	insert_edge(graph, e37);


	//insert_edge(graph, e41);
	//insert_edge(graph, e42);
	insert_edge(graph, e45);


	//insert_edge(graph, e51);
	//insert_edge(graph, e52);
	//insert_edge(graph, e54);
	insert_edge(graph, e58);


	//insert_edge(graph, e63);
	insert_edge(graph, e67);
	insert_edge(graph, e69);

	//insert_edge(graph, e73);
	//insert_edge(graph, e76);
	//insert_edge(graph, e85);
	//insert_edge(graph, e96);
	dfs(1);


	//+ 1
	return 0;
}

