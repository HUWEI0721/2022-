/* 软件 2153393 胡峻玮*/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <windows.h> //取系统时间
using namespace std;

int main()
{
    LARGE_INTEGER tick, begin, end;

    QueryPerformanceFrequency(&tick);	//获得计数器频率
    QueryPerformanceCounter(&begin);	//获得初始硬件计数器计数

    /* 此处是你的程序开始 */
    int a, b, c, n = 0, i;
    int sum = 0;
    bool g1, g2, g3, g4, g5, g6, g7, g8, g9;
    for (a = 123; a < 599; a++)
    {
        for (b = 512; b < 877; b++)
        {        
            if (a > b)
            continue;
            for (c = 712; c < 988; c++)
            {
                if ((a < b) && (b < c))
                {
                    g1 = g2 = g3 = g4 = g5 = g6 = g7 = g8 = g9 = 0;
                    sum = a * 1000000 + b * 1000 + c;
                    for (i = 0; i < 9; i++)
                    {
                        switch (sum % 10)
                        {
                            case 1:
                                g1 = 1;
                                break;
                            case 2:
                                g2 = 1;
                                break;
                            case 3:
                                g3 = 1;
                                break;
                            case 4:
                                g4 = 1;
                                break;
                            case 5:
                                g5 = 1;
                                break;
                            case 6:
                                g6 = 1;
                                break;
                            case 7:
                                g7 = 1;
                                break;
                            case 8:
                                g8 = 1;
                                break;
                            case 9:
                                g9 = 1;
                                break;
                            default:
                                break;
                        }
                        sum = sum / 10;
                        if (g1 && g2 && g3 && g4 && g5 && g6 && g7 && g8 && g9 && (a + b + c == 1953))
                        {
                            n += 1;
                            cout << "No." << setw(3) << n << " : " << a << "+" << b << "+" << c << "=1953" << endl;
                        }
                    }
                }
                else
                    continue;
            }
        }
    }
    cout << "total=" << n << endl;
    /* 此处是你的程序结束 */

    QueryPerformanceCounter(&end);		//获得终止硬件计数器计数

    cout << "计数器频率 : " << tick.QuadPart << "Hz" << endl;
    cout << "计数器计数 : " << end.QuadPart - begin.QuadPart << endl;
    cout << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "秒" << endl;

    return 0;
}
