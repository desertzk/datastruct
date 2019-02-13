#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<iostream>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<cmath>
#include<algorithm>
using namespace std;
vector<vector<int>> graze;
//E
int main()
{
	int lines = 0, linenums = 0;
	scanf("%d %d",&lines,&linenums);
	for (int i = 0; i < lines; i++)
	{
		vector<int> v;
		for (int j = 0; j < linenums; j++)
		{
			int gross = 0;
			scanf("%d", &gross);
			v.push_back(gross);
		}
		graze.push_back(v);
	}
	int maxrow = lines-1;
	int maxcol = linenums - 1;
	graze[maxrow][maxcol];

	system("pause");
	return 0;
}



//A - 质数的最大乘积 
int isprime_number(int num)
{
	if (num == 1)
		return true;
	for (int i = 2; i < num; ++i)
	{
		if (num%i == 0)
			return false;
	}
	return true;
}
//两个质数的和是S，它们的积最大是多少?
int mainA()
{
	int num = 0;
	scanf("%d", &num);


	int maxprimenum = 0;
	int s1 = 0;
	int s2 = num;
	for (; s2 >= s1; ++s1, --s2)
	{
		if (!isprime_number(s1) || !isprime_number(s2))
			continue;
		if(s2+s1== num)
			maxprimenum = s2 * s1 > maxprimenum ? s2 * s1 : maxprimenum;
	}
	cout << maxprimenum<<endl;
	return 0;
}


/*
Alice从市场上买了N根竹竿，每根竹竿都以“节”为单位。这些竹竿中最短的有A节，最长的有B节，其余竹竿各有长短，每根竿的节数也必定在[A,B]范围内。现在Alice希望将这些竹竿用连接部件全部接成一根长竹竿。连接部件的长度忽略不计，请你输出连接后的长竹竿共可能有多少种不同节数。
数据不合理或组合不出结果时输出0
*/


int mainB()
{
	int count = 0,min = 0,max=0;

	scanf("%d %d %d", &count, &min, &max);

	if (min > max)
	{
		cout << 0 << endl;
		return 0;
	}

	if (count == 1&& min!=max)
	{
		cout << 0 << endl;
		return 0;
	}



	set<int> resultnum;

	vector<int> allnum;
	for (int i = min; i <= max; i++)
	{
		allnum.push_back(i);
	}

	
	for (int i = 0; i < 50; ++i)
	{
		
		int sum = allnum[0] + allnum[allnum.size() - 1];
		for (int j = 0; j <count-2;j++ )
		{
			int randomnum = rand() % allnum.size();
			sum += allnum[randomnum];
		}
		resultnum.insert(sum);
	}


	cout << resultnum.size();
	return 0;
}



/*
题目描述
猫从薛定谔的箱子里成功存活并逃脱出来，这时它发现它已经掌握了量子力学的原理并拥有运用量子的能力。即便这样它还是克服不了它喜欢钻入纸箱的天性。
假设现在有一排纸箱的一端从0开始依次编号，这只猫可以以如下的方式在箱子之间行动：
走到相邻箱子：从第X号箱子走到相邻的第X+1号或X-1号箱子。
量子形式转移：从第X号箱子以量子态形式转移到2X号箱子里。
不论是用走的方法还是量子转移的方法，都算作一次转移。假设现在这只猫在第X号箱子里，它希望到第Y号箱子中，请问最少需要几次转移可以达到.

输入数据
输入只有一行，两个整数X Y由一个空格隔开
X Y
0≤X,Y≤100000

*/


int findway(int num,int finalnum,int &time)
{
	if (num == finalnum)
		return 0;
	else if (num > finalnum) {
		time++;
		findway(num - 1, finalnum, time);
	}else
	{
		time++;
		findway(2 * num, finalnum, time);
		findway(num + 1, finalnum, time);
	}

}

#define VISITEDMAX 100003


