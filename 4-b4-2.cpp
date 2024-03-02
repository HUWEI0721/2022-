/* 2153393 胡峻玮 软件 */
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

const int MAX_X = 69;	//定义*组成的边框的宽度
const int MAX_Y = 17;	//定义*组成的边框的高度

/***************************************************************************
  函数名称：
  功    能：完成与system("cls")一样的功能，但效率高
  输入参数：
  返 回 值：
  说    明：清除整个屏幕缓冲区，不仅仅是可见窗口区域(使用当前颜色)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* 取当前缓冲区信息 */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* 填充字符 */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* 填充属性 */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* 光标回到(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  函数名称：gotoxy
  功    能：将光标移动到指定位置
  输入参数：HANDLE hout ：输出设备句柄
			int X       ：指定位置的x坐标
			int Y       ：指定位置的y坐标
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  函数名称：showch
  功    能：在指定位置处打印一个指定的字符
  输入参数：HANDLE hout ：输出设备句柄
			int X       ：指定位置的x坐标
			int Y       ：指定位置的y坐标
			char ch     ：要打印的字符
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  函数名称：init_border
  功    能：显示初始的边框及随机字符
  输入参数：HANDLE hout：输出设备句柄
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//光标移回左上角(0,0)
	cout << "***********************************************************************" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "***********************************************************************" << endl;

	/* 随机显示20个大写字母，字母的值、XY坐标都随机显示
	   rand()函数的功能：随机生成一个在 0-32767 之间的整数
	   思考：在什么情况下，下面这个循环执行生成后，你看到的实际字母个数不足20个？ */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- 按需增加的若干函数可以放在此处 --*/
int menu(const HANDLE hout)
{
	cout << "1.用I、J、K、L键控制上下左右(大小写均可，边界停止)" << endl;
	cout << "2.用I、J、K、L键控制上下左右(大小写均可，边界回绕)" << endl;
	cout << "3.用箭头键控制上下左右，边界停止" << endl;
	cout << "4.用箭头键控制上下左右，边界回绕" << endl;
	cout << "5.用I、J、K、L键控制上下左右(大小写均可，边界停止)(左箭头不移动)" << endl;
	cout << "6.用I、J、K、L键控制上下左右(大小写均可，边界回绕)(左箭头不移动)" << endl;
	cout << "0.退出" << endl;
	cout << "[请选择0-6]";
	int num = _getch();
	while (num < '0' || num > '6')
		num = _getch();
	return num - '0';
}

void move_by_ijkl(const HANDLE hout, int mode, int sign)//mode代表菜单中的模式，sign代表边界停止(0)还是回绕(1)
{
	cls(hout);
	init_border(hout);
	gotoxy(hout, 35, 9);
	//x=MAX_X/2+1;
	//y=MAX_Y/2+1;
	int x = 35, y = 9;
	while (1)
	{
		int arrow = _getch();
		if (((mode == 5) || (mode == 6)) && arrow == 224)
			arrow += _getch();
		if (arrow == 'q' || arrow == 'Q')
			break;
		if (arrow == ' ')
			showch(hout, x, y, ' ');
		if (arrow == 'i' || arrow == 'I')
		{
			--y;
			if (y == 0)
			{
				if (sign == 0)
					++y;
				else
					y = MAX_Y;
			}
		}
		if (arrow == 'k' || arrow == 'K')
		{
			++y;
			if (y > MAX_Y)
			{
				if (sign == 0)
					--y;
				else
					y = 1;
			}
		}
		if (arrow == 'j' || arrow == 'J')
		{
			--x;
			if (x == 0)
			{
				if (sign == 0)
					++x;
				else
					x = MAX_X;
			}
		}
		if (arrow == 'l' || arrow == 'L')
		{
			++x;
			if (x > MAX_X)
			{
				if (sign == 0)
					--x;
				else
					x = 1;
			}
		}
		gotoxy(hout, x, y);
	}
	gotoxy(hout, 0, 23);
	cout << "游戏结束，按回车键返回菜单.";
	while (1)
	{
		int arrow = _getch();
		if (arrow == '\r')
			break;
	}
}

void move_by_arrow(const HANDLE hout, int sign)//sign代表边界停止(0)还是回绕(1)
{
	cls(hout);
	init_border(hout);
	gotoxy(hout, 35, 9);

	int x = 35, y = 9;
	while (1)
	{
		int arrow = _getch();
		if (arrow != 224)
		{
			if (arrow == 'q' || arrow == 'Q')
				break;
			if (arrow == ' ')
			{
				showch(hout, x, y, ' ');//				gotoxy(hout, x, y);
			}
			continue;
		}
		arrow = _getch();
		if (arrow == 72)
		{
			--y;
			if (y == 0)
			{
				if (sign == 0)
					++y;
				else
					y = MAX_Y;
			}
		}
		if (arrow == 80)
		{
			++y;
			if (y > MAX_Y)
			{
				if (sign == 0)
					--y;
				else
					y = 1;
			}
		}
		if (arrow == 75)
		{
			--x;
			if (x == 0)
			{
				if (sign == 0)
					++x;
				else
					x = MAX_X;
			}
		}
		if (arrow == 77)
		{
			++x;
			if (x > MAX_X)
			{
				if (sign == 0)
					--x;
				else
					x = 1;
			}
		}
		gotoxy(hout, x, y);
	}
	gotoxy(hout, 0, 23);
	cout << "游戏结束，按回车键返回菜单.";
	while (1)
	{
		int a = _getch();
		if (a == '\r')
			break;
	}
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数仅用于初始演示，可以按题目要求全部推翻重写
***************************************************************************/
int main()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	srand((unsigned int)(time(0)));

	int temp;
	while (temp = menu(hout))
	{
		if ((temp == 1) || (temp == 5))
		{
			move_by_ijkl(hout, temp, 0);
			cls(hout);
		}
		else if ((temp == 2) || (temp == 6))
		{
			move_by_ijkl(hout, temp, 1);
			cls(hout);
		}
		else if (temp == 3)
		{
			move_by_arrow(hout, 0);
			cls(hout);
		}
		else if (temp == 4)
		{
			move_by_arrow(hout, 1);
			cls(hout);
		}
	}
	return 0;
}
/*思考1：方向键的ASCII码为两字节，因此会返回两个键值，第二个与ijkl的冲突，可以通过读入两个键值来避免
  思考2：可能不到20个，因为有可能两次或多次随机出现在同一位置，在同一位置后出现的字母覆盖掉前面的字母*/