#include<stdio.h>

#define MAXINT 99
#define MAXN 10
int mat[MAXN][MAXN];
int vertexnum, beginu;


int g_cost[][MAXN] =
{
	{ 0,6,1,5,MAXINT,MAXINT },//1
	{ 6,0,5,MAXINT,3,MAXINT },
	{ 1,5,0,5,6,4 },
	{ 5,MAXINT,5,0,MAXINT,2 },
	{ MAXINT,3,6,MAXINT,0,6 },
	{ MAXINT,MAXINT,4,2,6,0 }
};


void print_arr(int *lowcost,int size)
{
	printf("lowest: ");
	for (int i = 0; i < size; ++i)
		printf("%4d", *(lowcost + i));

	printf("\n");
}





void prim(int cost[][MAXN], int vertexnum, int beginu)
{
	int lowcost[MAXN] = {0}, min;
	int closest[MAXN] = {0};
	int i, j, k = 0;
	for (i = 0; i < vertexnum; ++i)
	{
		lowcost[i] = cost[beginu][i];
		closest[i] = beginu;
	}
	//print_arr(lowcost, vertexnum);

	for (i = 0; i < vertexnum-1; ++i)
	{
		//从所有代价里选择最小的代价并选择最小的代价的顶点把它归入最小生成树
		min = MAXINT;
		for(j=0;j< vertexnum;++j)
			if (lowcost[j]!=0&&lowcost[j] < min)
			{
				min = lowcost[j];
				k = j;
			}

		printf("{%3d%3d%5d}  \n", closest[k],k,cost[closest[k]][k]);
		print_arr(lowcost, vertexnum);
		print_arr(closest, vertexnum);
		lowcost[k] = 0;//选择最小的代价的顶点把它归入最小生成树
		//最小树里多了一个顶点  所以对应的代价要更新为新的也就是更小的
		for(j=0;j< vertexnum;++j)
			if (cost[k][j] != 0 && cost[k][j] < lowcost[j])
			{
				lowcost[j] = cost[k][j];
				closest[j] = k;
			}

	}

}


int main04()
{
	prim(g_cost, 6, 0);
	system("pause");
	return 0;
}






