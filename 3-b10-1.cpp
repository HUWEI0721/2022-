/* ��� 2153393 ������*/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <windows.h> //ȡϵͳʱ��
using namespace std;

int main()
{
    LARGE_INTEGER tick, begin, end;

    QueryPerformanceFrequency(&tick);	//��ü�����Ƶ��
    QueryPerformanceCounter(&begin);	//��ó�ʼӲ������������

    /* �˴�����ĳ���ʼ */
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
    /* �˴�����ĳ������ */

    QueryPerformanceCounter(&end);		//�����ֹӲ������������

    cout << "������Ƶ�� : " << tick.QuadPart << "Hz" << endl;
    cout << "���������� : " << end.QuadPart - begin.QuadPart << endl;
    cout << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "��" << endl;

    return 0;
}