int mainD()
{
	int visited[VISITEDMAX] = { 0 };
	int nowplace = 0, toplace = 0;
	scanf("%d %d",&nowplace , &toplace);
	if (nowplace >= toplace)
	{
		printf("%d\n", nowplace - toplace);
		return 0;
	}
	

	int x = nowplace;
	int time = 0;
	//findway(x, toplace, time);
	int rank = 0;

	queue<pair<int,int>> q;
	q.push(make_pair(x, rank));
	while (q.size())
	{
		pair<int, int> tmp=q.front();
		q.pop();
		x = tmp.first;
		if (x == toplace)
		{
			cout << tmp.second<<endl;
			break;
		}
		else
		{
			visited[x] = 1;
		}
		int _2x = 2 * x;
		int _xplus1 = x + 1;
		int _xminus1 = x - 1;
		rank= tmp.second+1;
		if(visited[_2x]==0&& _2x<VISITEDMAX)
			q.push(make_pair(_2x, rank));
		if (visited[_xplus1] == 0&& _xplus1<VISITEDMAX)
			q.push(make_pair(_xplus1, rank));
		if (visited[_xminus1] == 0&& _xminus1< VISITEDMAX)
			q.push(make_pair(_xminus1, rank));
	}


	//cout << time;
	return 0;
	//system("pause");
}


/*
中国幅员辽阔，来自全国各地的朋友的饮食口味也不尽相同。饮食喜好相同的人会组在一起吃饭，我们称其互为“饭友”。而你意外得到了一份食堂的流水账单记录，想从中发现今天来食堂吃饭的人当中每个人究竟有多少名饭友。
首先你对账单的记录进行了一番整理，把N个消费者依次编号为1,2,…,N，把M种食品依次编号为1,2,…,M。为简单起见，认为喜欢吃同一种食品的人，就是他的饭友。你现在的任务是从这份账单记录中计算出每个人有几个饭友。

第一行两个整数N,M，2 <= N ，M<= 200。接下来有N行，第i(i = 1,2,…,N)行每一行有一个数，表示食客i-1最喜欢的食品的编号P(1<=P<=M)

包括N行，每行一个数，第i行的数表示第i号食客有几名饭友。如果i没有饭友，悲剧地发现没有人和他的口味相近，则输出“BeiJu”.
*/

int mainE()
{
	int linenum = 0, foods = 0;
	scanf("%d %d",&linenum,&foods);

	//if()
	map<int, int> foodstolines;
	vector<int> vlikefood;


	for (int i = 0; i < linenum; i++)
	{
		int favouritefood = 0;
		scanf("%d", &favouritefood);
		if (foodstolines.find(favouritefood) == foodstolines.end())
		{
			foodstolines.insert(make_pair(favouritefood,0));
		}
		else {
			int likenum = foodstolines[favouritefood];
			likenum++;
			foodstolines[favouritefood] = likenum;
		}
		vlikefood.push_back(favouritefood);
	}



	for (vector<int>::iterator it = vlikefood.begin(); it != vlikefood.end(); ++it)
	{
		int likefood = *it;
		if (foodstolines.find(likefood) != foodstolines.end())
		{
			if(foodstolines[likefood]>0)
				cout << foodstolines[likefood] << endl;
			else
				cout << "BeiJu" << endl;

		}
		else {
			cout << "BeiJu"<< endl;
		}

	}


	system("pause");
	return 0;
}

/*
一个正整数,如果它能被x整除,或者它的十进制表示法中某个位数上的数字为x,则称其为与x相关的数.
请你计算所有小于等于n(n<300)的与x无关的正整数的平方和.
输入为一行,正整数n,(n<300)
*/
//题目要看清某个位数上，不是个位上
int unitdigitright(int num,int errnum1)
{
	if (num % errnum1 == 0)
		return true;
	/*char strnum[16] = { 0 };
	sprintf(strnum, "%d", num);

	int size = strlen(strnum);
	int unitdigit=atoi(&strnum[size-1]);

	if (errnum1 == unitdigit)
	{
		return true;
	}
	else {
		return false;
	}*/
	while (num > 0)
	{
		if (num % 10 == errnum1)
			return true;
		num /= 10;
	}
	return false;

}


int main2A()
{
	int num = 0;
	scanf("%d", &num);

	//unitdigitright(1005, 3, 5);
	int sum = 0;
	for (int i = 1; i <= num; i++)
	{
		if (!unitdigitright(i, 3)&& !unitdigitright(i, 5))
		{
			sum += i * i;
		}
		
			
		
	}

	cout << sum;
	return 0;
	//system("pause");
}


