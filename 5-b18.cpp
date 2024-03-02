/*2153393 ºú¾þçâ Èí¼þ*/
#include <iostream>
using namespace std;
int main()
{
	static const char other[] = "!@#$%^&*-_=+,.?";
	char ch;
	int code_len, upp_count, min_count, num_count, other_count;
	int flag = 1;
	int tag = 1;
	while ((ch = getchar()) != '\n')
		;
	cin >> code_len >> upp_count >> min_count >> num_count >> other_count;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(1024, '\n');
		cout << "´íÎó" << endl;
		return 0;
	}
	if (code_len < 12 || code_len > 16)
	{
		cout << "´íÎó" << endl;
		return 0;
	}
	if (upp_count < 2)
	{
		cout << "´íÎó" << endl;
		return 0;
	}
	if (min_count < 2)
	{
		cout << "´íÎó" << endl;
		return 0;
	}
	if (num_count < 2)
	{
		cout << "´íÎó" << endl;
		return 0;
	}
	if (other_count < 2)
	{
		cout << "´íÎó" << endl;
		return 0;
	}
	if (upp_count + min_count + num_count + other_count > code_len)
	{
		cout << "´íÎó" << endl;
		return 0;
	}
	for (int i = 0; i < 10; i++)
	{
		int num_u = upp_count, num_m = min_count, num_n = num_count, num_o = other_count;
		char str[17] = { '\0' };
		cin >> str;
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
		if (!(num_u <= 0 && num_m <= 0 && num_n <= 0 && num_o <= 0 && tag == 1))
			flag = 0;
	}
	if (flag == 0)
		cout << "´íÎó" << endl;
	else if (flag == 1)
		cout << "ÕýÈ·" << endl;
	return 0;

}
/*
6r^&5mKS3451
O66R$k-1d066
=y02C4*0r0I0
H1d8,_042kH9
.837m2z*B8L7
9=d8qG89#7G7
3?47d63u5?EN
vR7j0#6F6#95
#pn95Q88#6C4
53k2ITn8!?79
*/