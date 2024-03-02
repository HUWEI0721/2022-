/* 软件 2153393 胡峻玮 */
#include<iostream>
#include<iomanip>
#include<windows.h>
#include<conio.h>
#include"cmd_console_tools.h"
#include"hanoi.h"
using namespace std;
/* ----------------------------------------------------------------------------------

     本文件功能：
    1、存放被 hanoi_main.cpp 中根据菜单返回值调用的各菜单项对应的执行函数

     本文件要求：
    1、不允许定义外部全局变量（const及#define不在限制范围内）
    2、允许定义静态全局变量（具体需要的数量不要超过文档显示，全局变量的使用准则是：少用、慎用、能不用尽量不用）
    3、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
    4、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */
int numA[10] = { 0 };
int numB[10] = { 0 };
int numC[10] = { 0 };
int num = 0;//步数记录
static int wait;//延时
int a = 0, b = 0, c = 0;
//设置起始塔
void set(int* n, char* src)
{
    if (*src == 'A')
    {
        for (int i = 0; i < *n; i++)
            numA[i] = *n - i;
        a = *n;
    }
    if (*src == 'B')
    {
        for (int i = 0; i < *n; i++)
            numB[i] = *n - i;
        b = *n;
    }
    if (*src == 'C')
    {
        for (int i = 0; i < *n; i++)
            numC[i] = *n - i;
        c = *n;
    }
}
//初始化全局变量
void init_all()
{
    num = 0, a = 0, b = 0, c = 0;
    for (int i = 0; i < 10; i++)
    {
        numA[i] = 0;
        numB[i] = 0;
        numC[i] = 0;
    }
}
//进栈
void in(char k, int j)
{
    if (k == 'A')
        numA[a++] = j;
    if (k == 'B')
        numB[b++] = j;
    if (k == 'C')
        numC[c++] = j;
}
//出栈
int out(char k)
{
    int t = 0;
    if (k == 'A')
    {
        t = numA[--a];
        numA[a] = 0;
    }
    if (k == 'B')
    {
        t = numB[--b];
        numB[b] = 0;
    }
    if (k == 'C')
    {
        t = numC[--c];
        numC[c] = 0;
    }
    return t;
}
//移动延时
void delay_move(int wait, int flag)
{
    int a;
    if (wait == 0)
    {
        if (flag == 0)
        {
            while (1)
            {
                a = _getch();
                if (a == 13)
                    break;
            }
        }
        else if (flag == 1)
            Sleep(20);
    }
    else if (wait == 1)
        Sleep(500);
    else if (wait == 2)
        Sleep(300);
    else if (wait == 3)
        Sleep(100);
    else if (wait == 4)
        Sleep(30);
    else if (wait == 5)
        Sleep(1);
}
//纵向移动
void line_move(int n, char src, char tmp, char dst, int choice, int uod)//uod--up or down --'1'代表up--'0'代表down
{
    int stack_top[3] = { a,b,c };
    int x_start, y_start, x_end, y_end;
    if (uod == 1)
    {
        x_start = (src - 'A') * 32 + 12 - n;
        y_start = 14 - stack_top[src - 'A'];
        y_end = 1;
        for (int i = y_start; i >= y_end; --i)
        {
            cct_showch(x_start, i, ' ', n, n, 2 * n + 1);
            delay_move(wait, 1);
            if (i > y_end)
            {
                cct_showch(x_start, i, ' ', 0, 7, 2 * n + 1);
                if (i > 2)
                    cct_showch(x_start + n, i, ' ', 14, 7, 1);
            }
        }
    }
    if (uod == 0)
    {
        x_end = (dst - 'A') * 32 + 12 - n;
        y_start = 1;
        y_end = 15 - stack_top[dst - 'A'];
        for (int i = y_start; i <= y_end; i++)
        {
            cct_showch(x_end, i, ' ', n, n, 2 * n + 1);
            delay_move(wait, 1);
            if (i < y_end)
            {
                cct_showch(x_end, i, ' ', 0, 7, 2 * n + 1);
                if (i > 2)
                    cct_showch(x_end + n, i, ' ', 14, 7, 1);
            }
        }
    }
}
//横向移动
void row_move(int n, char src, char tmp, char dst, int choice)
{
    const int stack_top[] = { a,b,c };
    int x_start, y_start, x_end, y_end;
    int towards;
    if ((int)dst - (int)src > 0)
        towards = 1;
    else
        towards = -1;
    x_start = (src - 'A') * 32 + 12 - n;
    x_end = (dst - 'A') * 32 + 12 - n;
    y_start = y_end = 1;
    while (1)
    {
        cct_showch(x_start, y_start, ' ', n, n, 2 * n + 1);
        delay_move(wait, 1);
        if (x_start != x_end)
        {
            cct_showch(x_start, y_start, ' ', 0, 7, 2 * n + 1);
            cct_showch(x_start + n, y_start, ' ', 14, 7, 1);
        }
        if (x_start == x_end)
        {
            break;
        }
        x_start = x_start + towards;
    }
}
//横向打印前缀第n步
void print_front(int n, char src, char dst, int choice)
{
    if (choice != 7)
    {
        cct_setcolor();
        if (choice == 8)
            cct_gotoxy(0, 32);
        cout << "第" << setfill(' ') << setw(4) << num << " 步(" << setw(2) << n << "#: " << src << "-->" << dst << ") ";
    }
    in(dst, out(src));
}
//横向打印数组
void sernum(int choice)
{
    if (choice != 7)
    {
        cct_setcolor(0, 7);
        if (choice == 4)
            cct_gotoxy(23, 17);
        if (choice == 3)
            cout << " A:";
        else
            cout << "A:";
        for (int i = 0; i < 10; i++)
        {
            if (numA[i] == 10)
                cout << 10;
            if (numA[i] < 10 && numA[i]>0)
                cout << setw(2) << numA[i];
            if (numA[i] == 0)
                cout << "  ";
        }
        cout << " B:";
        for (int i = 0; i < 10; i++)
        {
            if (numB[i] == 10)
                cout << 10;
            if (numB[i] < 10 && numB[i]>0)
                cout << setw(2) << numB[i];
            if (numB[i] == 0)
                cout << "  ";
        }
        cout << " C:";
        for (int i = 0; i < 10; i++)
        {
            if (numC[i] == 10)
                cout << 10;
            if (numC[i] < 10 && numC[i]>0)
                cout << setw(2) << numC[i];
            if (numC[i] == 0)
                cout << "  ";
        }
        cout << endl;
    }
}
//纵向打印数组
void print_back(int choice)
{
    if (choice != 7)
    {
        int x, y;
        x = 11;
        y = 11;
        if (choice == 8 || choice == 9)
            y += 15;
        for (int i = 0; i < 10; i++)
        {
            cct_gotoxy(x, y - i);
            if (numA[i] != 0)
                cout << numA[i];
            else
                cout << "  ";
        }
        for (int i = 0; i < 10; i++)
        {
            cct_gotoxy(x + 10, y - i);
            if (numB[i] != 0)
                cout << numB[i];
            else
                cout << "  ";
        }
        for (int i = 0; i < 10; i++)
        {
            cct_gotoxy(x + 20, y - i);
            if (numC[i] != 0)
                cout << numC[i];
            else
                cout << "  ";
        }
        cct_gotoxy(0, 17);
        if (choice == 4)
            delay_move(wait, 0);
    }
}
//移动
void move_1(int n, char src, char tmp, char dst, int choice)
{
    num++;
    if (choice == 1)
    {
        cout << n << "# " << src << "---->" << dst << endl;
    }
    if (choice == 2)
    {
        cout << "第" << setfill(' ') << setw(4) << num << " 步(" << setw(2) << n << "#: " << src << "-->" << dst << ")" << endl;
    }
    if (choice == 3 || choice == 4)
    {
        print_front(n, src, dst, choice);
        sernum(choice);
        if (choice == 4)
            print_back(choice);
    }
    if (choice == 7 || choice == 8 || choice == 9)
    {

        if (choice == 8)
            delay_move(wait, 0);
        if (choice == 7 || choice == 9)
            delay_move(wait, 1);
        print_front(n, src, dst, choice);
        sernum(choice);
        print_back(choice);
        line_move(n, src, tmp, dst, choice, 1);
        row_move(n, src, tmp, dst, choice);
        line_move(n, src, tmp, dst, choice, 0);
    }
}
//唯一递归
void hanoi(int n, char src, char tmp, char dst, int choice)
{
    if (n == 1)
        move_1(n, src, tmp, dst, choice);
    else
    {
        hanoi(n - 1, src, dst, tmp, choice);
        if (choice != 7)
        {
            move_1(n, src, tmp, dst, choice);
            hanoi(n - 1, tmp, src, dst, choice);
        }
        else
            return;
    }
}
//输入
void input_data(int* n, char* src, char* tmp, char* dst, char choice)
{
    while (1)
    {
        cout << "请输入汉诺塔的层数(1-10)" << endl;
        cin >> *n;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        else if (*n >= 1 && *n <= 10)
            break;
        else if (*n < 1 || *n > 10)
            continue;
    }
    while (1)
    {
        cout << "请输入起始柱(A-C)" << endl;
        cin >> *src;
        if (*src == 'a' || *src == 'b' || *src == 'c')
            *src = *src - 32;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        else if ((*src == 'A') || (*src == 'B') || (*src == 'C'))
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
        cout << "请输入目标柱(A-C)" << endl;
        cin >> *dst;
        if (*dst == 'a' || *dst == 'b' || *dst == 'c')
            *dst = *dst - 32;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        else if ((*dst == 'A') || (*dst == 'B') || (*dst == 'C'))
        {
            if (*src == *dst)
            {
                if (*dst == 'A')
                    cout << "目标柱(A)不能与起始柱(A)相同" << endl;
                else if (*dst == 'B')
                    cout << "目标柱(B)不能与起始柱(B)相同" << endl;
                else if (*dst == 'C')
                    cout << "目标柱(C)不能与起始柱(C)相同" << endl;
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
    *tmp = 3 * 'B' - *dst - *src;
    if (choice == 4 || choice == 8)
    {
        while (1)
        {
            cout << "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短) ";
            cin >> wait;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(1024, '\n');
                continue;
            }
            else if (wait >= 0 && wait <= 5)
                break;
            else if (wait < 0 || wait > 5)
                continue;
        }
    }
    set(n, src);
}
//模式4
void mode_4(int n, char src, char tmp, char dst, int choice)
{
    cct_cls();
    cct_setcursor(3);
    cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层，延时设置为 " << wait << endl;
    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
    cout << "         =========================" << endl;
    cout << "           A         B         C" << endl;
    cout << endl << endl << endl;
    cout << "初始:";
    sernum(choice);
    print_back(choice);
    hanoi(n, src, tmp, dst, choice);
    char ch;
    ch = getchar();
    for (int i = 0; i < 20; i++)
        cout << endl;
}
//画塔
void draw_tower(int n, char src)
{
    cct_showch(1, 15, ' ', COLOR_HYELLOW, COLOR_HYELLOW, 23);
    cct_showch(33, 15, ' ', COLOR_HYELLOW, COLOR_HYELLOW, 23);
    cct_showch(65, 15, ' ', COLOR_HYELLOW, COLOR_HYELLOW, 23);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 14; j >= 3; j--)
        {
            cct_showch(i * 32 + 12, j, ' ', COLOR_HYELLOW, COLOR_HYELLOW, 1);
            Sleep(20);
        }
    }
}
//画盘
void draw_init_plate(int n, char src)
{
    for (int i = n; i >= 1; i--)
    {
        Sleep(30);
        cct_showch((src - 'A') * 32 + 12 - i, 14 - n + i, ' ', i, i, 2 * i + 1);
    }
}
//模式9前序
void mode_9_front(int n, char src, char tmp, char dst, int choice)
{
    cct_cls();
    cct_setcursor(3);
    cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层，延时设置为 " << wait << endl;
    draw_tower(n, src);
    draw_init_plate(n, src);
    Sleep(500);
    cct_setcolor(0, 7);
    cct_gotoxy(0, 27);
    cout << "         =========================" << endl;
    cout << "           A         B         C" << endl;
    cct_gotoxy(0, 32);
    cout << "初始:";
    sernum(choice);
    print_back(choice);
    cct_gotoxy(0, 37);
    cct_setcolor(0, 7);
}
//运行各个功能
void show(int choice)
{
    int n = 0;
    char src = '0', tmp = '0', dst = '0';
    init_all();
    if (choice == 0)
    {
        for (int i = 1; i < 23; i++)
            cout << endl;
        return;
    }
    if (choice == 5)
    {
        cct_cls();
        draw_tower(n, src);
        cct_gotoxy(0, 37);
        cct_setcolor(0, 7);
    }
    if (choice != 5)
    {
        if (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 6 && choice != 7 && choice != 8 && choice != 9)
            return;
        input_data(&n, &src, &tmp, &dst, choice);
        if (choice == 1 || choice == 2 || choice == 3)
            hanoi(n, src, tmp, dst, choice);
        if (choice == 4)
            mode_4(n, src, tmp, dst, choice);
        if (choice == 6)
        {
            cct_cls();
            cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层" << endl;
            draw_tower(n, src);
            draw_init_plate(n, src);
            cct_gotoxy(0, 37);
            cct_setcolor(0, 7);
        }
        if (choice == 7 || choice == 8)
        {
            cct_cls();
            cct_setcursor(3);
            if (choice == 7)
            {
                cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层" << endl;
            }
            else
            {
                cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层，延时设置为 " << wait << endl;
            }
            draw_tower(n, src);
            draw_init_plate(n, src);
            Sleep(500);
            if (choice == 8)
            {
                cct_setcolor(0, 7);
                cct_gotoxy(0, 27);
                cout << "         =========================" << endl;
                cout << "           A         B         C" << endl;
                cct_gotoxy(0, 32);
                cout << "初始:";
                sernum(choice);
                print_back(choice);
            }
            hanoi(n, src, tmp, dst, choice);
            cct_gotoxy(0, 37);
            cct_setcolor(0, 7);
        }
        if (choice == 9)
        {
            mode_9_front(n, src, tmp, dst, choice);
            wait = 4;
            while (1)
            {
                int i = 0;
                char hjw_memory[20] = { '\0' };
                for (int j = 0; j < 20; j++)
                    hjw_memory[i] = '\0';
                cct_gotoxy(0, 34);
                cct_setcolor(0, 7);
                cct_setcursor(2);
                cout << "请输入移动的柱号(命令形式：AC=A顶端的盘子移动到C，Q=退出) ：                    ";
                cout << "                                      ";
                int last_plate = INT_MAX;
                int ready_togo_plate = INT_MAX;
                cct_gotoxy(60, 34);
                for (; i < 20; i++)
                {
                    hjw_memory[i] = _getche();
                    if (hjw_memory[i] >= 'a' && hjw_memory[i] <= 'c')
                        hjw_memory[i] -= 32;
                    if (hjw_memory[i] == '\r')
                        break;
                    if (hjw_memory[i] == '\b')
                    {
                        cct_gotoxy(60 + i, 34);
                        i--;
                        continue;
                    }
                    if (i == 19)
                    {
                        cct_gotoxy(60, 34);
                        break;
                    }
                }
                if (i == 19 || hjw_memory[3] != '\0' || hjw_memory[0] == hjw_memory[1])
                    continue;
                if (hjw_memory[0] == 'q' || hjw_memory[0] == 'Q')
                {
                    cct_gotoxy(0, 35);
                    cout << "游戏中止!!!!!" << endl << endl;
                    break;
                }
                if (hjw_memory[0] >= 'A' && hjw_memory[0] <= 'C' && hjw_memory[1] >= 'A' && hjw_memory[1] <= 'C')
                {

                    if (hjw_memory[0] == 'A' && a > 0)
                        last_plate = numA[a - 1];
                    else if (hjw_memory[0] == 'B' && b > 0)
                        last_plate = numB[b - 1];
                    else if (hjw_memory[0] == 'C' && c > 0)
                        last_plate = numC[c - 1];
                    else
                    {
                        cct_gotoxy(0, 35);
                        cct_setcolor(0, 7);
                        cout << "非法移动！起始柱为空!";
                        Sleep(2000);
                        cct_gotoxy(0, 35);
                        cout << "                              ";
                        continue;
                    }
                    if (hjw_memory[1] == 'A' && a > 0)
                        ready_togo_plate = numA[a - 1];
                    if (hjw_memory[1] == 'B' && b > 0)
                        ready_togo_plate = numB[b - 1];
                    if (hjw_memory[1] == 'C' && c > 0)
                        ready_togo_plate = numC[c - 1];
                    if (ready_togo_plate < last_plate)
                    {
                        cct_gotoxy(0, 35);
                        cct_setcolor(0, 7);
                        cout << "非法移动！大盘压小盘!";
                        Sleep(2000);
                        cct_gotoxy(0, 35);
                        cout << "                              ";
                        continue;
                    }
                    else
                    {
                        cct_gotoxy(0, 32);
                        cct_setcolor(0, 7);
                        move_1(last_plate, hjw_memory[0], tmp, hjw_memory[1], choice);
                        cct_setcolor(0, 7);
                        if ((a == 0 && b == 0 && c != 0 && (dst == 'C')) || (a == 0 && c == 0 && b != 0 && (dst == 'B') || (a != 0 && b == 0 && c == 0) && (dst == 'A')))
                        {
                            cct_gotoxy(0, 35);
                            cout << "游戏结束!!!" << endl;
                            break;
                        }
                    }
                }
            }
        }
    }
}
