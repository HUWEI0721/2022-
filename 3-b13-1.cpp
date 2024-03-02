/*软件 2153393 胡峻玮*/
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int year, month, day, s, date;
	while (1)
	{
		cout << "请输入年份(2000-2030)和月份(1-12) : ";
		cin >> year >> month;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "输入非法，请重新输入" << endl;
			continue;
		}
		else if (year >= 2000 && year <= 2030 && month >= 1 && month <= 12)
			break;
		else
		{
			cout << "输入非法，请重新输入" << endl;
			continue;
		}
	}
	while (1)
	{
		cout << "请输入" << year << "年" << month << "月1日的星期(0-6表示星期日-星期六) : ";
		cin >> day;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "输入非法，请重新输入" << endl;
			continue;
		}
		else if (day >= 0 && day <= 6)
			break;
		else
		{
			cout << "输入非法，请重新输入" << endl;
			continue;
		}
	}
	cout << endl;
	cout << year << "年" << month << "月的月历为:" << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
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