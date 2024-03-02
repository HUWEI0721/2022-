/*2153393 软件 胡峻玮*/
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
#define pi 3.14159
int main()
{
	int a, b, c ;
	float d, S;
	cout << "请输入三角形的两边及其夹角(角度)" << endl;
	cin >> a >> b >> c;
	d = (float)(sin(c * pi / 180));
	S = (float)(0.5 * a * b * d);
	cout << setiosflags(ios::fixed);
	cout << "三角形面积为 : " << setprecision(3) << S << endl;

	return 0;
}