/*2153393 ��� ������*/
#include<iostream>
using namespace std;
int main()
{
	double a, b;
	int m;
	cout << "������[0,100��)֮�������:" << endl;
	cin >> a;
	b = a;
	a = a / 10;
	long zheng = (long)a;
	m = (int)((a - zheng +0.0001) * 1000);
	cout << "ʮ��λ : " << zheng / 100000000 % 10 << endl;
	cout << "��λ   : " << zheng / 10000000 % 10 << endl;
	cout << "ǧ��λ : " << zheng / 1000000 % 10 << endl;
	cout << "����λ : " << zheng / 100000 % 10 << endl;
	cout << "ʮ��λ : " << zheng / 10000 % 10 << endl;
	cout << "��λ   : " << zheng / 1000 % 10 << endl;
	cout << "ǧλ   : " << zheng / 100 % 10 << endl;
	cout << "��λ   : " << zheng / 10 % 10 << endl;
	cout << "ʮλ   : " << zheng / 1 % 10 << endl;
	cout << "Բ     : " << m / 100 % 10 << endl;
	cout << "��     : " << m / 10 % 10 << endl;
	cout << "��     : " << m / 1 % 10 << endl;
	return 0; 
}
