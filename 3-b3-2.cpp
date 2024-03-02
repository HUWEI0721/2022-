/*2153393 软件 胡峻玮*/
#include<iostream>
using namespace std;
int main()
{
	double a, b;
	int m;
	cout << "请输入[0,100亿)之间的数字:" << endl;
	cin >> a;
	b = a;
	a = a / 10;
	long zheng = (long)a;
	m = (int)((a - zheng +0.0001) * 1000);
	cout << "十亿位 : " << zheng / 100000000 % 10 << endl;
	cout << "亿位   : " << zheng / 10000000 % 10 << endl;
	cout << "千万位 : " << zheng / 1000000 % 10 << endl;
	cout << "百万位 : " << zheng / 100000 % 10 << endl;
	cout << "十万位 : " << zheng / 10000 % 10 << endl;
	cout << "万位   : " << zheng / 1000 % 10 << endl;
	cout << "千位   : " << zheng / 100 % 10 << endl;
	cout << "百位   : " << zheng / 10 % 10 << endl;
	cout << "十位   : " << zheng / 1 % 10 << endl;
	cout << "圆     : " << m / 100 % 10 << endl;
	cout << "角     : " << m / 10 % 10 << endl;
	cout << "分     : " << m / 1 % 10 << endl;
	return 0; 
}
