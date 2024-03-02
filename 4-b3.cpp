/*2153393 软件 胡峻玮*/
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
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
	cout << "======================================================" << endl;
	//判断平年还是闰年
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		s = 366;
	else
		s = 365;
	//判断月份天数
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
		cout << "请输入年[1900-2100]、月" << endl;
		cin >> year_ >> month_;
		cout << endl;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "输入错误，请重新输入" << endl;
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
				cout << "月不正确，请重新输入" << endl;
			}
		}
		else if (!(year_ >= 1900 && year_ <= 2100))
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "年份不正确，请重新输入" << endl;
		}
	}
	cout << year_ << "年" << month_ << "月" << endl;
	a = zeller(year_, month_);//a=zeller(year_,month_,1)  1代表1号
	b = calendar(year_, month_, a);
	return 0;
}