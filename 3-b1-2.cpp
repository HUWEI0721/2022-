/*2153393 软件 胡峻玮*/
#include<iostream>
#include<iomanip>
using namespace std;
#define Pi 3.14159
int main()
{
	double r, h, c, s1, s2, v1, v2;
	cout << "请输入半径和高度" << endl;
	cin >> r >> h;
	c = 2 * Pi * r;
	s1 = Pi * r * r;
	s2 = 4 * Pi * r * r;
	v1 = 4 * Pi * r * r * r / 3;
	v2 = Pi * r * r * h;
	cout << setiosflags(ios::fixed);
	cout << "圆周长     : "<< setprecision(2) << c  << endl;
	cout << "圆面积     : "<< setprecision(2) << s1 << endl;
	cout << "圆球表面积 : "<< setprecision(2) << s2 << endl;
	cout << "圆球体积   : "<< setprecision(2) << v1 << endl;
	cout << "圆柱体积   : "<< setprecision(2) << v2 << endl;
	return 0;
}
