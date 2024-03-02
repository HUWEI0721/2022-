/*��� 2153393 ������*/
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int year, month, day, s, date;
	while (1)
	{
		cout << "���������(2000-2030)���·�(1-12) : ";
		cin >> year >> month;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "����Ƿ�������������" << endl;
			continue;
		}
		else if (year >= 2000 && year <= 2030 && month >= 1 && month <= 12)
			break;
		else
		{
			cout << "����Ƿ�������������" << endl;
			continue;
		}
	}
	while (1)
	{
		cout << "������" << year << "��" << month << "��1�յ�����(0-6��ʾ������-������) : ";
		cin >> day;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "����Ƿ�������������" << endl;
			continue;
		}
		else if (day >= 0 && day <= 6)
			break;
		else
		{
			cout << "����Ƿ�������������" << endl;
			continue;
		}
	}
	cout << endl;
	cout << year << "��" << month << "�µ�����Ϊ:" << endl;
	cout << "������  ����һ  ���ڶ�  ������  ������  ������  ������" << endl;
	//�ж�ƽ�껹������
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		s = 366;
	else
		s = 365;
	//�ж��·�����
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		date = 31;
	else if (s == 366 && month == 2)
		date = 29;
	else if (s == 365 && month == 2)
		date = 28;
	else
		date = 30;
	for (int i = 0; i < day; i++)
		cout << setw(4) << " " << setw(4) << " ";
	for (int i = 1, j = day + i; i <= date; i++, j++)
	{
		cout << setw(4) << i << setw(4) << " ";
		if (j % 7 == 0)
			cout << endl;
	}
	cout << endl;
	return 0;
}