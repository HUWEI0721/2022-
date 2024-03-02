/*2153393 胡峻玮 软件*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;
#define sum 26
struct KFC 
{
	char num;
	const char* name;
	double price;
};
struct SPECIAL 
{
	const char* num;
	const char* name;
	double price;
};
const struct KFC list[] = {
	{'A', "香辣鸡腿堡",			19.5},
	{'B', "劲脆鸡腿堡",			19.5},
	{'C', "新奥尔良烤鸡腿堡",		20.0},
	{'D', "老北京鸡肉卷",			18.5},
	{'E', "黄金SPA鸡排堡(藤椒风味)",	18.0},
	{'F', "经典美式风味嫩牛堡(单层)",	18.0},
	{'G', "吮指原味鸡(1块)",		12.5},
	{'H', "黄金脆皮鸡",			13.5},
	{'I', "新奥尔良烤翅(2块)",		13.5},
	{'J', "劲爆鸡米花",			12.0},
	{'K', "香辣鸡翅(2块)",			12.5},
	{'L', "热辣香骨鸡(3块)",		12.5},
	{'M', "汁汁厚做培根三层和牛堡",	55.0},
	{'N', "薯条(小)",				9.0},
	{'O', "薯条(中)",				12.5},
	{'P', "薯条(大)",				14.5},
	{'Q', "芙蓉蔬荟汤",			9.0},
	{'R', "原味花筒冰激凌",			6.0},
	{'S', "醇香土豆泥",			7.5},
	{'T', "黄金鸡块",				12.5},
	{'U', "葡式蛋挞",				8.0},
	{'V', "百事可乐(小)",			8.5},
	{'W', "百事可乐(中)",			10.0},
	{'X', "百事可乐(大)",			12.0},
	{'Y', "九珍果汁",				13.0},
	{'Z', "雪顶咖啡",				14.5},
	{'\0', NULL,				0}
};

const struct SPECIAL special[] = {
	{"AOW", "OK三件套(香辣鸡腿堡)",		31}, //如果有需要，放开此项，注释掉下一行的“COW”优惠，观察优惠菜单是否发生了变化
	//	{"COW", "OK三件套(新奥尔良烤鸡腿堡)",	33.5}, //如果有需要，放开此项，注释掉上一行的“AOW”优惠，观察优惠菜单是否发生了变化
		{"HHHHHKKKSUWWW", "超爆全家桶(脆皮鸡)",	101},
		{"APUY", "人气明星配四件套(8折)",		44},
		{"GG","吮指原味鸡(2块)",			21},
		{NULL, NULL, 0}
};
int main()
{
	system("mode con cols=120 lines=35");
	while (1)
	{
		const KFC* list_p = list;
		const SPECIAL* special_p = special;
		int flag = 0, state = 0;
		double price_total = 0;
		char order[100] = { '\0' };
		int order_count[sum + 1] = { 0 };
		bool change_line = 0;
		system("cls");
		cout << "=========================================================================" << endl;
		cout << "                             KFC 2023春季菜单                            " << endl;
		cout << "=========================================================================" << endl;
		cout << setiosflags(ios::left);
		while ((*list_p).num != 0)
		{
			cout << setw(2) << (*list_p).num << " " << setw(26) << (*list_p).name << setw(6) << (*list_p).price;
			if (change_line == 1)
				cout << endl;
			if (change_line == 0)
				cout << " |  ";
			change_line = (change_line + 1) % 2;
			list_p++;
		}
		cout << endl;
		cout << "【优惠信息】" << endl;
		int discount[5][sum] = { 0 };
		for (int i = 0; special[i].price != 0; i++)
		{
			for (unsigned int j = 0; j < strlen(special[i].num); j++)
			{
				if (special[i].num[j] - 'A' >= 0)
					discount[i][special[i].num[j] - 'A']++;
			}
		}
		for (int i = 0; special[i].price != 0; i++)
		{
			cout << special[i].name << "=";
			for (unsigned int j = 0; j < strlen(special[i].num); j++)
			{
				for (int k = 0; k < sum; k++)
				{
					if (special[i].num[j] == list[k].num)
					{
						cout << list[k].name;
						if (discount[i][special[i].num[j] - 'A'] > 1)
						{
							cout << "*" << discount[i][special[i].num[j] - 'A'];
							j = j + discount[i][special[i].num[j] - 'A'] - 1;
						}
						if (j < strlen(special[i].num) - 1)
							cout << "+";
						else
						{
							cout << "=" << special[i].price << endl;
							break;
						}
					}
				}
			}
		}
		cout << endl;
		cout << "【输入规则说明】：" << endl;
		cout << "ANV=香辣鸡腿堡+薯条(小)+百事可乐(小) / akaak=香辣鸡腿堡*3+香辣鸡翅*2" << endl;
		cout << "字母不分大小写，不限顺序，单独输入0则退出程序" << endl;
		cout << endl;
		cout << "请点单: ";
		for (unsigned int i = 0;; i++)
		{
			order[i] = getchar();
			if (order[i] == '\n')
				break;
			if (order[0] == '0')
			{
				if (getchar() == '\n')
				{
					flag = 2;
					break;
				}
			}
			if (order[i] >= 'a' && order[i] <= 'z')
				order[i] -= 32;
			else if (order[i] < 'A' || order[i] > 'Z' || cin.fail())
			{
				cout << "输入错误，按任意键继续." << endl;
				flag = 1;
				break;
			}
		}
		if (flag == 1)
		{
			while (getchar() != '\n')
				;
			_getch();
			system("cls");
			continue;
		}
		else if (flag == 2)
		{
			return 0;
		}
		else if (order[0] == '\n')
		{
			system("cls");
			continue;
		}
		
		cout << "您的点餐=";
		for (unsigned int i = 0; i < strlen(order); i++)
		{
			if (order[i] - 'A' >= 0)
				order_count[order[i] - 'A']++;
		}
		int t = sum;
		while (t >= 0)
		{
			if (order_count[t] != 0)
			{
				state = t;
				break;
			}
			t--;
		}
		t = 0;
		while (list[t].price != 0)
		{
			if (order_count[t] != 0)
			{
				cout << list[t].name;
				if (order_count[t] > 1)
					cout << "*" << order_count[t];
				if (t != state)
					cout << "+";
				else
					cout << endl;
			}
			t++;
		}
		t = 0;
		while (special[t].price != 0)
		{
			int total = INT_MAX;
			bool tag = 0;
			for (unsigned int j = 0; j < sum; j++)
			{
				if (discount[t][j] != 0)
				{
					if (order_count[j] >= discount[t][j] && order_count[j] != 0)
					{
						if (order_count[j] / discount[t][j] < total)
							total = order_count[j] / discount[t][j];
					}
					else
					{
						tag = 1;
						break;
					}
				}
			}
			if (total != INT_MAX && tag != 1)
			{
				price_total += special[t].price * total;
				for (unsigned int j = 0; j < sum; j++)
				{
					if (discount[t][j] != 0)
						order_count[j] -= discount[t][j] * total;
				}
			}
			t++;
		}
		for (int i = 0; i <= state; i++)
		{
			if (order_count[i] > 0)
				price_total += order_count[i] * list[i].price;
		}
		cout << "共计："<<price_total << "元" << endl;
		cout << "点单完成，按任意键继续." << endl;
		_getch();
	}
}