int isluck(int testnum,int &recursive)
{
	if (testnum == 0)
		return 0;
	else if (recursive == 0)
	{
		return -1;
	}
	recursive--;
	isluck(testnum - 4, recursive);
	isluck(testnum - 7, recursive);
	
}


/*
Alice认为4和7是幸运数字，并且如果一个数字是几个幸运数字的和，那么这个数字也是幸运数字，例如
14=7+7
18=7+7+4
11=7+4
7=7
现在给你Q个数字，请你分别判断每个数字是否为幸运数字
输入共Q+1行，第一行一个数字代表数字个数，接下来Q行，每行一个数字x
1≤Q≤100
1≤x≤1016
*/
#define MAX2BINT 100000005

int lucknums[MAX2BINT] = { 0 };

void initluck()
{
	int i = 0;
	int max = 0;
	queue<int> q;
	q.push(4);
	q.push(7);
	for (; q.size();)
	{
		if (i > MAX2BINT)
			break;
		else if (lucknums[q.front()] == 1)
		{
			q.pop();
			continue;
		}/**/
		i = q.front();
		q.pop();
		/*if (i > max)
			max = i;*/
		lucknums[i] = 1;
		//if(lucknums[i])
		int plus4 = i + 4;
		int plus7 = i + 7;
		if (lucknums[plus4] == 0)
			q.push(plus4);
		if (lucknums[plus7] == 0)
			q.push(plus7);
	}
}
/*
这个题其实要找规律。找到规律就O(1)，找不到规律可能运算超时。枚举几个数就会发现，
大于17的所有正整数都是Alice认为的幸运数字。如果有一个幸运数字x的其中一个加数是7，
那么将它换成4+4，这样x+1也是幸运数字，并且每出现7个4就将其换成4个7，
每个7又可以换成4+4，如此可以归纳地证明任意一个大于17的正整数都是幸运数字。
所以，只需要判断输入的数x是否是小于等于17的那几个“不幸运数” 
[1,2,3,5,6,9,10,13,17]即可。


我做的不符合大数
*/
int main2B()
{
	int num = 0;
	scanf("%d", &num);

	initluck();


	for (int i = 0; i < num; i++)
	{
		int testnum = 0;
		scanf("%d", &testnum);
		int recursive = 2000;
		if (lucknums[testnum] == 1)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;

	}
	system("pause");
	//cout << sum;
	return 0;
}




double distance(double x, double y, double x1, double y1)
{
	double dis = pow(x - x1, 2) + pow(y - y1, 2);

	return pow(dis, 0.5);
}

int main2C()
{
	double x, y, x1, y1, x2, y2;
	scanf("%lf %lf %lf %lf %lf %lf", &x, &y, &x1, &y1, &x2, &y2);
	if (x1 <= x && x <= x2)
	{
		double dis1 = abs(y1 - y);
		double dis2 = abs(y2 - y);
		if (dis1 > dis2)
		{
			cout << dis2;
		}
		else {
			cout << dis1;
		}
	}
	else if (y1 <= y && y <= y2)
	{
		double dis1 = abs(x1 - x);
		double dis2 = abs(x2 - x);
		if (dis1 > dis2)
		{
			cout << dis2;
		}
		else {
			cout << dis1;
		}
	}
	else {
		double min = 999999999;
		double x3 = x2, y3 = y1;//right buttom
		double x4 = x1, y4 = y2;//left up
		double dis1 = distance(x, y, x1, y1);
		if (min > dis1)
		{
			min = dis1;
		}
		double dis2 = distance(x, y, x2, y2);
		if (min > dis2)
		{
			min = dis2;
		}

		double dis3 = distance(x, y, x3, y3);
		if (min > dis3)
		{
			min = dis3;
		}
		double dis4 = distance(x, y, x4, y4);
		if (min > dis4)
		{
			min = dis4;
		}
		cout << min;
	}

	system("pause");
	return 0;
}


