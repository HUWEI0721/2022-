/* ��� 2153393 ������ */
#include <iostream>
using namespace std;

/***************************************************************************
  �������ƣ�
  ��    �ܣ�����������㽱���������룬��ȷ��Ԫ��
  ���������
  �� �� ֵ��
  ˵    ����ֻ������switch-case��䣬��if�����÷�Ϊ0
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
  �������ƣ�
  ��    �ܣ�
  ����������Ӽ��̶�ȡһ��int�����������д����򰴴������߼��Ĺ��򣬸��������ʾ���ٴζ�
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int get_business_profit()
{
	int profit;
	while (1)
	{
		cout << "����������" << endl;
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
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main������׼��
***************************************************************************/
int main()
{
	int profit;

	profit = get_business_profit();
	cout << "Ӧ�������� : " << calc_bonus(profit) << endl;

	return 0;
}