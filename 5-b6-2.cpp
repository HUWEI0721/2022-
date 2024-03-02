/*2153393 胡峻玮 软件*/
#include <iostream>
#include <iomanip>
using namespace std;
int num = 0;
int arr[3][10] = { { 0 },{ 0 },{ 0 } };
int stick[] = { 0,0,0 };
void in(char k, int j)
{
    if (k == 'A')
        arr[0][stick[0]++] = j;
    if (k == 'B')
        arr[1][stick[1]++] = j;
    if (k == 'C')
        arr[2][stick[2]++] = j;
}
int out(char k)
{
    int temp = 0;
    if (k == 'A') 
    {
        temp = arr[0][--stick[0]];
        arr[0][stick[0]] = 0;
    }
    if (k == 'B') 
    {
        temp = arr[1][--stick[1]];
        arr[1][stick[1]] = 0;
    }
    if (k == 'C') 
    {
        temp = arr[2][--stick[2]];
        arr[2][stick[2]] = 0;
    }
    return temp;
}
void sernum()
{
    cout << " A:";
    for (int i = 0; i < 10; i++) 
    {
        if (arr[0][i] == 10)
            cout << 10;
        if (arr[0][i] < 10 && arr[0][i]>0)
            cout << " " << arr[0][i];
        if (arr[0][i] == 0)
            cout << "  ";
    }
    cout << " ";


    cout << "B:";
    for (int i = 0; i < 10; i++) {
        if (arr[1][i] == 10)
            cout << 10;
        if (arr[1][i] < 10 && arr[1][i]>0)
            cout << " " << arr[1][i];
        if (arr[1][i] == 0)
            cout << "  ";
    }
    cout << " ";


    cout << "C:";
    for (int i = 0; i < 10; i++) {
        if (arr[2][i] == 10)
            cout << 10;
        if (arr[2][i] < 10 && arr[2][i]>0)
            cout << " " << arr[2][i];
        if (arr[2][i] == 0)
            cout << "  ";
    }
    cout << endl;
}
void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 1) 
    {
        num++;
        cout << "第"<< setw(4) << num << " 步(" << " 1):" << " " << src << "-->" << dst;
        in(dst, out(src));
        sernum();
    }
    else if (n == 2) 
    {
        num++;
        cout << "第"<< setw(4) << num << " 步(" << " 1):" << " " << src << "-->" << tmp;
        in(tmp, out(src));
        sernum();

        num++;
        cout << "第"<< setw(4) << num << " 步(" << " 2):" << " " << src << "-->" << dst;
        in(dst, out(src));
        sernum();

        num++;
        cout << "第"<< setw(4) << num << " 步(" << " 1):" << " " << tmp << "-->" << dst;
        in(dst, out(tmp));
        sernum();
    }
    else 
    {
        hanoi(n - 1, src, dst, tmp);
        num++;
        cout << "第"<< setw(4) << num << " 步(";
        if (n < 10) 
            cout << " ";
        cout << n << "): " << src << "-->" << dst;
        in(dst, out(src));
        sernum();
        hanoi(n - 1, tmp, src, dst);
    }
}
int main()
{
    int n;
    while (1)
    {
        cout << "请输入汉诺塔的层数(1-10)" << endl;
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
        cout << "请输入起始柱(A-C)" << endl;
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
        cout << "请输入目标柱(A-C)" << endl;
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
                    cout << "目标柱(A)不能与起始柱(A)相同" << endl;
                else if ((dst == 'b') || (dst == 'B'))
                    cout << "目标柱(B)不能与起始柱(B)相同" << endl;
                else if ((dst == 'c') || (dst == 'C'))
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
        {
            arr[0][i] = n - i;
        }
        stick[0] = n;
    }
    if (src == 'B')
    {
        for (int i = 0; i < n; i++) 
        {
            arr[1][i] = n - i;
        }
        stick[1] = n;
    }
    if (src == 'C') 
    {
        for (int i = 0; i < n; i++) 
        {
            arr[2][i] = n - i;
        }
        stick[2] = n;
    }
    cout << "初始:               ";
    sernum();
    hanoi(n, src, tmp, dst);
}