/*2153393 胡峻玮 软件*/
#include <iostream>
using namespace std;
int main()
{
	int a[20] = { 0 };
	int b[21] = { 0 };
	int x, insert, i = 0;
	cout << "请输入任意个正整数（升序，最多20个），0或负数结束输入" << endl;
	for (i = 0; i < 20; i++)
	{
		cin >> x;
		if (x > 0)
			a[i] = x;
		else if (x <= 0)
			break;
	}
	cin.clear();
	cin.ignore(1024, '\n');
	if (a[0] == 0 || (a[0] < 0))
		cout << "无有效输入" << endl;
	else
	{
		cout << "原数组为：" << endl;
		for (i = 0; i < 20; i++)
		{
			if (a[i] != 0)
				cout << a[i] << " ";
			else
				break;
		}
		cout << endl;
		cout << "请输入要插入的正整数" << endl;
		cin >> insert;
		for (i = 0; i < 20; i++)
			b[i] = a[i];
		for (i = 0; i < 21; i++)
		{
			if (b[i] > insert)
			{
				for (int j = 19; j >= i; j--)
				{
					b[j + 1] = b[j];
				}
				b[i] = insert;
				break;
			}
			if(b[i]==0)
			{
				b[i]=insert;
				break;
			}
		}


		cout << "插入后的数组为：" << endl;
		for (i = 0; i < 21; i++)
		{
			if (b[i] != 0)
				cout << b[i] << " ";
			else
				break;
		}
	}
		
	return 0;
}
