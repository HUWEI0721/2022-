/*2153393 ������ ���*/
#include <iostream>
using namespace std;
int main()
{
	int a[20] = { 0 };
	int b[21] = { 0 };
	int x, insert, i = 0;
	cout << "��������������������������20������0������������" << endl;
	for (i = 0; i < 20; i++)
	{
		cin >> x;
		if (x > 0)
			a[i] = x;
		else if (x <= 0)
			break;
	}
	cin.clear();
	cin.ignore(1024, '\n');
	if (a[0] == 0 || (a[0] < 0))
		cout << "����Ч����" << endl;
	else
	{
		cout << "ԭ����Ϊ��" << endl;
		for (i = 0; i < 20; i++)
		{
			if (a[i] != 0)
				cout << a[i] << " ";
			else
				break;
		}
		cout << endl;
		cout << "������Ҫ�����������" << endl;
		cin >> insert;
		for (i = 0; i < 20; i++)
			b[i] = a[i];
		for (i = 0; i < 21; i++)
		{
			if (b[i] > insert)
			{
				for (int j = 19; j >= i; j--)
				{
					b[j + 1] = b[j];
				}
				b[i] = insert;
				break;
			}
			if(b[i]==0)
			{
				b[i]=insert;
				break;
			}
		}


		cout << "����������Ϊ��" << endl;
		for (i = 0; i < 21; i++)
		{
			if (b[i] != 0)
				cout << b[i] << " ";
			else
				break;
		}
	}
		
	return 0;
}
