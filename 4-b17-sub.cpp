/*2153393 胡峻玮 软件*/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
extern double a;
extern double b;
extern double c;
extern double delta;
void f1()
{
	cout << "不是一元二次方程" << endl;
	return;
}
void f2()
{
	double x1 = 0, x2 = 0;
	x1 = -b / (2 * a);
	x2 = x1;
	cout << "有两个相等实根：" << endl;
	if (fabs(x1) < 1e-6)
		x1 = 0;
	cout << setprecision(6) << "x1=x2=" << x1 << endl;
	return;
}
void f3()
{
	double s = 0, x1_x = 0;
	delta = fabs(delta);
	s = -b / (2 * a);
	x1_x = fabs(sqrt(delta) / (2 * a));
	cout << "有两个虚根：" << endl;
	if (fabs(s) < 1e-6)
		s = 0;
	if (fabs(x1_x) < 1e-6)
		x1_x = 0;
	if ((s != 0) && (x1_x != 1))
	{
		cout << setprecision(6) << "x1=" << s << "+" << x1_x << "i" << endl;
		cout << setprecision(6) << "x2=" << s << "-" << x1_x << "i" << endl;
	}
	else if (s == 0)
	{
		if (x1_x == 1)
		{
			cout << "x1=i" << endl;
			cout << "x2=-i" << endl;
		}
		else
		{
			cout << setprecision(6) << "x1=" << x1_x << "i" << endl;
			cout << setprecision(6) << "x2=-" << x1_x << "i" << endl;
		}
	}
	return;
}
void f4()
{
	double x1 = 0, x2 = 0;
	x1 = ((-b + sqrt(delta)) / (2 * a));
	x2 = ((-b - sqrt(delta)) / (2 * a));
	cout << "有两个不等实根：" << endl;
	if (fabs(x1) < 1e-6)
		x1 = 0;
	if (fabs(x2) < 1e-6)
		x2 = 0;
	cout << setprecision(6) << "x1=" << x1 << endl;
	cout << setprecision(6) << "x2=" << x2 << endl;
}