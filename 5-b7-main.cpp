/*2153393 ������ ���*/
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include "5-b7.h"
using namespace std;
int num = 0;
int numA[10] = { 0 };
int numB[10] = { 0 };
int numC[10] = { 0 };
int a = 0, b = 0, c = 0;
int stay;
int ifshow;
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/

void delay_move(int wait)
{
    int a;
    if (wait == 0)
        a = _getche();
    else if (wait == 1)
        Sleep(2000);
    else if (wait == 2)
        Sleep(1500);
    else if (wait == 3)
        Sleep(1000);
    else if (wait == 4)
        Sleep(500);
    else if (wait == 5)
        Sleep(50);
}
void sernum(int n)
{
    cct_gotoxy(40, 25);
    cout << " A:";
    for (int i = 0; i < 10; i++)
    {
        if (numA[i] == 10)
            cout << 10;
        else if (numA[i] < 10 && numA[i]>0)
            cout << " " << numA[i];
        else if (numA[i] == 0)
            cout << "  ";
    }
    cout << " B:";
    for (int i = 0; i < 10; i++)
    {
        if (numB[i] == 10)
            cout << 10;
        else if (numB[i] < 10 && numB[i]>0)
            cout << " " << numB[i];
        else if (numB[i] == 0)
            cout << "  ";
    }
    cout << " C:";
    for (int i = 0; i < 10; i++)
    {
        if (numC[i] == 10)
            cout << 10;
        else if (numC[i] < 10 && numC[i]>0)
            cout << " " << numC[i];
        else if (numC[i] == 0)
            cout << "  ";
    }
    if (n == 1)
        delay_move(stay);
}
void print_front(int n, char src, char dst)
{
    cct_gotoxy(20, 25);
    num++;
    cout << "��" << setfill(' ') << setw(4) << num << " ��(" << setw(2) << n << "): " << src << "-->" << dst;
    in(dst, out(src));
}
void print_back(int m)
{
    int x, y;
    x = 11;
    y = 19;

    for (int i = 0; i < 10; i++) 
    {
        cct_gotoxy(x, y - i);
        if (numA[i] != 0)
            cout << numA[i];
        else
            cout << " ";
    }
    for (int i = 0; i < 10; i++) 
    {
        cct_gotoxy(x + 10, y - i);
        if (numB[i] != 0)
            cout << numB[i];
        else
            cout << " ";
    }
    for (int i = 0; i < 10; i++) 
    {
        cct_gotoxy(x + 20, y - i);
        if (numC[i] != 0)
            cout << numC[i];
        else
            cout << " ";
    }
    cct_gotoxy(1,1);
    if (m == 1)
        delay_move(stay);
}
void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 1) 
    {
        if (ifshow)
            print_back(1);
        print_front(1, src, dst);
        sernum(1);
    }
    else if (n == 2) 
    {
        if (ifshow)
            print_back(1);
        print_front(1, src, tmp);
        sernum(1);
        if (ifshow)
            print_back(1);
        print_front(2, src, dst);
        sernum(1);
        if (ifshow)
            print_back(1);
        print_front(1, tmp, dst);
        sernum(1);
    }
    else
    {
        hanoi(n - 1, src, dst, tmp);
        if (ifshow)
            print_back(1);
        print_front(n, src, dst);
        sernum(1);
        hanoi(n - 1, tmp, src, dst);
        print_back(0);
    }
}
int main()
{
    int n, fw;
    while (1)
    {
        cout << "�����뺺ŵ���Ĳ���(1-10)" << endl;
        cin >> n;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        else if (n >= 1 && n <= 16)
        {
            cin.ignore(1024, '\n');
            break;
        }
    }
    char src, tmp = '0', dst;
    while (1)
    {
        cout << "��������ʼ��(A-C)" << endl;
        cin >> src;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        else if ((src == 'a') || (src == 'A') || (src == 'b') || (src == 'B') || (src == 'c') || (src == 'C'))
        {
            cin.clear();
            cin.ignore(1024, '\n');
            break;
        }
        else
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
    }
    while (1)
    {
        cout << "������Ŀ����(A-C)" << endl;
        cin >> dst;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        else if ((dst == 'a') || (dst == 'A') || (dst == 'b') || (dst == 'B') || (dst == 'c') || (dst == 'C'))
        {
            if (src == dst)
            {
                if ((dst == 'a') || (dst == 'A'))
                    cout << "Ŀ����(A)��������ʼ��(A)��ͬ" << endl;
                else if ((dst == 'b') || (dst == 'B'))
                    cout << "Ŀ����(B)��������ʼ��(B)��ͬ" << endl;
                else if ((dst == 'c') || (dst == 'C'))
                    cout << "Ŀ����(C)��������ʼ��(C)��ͬ" << endl;
                cin.clear();
                cin.ignore(1024, '\n');
                continue;
            }
            cin.clear();
            cin.ignore(1024, '\n');
            break;
        }
        else
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
    }
    if (src == 'a')
        src = 'A';
    else if (src == 'b')
        src = 'B';
    else if (src == 'c')
        src = 'C';
    if (dst == 'a')
        dst = 'A';
    else if (dst == 'b')
        dst = 'B';
    else if (dst == 'c')
        dst = 'C';
    while (1)
    {
        cout << "�������ƶ��ٶ�(0-5: 0-���س�������ʾ 1-��ʱ� 5-��ʱ���)" << endl;
        cin >> stay;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        else if (stay >= 0 && stay <= 5)
        {
            cin.clear();
            cin.ignore(1024, '\n');
            break;
        }
        else
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
    }
    while (1)
    {
        cout << "�������Ƿ���ʾ�ڲ�����ֵ(0-����ʾ 1-��ʾ)" << endl;
        cin >> ifshow;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        else if (ifshow == 0 || ifshow == 1)
        {
            cin.clear();
            cin.ignore(1024, '\n');
            break;
        }
        else
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
    }
    if (src == 'A')
    {
        if (dst == 'B')
            tmp = 'C';
        else if (dst == 'C')
            tmp = 'B';
    }
    else if (src == 'B')
    {
        if (dst == 'C')
            tmp = 'A';
        else if (dst == 'A')
            tmp = 'C';
    }
    else if (src == 'C')
    {
        if (dst == 'B')
            tmp = 'A';
        else if (dst == 'A')
            tmp = 'B';
    }
    tmp = 3 * 'B' - src - dst;
    if (src == 'A')
    {
        for (int i = 0; i < n; i++)
            numA[i] = n - i;
        a = n;
    }
    if (src == 'B')
    {
        for (int i = 0; i < n; i++)
            numB[i] = n - i;
        b = n;
    }
    if (src == 'C')
    {
        for (int i = 0; i < n; i++)
            numC[i] = n - i;
        c = n;
    }
    cct_cls();
    if (ifshow != 0)
        cout << "�� " << src << " �ƶ��� " << dst << "���� " << n << " �㣬��ʱ����Ϊ " << stay << "��" << "��ʾ�ڲ�����ֵ" << endl;
    else
        cout << "�� " << src << " �ƶ��� " << dst << "���� " << n << " �㣬��ʱ����Ϊ " << stay << "��" << "����ʾ�ڲ�����ֵ" << endl;
    for (int k = 0; k < 19; k++)
        cout << endl;
   
    cct_gotoxy(20, 25);
    if (ifshow) 
    {
        cout << "��ʼ:                ";
        sernum(1);
    }
    cct_gotoxy(9, 20);
    cout << "=========================" << endl;
    cout << "           A         B         C" << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    print_back(0);
    hanoi(n, src, tmp, dst);
    fw = _getche();
    cct_gotoxy(20, 35);
    
	system("pause"); //���������ʾ��ͣ��ע�⣺ֻ�ʺ����ض��������ر������ĳ���Ӵ˾���÷�Ϊ0��
	return 0;
}
