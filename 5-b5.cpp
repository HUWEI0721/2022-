/*2153393 ������ ���*/
#include <iostream>
using namespace std;
int main()
{
	int a[1000] = { 0 };
	int b[1000] = { 0 };
	int i, x, num = 0;
	for (i = 0; i < 1000; i++)
		a[i] = -1;
	cout<<"������ɼ������1000������������������" << endl;
	for (i = 0; i < 1000; i++)
	{
		cin >> x;
		if (x >= 0)
			a[i] = x;
		else if (x < 0)
			break;
	}
	if (a[0] < 0)
		cout << "����Ч����" << endl;
	else 
	{
		cout << "���������Ϊ:" << endl;
		for (i = 0; i < 1000; i++)
		{
			if (a[i] >= 0)
			{
				if ((i % 10 == 0) && (i != 0))
					cout << endl;
				cout << a[i] << " ";
			}
			else
				break;
		}
		cout << endl;
		cout << "���������εĶ�Ӧ��ϵΪ:" << endl;
		for (int i = 0; i < 999; i++)
		{
			for (int j = 0; j < 999 - i; j++)
			{
				if (a[j] > a[j + 1])
				{
					int temp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = temp;
				}
			}
		}
		for (i = 999; i >= 0; i--)
		{
			num++;
			b[i] = num;
		}
		for (i = 999; i >= 0; i--)
		{
			if (a[i] == a[i - 1])
				b[i-1] = b[i];
		}
		for (i = 999; i >= 0; i--)
		{
			if (a[i] >= 0)
				cout << a[i] << " " << b[i] << endl;
		}
	}
	return 0;
}