/*
问题描述
半个月之前Alice买了一些竹竿，拼接之后Alice把它截成等长的四段，围出一个正方形的牛棚用来养牛。由于Alice的畜牧经验不足，这头牛患了病。Alice找到当地的兽医开药，并药物拌入饲料喂给这头牛。
假设这个牛棚是个边长为N的正方形，牛棚中所有的点描述为从(0,0)到(N,N)的坐标，牛棚的边缘的各点都堆有饲料，而其中只有M个点放置的是拌有药品的饲料。
假设牛在吃完一堆饲料再吃下一堆时，只会选择与刚吃完这堆相邻近的饲料。现在这头牛需要吃K堆含药饲料才能痊愈，吃每堆饲料要花1分钟。
若从吃完第一堆开始计时，请问这头牛最少要额外花几分钟才能达到吃药的目标
数据输入
第一行有三个整数N,M,K
接下来有M行，每行两个整数表示拌入药物的饲料的坐标，题目保证给出的坐标在正方形的边缘
1 ≤ N,M ≤105
1 ≤K ≤ M
0 ≤ xi,yi≤N
xi与yi至少有一个为0或为N（保证坐标在正方形牛棚的边缘）
数据输出
输出一行，一个整数，代表牛吃到相应数量的药最短可能花费的时间
输入样例
5 5 3
5 3
0 0
0 4
3 0
1 5
输出样例
6
提示
输入样例的解如下图示，牛从E开始吃第一堆。吃完E点的第一堆开始计时，第1分钟在点(0,5)吃，
第2分钟在点(0,4)吃，…直到第6分钟吃完(0,0)的饲料，吃了3次药达到目标，花费6分钟。
当然，如果牛先从B开始然后顺时针吃C和E也可以，同样花费6分钟

*/

struct point
{
	point(int x1, int y1, int cap)
	{
		x = x1;
		y = y1;
		dis.resize(cap);
	}
	//int index;
	int x;
	int y;

	vector<int> dis;
	int sortandsumup(int num)
	{
		sort(dis.begin(), dis.end());
		int sum = 0;
		for (int i = 0; i < dis.size(); ++i)
		{
			if (num-- == 0)
			{
				break;
			}
			sum += dis[i];
		}
		return sum;
	}
};

//LGraph g_Graph;
vector<point> points;


void calceachpoint(int testnum)
{
	for (int i = 0; i < points.size(); i++)
	{

		for (int j = i; j < points.size(); j++)
		{
			if (i == j)
				continue;//same point
			int dis = abs(points[i].x - points[j].x) + abs(points[i].y - points[j].y);
			points[i].dis[j] = dis;
			points[j].dis[i] = dis;

		}
		/*g_2D[i][i - 1] = dis;
		g_2D[i - 1][i] = dis;*/

	}
	//sum means shortest path to three vertex
	int begin = 0;
	int min = 9999999;
	for (int i = 0; i < points.size(); ++i)
	{
		int sum = points[i].sortandsumup(testnum);
		if (sum < min)
		{
			min = sum;
			begin = i;
		}
	}

	cout << min;

}

//只有2分晕了
int main2D()
{
	int N, lines, curenum;
	scanf("%d %d %d", &N, &lines, &curenum);

	/*for (int i = 0; i < N; i++)
	{
		vector<int> v;
		for (int i = 0; i < N; i++)
		{
			v.push_back(0);
		}
		g_2D.push_back(v);
	}*/


	for (int i = 0; i < lines; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		//g_2D[x][y] = 1;
		point p(x, y, lines);

		points.push_back(p);
	}

	//g_vertexs
	/*LGraph MST = NULL;
	g_Graph = CreateGraph(N);*/
	calceachpoint(curenum);

	//int need=Kruskal_ex(g_Graph, MST, curenum);

	//cout << need;
	return 0;
}








/*
24点游戏是非常经典而简单的小游戏，从一堆扑克牌中抽取4张，向其中添加运算符号并使其运行结果恰等于24,这叫作24点游戏。
现在我们不再是组合24，而是组合出给定的数字n，但要求只可以利用任意多个数字1，并且运算只有加法、乘法和括号。对于给定的数字N，最少需要几个1可以完成
数据输入
输入一个数字N( 1≤N≤5000)
数据输出
输出一个整数，表示仅用加号，乘号和括号能组成等于N所需最少的1的个数
样例1
输入样例
7
输出样例
6
提示
7=(1+1)*(1+1+1)+1
样例2
输入样例
27
输出样例
9
提示
27=(1+1+1)*(1+1+1)*(1+1+1)
*/

