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

int main()
{
	int bulls = 0;
	vector<int> vout;
	while (scanf("%d", &bulls))
	{
		//int *allnums=(int *)calloc(bulls,sizeof(int));
		map<int, int> schedule;
			//allnums.reserve(100000000);
		for (int i = 0; i < bulls; ++i)
		{
			int begin = 0, end=0;
			scanf("%d %d", &begin,&end);
			schedule[begin] = end;
		}
		
		schedule.begin();



		
	}
	
	system("pause");
	return 0;

}

/*
��������
�쵽����ļ����ˣ�AliceҪ׼��Ϊ�������ţ������ԡ�Ϊ�˱�֤�Ŵ���״�������������������ͷţ������ԣ�
Ҫ����һ�������������ݶ�ţ��һϵ���Ŵ�ѧ��������ÿͷţ������Ŵ������Ĺؼ��ֱ�ţ���Щţ����ͬһ��Ʒ��
������״һ�£�����ţ��������ſ����ظ��������ͷţ�ı��֮��ǡΪK����ô���Ŵ�ѧ�����۵��ӽǿ���
����ͷţ������Խ���������ŵģ�Alice��Ҫ������ͷţ����������һ��������׼��Ϊ������ԡ�
���ڸ���������ţ�ı�ź�����K�������Alice�ҳ�һ�Կ�����Ե�ţ��

Input
������3�У���һ��һ��������N��ʾ����Nͷţ���ڶ�����N�����֣��ֱ��ʾ��ţ�ı�ţ�������һ��������K��

0 < N �� 100000
ţ�ı����[0,108]֮�������
0��K��230
Output
��������K��������ҵ���ͷţ�ı��֮����K������һ�����������ͷţ�ı�ţ�С����ǰ������ں��м���һ���ո�ָ���
���ж��ţ��������������ֻ�����С��Ÿ�С������ͷţ�����Ҳ������ʵ�ţ������һ�������No

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
	for (int i=0;i<allnums.size();i++)
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

//A - ���������˻� 
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



//���������ĺ���S�����ǵĻ�����Ƕ���?
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
Alice���г�������N����ͣ�ÿ����Ͷ��ԡ��ڡ�Ϊ��λ����Щ�������̵���A�ڣ������B�ڣ�������͸��г��̣�ÿ���͵Ľ���Ҳ�ض���[A,B]��Χ�ڡ�����Aliceϣ������Щ��������Ӳ���ȫ���ӳ�һ������͡����Ӳ����ĳ��Ⱥ��Բ��ƣ�����������Ӻ�ĳ���͹������ж����ֲ�ͬ������
���ݲ��������ϲ������ʱ���0
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
��Ŀ����
è��Ѧ���̵�������ɹ������ѳ�������ʱ���������Ѿ�������������ѧ��ԭ��ӵ���������ӵ��������������������ǿ˷�������ϲ������ֽ������ԡ�
����������һ��ֽ���һ�˴�0��ʼ���α�ţ���ֻè���������µķ�ʽ������֮���ж���
�ߵ��������ӣ��ӵ�X�������ߵ����ڵĵ�X+1�Ż�X-1�����ӡ�
������ʽת�ƣ��ӵ�X������������̬��ʽת�Ƶ�2X�������
���������ߵķ�����������ת�Ƶķ�����������һ��ת�ơ�����������ֻè�ڵ�X���������ϣ������Y�������У�����������Ҫ����ת�ƿ��Դﵽ.

��������
����ֻ��һ�У���������X Y��һ���ո����
X Y
0��X,Y��100000

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
�й���Ա����������ȫ�����ص����ѵ���ʳ��ζҲ������ͬ����ʳϲ����ͬ���˻�����һ��Է������ǳ��以Ϊ�����ѡ�����������õ���һ��ʳ�õ���ˮ�˵���¼������з��ֽ�����ʳ�óԷ����˵���ÿ���˾����ж��������ѡ�
��������˵��ļ�¼������һ��������N�����������α��Ϊ1,2,��,N����M��ʳƷ���α��Ϊ1,2,��,M��Ϊ���������Ϊϲ����ͬһ��ʳƷ���ˣ��������ķ��ѡ������ڵ������Ǵ�����˵���¼�м����ÿ�����м������ѡ�

��һ����������N,M��2 <= N ��M<= 200����������N�У���i(i = 1,2,��,N)��ÿһ����һ��������ʾʳ��i-1��ϲ����ʳƷ�ı��P(1<=P<=M)

����N�У�ÿ��һ��������i�е�����ʾ��i��ʳ���м������ѡ����iû�з��ѣ�����ط���û���˺����Ŀ�ζ������������BeiJu��.
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
һ��������,������ܱ�x����,��������ʮ���Ʊ�ʾ����ĳ��λ���ϵ�����Ϊx,�����Ϊ��x��ص���.
�����������С�ڵ���n(n<300)����x�޹ص���������ƽ����.
����Ϊһ��,������n,(n<300)
*/
//��ĿҪ����ĳ��λ���ϣ����Ǹ�λ��
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
Alice��Ϊ4��7���������֣��������һ�������Ǽ����������ֵĺͣ���ô�������Ҳ���������֣�����
14=7+7
18=7+7+4
11=7+4
7=7
���ڸ���Q�����֣�����ֱ��ж�ÿ�������Ƿ�Ϊ��������
���빲Q+1�У���һ��һ�����ִ������ָ�����������Q�У�ÿ��һ������x
1��Q��100
1��x��1016
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
�������ʵҪ�ҹ��ɡ��ҵ����ɾ�O(1)���Ҳ������ɿ������㳬ʱ��ö�ټ������ͻᷢ�֣�
����17����������������Alice��Ϊ���������֡������һ����������x������һ��������7��
��ô��������4+4������x+1Ҳ���������֣�����ÿ����7��4�ͽ��任��4��7��
ÿ��7�ֿ��Ի���4+4����˿��Թ��ɵ�֤������һ������17�������������������֡�
���ԣ�ֻ��Ҫ�ж��������x�Ƿ���С�ڵ���17���Ǽ��������������� 
[1,2,3,5,6,9,10,13,17]���ɡ�


