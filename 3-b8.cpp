/*2153393 软件 胡峻玮*/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
	int x, i = 0;
	double t = 1, sum = 0, zi = 1, mu = 1;
	cout << "请输入x的值[-10 ~ +65]" << endl;
	cin >> x;
	while ((x < -10) || (x > 65))
	{
		cout << "输入非法，请重新输入" << endl;
		cout << "请输入x的值[-10 ~ +65]" << endl;
		cin >> x;
		if ((x < -10) || (x > 65))
			continue;
		else
			break;
	}
	while (fabs(t) > 1e-6)
	{
		sum += t;
		i += 1;
		zi = pow(x, i);
		mu = mu * i;
		t = zi / mu;
		
	}
	cout << "e^" << x << "=" << setprecision(10) << sum << endl;
	return 0;
}