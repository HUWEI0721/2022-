/* 2153393 ��� ������ */ 
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	/* ��Щ�����������ʾ���ַ���������Ҹ��Ƶ�����λ�ã�����ϸ�ڲ��� */ 
	int x,y,r,j,xin;
	double x1,y1,x2,y2; 
	const double pi=3.14159;
	cout<<"������Բ��x����[-100..100] : ";
	cin>>x;
	cout<<"������Բ��y����[-100..100] : ";
	cin>>y;
	cout<<"������Բ�뾶r[1..100] : ";
	cin>>r;
	cout<<"���������(�ɼ�)�Ƕ�[0..360) : ";
	cin>>j;
	cout<<"�������յ�(�¼�)�Ƕ�[0..360) : ";
	cin>>xin;
	x1=x+r*sin(pi*j/180.0);
	y1=y+r*cos(pi*j/180.0);
	x2=x+r*sin(pi*xin/180.0);
	y2=y+r*cos(pi*xin/180.0);
	cout << setiosflags(ios::fixed);
	cout<<"�ɼ����� : "<<setprecision(2)<<"("<<x1<<", "<<y1<<")"<<endl;
	cout<<"�¼����� : "<<setprecision(2)<<"("<<x2<<", "<<y2<<")"<<endl;

	return 0;
}
