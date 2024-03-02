/* 2153393 ������ ��� */
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

const int MAX_X = 69;	//����*��ɵı߿�Ŀ��
const int MAX_Y = 17;	//����*��ɵı߿�ĸ߶�

/***************************************************************************
  �������ƣ�
  ��    �ܣ������system("cls")һ���Ĺ��ܣ���Ч�ʸ�
  ���������
  �� �� ֵ��
  ˵    �������������Ļ���������������ǿɼ���������(ʹ�õ�ǰ��ɫ)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* ȡ��ǰ��������Ϣ */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* ����ַ� */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* ������� */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* ���ص�(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  �������ƣ�gotoxy
  ��    �ܣ�������ƶ���ָ��λ��
  ���������HANDLE hout ������豸���
			int X       ��ָ��λ�õ�x����
			int Y       ��ָ��λ�õ�y����
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  �������ƣ�showch
  ��    �ܣ���ָ��λ�ô���ӡһ��ָ�����ַ�
  ���������HANDLE hout ������豸���
			int X       ��ָ��λ�õ�x����
			int Y       ��ָ��λ�õ�y����
			char ch     ��Ҫ��ӡ���ַ�
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  �������ƣ�init_border
  ��    �ܣ���ʾ��ʼ�ı߿�����ַ�
  ���������HANDLE hout������豸���
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//����ƻ����Ͻ�(0,0)
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

	/* �����ʾ20����д��ĸ����ĸ��ֵ��XY���궼�����ʾ
	   rand()�����Ĺ��ܣ��������һ���� 0-32767 ֮�������
	   ˼������ʲô����£��������ѭ��ִ�����ɺ��㿴����ʵ����ĸ��������20���� */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- �������ӵ����ɺ������Է��ڴ˴� --*/
int menu(const HANDLE hout)
{
	cout << "1.��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ)" << endl;
	cout << "2.��I��J��K��L��������������(��Сд���ɣ��߽����)" << endl;
	cout << "3.�ü�ͷ�������������ң��߽�ֹͣ" << endl;
	cout << "4.�ü�ͷ�������������ң��߽����" << endl;
	cout << "5.��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ)(���ͷ���ƶ�)" << endl;
	cout << "6.��I��J��K��L��������������(��Сд���ɣ��߽����)(���ͷ���ƶ�)" << endl;
	cout << "0.�˳�" << endl;
	cout << "[��ѡ��0-6]";
	int num = _getch();
	while (num < '0' || num > '6')
		num = _getch();
	return num - '0';
}

void move_by_ijkl(const HANDLE hout, int mode, int sign)//mode����˵��е�ģʽ��sign����߽�ֹͣ(0)���ǻ���(1)
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
	cout << "��Ϸ���������س������ز˵�.";
	while (1)
	{
		int arrow = _getch();
		if (arrow == '\r')
			break;
	}
}

void move_by_arrow(const HANDLE hout, int sign)//sign����߽�ֹͣ(0)���ǻ���(1)
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
	cout << "��Ϸ���������س������ز˵�.";
	while (1)
	{
		int a = _getch();
		if (a == '\r')
			break;
	}
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main���������ڳ�ʼ��ʾ�����԰���ĿҪ��ȫ���Ʒ���д
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
/*˼��1���������ASCII��Ϊ���ֽڣ���˻᷵��������ֵ���ڶ�����ijkl�ĳ�ͻ������ͨ������������ֵ������
  ˼��2�����ܲ���20������Ϊ�п������λ������������ͬһλ�ã���ͬһλ�ú���ֵ���ĸ���ǵ�ǰ�����ĸ*/