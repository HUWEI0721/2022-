/* 2153393 ��� ������ */ 
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int b = 654321;

	cout << "==================================================" << endl;
	cout << "0         1         2         3         4" << endl;
	cout << "01234567890123456789012345678901234567890123456789" << endl;
	cout << "==================================================" << endl;

	/* ��Ҫ�����b�ĸ�����ʽ -- Begin */ 
	cout<<b<<"#"<<endl;
	cout<<setiosflags(ios::uppercase)<<hex<<b<<"#"<<endl;
 	cout<<resetiosflags(ios::uppercase)<<hex<<b<<"#"<<endl; 
 	cout<<setiosflags(ios::uppercase)<<hex<<b<<"#"<<endl;
 	cout<<dec<<setw(10)<<b<<","<< setiosflags(ios::left)<<setw(10)<<b<<"#"<<endl;
 	cout<<setw(10)<<setfill('*')<<b<<"#"<<endl;
 	cout<<setw(10)<<setfill(' ')<<resetiosflags(ios::left)<<b<<"#"<<endl;	
 	cout<<setiosflags(ios::showpos)<<b<<"#"<<endl;
	cout<<setfill(' ');
	cout<<oct<<setiosflags(ios::left)<<setw(10)<<b<<","<<resetiosflags(ios::left)<<setw(10)<<b<<"#"<<endl;
	cout<<oct<<setw(10)<<setfill('*')<<b<<"#"<<endl;
	cout<<oct<<setw(10)<<setfill(' ')<<setiosflags(ios::left)<<b<<"#"<<endl;
	/* ��Ҫ�����b�ĸ�����ʽ -- End */ 

	cout << "==================================================" << endl;
	cout << "01234567890123456789012345678901234567890123456789" << endl;
	cout << "0         1         2         3         4" << endl;
	cout << "==================================================" << endl;

	return 0;
}
