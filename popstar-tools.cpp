/*2153393 胡峻玮 软件*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<windows.h>
#include<conio.h>
#include<ctime>
#include<cmath>
#include"cmd_console_tools.h"
#include"popstar.h"
using namespace std;
int random(int n)
{
	return rand() % n;
}
void init_array(int row, int col, int board_key[N][N], int board_state[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			board_key[i][j] = 0;
			board_state[i][j] = 1;
		}

	}
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
			board_key[i][j] = random(5) + 1;
	}
}
void show_array(char choice, int row, int col, int board_key[N][N], int board_state[N][N], int flag_1)
{
	cct_setcolor();
	cout << endl;
	if (flag_1 == 0)
		cout << "当前数组:" << endl;
	else if(flag_1==1)
		cout << "查找结果数组:" << endl;
	else if(flag_1==2)
		cout << "当前数组(不同色标识):" << endl;
	else if (flag_1 == 3)
		cout << "相同值归并后的数组(不同色标识):" << endl;
	else if(flag_1==4)
		cout << "下落后的数组" << endl;
	draw_arr(row, col, flag_1, board_key, board_state);
}
void draw_arr(int row, int col, int flag_1, int board_key[N][N], int board_state[N][N])
{
	cout << "  |";
	for (int i = 0; i < col; i++)
		cout << "  " << i;
	cout << endl;
	cout << "--+";
	for (int i = 0; i < 3 * col + 2; i++)
		cout << '-';
	cout << endl;
	for (int i = 1; i <= row; i++)
	{
		cout << char('A' + i - 1) << " |";
		for (int j = 1; j <= col; j++)
		{
			if (flag_1 == 0 || flag_1 == 4)
			{
				if (board_key[i][j] == 0)
				{
					cout << "  ";
					cct_setcolor(COLOR_HYELLOW, COLOR_BLACK);
					cout << board_key[i][j];
					cct_setcolor();
				}
				else
					cout << "  " << board_key[i][j];
			}
			else if (flag_1 == 1)
			{
				if (board_state[i][j] == 2)
					cout << "  *";
				else
					cout << "  0";
			}
			else if (flag_1 == 2 || flag_1 == 3)
			{
				if (board_state[i][j] == 2 || board_state[i][j] == 3)
				{
					cout << "  ";
					cct_setcolor(COLOR_HYELLOW, COLOR_BLACK);
					cout << board_key[i][j];
					cct_setcolor();
				}
				else
					cout << "  " << board_key[i][j];
			}
		}
		cout << endl;
	}
}
void judge_end()
{
	cct_setcursor(2);
	while (1)
	{
		cout << "本小题结束,输入End继续...";
		char s[20], * ps;
		cin >> s;
		ps = _strupr(s);
		if (strcmp(ps, "END") == 0)
			break;
		else
			cout << "输入错误,请重新输入" << endl;
	}
}
int cmd_clear(char choice, int row, int col, const int* row_1, const int* col_1, int board_key[N][N], int board_state[N][N], int& score)
{
	cout << endl;
	cout << "请确认是否把" << (char)(*row_1 + 'A' - 1) << *col_1 - 1 << "及周围的相同值消除(Y/N/Q)：";
	char order;
	int count = 0, * pcount = &count;
	while (1)
	{
		order = _getche();
		cout << endl;
		if (order == 'Y' || order == 'y' || order == 'N' || order == 'n' || order == 'Q' || order == 'q')
			break;
	}
	if (order == 'Y' || order == 'y')
	{
		search_same(*row_1, *col_1, board_key, board_state, pcount, 2);
		trans_array(row, col, board_key, board_state, "sweep");
		show_array(choice, row, col, board_key, board_state, 3);
		cout << endl;
		score += bonus * count * count;
		cout << "本次得分:" << bonus * count * count << "  总得分:" << score << endl;
		trans_array(row, col, board_key, board_state, "reset");
		fall_array(row, col, board_key, board_state);
		move_left(row, col, board_key, board_state, 0);
		show_array(choice, row, col, board_key, board_state, 4);
		cout << endl;
		return 1;
	}
	else if (order == 'N' || order == 'n')
	{
		trans_array(row, col, board_key, board_state, "reset");
		return 2;
	}
	else
	{
		trans_array(row, col, board_key, board_state, "reset");
		return 0;
	}
}
int trans_array(int row, int col, int board_key[N][N], int board_state[N][N], const char* s)
{
	int count = 0;
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			if (strcmp(s, "sweep") == 0)
			{
				if (board_state[i][j] == 3)
					board_key[i][j] = 0;
			}
			else if (strcmp(s, "reset") == 0)
				board_state[i][j] = 1;
			else 
			{
				if (board_key[i][j] != 0)
					count++;
			}
		}
	}
	return count;
}
bool all_zero(int board_key[N][N], int row, int col_no)
{
	int	count_of_zero = 0;
	for (int i = 1; i <= row; i++)
		if (board_key[i][col_no] == 0)
			count_of_zero++;
	if (count_of_zero == row)
		return 1;
	else
		return 0;
}
bool check_gameover(int row, int col, int board_key[N][N], int board_state[N][N])//gameover返回0代表未结束,返回1代表结束
{
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			if (board_key[i][j] != 0)
			{
				int count = 0, * pcount = &count;
				search_same(i, j, board_key, board_state, pcount, 0);
				if (count > 1)
				{
					trans_array(row, col, board_key, board_state, "reset");
					return 0;
				}
			}
		}
	}
	trans_array(row, col, board_key, board_state, "reset");
	return 1;
}
void find_pos(int row, int col, int board_key[N][N], int board_state[N][N], int col_x, int tmp_row, int& target)
{
	for (int i = row; i > tmp_row; i--)
	{
		if (board_key[i][col_x] == 0)
		{
			target = i;
			return;
		}
	}
}
void wait_for_move()
{
	int M_X, M_Y, M_action, keycode_1, keycode_2;
	cct_read_keyboard_and_mouse(M_X, M_Y, M_action, keycode_1, keycode_2);
	while (M_action != MOUSE_ONLY_MOVED)
		cct_read_keyboard_and_mouse(M_X, M_Y, M_action, keycode_1, keycode_2);

}
void GAME(int row, int col, int board_key[N][N], int board_state[N][N], int& score, bool* right_click)
{

	int pos_y = 4 + (1 + height) * row;
	cct_gotoxy(0, pos_y);
	int row_1 = 0, col_1 = 0;
	row_1 = row, col_1 = 1;
	
	cout << "箭头键/鼠标移动,回车键/单击左键选择                ";
	while (1)
	{
		int count = 0, * pcount = &count;
		draw_block_choice(row, col, &row_1, &col_1, board_key, board_state, 1);
		mouse_and_key(row, col, &row_1, &col_1, board_key, board_state, 1,right_click);
		if (*right_click == 1)
		{
			return;
		}
		search_same(row_1, col_1, board_key, board_state, &count, 0);
		if (*pcount == 1)
		{
			board_state[row_1][col_1] = 1;
			cct_gotoxy(0, pos_y);
			cout << "周围无相同值,箭头键/鼠标移动,回车键/单击左键合成                         ";
			wait_for_move();
			continue;
		}
		else
		{
			cct_gotoxy(0, pos_y);
			cout << "箭头键/鼠标移动取消当前选择,回车键/单击左键合成，Q/单击右键结束                          ";
			draw_block_divide(row, col, &row_1, &col_1, board_key, board_state, 2);
			if (check_to_clear(row, col, &row_1, &col_1, board_key, board_state, score, 1) == true)
			{
				int key = board_key[row_1][col_1];
				delete_same(row_1, col_1, board_key, board_state, key);
				trans_array(row, col, board_key, board_state, "reset");
				fall_down(row, col, board_key, board_state, 1);
				move_left(row, col, board_key, board_state, 2);
				return;
			}
		}
	}
}