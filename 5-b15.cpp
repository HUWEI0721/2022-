/*2153393 ��� ������*/
#include <iostream>
using namespace std;
#define N 128
int main()
{
	char str[3][N];
	int upp = 0, min = 0, num = 0, spc = 0, oth = 0;
	for (int i = 0; i < 3; i++)
	{
		cout << "�������" << i + 1 << "��" << endl;
		cin.getline(str[i], N);
	}
	for (int i = 0; i < 3; i++) 
	{
		for (int j = 0; j < 128; j++) 
		{
			char temp = str[i][j];
			if (temp >= 'A' && temp <= 'Z')
				upp += 1;
			else if (temp >= 'a' && temp <= 'z')
				min += 1;
			else if (temp >= '0' && temp <= '9')
				num += 1;
			else if (temp == ' ')
				spc += 1;
			else if (temp != '\0')
				oth += 1;
			if (temp == '\0')
				break;
		}
	}
	cout << "��д : " << upp << endl;
	cout << "Сд : " << min << endl;
	cout << "���� : " << num << endl;
	cout << "�ո� : " << spc << endl;
	cout << "���� : " << oth << endl;
	return 0;
}
/*Welcome to Tongji University.
<Hello,world!> -> ��Hello��world����
Name=���� and No=2059999 && Sex=��*/