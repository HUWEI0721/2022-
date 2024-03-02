/*2153393 ������ ���*/
#include <iostream>
#include <time.h>
using namespace std;
int main()
{
	static const char other[] = "!@#$%^&*-_=+,.?";
	int code_len = 0, upp_count = 0, min_count = 0, num_count = 0, other_count = 0;
	int i = 0;
	int tag = 1;
	srand((unsigned)time(NULL));
	cout << "���������볤��(12-16)����д��ĸ����(��2)��Сд��ĸ����(��2)�����ָ���(��2)���������Ÿ���(��2)" << endl;
	cin >> code_len >> upp_count >> min_count >> num_count >> other_count;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(1024, '\n');
		cout << "����Ƿ�" << endl;
		return 0;
	}
	if (code_len < 12 || code_len > 16)
	{
		cout << "���볤��[" << code_len << "]����ȷ" << endl;
		return 0;
	}
	if (upp_count < 2)
	{
		cout << "��д��ĸ����[" << upp_count << "]����ȷ" << endl;
		return 0;
	}
	if (min_count < 2)
	{
		cout << "Сд��ĸ����[" << min_count << "]����ȷ" << endl;
		return 0;
	}
	if (num_count < 2)
	{
		cout << "���ָ���[" << num_count << "]����ȷ" << endl;
		return 0;
	}
	if (other_count < 2)
	{
		cout << "�������Ÿ���[" << other_count << "]����ȷ" << endl;
		return 0;
	}
	if (upp_count + min_count + num_count + other_count > code_len)
	{
		cout << "�����ַ�����֮��[" << upp_count << "+" << min_count << "+" << num_count << "+" << other_count << "]���������볤��[" << code_len << "]" << endl;
		return 0;
	}
	cout << code_len << " " << upp_count << " " << min_count << " " << num_count << " " << other_count << endl;
	while (1)
	{
		int num_u = upp_count, num_m = min_count, num_n = num_count, num_o = other_count;
		if (i < 10)
		{
			char str[16] = { '\0' };
			for (int j = 0; j < code_len; j++)
				str[j] = rand() % 94 + 33;
			for (int j = 0; j < code_len; j++)
			{
				if (str[j] >= 'A' && str[j] <= 'Z')
					num_u--;
				else if (str[j] >= 'a' && str[j] <= 'z')
					num_m--;
				else if (str[j] >= '0' && str[j] <= '9')
					num_n--;
				else
				{
					for (int k = 0; k < 15; k++)
					{
						if (str[j] == other[k])
						{
							num_o--;
							tag = 1;
							break;
						}
						if (str[j] != other[k])
							tag = 0;
					}
				}
			}
			if (num_u <= 0 && num_m <= 0 && num_n <= 0 && num_o <= 0 && tag == 1)
			{
				i++;
				for (int j = 0; j < code_len; j++)
					cout << char(str[j]);
				cout << endl;
			}
		}
		if (i == 10)
			break;
	}
	return 0;
}