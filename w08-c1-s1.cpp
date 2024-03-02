/* 软件 2153393 胡峻玮 */
#include <iostream>
using namespace std;

/***************************************************************************
  函数名称：
  功    能：根据利润计算奖金（四舍五入，精确到元）
  输入参数：
  返 回 值：
  说    明：只允许用switch-case语句，用if语句则得分为0
***************************************************************************/
int calc_bonus(int profit)
{
	int a, bonus = 0;
	a = profit / 100000;
	switch (a)
	{
		case 0:
			bonus = (profit * 0.1 + 0.5);
			break;
		case 1:
			bonus = 10000 + ((profit - 100000) * 0.075 + 0.5);
			break;
		case 2:
		case 3:
			bonus = 17500 + ((profit - 200000) * 0.05 + 0.5);
			break;
		case 4:
		case 5:
			bonus = 27500 + ((profit - 400000) * 0.03 + 0.5);
			break;
		case 6:
		case 7:
		case 8:
		case 9:
			bonus = 33500 + ((profit - 600000) * 0.015 + 0.5);
			break;
		default:
			bonus = 39500 + ((profit - 1000000) * 0.01 + 0.5);
			break;
	}
	return bonus;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：从键盘读取一个int型正整数，有错误则按错误处理逻辑的规则，给出输出提示后再次读
  返 回 值：
  说    明：
***************************************************************************/
int get_business_profit()
{
	int profit;
	while (1)
	{
		cout << "请输入利润" << endl;
		cin >> profit;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		else if (profit >= 1)
			break;
	}
	return profit;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数不准动
***************************************************************************/
int main()
{
	int profit;

	profit = get_business_profit();
	cout << "应发奖金数 : " << calc_bonus(profit) << endl;

	return 0;
}