#include<stdio.h>

#define MAXINT 99
#define MAXN 10
typedef int MAT[MAXN][MAXN];

//int vertexnum, vertex;


int g_cost1[][MAXN] =
{
	{ 0,13,8,MAXINT,30,MAXINT,32 },
	{ MAXINT,0,MAXINT,MAXINT,MAXINT,9,7 },//1
	{ MAXINT,MAXINT,0,5,MAXINT,MAXINT,MAXINT },
	{ MAXINT,MAXINT,MAXINT,0,6,MAXINT,MAXINT },
	{ MAXINT,MAXINT,MAXINT,MAXINT,0,2,MAXINT },
	{ MAXINT,MAXINT,MAXINT,MAXINT,MAXINT,0,17 },
	{ MAXINT,MAXINT,MAXINT,MAXINT,MAXINT,MAXINT,0 }
};

//dijikalas
void shortestpath(MAT cost, int vertexnum, int vertex)
{
	int dist[MAXN] = { 0 },  pre[MAXN] = { 0 };
	int s[MAXN] = { 0 };
	int i = 0, j = 0, k = 0, min = 0;
	for (i = 0; i < vertexnum; ++i)
	{
		dist[i] = cost[vertex][i];
		s[i] = 0;
		if (dist[i] < MAXINT)
			pre[i] = vertex;
		else
			pre[i] = 0;
	}

	s[vertex] = 1;
	pre[vertex] = 0;


	for (i = 0; i < vertexnum; ++i)
	{
		min = MAXINT;
		k = 0;

		for(j=0;j< vertexnum;++j)
			if(s[j]==0)
				if (dist[j] != 0 && dist[j] < min)
				{
					min = dist[j];
					k = j;//最小堆
				}

		if (k == 0) continue;
		printf("go to %d \n", k);
		s[k] = 1;//标记为已经访问，主要是用来做到优先队列效果
		for(j=0;j< vertexnum;++j)
			if(s[j]==0 && cost[k][j]<MAXINT)
				if (dist[k] + cost[k][j] < dist[j])// dist smaller than new then change to the smaller dist[k] + cost[k][j]
				{
					dist[j] = dist[k] + cost[k][j];
					pre[j] = k;
				}
	}



}



int main01()
{
	//int dist[MAXN] = { 0 }, pre[MAXN] = { 0 };
	shortestpath(g_cost1, 7, 0);
	//prim(g_cost, 6, 1);
	system("pause");
	return 0;
}
