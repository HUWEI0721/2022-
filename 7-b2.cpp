/*2153393 ������ ���*/
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
	{'A', "�������ȱ�",			19.5},
	{'B', "���༦�ȱ�",			19.5},
	{'C', "�°¶��������ȱ�",		20.0},
	{'D', "�ϱ��������",			18.5},
	{'E', "�ƽ�SPA���ű�(�ٽ���ζ)",	18.0},
	{'F', "������ʽ��ζ��ţ��(����)",	18.0},
	{'G', "˱ָԭζ��(1��)",		12.5},
	{'H', "�ƽ��Ƥ��",			13.5},
	{'I', "�°¶�������(2��)",		13.5},
	{'J', "�������׻�",			12.0},
	{'K', "��������(2��)",			12.5},
	{'L', "������Ǽ�(3��)",		12.5},
	{'M', "֭֭������������ţ��",	55.0},
	{'N', "����(С)",				9.0},
	{'O', "����(��)",				12.5},
	{'P', "����(��)",				14.5},
	{'Q', "ܽ��������",			9.0},
	{'R', "ԭζ��Ͳ������",			6.0},
	{'S', "����������",			7.5},
	{'T', "�ƽ𼦿�",				12.5},
	{'U', "��ʽ��̢",				8.0},
	{'V', "���¿���(С)",			8.5},
	{'W', "���¿���(��)",			10.0},
	{'X', "���¿���(��)",			12.0},
	{'Y', "�����֭",				13.0},
	{'Z', "ѩ������",				14.5},
	{'\0', NULL,				0}
};

const struct SPECIAL special[] = {
	{"AOW", "OK������(�������ȱ�)",		31}, //�������Ҫ���ſ����ע�͵���һ�еġ�COW���Żݣ��۲��Żݲ˵��Ƿ����˱仯
	//	{"COW", "OK������(�°¶��������ȱ�)",	33.5}, //�������Ҫ���ſ����ע�͵���һ�еġ�AOW���Żݣ��۲��Żݲ˵��Ƿ����˱仯
		{"HHHHHKKKSUWWW", "����ȫ��Ͱ(��Ƥ��)",	101},
		{"APUY", "�����������ļ���(8��)",		44},
		{"GG","˱ָԭζ��(2��)",			21},
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
		cout << "                             KFC 2023�����˵�                            " << endl;
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
		cout << "���Ż���Ϣ��" << endl;
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
		cout << "���������˵������" << endl;
		cout << "ANV=�������ȱ�+����(С)+���¿���(С) / akaak=�������ȱ�*3+��������*2" << endl;
		cout << "��ĸ���ִ�Сд������˳�򣬵�������0���˳�����" << endl;
		cout << endl;
		cout << "��㵥: ";
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
				cout << "������󣬰����������." << endl;
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
		
		cout << "���ĵ��=";
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
		cout << "���ƣ�"<<price_total << "Ԫ" << endl;
		cout << "�㵥��ɣ������������." << endl;
		_getch();
	}
}