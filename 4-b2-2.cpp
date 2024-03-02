/*2153393 软件 胡峻玮*/
#include <iostream>
using namespace std;
int zeller(int y, int m, int d)
{
	int w = 0, c = 0, nian = 0, yue = 0, ri = 0;
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
		
	ri = d;
	w = ((nian + nian / 4 + c / 4 - 2 * c + (26 * (yue + 1) / 10) + ri - 1) + 700) % 7;
	return w;

}
int main()
{
	int n, yue, r;
	int a;
	while (1) {
		cout << "请输入年[1900-2100]、月、日：" << endl;
		cin >> n >> yue >> r;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "输入错误，请重新输入" << endl;
			continue;
		}
		else if (n >= 1900 && n <= 2100)
		{
			if (yue >= 1 && yue <= 12)
			{
				//闰年
				if ((n % 4 == 0 && n % 100 != 0) || n % 400 == 0)
				{
					if ((yue == 2) && (r <= 29))
						break;
					else if ((r <= 31) && (yue == 1 || yue == 3 || yue == 5 || yue == 7 || yue == 8 || yue == 10 || yue == 12))
						break;
					else if ((r <= 30) && (yue == 4 || yue == 6 || yue == 9 || yue == 11))
						break;
					else 
					{
						cin.clear();
						cin.ignore(1024, '\n');
						cout << "日不正确，请重新输入" << endl;
					}
						
				}
				else
				{
					if ((yue == 2) && (r <= 28))
						break;
					else if ((r <= 31) && (yue == 1 || yue == 3 || yue == 5 || yue == 7 || yue == 8 || yue == 10 || yue == 12))
						break;
					else if ((r <= 30) && (yue == 4 || yue == 6 || yue == 9 || yue == 11))
						break;
					else
					{
						cin.clear();
						cin.ignore(1024, '\n');
						cout << "日不正确，请重新输入" << endl;
					}
				}
			}
			else if (!(yue >= 1 && yue <= 12))
			{
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "月不正确，请重新输入" << endl;
			}
		}
		else if (!(n >= 1900 && n <= 2100))
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "年不正确，请重新输入" << endl;
		}

	}
	a = zeller(n, yue, r);
	switch (a)
	{
		case 0:
			cout << "星期日" << endl;
			break;
		case 1:
			cout << "星期一" << endl;
			break;
		case 2:
			cout << "星期二" << endl;
			break;
		case 3:
			cout << "星期三" << endl;
			break;
		case 4:
			cout << "星期四" << endl;
			break;
		case 5:
			cout << "星期五" << endl;
			break;
		case 6:
			cout << "星期六" << endl;
			break;
	}
	return 0;
}