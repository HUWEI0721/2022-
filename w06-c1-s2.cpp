/* 2153393 软件 胡峻玮 */ 
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	/* 这些是输入输出提示的字符串，供大家复制到所需位置，避免细节差异 */ 
	int x,y,r,j,xin;
	double x1,y1,x2,y2; 
	const double pi=3.14159;
	cout<<"请输入圆心x坐标[-100..100] : ";
	cin>>x;
	cout<<"请输入圆心y坐标[-100..100] : ";
	cin>>y;
	cout<<"请输入圆半径r[1..100] : ";
	cin>>r;
	cout<<"请输入起点(旧家)角度[0..360) : ";
	cin>>j;
	cout<<"请输入终点(新家)角度[0..360) : ";
	cin>>xin;
	x1=x+r*sin(pi*j/180.0);
	y1=y+r*cos(pi*j/180.0);
	x2=x+r*sin(pi*xin/180.0);
	y2=y+r*cos(pi*xin/180.0);
	cout << setiosflags(ios::fixed);
	cout<<"旧家坐标 : "<<setprecision(2)<<"("<<x1<<", "<<y1<<")"<<endl;
	cout<<"新家坐标 : "<<setprecision(2)<<"("<<x2<<", "<<y2<<")"<<endl;

	return 0;
}
