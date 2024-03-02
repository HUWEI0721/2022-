/*2153393 胡峻玮 软件*/
#include <iostream>
using namespace std;
#define N 32
int main()
{
	char str[N + 1];
	char* p = str;
	unsigned int sum = 0;
	cout << "请输入一个0/1组成的字符串，长度不超过" << N << endl;
	cin.getline(str, N + 1);
	while (1)
	{
		if (*p != 0)
		{
			sum += sum + (int)*p - 48;
			p++;
		}
		else
			break;
	}
	cout << sum << endl;
}