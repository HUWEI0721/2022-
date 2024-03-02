/*2153393 胡峻玮 软件*/
#include <iostream>

using namespace std;
int max(int x, int y)
{
	return (x > y ? x : y);
}
int max(int x, int y, int z)
{
	int t = (x > y ? x : y);
	return (t > z ? t : z);
}
int max(int x, int y, int m, int z)
{
	int temp1 = (x > y ? x : y);
	int temp2 = (m > z ? m : z);
	return (temp1 > temp2 ? temp1 : temp2);
}
int main()
{
	int i, arr[5] = { 0 }, result, tag = 1;
	while (1)
	{
		cout << "请输入个数num及num个正整数：" << endl;
		cin >> i;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (i > 4 || i < 2)
		{
			cout << "个数输入错误" << endl;
			return 0;
		}
		for (int j = 0; j < i; j++)
		{
			cin >> arr[j];
			if (arr[j] < 1)
				tag = 0;
		}
		if (cin.fail() || tag == 0)
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		else
			break;
	}
	switch (i)
	{
		case 2:
			result = max(arr[0], arr[1]);
			break;
		case 3:
			result = max(arr[0], arr[1], arr[2]);
			break;
		case 4:
			result = max(arr[0], arr[1], arr[2], arr[3]);
			break;
		default:
			break;
	}
	cout << "max=" << result << endl;
	return 0;
}