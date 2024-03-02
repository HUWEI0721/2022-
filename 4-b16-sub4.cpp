/*2153393 胡峻玮 软件*/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
void f4(double a, double b, double c, double delta)
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