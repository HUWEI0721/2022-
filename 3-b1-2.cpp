/*2153393 ��� ������*/
#include<iostream>
#include<iomanip>
using namespace std;
#define Pi 3.14159
int main()
{
	double r, h, c, s1, s2, v1, v2;
	cout << "������뾶�͸߶�" << endl;
	cin >> r >> h;
	c = 2 * Pi * r;
	s1 = Pi * r * r;
	s2 = 4 * Pi * r * r;
	v1 = 4 * Pi * r * r * r / 3;
	v2 = Pi * r * r * h;
	cout << setiosflags(ios::fixed);
	cout << "Բ�ܳ�     : "<< setprecision(2) << c  << endl;
	cout << "Բ���     : "<< setprecision(2) << s1 << endl;
	cout << "Բ������ : "<< setprecision(2) << s2 << endl;
	cout << "Բ�����   : "<< setprecision(2) << v1 << endl;
	cout << "Բ�����   : "<< setprecision(2) << v2 << endl;
	return 0;
}
