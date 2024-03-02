/*2153393 软件 胡峻玮*/
#include <iostream>
using namespace std;
int main()
{
	int x1, x2, y1, y2;
	double x0 = 0, y0 = 0;
	double k = 0;
	cout << "请输入第1个点的坐标 : ";
	cin >> x1 >> y1;
	cout << "请输入第2个点的坐标 : ";
	cin >> x2 >> y2;
	if (x2 == x1)
	{
		if (x1 > 0)
			cout << "平行于y轴,在一四象限" << endl;
		else if (x1 < 0)
			cout << "平行于y轴,在二三象限" << endl;
	}
	else if (y2 == y1)
	{
		if (y1 > 0)
			cout << "平行于x轴,在一二象限" << endl;
		else if (y1 < 0)
			cout << "平行于x轴,在三四象限" << endl;
	}
	else if ((x2 != x1) && (y2 != y1))
	{
	//	k = (y1 - y2)*1.00 / (x1 - x2);
		x0 =(x1*y2-x2*y1)*1.0/(y2-y1); 
		y0 =(x2*y1-x1*y2)*1.0/(x2-x1);
		if ((x0 > 0) && (y0 > 0))
			cout << "在第一象限" << endl;
		else if ((x0 < 0) && (y0 > 0))
			cout << "在第二象限" << endl;
		else if ((x0 < 0) && (y0 < 0))
			cout << "在第三象限" << endl;
		else if ((x0 > 0) && (y0 < 0))
			cout << "在第四象限" << endl;
	}

	return 0;
}
