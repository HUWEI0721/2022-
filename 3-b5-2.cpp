/*2153393 软件 胡峻玮*/
#include <iostream>
using namespace std;
int main()
{
	int y, m, d;
	int sum = 0;
	int leap;
	cout << "请输入年，月，日" << endl;
	cin >> y >> m >> d;
	if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
		leap = 1;
	else
		leap = 0;
	
	if ((m > 12) || (m <= 0))
	{
		cout << "输入错误-月份不正确" << endl;
	}
	else if (((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) && (d == 30)) ||
		((m == 4 || m == 6 || m == 9 || m == 11) && (d == 31)) || (leap == 1 && m == 2 && d > 29) ||
		(leap == 0 && m == 2 && d > 28) || (d > 31) || (d <= 0))
	{
		cout << "输入错误-日与月的关系非法" << endl;
	}
	else
	{
		switch (m)
		{
			case 1:
				sum = 0;
				break;
			case 2:
				sum = 31;
				break;
			case 3:
				sum = 59;
				break;
			case 4:
				sum = 90;
				break;
			case 5:
				sum = 120;
				break;
			case 6:
				sum = 151;
				break;
			case 7:
				sum = 181;
				break;
			case 8:
				sum = 212;
				break;
			case 9:
				sum = 243;
				break;
			case 10:
				sum = 273;
				break;
			case 11:
				sum = 304;
				break;
			case 12:
				sum = 334;
				break;
			default:
				return 0;
		}
		sum += d;
		if (leap == 1 && m > 2)
			sum++;
		cout << y << "-" << m << "-" << d << "是" << y << "年的第" << sum << "天" << endl;
	}
	return 0;
}