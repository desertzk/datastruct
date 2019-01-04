#define _CRT_SECURE_NO_WARNINGS
#include"polynomial.h"


static int statictest = 0;



int fribonacci(int n)
{
	if (n == 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}
	if (n ==2)
	{
		return 2;
	}
	return fribonacci(n - 1) + fribonacci(n - 2) + fribonacci(n - 3);
}

//int fribonacci2(int n)
//{
//	if (n == 0)
//	{
//		return 0;
//	}
//	if (n == 1)
//	{
//		return 1;
//	}
//	if (n == 2)
//	{
//		return 2;
//	}
//
//	for(int i=0;i<)
//
//	return fribonacci(n - 1) + fribonacci(n - 2) + fribonacci(n - 3);
//}



int main11()
{
	int a=1;
	int b=a << sizeof(a) * 8 + 3;
	int c = a << sizeof(a) * 8;
	//+ 1
	return 0;
}



int main1206()
{
	int a[100];
	double b[10][20];
	
	//+ 1
	return 0;
}

int cmp(const void *s1, const void *s2) {
	return ((int *)s2)[0] - ((int *)s1)[0];
}

int dist[10][2];

void main181213()
{
	FILE *fp = fopen("E:\\ccppworkspace\\cdatastruct\\Debug\\data.txt", "r");
	int x1, y1, x2, y2, i, n, x, y, answer = 100000, max2 = 0;
	fscanf(fp, "%d%d%d%d%d", &x1, &y1, &x2, &y2, &n);
	for (i = 0; i < n; i++)
	{
		fscanf(fp, "%d%d", &x, &y);
		dist[i][0] = (x - x1)*(x - x1) + (y - y1)*(y - y1);
		dist[i][1] = (x - x2)*(x - x2) + (y - y2)*(y - y2);
		printf("(%d,%d),[%d,%d]\n",x,y, dist[i][0], dist[i][1]);
	}
	qsort(dist,n,sizeof(int[2]),cmp);
	printf("[%d,%d]\n", dist[i][0], dist[i][1]);
	for (i = 0; i < n; i++)
	{
		if (answer > dist[i][0] + max2) answer = dist[i][0] + max2;
		if (max2 < dist[i][1]) max2 = dist[i][1];
	}
	printf("%d\n",answer);

}