/*2153393 ��� ������*/
#include <iostream>
using namespace std;
int main()
{
    double money;
    int a, b, c, d, e, f, g, h, i, j, m;
    int sum;
    cout << "����������ֵ��" << endl;
    cin >> money;
    m = (int)(money * 100+0.001);
    a = m / 5000;
    b = (m - a * 5000) / 2000;
    c = (m - a * 5000 - b * 2000) / 1000;
    d = (m - a * 5000 - b * 2000 - c * 1000) / 500;
    e = (m - a * 5000 - b * 2000 - c * 1000 - d * 500) / 100;
    f = (m - a * 5000 - b * 2000 - c * 1000 - d * 500 - e * 100) / 50;
    g = (m - a * 5000 - b * 2000 - c * 1000 - d * 500 - e * 100 - f * 50) / 10;
    h = (m - a * 5000 - b * 2000 - c * 1000 - d * 500 - e * 100 - f * 50 - g * 10) / 5;
    i = (m - a * 5000 - b * 2000 - c * 1000 - d * 500 - e * 100 - f * 50 - g * 10 - h * 5) / 2;
    j = (m - a * 5000 - b * 2000 - c * 1000 - d * 500 - e * 100 - f * 50 - g * 10 - h * 5 - i * 2) / 1;
    sum = a + b + c + d + e + f + g + h + i + j;
    cout << "��" << sum << "�����㣬�������£�" << endl;
    if (a != 0)
        cout << "50Ԫ : " << a << "��" << endl;
    if (b != 0)
        cout << "20Ԫ : " << b << "��" << endl;
    if (c != 0)
        cout << "10Ԫ : " << c << "��" << endl;
    if (d != 0)
        cout << "5Ԫ  : " << d << "��" << endl;
    if (e != 0)
        cout << "1Ԫ  : " << e << "��" << endl;
    if (f != 0)
        cout << "5��  : " << f << "��" << endl;
    if (g != 0)
        cout << "1��  : " << g << "��" << endl;
    if (h != 0)
        cout << "5��  : " << h << "��" << endl;
    if (i != 0)
        cout << "2��  : " << i << "��" << endl;
    if (j != 0)
        cout << "1��  : " << j << "��" << endl;
    return 0;
}