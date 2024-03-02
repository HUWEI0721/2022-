/*2153393 胡峻玮 软件*/
#include <iostream>
#include <iomanip>
#include <cmath>
double a, b, c, delta = 0;
using namespace std;
extern void f1();
extern void f2();
extern void f3();
extern void f4();
int main()
{
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
		f2();
	else if (delta < 0)
		f3();
	else if (delta > 0)
		f4();
	return 0;
}