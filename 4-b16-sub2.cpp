/*2153393 胡峻玮 软件*/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
void f2(double a, double b, double c)
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