�����Ĳ����ϴ���
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
��������
�����֮ǰAlice����һЩ��ͣ�ƴ��֮��Alice�����سɵȳ����ĶΣ�Χ��һ�������ε�ţ��������ţ������Alice���������鲻�㣬��ͷţ���˲���Alice�ҵ����ص���ҽ��ҩ����ҩ���������ι����ͷţ��
�������ţ���Ǹ��߳�ΪN�������Σ�ţ�������еĵ�����Ϊ��(0,0)��(N,N)�����꣬ţ��ı�Ե�ĸ��㶼�������ϣ�������ֻ��M������õ��ǰ���ҩƷ�����ϡ�
����ţ�ڳ���һ�������ٳ���һ��ʱ��ֻ��ѡ����ճ���������ڽ������ϡ�������ͷţ��Ҫ��K�Ѻ�ҩ���ϲ���Ȭ������ÿ������Ҫ��1���ӡ�
���ӳ����һ�ѿ�ʼ��ʱ��������ͷţ����Ҫ���⻨�����Ӳ��ܴﵽ��ҩ��Ŀ��
��������
��һ������������N,M,K
��������M�У�ÿ������������ʾ����ҩ������ϵ����꣬��Ŀ��֤�����������������εı�Ե
1 �� N,M ��105
1 ��K �� M
0 �� xi,yi��N
xi��yi������һ��Ϊ0��ΪN����֤������������ţ��ı�Ե��
�������
���һ�У�һ������������ţ�Ե���Ӧ������ҩ��̿��ܻ��ѵ�ʱ��
��������
5 5 3
5 3
0 0
0 4
3 0
1 5
�������
6
��ʾ
���������Ľ�����ͼʾ��ţ��E��ʼ�Ե�һ�ѡ�����E��ĵ�һ�ѿ�ʼ��ʱ����1�����ڵ�(0,5)�ԣ�
��2�����ڵ�(0,4)�ԣ���ֱ����6���ӳ���(0,0)�����ϣ�����3��ҩ�ﵽĿ�꣬����6���ӡ�
��Ȼ�����ţ�ȴ�B��ʼȻ��˳ʱ���C��EҲ���ԣ�ͬ������6����

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

//ֻ��2������
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
24����Ϸ�Ƿǳ�������򵥵�С��Ϸ����һ���˿����г�ȡ4�ţ����������������Ų�ʹ�����н��ǡ����24,�����24����Ϸ��
�������ǲ��������24��������ϳ�����������n����Ҫ��ֻ������������������1����������ֻ�мӷ����˷������š����ڸ���������N��������Ҫ����1�������
��������
����һ������N( 1��N��5000)
�������
���һ����������ʾ���üӺţ��˺ź���������ɵ���N�������ٵ�1�ĸ���
����1
��������
7
�������
6
��ʾ
7=(1+1)*(1+1+1)+1
����2
��������
27
�������
9
��ʾ
27=(1+1+1)*(1+1+1)*(1+1+1)
*/

