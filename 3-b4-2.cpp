/*2153393 ��� ������*/
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
#define pi 3.14159
int main()
{
	int a, b, c ;
	float d, S;
	cout << "�����������ε����߼���н�(�Ƕ�)" << endl;
	cin >> a >> b >> c;
	d = (float)(sin(c * pi / 180));
	S = (float)(0.5 * a * b * d);
	cout << setiosflags(ios::fixed);
	cout << "���������Ϊ : " << setprecision(3) << S << endl;

	return 0;
}