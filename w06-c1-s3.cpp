/*2153393 ��� ������*/
#include <iostream>
using namespace std;
int main()
{
	int x1, x2, y1, y2;
	double x0 = 0, y0 = 0;
	double k = 0;
	cout << "�������1��������� : ";
	cin >> x1 >> y1;
	cout << "�������2��������� : ";
	cin >> x2 >> y2;
	if (x2 == x1)
	{
		if (x1 > 0)
			cout << "ƽ����y��,��һ������" << endl;
		else if (x1 < 0)
			cout << "ƽ����y��,�ڶ�������" << endl;
	}
	else if (y2 == y1)
	{
		if (y1 > 0)
			cout << "ƽ����x��,��һ������" << endl;
		else if (y1 < 0)
			cout << "ƽ����x��,����������" << endl;
	}
	else if ((x2 != x1) && (y2 != y1))
	{
	//	k = (y1 - y2)*1.00 / (x1 - x2);
		x0 =(x1*y2-x2*y1)*1.0/(y2-y1); 
		y0 =(x2*y1-x1*y2)*1.0/(x2-x1);
		if ((x0 > 0) && (y0 > 0))
			cout << "�ڵ�һ����" << endl;
		else if ((x0 < 0) && (y0 > 0))
			cout << "�ڵڶ�����" << endl;
		else if ((x0 < 0) && (y0 < 0))
			cout << "�ڵ�������" << endl;
		else if ((x0 > 0) && (y0 < 0))
			cout << "�ڵ�������" << endl;
	}

	return 0;
}
