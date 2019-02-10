#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

/*
C - ���
Alice׼����ң������Լ�����Ʒ��װ������������������������ӵ�������װ���Ҫ����Щ�����˵���������ȥ�µ�ס�������������������˵�ʱ��
��Ҫ�����������Խ�ʡ�����ϵĿռ䡣��������ʱ������Ϸ������ӱ��·����Ӹ��أ���ô����·�����ѹ����
��ʱ����Ҫ���¶���һ�ѡ�Aliceϣ����дһ�����������������ٶѼ������ӡ�
������ʽΪ
N
w1
w2
...
wN
���빲N+1�У���1����һ������N��ʾ��N�����ӣ�������N�У�ÿ��һ�����ֱ�ʾ���ӵ�����

0��N��50
0��wi��100000
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
		//�����С�Ĳ��ǿ��Էŵ�
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

	//�ŵ����ʵ�ջ��
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