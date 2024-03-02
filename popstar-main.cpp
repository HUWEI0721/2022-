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
char menu()
{
	char choice;
	cout << "--------------------------------------------" << endl;
	cout << "A.命令行找出可消除项并标识" << endl;
	cout << "B.命令行完成一次消除（分步骤显示）" << endl;
	cout << "C.命令行完成一关（分步骤显示）" << endl;
	cout << "D.伪图形界面下用鼠标选择一个色块（无分隔线）" << endl;
	cout << "E.伪图形界面下用鼠标选择一个色块（有分隔线）" << endl;
	cout << "F.伪图形界面完成一次消除（分步骤）" << endl;
	cout << "G.伪图形界面完整版" << endl;
	cout << "Q.退出" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "[请选择:] ";
	while (1)
	{
		choice = _getche();
		if ((choice >= 'a' && choice <= 'g') || choice == 'q')
			choice -= 32;
		if (choice >= 'A' && choice <= 'G')
		{
			cout << endl;
			Sleep(400);
			break;
		}
		else if (choice == 'Q')
		{
			for (int i = 0; i < 14; i++)
				cout << endl;
			break;
		}
		else
		{
			cin.clear();
			cct_gotoxy(11, 10);
			cout << "\b \b";
			continue;
		}
	}
	return choice;
}
void input_data(int* row, int* col)
{
	cct_cls();
	while (1)
	{
		cout << "请输入行数(8-10)：" << endl;
		cin >> *row;
		if (cin.fail() || *row < 8 || *row > 10)
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		else if (*row >= 8 && *row <= 10)
			break;
	}
	while (1)
	{
		cout << "请输入列数(8-10)：" << endl;
		cin >> *col;
		if (cin.fail() || *col < 8 || *col > 10)
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		else if (*col >= 8 && *col <= 10)
			break;
	}
}
void choose_menu(char choice, int* row, int* col, int board_key[N][N], int board_state[N][N])
{
	input_data(row, col);
	switch (choice)
	{
		case 'A':
			function_A('A', *row, *col, board_key, board_state);
			break;
		case 'B':
			function_B('B', *row, *col, board_key, board_state);
			break;
		case 'C':
			function_C('C', *row, *col, board_key, board_state);
			break;
		case 'D':
			function_D('D', *row, *col, board_key, board_state);
			break;
		case 'E':
			function_E('E', *row, *col, board_key, board_state);
			break;
		case 'F':
			function_F('F', *row, *col, board_key, board_state);
			break;
		case 'G':
			function_G('G', *row, *col, board_key, board_state);
			break;
	}
}
void function_A(char choice, int row, int col, int board_key[N][N], int board_state[N][N])
{
	int row_1, col_1;
	row_1 = 0; col_1 = 0;
	init_array(row, col, board_key, board_state);
	show_array('A', row, col, board_key, board_state, 0);
	while (1)
	{
		judge_pos('A', row, col, &row_1, &col_1, board_key, board_state);
		if (judge_tant_zero('A', row, col, &row_1, &col_1, board_key, board_state))
			break;
	}
	show_array('A', row, col, board_key, board_state, 1);
	cout << endl << endl;
	show_array('A', row, col, board_key, board_state, 2);
	cout << endl;
	judge_end();
}
void function_B(char choice, int row, int col, int board_key[N][N], int board_state[N][N])
{
	int row_1, col_1;
	row_1 = 0, col_1 = 0;
	int score = 0;
	init_array( row, col, board_key, board_state);
	show_array('B', row, col, board_key, board_state, 0);
	while (1)
	{
		judge_pos('B', row, col, &row_1, &col_1, board_key, board_state);
		if (judge_tant_zero('B', row, col, &row_1, &col_1, board_key, board_state))
			break;
	}
	show_array('B', row, col, board_key, board_state, 1);
	cout << endl << endl;
	show_array('B', row, col, board_key, board_state, 2);
	cmd_clear('B', row, col, &row_1, &col_1, board_key, board_state, score);
	cout << endl;
	judge_end();
}
void function_C(char choice, int row, int col, int board_key[N][N], int board_state[N][N])
{
	int row_1, col_1;
	row_1 = 0; col_1 = 0;
	int score = 0;
	int flag = 0;
	init_array(row, col, board_key, board_state);
	while (1)
	{
		show_array('C', row, col, board_key, board_state, 0);
		while (1)
		{
			judge_pos('C', row, col, &row_1, &col_1, board_key, board_state);
			if (judge_tant_zero('C', row, col, &row_1, &col_1, board_key, board_state))
				break;
		}
		show_array('C', row, col, board_key, board_state, 1);
		cout << endl << endl;
		show_array('C', row, col, board_key, board_state, 2);
		flag = cmd_clear('C', row, col, &row_1, &col_1, board_key, board_state, score);
		if (flag == 1)
		{
			cout << "本次消除结束，按回车继续新一次的消除..." << endl;
			while (1)
				if (_getche() == '\r')
					break;
		}
		if (flag == 0)
		{
			judge_end();
			return;
		}
		if (check_gameover(row, col, board_key, board_state))
		{
			show_array('C', row, col, board_key, board_state, 0);
			cct_setcolor(COLOR_HYELLOW, COLOR_RED);
			cout << endl;
			cout << "剩余" << trans_array(row, col, board_key, board_state, "count") << "个不可消除项,本关结束!";
			cct_setcolor();
			cout << endl;
			break;
		}
	}
	judge_end();
}
void function_D(char choice, int row, int col, int board_key[N][N], int board_state[N][N])
{
	int pos_of_y = 4 + height * row;
	int row_1, col_1;
	bool right_click = 0;
	row_1 = 0; col_1 = 0;
	init_array( row, col, board_key, board_state);
	draw_row_col(row, col);
	draw_border(row, col);
	draw_block(row, col, &row_1, &col_1, board_key, board_state, 0);
	row_1 = row, col_1 = 1;
	cct_gotoxy(0, pos_of_y);
	cct_setcursor(3);
	cout << "箭头键/鼠标移动,回车键/单击左键选择并结束";
	draw_block_choice(row, col, &row_1, &col_1, board_key, board_state, 0);
	mouse_and_key(row, col, &row_1, &col_1, board_key, board_state, 0, &right_click);
	cct_gotoxy(0, pos_of_y);
	cout << "选中了" << (char)(row_1 - 1 + 'A') << "行" << col_1 - 1 << "列" << "                             " << endl;
	if (right_click == 1)
	{
		judge_end();
		return;
	}
	judge_end();
}
void function_E(char choice, int row, int col, int board_key[N][N], int board_state[N][N])
{
	int pos_of_y = 4 + (1 + height) * row;
	int row_1, col_1;
	bool right_click = 0;
	row_1 = 0; col_1 = 0;
	init_array( row, col, board_key, board_state);
	draw_border_divide(row, col);
	draw_block_divide(row, col, &row_1, &col_1, board_key, board_state, 0);
	row_1 = row, col_1 = 1;
	cct_gotoxy(0, pos_of_y);
	cct_setcursor(3);
	cout << "箭头键/鼠标移动,回车键/单击左键选择并结束";
	draw_block_choice(row, col, &row_1, &col_1, board_key, board_state, 1);
	mouse_and_key(row, col, &row_1, &col_1, board_key, board_state, 1,&right_click);
	cct_gotoxy(0, pos_of_y);
	cout << "选中了" << (char)(row_1 - 1 + 'A') << "行" << col_1 - 1 << "列" << "                             " << endl;
	if (right_click == 1)
	{
		judge_end();
		return;
	}
	judge_end();
}
void function_F(char choice, int row, int col, int board_key[N][N], int board_state[N][N])
{
	int pos_y = 4 + height * row;
	int row_1, col_1;
	row_1 = 1; col_1 = 1;
	int score = 0;
	bool boundary = false;
	bool right_click = 0;
	init_array(row, col, board_key, board_state);
	draw_row_col(row, col);
	draw_border(row, col);
	draw_block(row, col, NULL, NULL, board_key, board_state, 0);
	cct_setcursor(3);
	cct_gotoxy(0, pos_y);
	cout << "箭头键/鼠标移动,回车键/单击左键选择                ";
	while (1)
	{
		int count = 0, * pcount = &count;
		draw_block_choice(row, col, &row_1, &col_1, board_key, board_state, 0);
		mouse_and_key(row, col, &row_1, &col_1, board_key, board_state, 0, &right_click);
		if (right_click == 1)
		{
			cct_gotoxy(0, pos_y);
			cout << "                                                               " << endl;
			judge_end();
			return;
		}
		search_same(row_1, col_1, board_key, board_state, pcount, 0);
		if (*pcount == 1)
		{
			board_state[row_1][col_1] = 1;
			cct_gotoxy(0, pos_y);
			cout << "周围无相同值,箭头键/鼠标移动,回车键/单击左键合成                         ";
			continue;
		}
		else
		{
			cct_gotoxy(0, pos_y);
			cout << "箭头键/鼠标移动取消当前选择,回车键/单击左键合成，Q/单击右键结束                          ";
			draw_block(row, col, &row_1, &col_1, board_key, board_state, 2);
			if (check_to_clear(row, col, &row_1, &col_1, board_key, board_state, score, 0) == true)
			{
				cct_gotoxy(0, pos_y);
				cout << "合成完成,回车键/单击左键下落                             ";
				check_to_fall(row, col, &row_1, &col_1, board_key, board_state, 0);
				break;
			}
			else
				continue;
		}
	}
	cct_gotoxy(0, pos_y);
	cout << "本次合成结束,按C/单击左键继续新一次的合成                 " << endl;
	int M_X, M_Y, M_action, keycode_1, keycode_2;
	while (cct_read_keyboard_and_mouse(M_X, M_Y, M_action, keycode_1, keycode_2) == 1 && (keycode_1 != 'C' || keycode_1 != 'c'))
	{
		cct_gotoxy(0, pos_y);
		cout << "                                                               " << endl;
		judge_end();
		return;
	}
	cct_read_keyboard_and_mouse(M_X, M_Y, M_action, keycode_1, keycode_2);
	cct_gotoxy(0, pos_y);
	cout << "                                                               " << endl;
	judge_end();
}
void function_G(char choice, int row, int col, int board_key[N][N], int board_state[N][N])
{
	int pos_y = 4 + (1 + height) * row;
	int score = 0;
	init_array(row, col, board_key, board_state);
	draw_border_divide(row, col);
	draw_block_divide(row, col, NULL, NULL, board_key, board_state, 0);
	while (1)
	{
		int score_0 = score;
		bool right_click = 0;
		cct_setcursor(3);
		GAME(row, col, board_key, board_state, score, &right_click);
		if (right_click == 1)
		{
			cct_gotoxy(0, pos_y);
			cout << "                                                               " << endl;
			judge_end();
			return;
		}
		if (check_gameover(row, col, board_key, board_state))
		{
			cct_gotoxy(0, pos_y);
			int rest = trans_array(row, col, board_key, board_state, "count");
			cout << "剩余" << rest << "个不可消除项,本关结束,'回车'下一关,'Q'退出本关卡          ";
			if (rest <= 10)
				score += (10 - rest) * 180;
			cct_gotoxy(0, 0);
			cout << "本次得分:" << score - score_0 << "      总得分:" << score << "      ";
			while (1)
			{
				char ch = '0';
				ch = _getche();
				if (ch == '\r')
				{
					init_array(row, col, board_key, board_state);
					draw_border_divide(row, col);
					draw_block_divide(row, col, NULL, NULL, board_key, board_state, 0);
					break;
				}
				else if (ch == 'Q' || ch == 'q')
					return;
			}
		}
	}
}
int main()
{
	srand((unsigned int)(time(0)));
	cct_setconsoleborder(120, 40, 120, 9000);
	char choice;
	int row, col;
	int board_key[N][N], board_state[N][N];
	while (1)
	{
		cct_cls();
		choice = menu();
		if (choice == 'Q')
			return 0;
		else
			choose_menu(choice, &row, &col,board_key, board_state);
	}
}