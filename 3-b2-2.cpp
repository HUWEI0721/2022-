/*2153393 软件 胡峻玮*/
#include<iostream>
using namespace std;
int main()
{
	int a;
	cout<<"请输入一个[1..30000]间的整数:" << endl;
	cin >> a;
	cout << "万位 : " << a / 10000 % 10 << endl;
	cout << "千位 : " << a / 1000 % 10 << endl;
	cout << "百位 : " << a / 100 % 10 << endl;
	cout << "十位 : " << a / 10 % 10 << endl;
	cout << "个位 : " << a / 1 % 10 << endl;
	return 0;
}