/*
F.n点游戏  动态规划
一维的动态规划。
若用f(n)表示计算n所需最少1的个数，对于n=1-5的情形，f(n)=n。
举几个例子，n=6时,6=2*3，所以f(6)=f(2)+f(3)=5，对于n=9，由于9=3*3,所以f(9)=f(3)+f(3)，要计算f(27)，因为27=3*9，所以f(27)=f(3)+f(9)，
但计算f(9)还要计算f(9)=f(3)*f(3)，这样计算的话会出现许多重复，刚才f(9)已经计算出来了，我们可以直接将其保存下来，
将f()改为数组d[]，从1开始向N计算d[i]的值即可。对于任何数字i>1，d[i]=d[i-1]+1，然后我们再检查是否有两个数字x,y相乘等于i，
若有就尝试d[x]+d[y]是否小于当前d[i]，若小于就更新d[i]。计算d[i]后依照此法再计算d[i+1]，直到计算出d[N].
*/
int maken(int now, int target, int rank) {
	if (now == 1)
		return 1;

	//int add = now + 1;
	/*int multi=maken(now)*maken(now);
	int add = maken(now) + 1;*/
	//int good = max(add, multi);
}
#include <cstdio>
#include <algorithm>
#define MAXN 5007
using std::min;

//不会直接看答案的
int main2F(void)
{
	int i, j, N;
	int dp[MAXN];
	scanf("%d", &N);
	dp[1] = 1;
	for (i = 2; i <= N; i++)
	{
		dp[i] = dp[i - 1] + 1;
		for (j = 2; j*j <= i; j++)
		{
			if (i%j == 0)
			{
				dp[i] = min(dp[i], dp[i / j] + dp[j]);
			}
		}
	}

	printf("%d\n", dp[N]);

	return 0;
}


/*
Alice在山上放牛，发现前边的山坡上有一块优质草场。草场呈三角形分布，共有N行，第i行有i棵牧草，这块草场上的每棵的牧草的品质可以用一个正整数来描述。
		7
	  3   8
	8   1   0
  2   7   4   4
4   5   2   6   5
Alice牵着牛从三角形的上方的顶点开始，牛吃完一棵牧草之后只可以吃当前的左前方或右前方的一棵。请你帮Alice计算牵着牛从第1行到第N行吃牧草，能吃到牧草的品质之和最大为多少。
数据输入
输入共N+1行。第一行有一个整数N代表三角形的行数，接下来N行，第i行有空格分隔的i-1个整数，表示草场上各棵牧草的品质
1<N≤100
牧草品质的整数均在区间[0,100]
数据输出
输出只有一行,一个整数代表吃到牧草品质之和的最大值
样例1
输入样例
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
输出样例
30
提示
7 -> 3 -> 8 -> 7 -> 5
7+3+8+7+5=30
*/

vector<vector<int>> g_allgraze;
map<string, int> g_grazecache;
//recusive version dynamic programing
int eatgraze(int left, int rank, int totalrank)
{

	if (rank >= totalrank)
		return 0;
	int right = left + 1;
	int retl = g_allgraze[rank][left];
	//int retr = g_allgraze[rank][right];

	char strl[256] = { 0 };
	sprintf(strl, "[%d][%d]", rank, left);
	char strr[256] = { 0 };
	sprintf(strr, "[%d][%d]", rank, right);
	int resultl = 0;
	int resultr = 0;
	/**/if (g_grazecache.find(strl) == g_grazecache.end())
	{
		resultl = eatgraze(left, rank + 1, totalrank);
		g_grazecache.insert(make_pair(strl, resultl));
	}
	else {
		resultl = g_grazecache.at(strl);
	}
	if (g_grazecache.find(strr) == g_grazecache.end())
	{
		resultr = eatgraze(right, rank + 1, totalrank);
		g_grazecache.insert(make_pair(strr, resultr));
	}
	else {
		resultr = g_grazecache.at(strr);
	}/**/
	int goodgraze = retl + max(resultl, resultr);

	return goodgraze;
	//return 0;
}
//success 100 
int main2E()
{
	int lines = 0;
	scanf("%d", &lines);

	for (int i = 0; i < lines; ++i)
	{
		vector<int> v;


		for (int j = 0; j < i + 1; j++)
		{
			int graze = 0;
			scanf("%d", &graze);
			v.push_back(graze);
		}
		g_allgraze.push_back(v);
	}
	int rank = 0;


	cout << eatgraze(0, rank, lines);
	return 0;
}



