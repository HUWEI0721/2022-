/*2153393 ��� ������*/
#include <iostream>
#include <iomanip>
using namespace std;
int zeller(int y, int m)
{
	int w = 0, c = 0, nian = 0, yue = 0;
	if ((m == 1 || m == 2) && (y != 2000))
	{
		c = y / 100;
		yue = m + 12;
		nian = y - c * 100 - 1;
	}
	else if ((m == 1 || m == 2) && (y == 2000))
	{
		c = (y - 1) / 100;
		yue = m + 12;
		nian = y - ((y - 1) / 100) * 100 - 1;
	}
	else
	{
		c = y / 100;
		yue = m;
		nian = y - c * 100;
	}
	w = ((nian + nian / 4 + c / 4 - 2 * c + (13 * (yue + 1) / 5) + 1 - 1) + 700) % 7;
	//w = ((nian + nian / 4 + c / 4 - 2 * c + (26 * (yue + 1) / 10) ) + 700) % 7;
	return w;

}
int calendar(int year,int month,int day)
{
	int s, date;
	cout << "======================================================" << endl;
	cout << "������  ����һ  ���ڶ�  ������  ������  ������  ������" << endl;
	cout << "======================================================" << endl;
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
int main()
{
	int year_, month_;
	int a, b;
	while (1)
	{
		cout << "��������[1900-2100]����" << endl;
		cin >> year_ >> month_;
		cout << endl;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "�����������������" << endl;
			continue;
		}
		else if (year_ >= 1900 && year_ <= 2100)
		{
			if (month_ >= 1 && month_ <= 12)
				break;
				
			else if (!(month_ >= 1 && month_ <= 12))
			{
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "�²���ȷ������������" << endl;
			}
		}
		else if (!(year_ >= 1900 && year_ <= 2100))
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "��ݲ���ȷ������������" << endl;
		}
	}
	cout << year_ << "��" << month_ << "��" << endl;
	a = zeller(year_, month_);//a=zeller(year_,month_,1)  1����1��
	b = calendar(year_, month_, a);
	return 0;
}