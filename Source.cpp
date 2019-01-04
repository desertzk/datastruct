#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<iostream>
#include<stack>
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