/*
遥远的M-886星云，整数世界正在进行一场战役，所有的正整数针锋相对，发生了正面冲突。如果数字不幸在战役中消失，就用YODA纪念这个数字，史称YODA战役。
两个数相互交锋的过程中，对于数字的每一位，如果两数的这一位上数字相同，那么这一位不会受影响，否则这一位上数字更小的那个会消失。

给出两个数字，请你计算出两数进行交战之后各自的新数值，如果一个数字在交战之后什么也不剩，那么输出YODA

数据输入
数据共2行，每行一个正整数，分别表示交战的两个数字。数字范围为[1,109]
数据输出
输出2行，每行一个数字，表示交战后数字的结果。若数字一位也不剩，则输出“YODA”
样例1
输入样例
300
500
输出样例
0
500
样例2
输入样例
65743
9651
输出样例
673
95
样例3
输入样例
2341
6785
输出样例
YODA
6785
*/

//success 100
int main3A()
{
	int line1 = 0, line2 = 0;
	scanf("%d", &line1);
	scanf("%d", &line2);
	char str1[128] = { 0 };
	char str2[128] = { 0 };
	sprintf(str1, "%d", line1);
	sprintf(str2, "%d", line2);
	char addstr[128] = { 0 };
	if (strlen(str1) > strlen(str2))
	{
		int addlen = strlen(str1) - strlen(str2);
		for (int i = 0; i < addlen; i++)
		{
			addstr[i] = '0';
		}
		strcat(addstr, str2);
		strcpy(str2, addstr);
	}
	else if (strlen(str1) < strlen(str2)) {
		//need add before str1
		int addlen = strlen(str2) - strlen(str1);
		for (int i = 0; i < addlen; i++)
		{
			addstr[i] = '0';
		}
		strcat(addstr, str1);
		strcpy(str1, addstr);
	}


	for (int i = 0; i < 63; i++)
	{
		if (str1[i] > str2[i])
			str2[i] = ' ';
		else if (str1[i] == str2[i])
			continue;
		else {
			str1[i] = ' ';
		}
	}
	char outstr1[64] = { 0 };
	char outstr2[64] = { 0 };
	char *startoutstr1 = outstr1;
	char *startoutstr2 = outstr2;
	for (int i = 0; i < 63; i++)
	{
		if (str1[i] != ' ')
		{
			*startoutstr1 = str1[i];
			startoutstr1++;
		}

		if (str2[i] != ' ')
		{
			*startoutstr2 = str2[i];
			startoutstr2++;
		}
	}
	if (strcmp(outstr1, "")) {
		line1 = atoi(outstr1);
		cout << line1 << endl;
	}
	else {
		cout << "YODA" << endl;
	}
	if (strcmp(outstr2, "")) {
		line2 = atoi(outstr2);
		cout << line2 << endl;
	}
	else {
		cout << "YODA" << endl;
	}
	/*cout << line1 << endl;
	cout << line2<< endl;*/
	return 0;
	system("pause");
}



