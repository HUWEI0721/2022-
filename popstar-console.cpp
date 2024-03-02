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
void draw_row_col(int row, int col)
{
	cct_cls();
	cct_setconsoleborder(15 + width * col, 12 + height * row, 15 + width * col, 9000);
	cout << "屏幕当前设置为:" << 12 + height * row << "行" << 15 + width * col << "列" << endl;
	cout << ' ';
	for (int i = 0; i < col; i++)
		cout << "     " << i;
	cout << endl;
	cout << "  ";

	int x_start, y_start;//记录边框的起始位置
	cct_getxy(x_start, y_start);
	cct_gotoxy(0, y_start - 1);
	for (int i = 0; i < row; i++)
	{
		cout << endl << endl << endl;
		cout << char('A' + i);
	}
	cct_gotoxy(x_start, y_start);
}
void draw_border(int row, int col)
{
	int x_start, y_start;//记录边框的起始位置
	cct_getxy(x_start, y_start);
	cct_gotoxy(x_start, y_start);
	cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
	for (int line = 0; line < 2 + height * row; line++)
	{
		cct_gotoxy(x_start, y_start + line);
		if (line == 0)
		{
			cout << "╔";
			for (int i = 1; i <= width / 2 * col; i++)
			{
				if (i % 3 == 0)
					Sleep(1);
				cout << "═";
			}
			cout << "╗";
		}
		else if (line == 1 + height * row)
		{
			cout << "╚";
			for (int i = 1; i <= height * col; i++)
			{
				if (i % 3 == 0)
					Sleep(1);
				cout << "═";
			}
			cout << "╝";
		}
		else
		{
			cout << "║";
			for (int i = 1; i <= height * col; i++)
			{
				if (i % 3 == 0)
					Sleep(1);
				cout << "  ";
			}
			cout << "║";
		}
	}
	cct_setcolor();
}
void draw_border_divide(int row, int col)
{
	cct_cls();
	cct_setconsoleborder(15 + (2 + width) * col, 12 + (1 + height) * row, 15 + (2 + width) * col, 9000);
	cout << "屏幕当前设置为:" << 12 + (1 + height) * row << "行" << 15 + (2 + width) * col << "列" << endl;
	for (int i = 0; i < col; i++)
		cout << "       " << i;
	cout << endl;
	cout << "   ";
	int x_start, y_start;//记录边框的起始位置
	cct_getxy(x_start, y_start);
	cct_gotoxy(0, y_start - 2);
	for (int i = 0; i < row; i++)
	{
		cout << endl << endl << endl << endl;
		cout << char('A' + i);
	}
	cct_gotoxy(x_start, y_start);
	cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
	int row_num = 1 + (1 + height) * row;
	int col_num = 1 + (1 + width / 2) * col;
	for (int line = 0; line < row_num; line++)
	{
		cct_gotoxy(x_start, y_start + line);
		//首行
		if (line == 0)
		{
			for (int i = 0; i < col_num; i++)
			{
				if (i == 0)
					cout << "╔";
				else if (i == col_num - 1)
					cout << "╗";
				else
				{
					if (i % (width / 2 + 1) == 0)
					{
						cout << "╦";
						Sleep(1);
					}
					else
						cout << "═";
				}
			}
		}
		//末行
		else if (line == row_num - 1)
		{
			for (int i = 0; i < col_num; i++)
			{
				if (i == 0)
					cout << "╚";
				else if (i == col_num - 1)
					cout << "╝";
				else
				{
					if (i % (width / 2 + 1) == 0)
					{
						cout << "╩";
						Sleep(1);
					}
					else
						cout << "═";
				}
			}
		}
		//中间行
		else
		{
			if (line % (1 + height) == 0)
			{
				for (int i = 0; i < col_num; i++)
				{
					if (i == 0)
						cout << "╠";
					else if (i == col_num - 1)
						cout << "╣";
					else
					{
						if (i % (width / 2 + 1) == 0)
						{
							cout << "╬";
							Sleep(1);
						}
						else
							cout << "═";
					}
				}
			}
			else
			{
				for (int i = 0; i < col_num; i++)
				{
					if (i % (width / 2 + 1) == 0)
					{
						cout << "║";
						Sleep(1);
					}
					else
						cout << "  ";
				}
			}
		}
	}
	cct_setcolor();
}
void draw_block(int row, int col, const int* row_1, const int* col_1, int board_key[N][N], int board_state[N][N], int flag_3)
{
	
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			const int fix_w = 4 + width * (j - 1), fix_h = 4 + height * (i - 1);
			cct_gotoxy(fix_w, fix_h - 1);
			if (board_key[i][j] == 0)
			{
				cct_setcolor(COLOR_HWHITE, COLOR_HWHITE);
				cout << "      ";
				cct_gotoxy(fix_w, fix_h);
				cout << "      ";
				cct_gotoxy(fix_w, fix_h + 1);
				cout << "      ";
			}
			else 
			{
				if (flag_3 == 0) 
				{
					cct_setcolor(board_key[i][j] + 8, COLOR_BLACK);
					cout << "╔═╗";
					cct_gotoxy(fix_w, fix_h);
					cout << "║★║";
					cct_gotoxy(fix_w, fix_h + 1);
					cout << "╚═╝";
				}
				else if (flag_3 == 1) 
				{
					if (i == *row_1 && j == *col_1)
						cct_setcolor(board_key[i][j] + 8, COLOR_HWHITE);
					else
						cct_setcolor(board_key[i][j] + 8, COLOR_BLACK);
					cout << "╔═╗";
					cct_gotoxy(fix_w, fix_h);
					cout << "║★║";
					cct_gotoxy(fix_w, fix_h + 1);
					cout << "╚═╝";
				}
				else if (flag_3 == 2) 
				{
					if (board_state[i][j] == 2 || board_state[i][j] == 3)
						cct_setcolor(board_key[i][j] + 8, COLOR_HWHITE);
					else
						cct_setcolor(board_key[i][j] + 8, COLOR_BLACK);
					cout << "╔═╗";
					cct_gotoxy(fix_w, fix_h);
					cout << "║★║";
					cct_gotoxy(fix_w, fix_h + 1);
					cout << "╚═╝";
				}
			}
		}
	}
	cct_setcolor();
}
void draw_block_divide(int row, int col, const int* row_1, const int* col_1, int board_key[N][N], int board_state[N][N], int flag_4)
{
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			const int fix_w = 5 + (2 + width) * (j - 1), fix_h = 4 + (1 + height) * (i - 1);
			cct_gotoxy(5 + (2 + width) * (j - 1), 3 + (1 + height) * (i - 1));
			if (board_key[i][j] == 0)
			{
				cct_setcolor(COLOR_HWHITE, COLOR_HWHITE);
				cout << "      ";
				cct_gotoxy(fix_w, fix_h);
				cout << "      ";
				cct_gotoxy(fix_w, fix_h + 1);
				cout << "      ";
			}
			else
			{
				if (flag_4 == 0)
				{
					cct_setcolor(board_key[i][j] + 8, COLOR_BLACK);
					cout << "╔═╗";
					cct_gotoxy(fix_w, fix_h);
					cout << "║★║";
					cct_gotoxy(fix_w, fix_h + 1);
					cout << "╚═╝";
				}
				else if (flag_4 == 1)
				{
					if (i == *row_1 && j == *col_1)
						cct_setcolor(board_key[i][j] + 8, COLOR_HWHITE);
					else
						cct_setcolor(board_key[i][j] + 8, COLOR_BLACK);
					cout << "╔═╗";
					cct_gotoxy(fix_w, fix_h);
					cout << "║★║";
					cct_gotoxy(fix_w, fix_h + 1);
					cout << "╚═╝";
				}
				else if (flag_4 == 2)
				{
					if (board_state[i][j] == 2 || board_state[i][j] == 3)
						cct_setcolor(board_key[i][j] + 8, COLOR_HWHITE);
					else
						cct_setcolor(board_key[i][j] + 8, COLOR_BLACK);
					cout << "╔═╗";
					cct_gotoxy(fix_w, fix_h);
					cout << "║★║";
					cct_gotoxy(fix_w, fix_h + 1);
					cout << "╚═╝";
				}
			}
		}
	}
	cct_setcolor();
}
void mouse_and_key(int row, int col, int* row_1, int* col_1, int board_key[N][N], int board_state[N][N], bool boundary,bool* right_click)
{
	//boundary = 0无分界线,boundary = 1有分界线
	while (1)
	{
		int pos_y = 0;
		if (boundary == 0)
			pos_y = 4 + height * row;
		else if (boundary == 1)
			pos_y = 4 + (1 + height) * row;
		int M_X, M_Y, M_action, keycode_1, keycode_2;
		int row_1_1 = *row_1, col_1_1 = *col_1;
		cct_enable_mouse();
		int result = cct_read_keyboard_and_mouse(M_X, M_Y, M_action, keycode_1, keycode_2);
		//键盘
		if (result == CCT_KEYBOARD_EVENT)
		{
			//方向键
			if (keycode_1 == 0xe0)
			{
				check_arrow(row, col, row_1, col_1, board_key, board_state, keycode_2);
				if (boundary == 0)
				{
					draw_block(row, col, row_1, col_1, board_key, board_state, 1);
				}

				else if (boundary == 1)
				{
					draw_block_divide(row, col, row_1, col_1, board_key, board_state, 1);
				}
				cct_gotoxy(0, pos_y);
				cout << "[当前键盘] " << (char)(*row_1 - 1 + 'A') << "行" << *col_1 - 1 << "列" << "                                                                        ";
			}
			if (keycode_1 == 0x0D) //回车
				return;
		}
		//鼠标
		else
		{
			if (M_action == MOUSE_LEFT_BUTTON_CLICK)
			{
				if (examine_and_convert(row, col, row_1, col_1, board_key, board_state, M_X, M_Y, boundary) == true)
					return;
			}
			if (M_action == MOUSE_RIGHT_BUTTON_CLICK)
			{
				*right_click = 1;
				return;
			}
			if (M_action == MOUSE_ONLY_MOVED)
			{
				bool legal = examine_and_convert(row, col, row_1, col_1, board_key, board_state, M_X, M_Y, boundary);
				if (row_1_1 != *row_1 || row_1_1 != *col_1)
				{
					if (!legal)
					{
						if (boundary == 0)
						{
							draw_block(row, col, row_1, col_1, board_key, board_state, 0);
						}

						else if (boundary == 1)
						{
							draw_block_divide(row, col, row_1, col_1, board_key, board_state, 0);
						}
						cct_gotoxy(0, pos_y);
						cout << "[当前鼠标] 位置非法                                                                                                              ";
					}
					else
					{
						if (boundary == 0)
						{
							draw_block(row, col, row_1, col_1, board_key, board_state, 1);
						}

						else if (boundary == 1)
						{
							draw_block_divide(row, col, row_1, col_1, board_key, board_state, 1);
						}
						cct_gotoxy(0, pos_y);
						cout << "[当前鼠标] " << (char)(*row_1 - 1 + 'A') << "行" << *col_1 - 1 << "列" << "                                                             ";
					}
				}
			}
		}
	}
}
void draw_block_choice(int row, int col, int* row_1, int* col_1, int board_key[N][N], int board_state[N][N], bool boundary)
{
	int pos_y;
	if (boundary == 0)
	{
		pos_y = 4 + height * row;
		draw_block(row, col, row_1, col_1, board_key, board_state, 0);
		draw_block(row, col, row_1, col_1, board_key, board_state, 1);
	}
	else if (boundary == 1)
	{
		pos_y = 4 + (1 + height) * row;
		draw_block_divide(row, col, row_1, col_1, board_key, board_state, 0);
		draw_block_divide(row, col, row_1, col_1, board_key, board_state, 1);
	}
}
void check_arrow(int row, int col, int* row_1, int* col_1, int board_key[N][N], int board_state[N][N], int keycode_2) //根据键值2判断上下左右移动,边界返回
{
	int i = 1;
	if (keycode_2 == KB_ARROW_UP)
	{
		if (board_key[*row_1 - 1][*col_1] == 0) //如果上面的元素为0,返回最底部
			*row_1 = row;
		else
			(*row_1)--;
	}
	else if (keycode_2 == KB_ARROW_DOWN)
	{
		if (*row_1 == row)
		{
			for (int i = 1; i <= row; i++)
			{
				if (board_key[i][*col_1] != 0)
				{
					*row_1 = i;
					break;
				}
			}
		}
		else
			(*row_1)++;
	}
	else if (keycode_2 == KB_ARROW_LEFT)
	{
		while (board_key[*row_1][(*col_1 - 1 + col - i) % col + 1] == 0)
			i++;
		*col_1 = (*col_1 - 1 + col - i) % col + 1;
	}
	else if (keycode_2 == KB_ARROW_RIGHT)
	{
		while (board_key[*row_1][(*col_1 - 1 + col + i) % col + 1] == 0)
			i++;
		*col_1 = (*col_1 - 1 + col + i) % col + 1;
	}
}
bool examine_and_convert(int row, int col, int* row_1, int* col_1, int board_key[N][N], int board_state[N][N], int M_X, int M_Y, bool boundary)//将鼠标所在的坐标转换为行列形式,并判断是否为合法区域
{
	bool tag = false;
	if (boundary == 0)
	{
		for (int i = 1; i <= row; i++)
		{
			for (int j = 1; j <= col; j++)
			{
				if (4 + width * (j - 1) <= M_X && M_X <= 4 + width * j&& 3 + height * (i - 1) <= M_Y && M_Y <= 3 + height * i)
				{
					tag = true;
					*row_1 = i;
					*col_1 = j;
				}
			}
		}
	}
	else
	{
		for (int i = 1; i <= row; i++)
		{
			for (int j = 1; j <= col; j++)
			{
				if (5 + (2 + width) * (j - 1) <= M_X && M_X <= 10 + (2 + width) * (j - 1) && 3 + (1 + height) * (i - 1) <= M_Y && M_Y <= 5 + (1 + height) * (i - 1))
				{
					tag = true;
					*row_1 = i;
					*col_1 = j;
				}
			}
		}
	}
	if (board_key[*row_1][*col_1] == 0)
		tag = false;
	return tag;
}
bool check_to_clear(int row, int col, const int* row_1, const int* col_1, int board_key[N][N], int board_state[N][N], int& score, bool tag)
{
	while (1)
	{
		int row_1_1 = *row_1, col_1_1 = *col_1;
		int M_X, M_Y, M_action, keycode_1, keycode_2;
		int result = cct_read_keyboard_and_mouse(M_X, M_Y, M_action, keycode_1, keycode_2);
		if (result == CCT_KEYBOARD_EVENT)
		{
			//回车
			if (keycode_1 == 13)
			{
				int count = 0, * pcount = &count;
				search_same(row_1_1, col_1_1, board_key, board_state, pcount, 2);
				score += bonus * count * count;
				trans_array(row, col, board_key, board_state, "sweep");
				if (tag == 0)
					draw_block(row, col, &row_1_1, &col_1_1, board_key, board_state, 0);
				else
					draw_block_divide(row, col, &row_1_1, &col_1_1, board_key, board_state, 0);
				cct_gotoxy(0, 0);
				cout << "本次得分:" << bonus * count * count << "      总得分:" << score << "      ";
				trans_array(row, col, board_key, board_state, "reset");
				return true;
			}
			//键盘按下方向键
			else if (keycode_1 == 0xe0)
			{
				trans_array(row, col, board_key, board_state, "reset");
				check_arrow(row, col, &row_1_1, &col_1_1, board_key, board_state, keycode_2);
				return false;
			}
		}
		else if (result == CCT_MOUSE_EVENT)
		{
			if (M_action == MOUSE_LEFT_BUTTON_CLICK)
			{
				int count = 0, * pcount = &count;
				search_same(row_1_1, col_1_1, board_key, board_state, pcount, 2);
				score += bonus * count * count;
				trans_array(row, col, board_key, board_state, "sweep");
				if (tag == 0)
					draw_block(row, col, &row_1_1, &col_1_1, board_key, board_state, 0);
				else
					draw_block_divide(row, col, &row_1_1, &col_1_1, board_key, board_state, 0);
				cct_gotoxy(0, 0);
				cout << "本次得分:" << bonus * count * count << "      总得分:" << score << "      ";
				trans_array(row, col, board_key, board_state, "reset");
				return true;
			}
			else if (M_action == MOUSE_ONLY_MOVED)
			{
				if (tag == 0)
					bool flag = examine_and_convert(row, col, &row_1_1, &col_1_1, board_key, board_state, M_X, M_Y, false);
				else
					bool flag = examine_and_convert(row, col, &row_1_1, &col_1_1, board_key, board_state, M_X, M_Y, true);
				if (row_1_1 != *row_1 || col_1_1 != *col_1)
				{
					trans_array(row, col, board_key, board_state, "reset");
					return false;
				}
			}
		}
	}

}
void check_to_fall(int row, int col, const int* row_1, const int* col_1, int board_key[N][N], int board_state[N][N], bool boundary) //这个不需要考虑抖动
{
	int M_X, M_Y, M_action, keycode_1, keycode_2;
	int count = 0, * pcount = &count;
	while (1)
	{
		cct_read_keyboard_and_mouse(M_X, M_Y, M_action, keycode_1, keycode_2);
		//键盘
		if (keycode_1 == 13)
		{
			int key = board_key[*row_1][*col_1];
			delete_same(*row_1, *col_1, board_key, board_state, key);
			trans_array(row, col, board_key, board_state, "reset");
			fall_down(row, col, board_key, board_state,0);
			move_left(row, col, board_key, board_state,1);
			return;
		}

		//鼠标
		if (M_action == MOUSE_LEFT_BUTTON_CLICK)
		{
			int key = board_key[*row_1][*col_1];
			delete_same(*row_1, *col_1, board_key, board_state, key);
			trans_array(row, col, board_key, board_state, "reset");
			fall_down(row, col, board_key, board_state,0);
			move_left(row, col, board_key, board_state,1);
			return;
		}
	}
}
void delete_same(int row_1, int col_1, int board_key[N][N], int board_state[N][N], int key)
{
	if (board_key[row_1][col_1] != key || board_state[row_1][col_1] == -1)
		return;
	else
	{
		board_key[row_1][col_1] = 0;
		board_state[row_1][col_1] = -1;
		delete_same(row_1 - 1, col_1, board_key, board_state, key);
		delete_same(row_1 + 1, col_1, board_key, board_state, key);
		delete_same(row_1, col_1 - 1, board_key, board_state, key);
		delete_same(row_1, col_1 + 1, board_key, board_state, key);
	}
}
void fall_down(int row, int col, int board_key[N][N], int board_state[N][N],bool boundary)
{
	for (int j = 1; j <= col; j++)
	{
		for (int i = row; i >= 1; i--)
		{
			if (board_key[i][j] != 0)
			{
				int target = i;
				find_pos(row, col, board_key, board_state, j, i, target);
				if (i != target)
					change_pos(row, col, board_key, board_state, j, i, target, boundary);
			}
		}
	}
}
void change_pos(int row, int col, int board_key[N][N], int board_state[N][N], int col_x, int tmp_row, int target,bool boundary)
{
	for (int i = tmp_row; i < target; i++)
	{
		int temp = board_key[i][col_x];
		board_key[i][col_x] = board_key[i + 1][col_x];
		board_key[i + 1][col_x] = temp;
		if (boundary == 0)
			draw_block(row, col, NULL, NULL, board_key, board_state, 0);
		else
			draw_block_divide(row, col, NULL, NULL, board_key, board_state, 0);
		Sleep(0);
	}
}