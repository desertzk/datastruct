#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<iostream>
#include<stack>
#include<queue>
#include<map>
#include"graphmatrix.hpp"
using namespace std;

//void main1127()
//{
//	//std::wcout.imbue(std::locale(""));
//	wchar_t ch1 = '֤';
//	wchar_t ch = L'֤';
//	std::wcout << (int)ch << std::endl << ch << std::endl;
//	//printf("%s",ch);
//	system("pause");
//}

/*
1003 Emergency （25 point(s)）
As an emergency rescue team leader of a city, you are given a special map of your country. The map shows several scattered cities connected by some roads. Amount of rescue teams in each city and the length of each road between any pair of cities are marked on the map. When there is an emergency call to you from some other city, your job is to lead your men to the place as quickly as possible, and at the mean time, call up as many hands on the way as possible.
Input Specification:
Each input file contains one test case. For each test case, the first line contains 4 positive integers: N (≤500) - the number of cities (and the cities are numbered from 0 to N−1), M - the number of roads, C1 and C2
​​ - the cities that you are currently in and that you must save, respectively. The next line contains N integers, where the i-th integer is the number of rescue teams in the i-th city. Then M lines follow, each describes a road with three integers c1
​​, c2
​​ and L, which are the pair of cities connected by a road and the length of that road, respectively. It is guaranteed that there exists at least one path from C1
​​ to C2​​.
Output Specification:
For each test case, print in one line two numbers: the number of different shortest paths between C1 and C2
​​, and the maximum amount of rescue teams you can possibly gather. All the numbers in a line must be separated by exactly one space, and there is no extra space allowed at the end of a line.

*/



int main1003()
{
	GraphMatrix<int> g;

	int vertexnum = 0, edgenum = 0, nowplace = 0, wantgo = 0;
	scanf("%d %d %d %d", &vertexnum, &edgenum, &nowplace, &wantgo);
	//adj matrix has weight info
	/*Graph<vertex<int>, edge<int>> *g = new Graph<vertex<int>, edge<int>>();
	g->edgenum = edgenum;
	g->vertexnum = vertexnum;
	for (int i = 0; i < g->vertexnum; ++i)
	{
		g->edgematrix.push_back(vector<edge<int>>());
		for (int j = 0; j < g->vertexnum; ++j)
		{
			g->edgematrix[i].push_back(edge<int>(0, 0));
		}
	}*/
	//init vetex weight
	for (int i = 0; i < vertexnum; ++i)
	{
		int rescueteam = 0;
		scanf("%d", &rescueteam);
		/*Rescue re;
		re.rescueteam = rescueteam;
		re.times = 0;*/
		g.insertvertex(rescueteam);
	}
	//init edge weight
	for (int index = 0; index < edgenum; index++)
	{
		int edgeweight = 0;
		int i = 0, j = 0;
		scanf("%d %d %d", &i, &j, &edgeweight);
		g.insertedge(edgeweight, i, j);
	}

	g.dijkstra_ex(nowplace, wantgo);


	system("pause");
	return 0;
}

int main1001(int argc,char *argv[])
{
	int a = 0;
	int b = 0;
	scanf("%d %d",&a,&b);
	int result = a + b;
	char str[128] = { 0 };
	sprintf(str,"%d", result);
	stack<char> stk;
	//
	int len=strlen(str);
	string out;
	for (int i = len-1,j=0; i >=0; --i)
	{
		//if(isdigit(str))

		if (j !=0&&j % 3 == 0)
		{
			/*out += ",";
			out += str[i];*/
			if(isdigit(str[i]))
				stk.push(',');
			stk.push(str[i]);
		}
		else {
			stk.push(str[i]);
		}

		if (isdigit(str[i]))
			++j;
	}
	
	for (; stk.size();)
	{
		out += stk.top();
		stk.pop();
	}

	printf("%s", out.c_str());
	return 0;
}


/*
1002 A+B for Polynomials （25 point(s)）
This time, you are supposed to find A+B where A and B are two polynomials.
Input Specification:
Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial:
K N1 a N1 N2 a N2... NKaNK
where K is the number of nonzero terms in the polynomial, N
​i and a
​N
​i
(i=1,2,⋯,K) are the formula1exponents and formula1coefficients, respectively. It is given that 1≤K≤10，0≤N
​K<⋯<N2<N1≤1000.
Output Specification:
For each test case you should output the sum of A and B in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate to 1 decimal place.
Sample Input:
2 1 2.4 0 3.2
2 2 1.5 1 0.5
Sample Output:
3 2 1.5 1 2.9 0 3.2

*/

