/* 2153393 ��� ������ */
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
		����   ��1����������һ�����������������ݹ麯�����������������ӵĺ����в������κ���ʽ��ѭ��
				 2��������ų���
				 3������const�ͱ���

		������ ��1������ȫ�ֱ���
				 2����print_tower֮������������в������徲̬�ֲ�����
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
	 �������ƣ�
	 ��    �ܣ���ӡ��ĸ��
	 ���������
	 �� �� ֵ��
	 ˵    �����βΰ�������
			   ��ʾ����һ������order��ָ������/����
   ***************************************************************************/
void print_tower(char start_ch, char end_ch, int order)
{
	/* �����趨�����һ����̬�ֲ�������Ҳ���Բ����壩 */
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
	/* ����ʵ�֣������в������κ���ʽ��ѭ����������������������� */

}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main�����е�...�����޸ģ�����λ�ò�׼�޸�
***************************************************************************/
int main()
{
	char end_ch;

	/* ������������ַ�(����д��Ч��Ϊ����ѭ�����֣��������������) */
	cout << "����������ַ�(A~Z)" << endl;
	end_ch = getchar();			//����������һ���ַ�
	if (end_ch < 'A' || end_ch > 'Z') {
		cout << "�����ַ����Ǵ�д��ĸ" << endl;
		return -1;
	}

	/* ��������ĸ��(����ΪA) */
	cout << setw(blank(end_ch)) << setfill('=') << "=" << endl; /* ����ĸ����������=(��������ѭ��) */
	cout << "��������ĸ��(A->" << end_ch << ")" << endl;
	cout << setw(blank(end_ch)) << setfill('=') << "=" << setfill(' ') << endl; /* ����ĸ����������=(��������ѭ��) */
	print_tower('A', end_ch, 0); //�����ӡ A~�����ַ� 
	cout << endl;

	/* ��������ĸ��(����ΪA) */
	cout << setw(blank(end_ch)) << setfill('=') << "=" << endl; /* ����ĸ����������=(��������ѭ��) */
	cout << "��������ĸ��(A->" << end_ch << ")" << endl;
	cout << setw(blank(end_ch)) << setfill('=') << "=" << setfill(' ') << endl; /* ����ĸ����������=(��������ѭ��) */
	print_tower('A', end_ch, 1); //�����ӡ A~�����ַ� 
	cout << endl;

	/* ����������Ư�������Σ����ΪA�� */
	cout << setw(blank(end_ch)) << setfill('=') << "=" << endl;;/* ����ĸ����������= */
	cout << "����(A->" << end_ch << ")" << endl;
	cout << setw(blank(end_ch)) << setfill('=') << "=" << setfill(' ') << endl;/* ����ĸ����������= */
	print_tower('A', end_ch, 0);   //��ӡ A~�����ַ��������� 
	print_tower('A', end_ch - 1, 1);   //��ӡ A~�����ַ�-1�ĵ����� 
	cout << endl;

	return 0;
}