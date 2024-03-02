/*2153393 胡峻玮 软件*/
#include<iostream>
using namespace std;
#define N 81
int judge_right(char* str)
{
	char* begin = str, * end = str;
	int flag = 1;
	while (*end != '\n')
		end++;
	end -= 1;
	while (1)
	{
		if (begin < end)
		{
			if (*begin != *end)
				flag = 0;
		}
		begin++;
		end--;
		if (begin >= end)
			break;
	}
	return flag;
}
int main()
{
	char str[N] = { '\0' };
	int flag = 0;
	cout << "请输入一个长度小于80的字符串（回文串）" << endl;
	fgets(str, N - 1, stdin);
	flag = judge_right(str);
	if (flag)
		cout << "yes";
	else
		cout << "no";
	cout << endl;
	return 0;
}