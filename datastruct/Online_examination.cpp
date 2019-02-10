#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

/*
C - 搬家
Alice准备搬家，他把自己的物品都装到箱子里，并在箱子上贴了箱子的重量。装箱后要将这些箱子运到卡车上运去新的住所。将箱子往卡车上运的时候，
需要把它堆起来以节省卡车上的空间。而堆砌的时候如果上方的箱子比下方箱子更重，那么会把下方箱子压坏，
这时就需要重新堆另一堆。Alice希望你写一个程序帮助计算出最少堆几垛箱子。
输入形式为
N
w1
w2
...
wN
输入共N+1行，第1行有一个数字N表示有N个箱子，后续有N行，每行一个数字表示箱子的重量

0≤N≤50
0≤wi≤100000
*/

vector<stack<int>> boxstack;

bool canput(int &indexstack,int weight)
{
	int min = 99999999;
	if (boxstack.size() == 0)
		return false;


	for (int j = 0; j < boxstack.size(); j++)
	{
		int top=boxstack[j].top();
		
		if (top >= weight)
		{
			/*min = top;*/
			indexstack = j;
			return true;
		}
	}
	return false;
}


void wheretoput(int weight)
{
	int closest = 9999999;
	int indexstack = -1;
	for (int j = 0; j < boxstack.size(); j++)
	{
		int top = boxstack[j].top();
		//差距最小的才是可以放的
		int gap = weight - top;
		if (gap > 0)
		{
			//can't put
			continue;
		}
		gap = abs(gap);
		if (gap < closest)
		{
			closest = gap;
			indexstack = j;
		}
	}

	//放到合适的栈中
	boxstack[indexstack].push(weight);
}


int mainC()
{
	int boxnum = 0;
	scanf("%d", &boxnum);
	
	
	for (int i = 0; i < boxnum; ++i)
	{
		int weight = 0;
		scanf("%d", &weight);
		int indexstack = 0;
		bool put = canput(indexstack, weight);
		if (put)
		{
			wheretoput(weight);
		}
		else {
			stack<int> newstack;
			newstack.push(weight);
			boxstack.push_back(newstack);
		}
	
	}


	cout << boxstack.size();
	//system("pause");
	return 0;
}