/*2153393 软件 胡峻玮*/
#include <iostream>
#include <iomanip>
using namespace std;
int zeller(int y, int m, int d)
{
    int w = 0, c = 0, nian = 0, yue = 0;
    if ((m == 1 || m == 2) && (y != 2000))
    {
        c = y / 100;
        yue = m + 12;
        nian = y - c * 100 - 1;
    }
    else if ((m == 1 || m == 2) && (y == 2000))
    {
        c = (y - 1) / 100;
        yue = m + 12;
        nian = y - ((y - 1) / 100) * 100 - 1;
    }
    else
    {
        c = y / 100;
        yue = m;
        nian = y - c * 100;
    }
    w = ((nian + nian / 4 + c / 4 - 2 * c + (13 * (yue + 1) / 5) + d - 1) + 700) % 7;
    return w;
}
void print(int month[], int first[], int k)
{
    for (int i = 1; i < 8; i++)
    {
        cout << setiosflags(ios::left);
        if (i - 1 < first[k])
            cout << setw(4) << " ";
        else
        {
            for (int j = 1; j <= 7 - first[k]; j++)
                cout << setw(4) << j;
            first[k] = 7 - first[k] + 1;
            break;
        }
    }
    cout << "    ";
    for (int i = 1; i < 8; i++)
    {
        if (i - 1 < first[k + 1])
            cout << setw(4) << " ";
        else
        {
            for (int j = 1; j <= 7 - first[k + 1]; j++)
                cout << setw(4) << j;
            first[k + 1] = 7 - first[k + 1] + 1;
            break;
        }
    }
    cout << "    ";
    for (int i = 1; i < 8; i++)
    {
        if (i - 1 < first[k + 2])
            cout << setw(4) << " ";
        else
        {
            for (int j = 1; j <= 7 - first[k + 2]; j++)
                cout << setw(4) << j;
            first[k + 2] = 7 - first[k + 2] + 1;
            break;
        }
    }
    cout << endl;
    for (int i = 0; i < 63; i++)
    {
        if (i % 21 < 7)
        {
            cout << setw(4) << first[k];
            first[k]++;
        }
        if (i % 21 == 7)
            cout << "    ";
        if (i % 21 >= 7 && i % 21 < 14)
        {
            cout << setw(4) << first[k + 1];
            first[k + 1]++;
        }
        if (i % 21 == 14)
            cout << "    ";
        if (i % 21 >= 14)
        {
            cout << setw(4) << first[k + 2];
            first[k + 2]++;
        }
        if ((i + 1) % 21 == 0)
            cout << endl;
    }
    while (month[k] - first[k] >= 0 || month[k + 1] - first[k + 1] >= 0 || month[k + 2] - first[k + 2] >= 0)
    {
        for (int i = 1; i < 8; i++)
        {
            if (month[k] < first[k])
                cout << setw(4) << " ";
            else
            {
                cout << setw(4) << first[k];
                first[k]++;
            }
        }
        cout << "    ";
        for (int i = 1; i < 8; i++)
        {
            if (month[k + 1] < first[k + 1])
                cout << setw(4) << " ";
            else
            {
                cout << setw(4) << first[k + 1];
                first[k + 1]++;
            }
        }
        cout << "    ";
        for (int i = 1; i < 8; i++)
        {
            if (month[k + 2] < first[k + 2])
                cout << setw(4) << " ";
            else
            {
                cout << setw(4) << first[k + 2];
                first[k + 2]++;
            }
        }
        cout << endl;
    }
}
int main()
{
    int year;
    int month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    int first[13] = { 1 };
    while (1)
    {
        cout << "请输入年份[1900-2100]" << endl;
        cin >> year;
        if (cin.fail() || year > 2100 || year < 1900)
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        else
        {
            cin.clear();
            cin.ignore(1024, '\n');
            break;
        }
    }
    cout << year << "年的日历:" << endl;
    cout << endl;
    for (int i = 1; i < 13; i++)
        first[i] = zeller(year, i, 1);
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        month[2] = 29;
    for (int i = 0; i < 4; i++)
    {
        cout << setiosflags(ios::right);
        cout << setw(13) << i * 3 + 1 << "月" << setw(30) << i * 3 + 2 << "月" << setw(30) << i * 3 + 3 << "月" << endl;
        cout << "Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat" << endl;
        cout << resetiosflags(ios::right);
        print(month, first, 3 * i + 1);
        cout << endl;
    }
    cout << endl;
    return 0;
}