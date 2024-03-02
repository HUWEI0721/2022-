/*2153393 胡峻玮 软件*/
#include <iostream>
using namespace std;
#define N 10
int main()
{
	int i, j, k, m = 1, n = 1, p = 1, q = 1;
	int a[N][N] = { 0 };
	int sqr[N] = { 0 };
	cout << "请输入9*9的矩阵，值为1-9之间" << endl;
	//输入
	for (i = 0; i < N - 1; i++)
	{
		for (j = 0; j < N - 1; j++)
		{
			while (1)
			{
				cin >> a[i][j];
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(1024, '\n');
					cout << "请重新输入第" << i + 1 << "行" << j + 1 << "列(行列均从1开始计数)的值" << endl;
					continue;
				}
				else if ((a[i][j] < 1) || (a[i][j] > 9))
				{
					cout << "请重新输入第" << i + 1 << "行" << j + 1 << "列(行列均从1开始计数)的值" << endl;
					continue;
				}
				else
					break;
			}
		}
	}
	//列判断
	for (i = 0; i < N - 1 && m == 1; i++)
	{
		for (j = 0; j < N - 1 && m == 1; j++)
		{
			for (k = j + 1; k < N - 1; k++)
			{
				if (a[i][j] != a[i][k])
					m = 1;
				else
				{
					m = 0;
					break;
				}
			}
		}
	}
	//行判断
	for (i = 0; i < N - 1 && n == 1; i++)
	{
		for (j = 0; j < N - 1 && n == 1; j++)
		{
			for (k = j + 1; k < N - 1; k++)
			{
				if (a[j][i] != a[k][i])
					n = 1;
				else
				{
					n = 0;
					break;
				}
			}
		}
	}
	//方块内判断
	for (int i = 0; i < 27; i++)
	{
		if (i < 9)
		{
			for (int j = 0; j < 3; j++)
			{
				switch (a[i % 9][j])
				{
					case 1:
						sqr[1]++;
						break;
					case 2:
						sqr[2]++;
						break;
					case 3:
						sqr[3]++;
						break;
					case 4:
						sqr[4]++;
						break;
					case 5:
						sqr[5]++;
						break;
					case 6:
						sqr[6]++;
						break;
					case 7:
						sqr[7]++;
						break;
					case 8:
						sqr[8]++;
						break;
					case 9:
						sqr[9]++;
						break;
					default:
						break;
				}
			}
		}
		if (i >= 9 && i < 18)
		{
			for (int j = 3; j < 6; j++)
			{
				switch (a[i % 9][j])
				{
					case 1:
						sqr[1]++;
						break;
					case 2:
						sqr[2]++;
						break;
					case 3:
						sqr[3]++;
						break;
					case 4:
						sqr[4]++;
						break;
					case 5:
						sqr[5]++;
						break;
					case 6:
						sqr[6]++;
						break;
					case 7:
						sqr[7]++;
						break;
					case 8:
						sqr[8]++;
						break;
					case 9:
						sqr[9]++;
						break;
					default:
						break;
				}
			}
		}
		if (i >= 18)
		{
			for (int j = 6; j < 9; j++)
			{
				switch (a[i % 9][j])
				{
					case 1:
						sqr[1]++;
						break;
					case 2:
						sqr[2]++;
						break;
					case 3:
						sqr[3]++;
						break;
					case 4:
						sqr[4]++;
						break;
					case 5:
						sqr[5]++;
						break;
					case 6:
						sqr[6]++;
						break;
					case 7:
						sqr[7]++;
						break;
					case 8:
						sqr[8]++;
						break;
					case 9:
						sqr[9]++;
						break;
					default:
						break;
				}
			}
		}
		if ((i + 1) % 3 == 0)
		{
			for (int j = 1; j < N; j++)
			{
				if (sqr[j] > (i + 1) / 3)
				{
					p = 0;
					break;
				}
			}
		}
	}
	if (m == n == p == 1)
		cout << "是数独的解" << endl;
	else
		cout << "不是数独的解" << endl;
	return 0;
}