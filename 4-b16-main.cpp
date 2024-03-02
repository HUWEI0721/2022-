/*2153393 胡峻玮 软件*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include "4-b16.h"
using namespace std;
int main()
{
	double a, b, c, delta = 0;
	cout << "请输入一元二次方程的三个系数a,b,c:" << endl;
	cin >> a >> b >> c;
	if (fabs(a) < 1e-6)
		a = 0;
	if (fabs(b) < 1e-6)
		b = 0;
	if (fabs(c) < 1e-6)
		c = 0;
	delta = b * b - 4 * a * c;
	if (fabs(delta) < 1e-6)
		delta = 0;

	if (a == 0)
		f1();
	else if (delta == 0)
		f2(a, b, c);
	else if (delta < 0)
		f3(a, b, c, delta);
	else if (delta > 0)
		f4(a, b, c, delta);
	return 0;
}