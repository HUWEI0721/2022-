/*2153393 ������ ���*/
#include <iostream>
using namespace std;
#define N 32
int main()
{
	char str[N + 1];
	char* p = str;
	unsigned int sum = 0;
	cout << "������һ��0/1��ɵ��ַ��������Ȳ�����" << N << endl;
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