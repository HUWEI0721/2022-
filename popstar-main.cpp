/*2153393 ������ ���*/
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
	cout << "A.�������ҳ����������ʶ" << endl;
	cout << "B.���������һ���������ֲ�����ʾ��" << endl;
	cout << "C.���������һ�أ��ֲ�����ʾ��" << endl;
	cout << "D.αͼ�ν����������ѡ��һ��ɫ�飨�޷ָ��ߣ�" << endl;
	cout << "E.αͼ�ν����������ѡ��һ��ɫ�飨�зָ��ߣ�" << endl;
	cout << "F.αͼ�ν������һ���������ֲ��裩" << endl;
	cout << "G.αͼ�ν���������" << endl;
	cout << "Q.�˳�" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "[��ѡ��:] ";
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
		cout << "����������(8-10)��" << endl;
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
		cout << "����������(8-10)��" << endl;
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
			cout << "�����������������س�������һ�ε�����..." << endl;
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
			cout << "ʣ��" << trans_array(row, col, board_key, board_state, "count") << "������������,���ؽ���!";
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
	cout << "��ͷ��/����ƶ�,�س���/�������ѡ�񲢽���";
	draw_block_choice(row, col, &row_1, &col_1, board_key, board_state, 0);
	mouse_and_key(row, col, &row_1, &col_1, board_key, board_state, 0, &right_click);
	cct_gotoxy(0, pos_of_y);
	cout << "ѡ����" << (char)(row_1 - 1 + 'A') << "��" << col_1 - 1 << "��" << "                             " << endl;
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
	cout << "��ͷ��/����ƶ�,�س���/�������ѡ�񲢽���";
	draw_block_choice(row, col, &row_1, &col_1, board_key, board_state, 1);
	mouse_and_key(row, col, &row_1, &col_1, board_key, board_state, 1,&right_click);
	cct_gotoxy(0, pos_of_y);
	cout << "ѡ����" << (char)(row_1 - 1 + 'A') << "��" << col_1 - 1 << "��" << "                             " << endl;
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
	cout << "��ͷ��/����ƶ�,�س���/�������ѡ��                ";
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
			cout << "��Χ����ֵͬ,��ͷ��/����ƶ�,�س���/��������ϳ�                         ";
			continue;
		}
		else
		{
			cct_gotoxy(0, pos_y);
			cout << "��ͷ��/����ƶ�ȡ����ǰѡ��,�س���/��������ϳɣ�Q/�����Ҽ�����                          ";
			draw_block(row, col, &row_1, &col_1, board_key, board_state, 2);
			if (check_to_clear(row, col, &row_1, &col_1, board_key, board_state, score, 0) == true)
			{
				cct_gotoxy(0, pos_y);
				cout << "�ϳ����,�س���/�����������                             ";
				check_to_fall(row, col, &row_1, &col_1, board_key, board_state, 0);
				break;
			}
			else
				continue;
		}
	}
	cct_gotoxy(0, pos_y);
	cout << "���κϳɽ���,��C/�������������һ�εĺϳ�                 " << endl;
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
			cout << "ʣ��" << rest << "������������,���ؽ���,'�س�'��һ��,'Q'�˳����ؿ�          ";
			if (rest <= 10)
				score += (10 - rest) * 180;
			cct_gotoxy(0, 0);
			cout << "���ε÷�:" << score - score_0 << "      �ܵ÷�:" << score << "      ";
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