/*
right answer
将数列的各项分成三类：是4的倍数，不是4但是2的倍数，不是2的倍数,每类数的个数分别用a4,a2,a1表示。如果要构成幸运数列，要求相邻的数字相乘是4的倍数，为了尽可能多的利用数字，a1只能与a4相邻，而a2可以与a4也可以与a2相邻。若已经统计出了数列中a4,a2与a1，如何判断数列能否组成幸运数列呢？
先解决a1的问题，a1必须配合a4出现，a1的数量若多于a4则必不是幸运数列。具体来说，先使a1与a4交替出现，[a1,a4,a1,a4,...]，这时若这一段数列的最后一个数是a1(此时a1=a4+1),那么后边接a2则不能排成幸运数列，所以当a2==0且a4<=a1+1时可以排成幸运数列。
如果有这段数列最后一个数是a4(此时a1≤a4),后边可以接a2，又由于a2可以与a2相邻，所以要在a2>0时需要a1≤a4的条件下则可排成幸运数列。
其它条件输出"No"
*/
int main3B(void)
{
	int a1count = 0, a2count = 0, a4count = 0;
	int i, N, x;
	scanf("%d", &N);
	while (N--)
	{
		scanf("%d", &x);
		if (x % 4 == 0)
			a4count++;
		else if (x % 2 == 0)
			a2count++;
		else
			a1count++;
	}
	if (a2count>0 && a1count <= a4count)
		printf("Yes\n");
	else if (a2count == 0 && a1count <= a4count + 1)
		printf("Yes\n");
	else
		printf("No\n");

	return 0;
}

bool testdivid4(vector<int> &allnums)
{
	for (int i = 0; i < allnums.size(); ++i)
	{
		int muti = allnums[i] * allnums[i - 1];
		if (muti % 4 != 0)
		{
			//can /4 test next i

			return false;
		}
	}
	return true;
}

#define _MAXNUM3B 1000000
//14/19 partial success
int main3Bp()
{
	int lines = 0;

	scanf("%d", &lines);
	vector<int> allnums;
	for (int i = 0; i < lines; ++i)
	{
		int num = 0;
		scanf("%d", &num);
		allnums.push_back(num);
	}

	int *test4ok = (int *)calloc(lines, sizeof(int));
	int *testeachnum = (int *)calloc(lines, sizeof(int));
	bool bluck = true;
	for (int i = 0; i < lines - 1; ++i)
	{
		//int muti=allnums[i] * allnums[i - 1];
		for (int j = i + 1; j < lines; ++j)
		{
			if (testeachnum[j] > 1)//相邻数最多用2次
				continue;
			int muti = allnums[i] * allnums[j];
			if (muti % 4 == 0)
			{
				//can /4 test next i
				test4ok[i] = 1;
				testeachnum[j]++;
				break;
			}

		}
	}

	for (int i = 0; i < lines - 1; ++i)
	{
		if (test4ok[i] == 0)
			bluck = false;
	}


	if (bluck)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	system("pause");
	return 0;
}





/*
Alice的牧场中有好多奶牛，每天挤牛奶要花不少时间，有的牛产奶快，挤的时间就比较短，有的牛则产奶慢。并且不同的牛在一天之中的产奶时间也不同。在长期挤奶的过程中，Alice总结出了每天牛产奶的时间表，请你根据牛产奶的时间帮Alice计算一下最多能接到几头牛产出的牛奶。由于挤牛奶需要带的用具比较多，如果错过了牛产奶的开始时间，Alice就不会选择这头牛挤奶。一旦开始挤牛奶，就要一直挤到这头牛产奶结束而不能中断去另一头牛挤牛奶。

Input
多组数据。每组数据的第一行是N，表示共有N头牛。接下来N行，每行有两个整数，表示牛开始产奶和结束的时间。数据输入的最后N=0表示数据结束

0 < N ≤ 100
各时间表示为[0,1000]的整数
Output
对每组数据，输出Alice最多能接到几头牛产的牛奶

测试样例
输入样例
2
1 2
2 3
8
3 4
0 7
3 8
15 19
15 20
10 15
8 18
6 12
0
输出样例
2
3
*/
struct mytime {
	int begin;
	int end;
	int during;

};