//思路对 一些用例过不了
#define COUNT 100
int main1002(int argc,char *argv)
{
	int num = 0;
	int tmpex1 = 0;
	float tmpco1 = 0;
	int formula1exponents[COUNT] = { 0 };
	double formula1coefficients[COUNT] = { 0 };
	
	/*scanf("%d %d %f %d %f %d %f %d %f %d %f %d %f %d %f %d %f %d %f %d %f", &num, formula1exponents, formula1coefficients
		, formula1exponents + 1, formula1coefficients + 1, formula1exponents + 2, formula1coefficients + 2, formula1exponents + 3, formula1coefficients + 3,
		formula1exponents + 4, formula1coefficients + 4, formula1exponents + 5, formula1coefficients + 5, formula1exponents + 6, formula1coefficients + 6,
		formula1exponents + 7, formula1coefficients + 7, formula1exponents + 8, formula1coefficients + 8, formula1exponents + 9, formula1coefficients + 9);
	*/
	scanf("%d", &num);
	for (int i = 0; i < num; ++i)
	{
		scanf("%d %f", &tmpex1, &tmpco1);
		formula1exponents[i] = tmpex1;
		formula1coefficients[i] = tmpco1;
	}

	int num2 = 0;
	int tmpex2 = 0;
	float tmpco2 = 0;
	int formula2exponents[COUNT] = { 0 };
	double formula2coefficients[COUNT] = { 0 };
	/*scanf("%d %d %f %d %f %d %f %d %f %d %f %d %f %d %f %d %f %d %f %d %f", &num2, formula2exponents, formula2coefficients
		, formula2exponents + 1, formula2coefficients + 1, formula2exponents + 2, formula2coefficients + 2, formula2exponents + 3, formula2coefficients + 3,
		formula2exponents + 4, formula2coefficients + 4, formula2exponents + 5, formula2coefficients + 5, formula2exponents + 6, formula2coefficients + 6,
		formula2exponents + 7, formula2coefficients + 7, formula2exponents + 8, formula2coefficients + 8, formula2exponents + 9, formula2coefficients + 9);
*/
	scanf("%d", &num2);
	for (int i = 0; i < num2; ++i)
	{
		scanf("%d %f", &tmpex2, &tmpco2);
		formula2exponents[i] = tmpex2;
		formula2coefficients[i] = tmpco2;
	}


	int sumnum = 0;
	//int sumexponents[COUNT] = { 0 };
	map<int, double> sumcoefficients;
	// i < COUNT
	//merge
	int i = num - 1, j = num2 - 1;
	for ( ;i>= 0&&j>= 0;)
	{

		if (formula1exponents[i] == formula2exponents[j])
		{
			//exponent same add coefficients
			sumcoefficients[formula1exponents[i]] = formula1coefficients[i] + formula2coefficients[j];
			--i;
			--j;
		}
		else if (formula1exponents[i] < formula2exponents[j])
		{
			sumcoefficients[formula1exponents[i]] = formula1coefficients[i];
			--i;
		}
		else {
			//formula1exponents[i] >formula2exponents[j]
			sumcoefficients[formula2exponents[j]] = formula2coefficients[j];
			--j;
		}

	}
	if (i >= 0)
	{
		while (i >= 0)
		{
			sumcoefficients[formula1exponents[i]] = formula1coefficients[i];
			i--;
		}
		
	}
	else if (j >= 0)
	{
		while (j >= 0)
		{
			sumcoefficients[formula2exponents[j]] = formula2coefficients[j];
			--j;
		}
	}

	


	cout << sumcoefficients.size();
	for (map<int, double>::reverse_iterator it = sumcoefficients.rbegin(); it!=sumcoefficients.rend(); ++it)
	{
		cout <<" "<< it ->first<<" "<< it->second;
	}
	//cout << endl;
	//cin.get();
	system("pause");
	return 0;
}

//right
const int maxn = 1005;
double exps[maxn]; //exps[i]存储结果指数为i的项对应的系数,一开始变量定义为exp，导致编译错误，估计有exp函数导致重名了。。。
int main1002r()
{
	int k, n;
	double a;
	scanf("%d", &k);
	memset(exps, 0, sizeof(exps));
	for (int i = 0; i < k; i++) {
		scanf("%d %lf", &n, &a);
		exps[n] = a;
	}
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%d %lf", &n, &a);
		exps[n] += a;
	}
	int cnt = 0;
	for (int i = 0; i < maxn; i++) {
		if (exps[i] != 0) {
			cnt++;
		}
	}


	printf("%d", cnt);
	for (int i = maxn - 1; i >= 0; i--) {
		if (exps[i] != 0) {
			printf(" %d %.1lf", i, exps[i]);
		}
	}
	system("pause");
	return 0;
}




