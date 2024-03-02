/* 2153393 软件 胡峻玮 */
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
		允许   ：1、按需增加一个或多个函数（包括递归函数），但是所有增加的函数中不允许任何形式的循环
				 2、定义符号常量
				 3、定义const型变量

		不允许 ：1、定义全局变量
				 2、除print_tower之外的其他函数中不允许定义静态局部变量
   ----------------------------------------------------------------------------------- */
void one_line_left(char start, char end_ch)
{
	if (end_ch >= start)
	{
		one_line_left(start, end_ch - 1);
		cout << end_ch;
	}

}
void one_line_right(char start, char end_ch)
{
	if (end_ch > start)
	{
		cout << (char)(end_ch - 1);
		one_line_right(start, end_ch - 1);
	}

}
void printline(int end)
{
	one_line_left('A', end);
	one_line_right('A', end);
	cout << endl;
}
int blank(char end_ch)
{
	int a, b;
	a = int(end_ch) - 64;
	b = 2 * a - 1;
	return b;
}
   /***************************************************************************
	 函数名称：
	 功    能：打印字母塔
	 输入参数：
	 返 回 值：
	 说    明：形参按需设置
			   提示：有一个参数order，指定正序/倒序
   ***************************************************************************/
void print_tower(char start_ch, char end_ch, int order)
{
	/* 允许按需定义最多一个静态局部变量（也可以不定义） */
	static int a = end_ch;
	if (order == 0)
	{
		int b = a - end_ch + 1;
		if (end_ch == 65)
		{
			cout << setw(b);
			printline(end_ch);
		}
		else
		{
			print_tower(start_ch, end_ch - 1, 0);
			cout << setw(b);
			printline(end_ch);
		}
	}
	if (order == 1)
	{
		int b = a - end_ch + 1;
		if (end_ch == 65)
		{
			cout << setw(b);
			printline(end_ch);
		}
		else
		{
			cout << setw(b);
			printline(end_ch);
			if (end_ch > 65)
				print_tower(start_ch, end_ch - 1, 1);
		}
	}
	/* 按需实现，函数中不允许任何形式的循环，函数允许调用其它函数 */

}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数中的...允许修改，其余位置不准修改
***************************************************************************/
int main()
{
	char end_ch;

	/* 键盘输入结束字符(仅大写有效，为避免循环出现，不处理输入错误) */
	cout << "请输入结束字符(A~Z)" << endl;
	end_ch = getchar();			//读缓冲区第一个字符
	if (end_ch < 'A' || end_ch > 'Z') {
		cout << "结束字符不是大写字母" << endl;
		return -1;
	}

	/* 正三角字母塔(两边为A) */
	cout << setw(blank(end_ch)) << setfill('=') << "=" << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	cout << "正三角字母塔(A->" << end_ch << ")" << endl;
	cout << setw(blank(end_ch)) << setfill('=') << "=" << setfill(' ') << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	print_tower('A', end_ch, 0); //正序打印 A~结束字符 
	cout << endl;

	/* 倒三角字母塔(两边为A) */
	cout << setw(blank(end_ch)) << setfill('=') << "=" << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	cout << "倒三角字母塔(A->" << end_ch << ")" << endl;
	cout << setw(blank(end_ch)) << setfill('=') << "=" << setfill(' ') << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	print_tower('A', end_ch, 1); //逆序打印 A~结束字符 
	cout << endl;

	/* 合起来就是漂亮的菱形（外侧为A） */
	cout << setw(blank(end_ch)) << setfill('=') << "=" << endl;;/* 按字母塔最大宽度输出= */
	cout << "菱形(A->" << end_ch << ")" << endl;
	cout << setw(blank(end_ch)) << setfill('=') << "=" << setfill(' ') << endl;/* 按字母塔最大宽度输出= */
	print_tower('A', end_ch, 0);   //打印 A~结束字符的正三角 
	print_tower('A', end_ch - 1, 1);   //打印 A~结束字符-1的倒三角 
	cout << endl;

	return 0;
}