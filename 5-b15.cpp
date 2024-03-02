/*2153393 软件 胡峻玮*/
#include <iostream>
using namespace std;
#define N 128
int main()
{
	char str[3][N];
	int upp = 0, min = 0, num = 0, spc = 0, oth = 0;
	for (int i = 0; i < 3; i++)
	{
		cout << "请输入第" << i + 1 << "行" << endl;
		cin.getline(str[i], N);
	}
	for (int i = 0; i < 3; i++) 
	{
		for (int j = 0; j < 128; j++) 
		{
			char temp = str[i][j];
			if (temp >= 'A' && temp <= 'Z')
				upp += 1;
			else if (temp >= 'a' && temp <= 'z')
				min += 1;
			else if (temp >= '0' && temp <= '9')
				num += 1;
			else if (temp == ' ')
				spc += 1;
			else if (temp != '\0')
				oth += 1;
			if (temp == '\0')
				break;
		}
	}
	cout << "大写 : " << upp << endl;
	cout << "小写 : " << min << endl;
	cout << "数字 : " << num << endl;
	cout << "空格 : " << spc << endl;
	cout << "其它 : " << oth << endl;
	return 0;
}
/*Welcome to Tongji University.
<Hello,world!> -> 《Hello，world！》
Name=张三 and No=2059999 && Sex=男*/