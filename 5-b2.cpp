/*2153393 ºú¾þçâ Èí¼þ*/
#include <iostream>
using namespace std;
int main()
{
	int n = 100, i, j, k = 100, t, a[100] = { 0 }, m = 0;
	for (i = 1; i <= n; i++)
	{
		t = 0;
		for (j = 1; j <= k; j++)
		{
			if (i % j == 0)
				t++;
		}
		if (t % 2 == 1)
		{
			a[m] = i;
			m++;
		}
	}
	for (i = 0; i < m - 1; i++)
		cout<<a[i] << " ";
	cout << a[m - 1];
	cout << endl;
	return 0;
}