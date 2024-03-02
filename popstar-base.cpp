/*2153393 胡峻玮 软件*/
#include<iostream>
#include<iomanip>
#include<windows.h>
#include<conio.h>
#include<ctime>
#include<cmath>
#include"cmd_console_tools.h"
#include"popstar.h"
using namespace std;
void judge_pos(char choice, int row, int col, int* row_1, int* col_1, int board_key[N][N], int board_state[N][N])
{
	int row_now = 0, col_now = 0;
	char ch1, ch2;
	cout << endl;
	cout << "请以字母+数字形式[例：c2]输入矩阵坐标：";
	cct_getxy(row_now, col_now);
	while (1)
	{
		cin >> ch1 >> ch2;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "输入有误,请重新输入";
			cct_showstr(row_now, col_now, "                             ");
			cct_gotoxy(row_now, col_now);
			for (int i = 0; i < 66; i++)
				cout << " ";
			continue;
		}
		bool flag0 = true, flag1 = true, flag2 = true;
		char c1;
		flag0 = type_of_char(ch1, "capital");
		if (!flag0)
			c1 = ch1 - 'a' + 'A';
		else
			c1 = ch1;
		if (!(type_of_char(c1, "capital") && c1 <= 'A' + row - 1))
			flag1 = false;
		if (!(type_of_char(ch2, "number") && ch2 <= '0' + col - 1))
			flag2 = false;
		if (flag1 && flag2)
		{
			*row_1 = c1 - 'A' + 1;
			*col_1 = ch2 - '0' + 1;
			cout << "输入为" << c1 << "行" << ch2 << "列                                      " << endl;
			break;
		}
		else
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "输入有误,请重新输入";
			cct_showstr(row_now, col_now, "                            ");
			cct_gotoxy(row_now, col_now);
			continue;
		}
	}
}
bool type_of_char(char ch, const char* s)
{
	if (strcmp(s, "capital") == 0)
	{
		if (ch >= 'A' && ch <= 'Z')
			return true;
		else
			return false;
	}
	else if (strcmp(s, "small") == 0)
	{
		if (ch >= 'a' && ch <= 'z')
			return true;
		else
			return false;
	}
	else if (strcmp(s, "number") == 0)
	{
		if (ch >= '0' && ch <= '9')
			return true;
		else
			return false;
	}
	else
		return false;
}
bool judge_tant_zero(char choice, int row, int col, const int* row_1, const int* col_1, int board_key[N][N], int board_state[N][N])
{
	int count = 0, * pcount = &count;
	bool tag = true;
	if (board_key[*row_1][*col_1] == 0)
	{
		cout << "输入矩阵坐标位置为0,请重新输入" << endl;
		tag = false;
	}
	else
	{
		search_same(*row_1, *col_1, board_key, board_state, &count, 0);
		if (count == 1)
		{
			board_state[*row_1][*col_1] = 1;
			cout << "输入矩阵坐标位置无连续相同值,请重新输入" << endl;
			tag = false;
		}
	}
	return tag;
}
void search_same(int row, int col, int board_key[N][N], int board_state[N][N], int* pcount, int flag_2)
{
	if (flag_2 == 0)
	{
		if (board_state[row][col] != 1)
			return;
		else
		{
			board_state[row][col] = 2;
			(*pcount)++;
		}
	}
	else if (flag_2 == 2)
	{
		if (board_state[row][col] != 2)
			return;
		else
		{
			board_state[row][col] = 3;
			(*pcount)++;
		}
	}
	if (board_key[row][col - 1] == board_key[row][col])
		search_same(row, col - 1, board_key, board_state, pcount, flag_2);
	if (board_key[row][col + 1] == board_key[row][col])
		search_same(row, col + 1, board_key, board_state, pcount, flag_2);
	if (board_key[row - 1][col] == board_key[row][col])
		search_same(row - 1, col, board_key, board_state, pcount, flag_2);
	if (board_key[row + 1][col] == board_key[row][col])
		search_same(row + 1, col, board_key, board_state, pcount, flag_2);
}
void fall_array(int row, int col, int board_key[N][N], int board_state[N][N])
{
	cout << endl;
	cout << "按回车进行数组下落操作...";
	while (_getche() != '\r')
		;
	for (int j = 1; j <= col; j++)
	{
		int temp[12] = { 0 }, * p = temp, * q = temp;
		for (int i = row; i >= 1; i--)
		{
			if (board_key[i][j] != 0)
			{
				*p = board_key[i][j];
				p++;
			}

		}

		for (int i = row; i >= 1; i--)
		{
			board_key[i][j] = *q;
			q++;
		}
	}
}
void move_left(int row, int col, int board_key[N][N], int board_state[N][N],int draw_or_not)
{
	//只有出现全零列和右侧相邻列非全零列的时候,才进行左右移动
	while (1)
	{
		bool tag = true;
		for (int j = 1; j <= col; j++)
		{
			if (all_zero(board_key, row, j) && !all_zero(board_key, row, j + 1))
				tag = false;
		}
		if (tag == true)
			break;
		else
		{
			for (int j = 1; j <= col; j++)
			{
				if (all_zero(board_key, row, j) && !all_zero(board_key, row, j + 1))
				{
					for (int i = 1; i <= row; i++)
					{
						board_key[i][j] = board_key[i][j + 1];
						board_key[i][j + 1] = 0;
						if (draw_or_not == 1)
						{
							draw_block(row, col, NULL, NULL, board_key, board_state, 0);
							Sleep(1);
						}
						else if(draw_or_not == 2)
						{
							draw_block_divide(row, col, NULL, NULL, board_key, board_state, 0);
							Sleep(1);
						}
					}
				}
			}

		}
	}
}