/*
F.n����Ϸ  ��̬�滮
һά�Ķ�̬�滮��
����f(n)��ʾ����n��������1�ĸ���������n=1-5�����Σ�f(n)=n��
�ټ������ӣ�n=6ʱ,6=2*3������f(6)=f(2)+f(3)=5������n=9������9=3*3,����f(9)=f(3)+f(3)��Ҫ����f(27)����Ϊ27=3*9������f(27)=f(3)+f(9)��
������f(9)��Ҫ����f(9)=f(3)*f(3)����������Ļ����������ظ����ղ�f(9)�Ѿ���������ˣ����ǿ���ֱ�ӽ��䱣��������
��f()��Ϊ����d[]����1��ʼ��N����d[i]��ֵ���ɡ������κ�����i>1��d[i]=d[i-1]+1��Ȼ�������ټ���Ƿ�����������x,y��˵���i��
���оͳ���d[x]+d[y]�Ƿ�С�ڵ�ǰd[i]����С�ھ͸���d[i]������d[i]�����մ˷��ټ���d[i+1]��ֱ�������d[N].
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

//����ֱ�ӿ��𰸵�
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
Alice��ɽ�Ϸ�ţ������ǰ�ߵ�ɽ������һ�����ʲݳ����ݳ��������ηֲ�������N�У���i����i�����ݣ����ݳ��ϵ�ÿ�õ����ݵ�Ʒ�ʿ�����һ����������������
		7
	  3   8
	8   1   0
  2   7   4   4
4   5   2   6   5
Aliceǣ��ţ�������ε��Ϸ��Ķ��㿪ʼ��ţ����һ������֮��ֻ���ԳԵ�ǰ����ǰ������ǰ����һ�á������Alice����ǣ��ţ�ӵ�1�е���N�г����ݣ��ܳԵ����ݵ�Ʒ��֮�����Ϊ���١�
��������
���빲N+1�С���һ����һ������N���������ε�������������N�У���i���пո�ָ���i-1����������ʾ�ݳ��ϸ������ݵ�Ʒ��
1<N��100
����Ʒ�ʵ�������������[0,100]
�������
���ֻ��һ��,һ����������Ե�����Ʒ��֮�͵����ֵ
����1
��������
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
�������
30
��ʾ
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
ңԶ��M-886���ƣ������������ڽ���һ��ս�ۣ����е������������ԣ������������ͻ��������ֲ�����ս������ʧ������YODA����������֣�ʷ��YODAս�ۡ�
�������໥����Ĺ����У��������ֵ�ÿһλ�������������һλ��������ͬ����ô��һλ������Ӱ�죬������һλ�����ָ�С���Ǹ�����ʧ��

�����������֣����������������н�ս֮����Ե�����ֵ�����һ�������ڽ�ս֮��ʲôҲ��ʣ����ô���YODA

��������
���ݹ�2�У�ÿ��һ�����������ֱ��ʾ��ս���������֡����ַ�ΧΪ[1,109]
�������
���2�У�ÿ��һ�����֣���ʾ��ս�����ֵĽ����������һλҲ��ʣ���������YODA��
����1
��������
300
500
�������
0
500
����2
��������
65743
9651
�������
673
95
����3
��������
2341
6785
�������
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
�����еĸ���ֳ����ࣺ��4�ı���������4����2�ı���������2�ı���,ÿ�����ĸ����ֱ���a4,a2,a1��ʾ�����Ҫ�����������У�Ҫ�����ڵ����������4�ı�����Ϊ�˾����ܶ���������֣�a1ֻ����a4���ڣ���a2������a4Ҳ������a2���ڡ����Ѿ�ͳ�Ƴ���������a4,a2��a1������ж������ܷ�������������أ�
�Ƚ��a1�����⣬a1�������a4���֣�a1������������a4��ز����������С�������˵����ʹa1��a4������֣�[a1,a4,a1,a4,...]����ʱ����һ�����е����һ������a1(��ʱa1=a4+1),��ô��߽�a2�����ų��������У����Ե�a2==0��a4<=a1+1ʱ�����ų��������С�
���������������һ������a4(��ʱa1��a4),��߿��Խ�a2��������a2������a2���ڣ�����Ҫ��a2>0ʱ��Ҫa1��a4������������ų��������С�
�����������"No"
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
			if (testeachnum[j] > 1)//�����������2��
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

