/*2153393 软件 胡峻玮*/
#include <iostream>
using namespace std;
int main()
{
    double money;
    int a, b, c, d, e, f, g, h, i, j, m;
    int sum;
    cout << "请输入找零值：" << endl;
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
    cout << "共" << sum << "张找零，具体如下：" << endl;
    if (a != 0)
        cout << "50元 : " << a << "张" << endl;
    if (b != 0)
        cout << "20元 : " << b << "张" << endl;
    if (c != 0)
        cout << "10元 : " << c << "张" << endl;
    if (d != 0)
        cout << "5元  : " << d << "张" << endl;
    if (e != 0)
        cout << "1元  : " << e << "张" << endl;
    if (f != 0)
        cout << "5角  : " << f << "张" << endl;
    if (g != 0)
        cout << "1角  : " << g << "张" << endl;
    if (h != 0)
        cout << "5分  : " << h << "张" << endl;
    if (i != 0)
        cout << "2分  : " << i << "张" << endl;
    if (j != 0)
        cout << "1分  : " << j << "张" << endl;
    return 0;
}