bool operator<(const mytime &left, const mytime &right)
{

	if (left.end < right.end)
	{
		return true;
	}
	else if (left.end == right.end)
	{
		if (left.during < right.during)
		{
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}




bool fillhours(int begin, int end, int hours[24])
{

	int len = end - begin;
	//check
	for (int i = 0; i < len; ++i)
	{
		if (hours[begin + i] >= 2)
		{
			return false;
		}
	}

	if (hours[begin] == 1)
	{
		hours[begin] = 2;
	}
	else {
		//开头设置为3
		hours[begin] = 3;
	}
	for (int i = 1; i <len; ++i)
	{
		hours[begin + i] = 2;
	}
	//结尾设置为1
	if (hours[begin + len] == 3)
		hours[begin + len] = 2;
	else
		hours[begin + len] = 1;
	return true;

}

//看答案的 自己做错的
int main3D()
{
	int bulls = 0;
	vector<int> vout;
	while (scanf("%d", &bulls))
	{
		if (bulls == 0)
			break;
		//int *allnums=(int *)calloc(bulls,sizeof(int));
		map<mytime, int> schedule;
		//allnums.reserve(100000000);
		for (int i = 0; i < bulls; ++i)
		{
			int begin = 0, end = 0;
			scanf("%d %d", &begin, &end);

			mytime t;
			t.begin = begin;
			t.during = end - begin;
			t.end = end;
			schedule.insert(make_pair(t, end));
		}
		int count = 0;
		int lastend = 0;
		int newhours[24] = { 0 };
		//map<time, int>::iterator minbegindur= schedule.begin();
		for (auto it = schedule.begin(); it != schedule.end(); ++it)
		{


			/*if (it->first.begin >= lastend)
			{
			for (auto it2 = schedule.begin(); it2 != schedule.end(); ++it2)
			{
			if ( minbegindur->first.begin < it->first.begin)
			{
			minbegindur = it2;

			}
			}
			}*/

			//fillhours(it->first.begin, it->second, newhours)
			if (it->first.begin >= lastend)
			{
				count++;
				lastend = it->second;
			}

		}

		vout.push_back(count);


	}


	for (int i = 0; i < vout.size(); i++)
	{
		cout << vout[i] << endl;
	}
	system("pause");
	return 0;

}

/*
问题描述
快到交配的季节了，Alice要准备为牧场里的牛进行配对。为了保证遗传性状的优良，不能随便找两头牛进行配对，
要满足一定的条件。根据对牛的一系列遗传学分析，给每头牛计算出遗传特征的关键字编号，有些牛的是同一个品种
并且性状一致，所以牛的特征编号可能重复。如果两头牛的编号之和恰为K，那么从遗传学的理论的视角看，
这两头牛进行配对结果将是最优的，Alice就要把这两头牛挑出来放在一个畜栏中准备为它们配对。
现在告诉你所有牛的编号和数字K，请你帮Alice找出一对可以配对的牛。

Input
输入有3行，第一行一个正整数N表示共有N头牛，第二行有N个数字，分别表示各牛的编号，第三行一个正整数K。

0 < N ≤ 100000
牛的编号是[0,108]之间的整数
0≤K≤230
Output
对于数字K，如果能找到两头牛的编号之和是K，就在一行中输出这两头牛的编号，小的在前，大的在后，中间用一个空格分隔。
若有多对牛都满足条件，则只输出较小编号更小的那两头牛。若找不到合适的牛，就在一行中输出No

Sample Input
4
2 5 1 4
6
Sample Output
1 5

*/

int main3C()
{
	int bulls = 0;

	scanf("%d", &bulls);
	vector<int> allnums;
	for (int i = 0; i < bulls; ++i)
	{
		int num = 0;
		scanf("%d", &num);
		allnums.push_back(num);
	}
	int K = 0;
	scanf("%d", &K);
	sort(allnums.begin(), allnums.end());
	bool findpair = false;
	for (int i = 0; i<allnums.size(); i++)
	{
		/*int first = allnums[i];//timeout
		for (int j = allnums.size() - 1; j >i; j--)
		{
		if (first + allnums[j] == K)
		{
		cout << first << " " << allnums[j] << endl;
		findpair = true;
		break;
		}
		}*/
		//get rid of timeout by using binary_search
		if (binary_search(allnums.begin() + i + 1, allnums.end(), K - allnums[i]))
		{
			cout << allnums[i] << " " << K - allnums[i] << endl;
			findpair = true;
			break;
		}

		if (findpair)
			break;
	}/**/

	if (!findpair)
		cout << "No" << endl;

	//system("pause");
	return 0;
}




