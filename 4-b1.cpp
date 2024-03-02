/* 2153393 胡峻玮 软件 */
#include <iostream>
using namespace std;

/* 可根据需要添加相应的内容 */

/***************************************************************************
  函数名称：
  功    能：输出大写的0~9
  输入参数：
  返 回 值：
  说    明：除本函数外，不允许任何函数中输出“零”-“玖”!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	/* 不允许对本函数做任何修改 */
	switch (num) {
		case 0:
			if (flag_of_zero)	//此标记什么意思请自行思考
				cout << "零";
			break;
		case 1:
			cout << "壹";
			break;
		case 2:
			cout << "贰";
			break;
		case 3:
			cout << "叁";
			break;
		case 4:
			cout << "肆";
			break;
		case 5:
			cout << "伍";
			break;
		case 6:
			cout << "陆";
			break;
		case 7:
			cout << "柒";
			break;
		case 8:
			cout << "捌";
			break;
		case 9:
			cout << "玖";
			break;
		default:
			cout << "error";
			break;
	}
}

/* 可根据需要自定义其它函数(也可以不定义) */

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	double n;
	int m;//为了计算圆角分部分
	int a, b, c, d, e, f, g, h, i, j, k, l;//记录各位数字
	int o = 0;//o的值为0，该位前无数字；o的值为1，该位前有数字
	while (1) {
		cout << "请输入[0-100亿)之间的数字:" << endl;
		cin >> n;  
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		else if (n >= 0.0 && n < 1e10)
			break;
	}
	n = n / 10;
	long zheng = (long)n;
	m = (int)((n - zheng + 0.0001) * 1000);
	a = zheng / 100000000 % 10;
	b = zheng / 10000000 % 10;
	c = zheng / 1000000 % 10;
	d = zheng / 100000 % 10;
	e = zheng / 10000 % 10;
	f = zheng / 1000 % 10;
	g = zheng / 100 % 10;
	h = zheng / 10 % 10;
	i = zheng / 1 % 10;
	j = m / 100 % 10;
	k = m / 10 % 10;
	l = m / 1 % 10;
	cout << "大写结果是:" << endl;
	if (a)
	{
		daxie(a, 0);
		cout << "拾";
		o = 1;
	}
	if (b)
	{
		daxie(b, 0);
		o = 1;
	}
	if (o)
		cout << "亿";
	if (c)
	{
		daxie(c, 0);
		cout << "仟";
		o = 1;
	}
	if (d)
	{
		if ((!c) && (o == 1))
			daxie(c, 1);
		daxie(d, 0);
		cout << "佰";
		o = 1;
	}
	if (e)
	{
		if ((!d) && (o == 1))
			daxie(d, 1);
		daxie(e, 0);
		cout << "拾";
		o = 1;
	}
	if (f)
	{
		if ((!e) && (o == 1))
			daxie(e, 1);
		daxie(f, 0);
		o = 1;
	}
	if (c || d || e || f)
		cout << "万";
	if (g)
	{
		daxie(g, 0);
		cout << "仟";
		o = 1;
	}
	if (h)
	{
		if ((!g) && (o == 1))
			daxie(g, 1);
		daxie(h, 0);
		cout << "佰";
		o = 1;
	}
	if (i)
	{
		if ((!h) && (o == 1))
			daxie(h, 1);
		daxie(i, 0);
		cout << "拾";
		o = 1;
	}
	if (j)
	{
		if ((!i) && (o == 1))
			daxie(i, 1);
		daxie(j, 0);
		o = 1;
	}
	if (o==1) 
		cout << "圆";

	if (k)
	{
		daxie(k, 0);
		cout << "角";
		o = 1;
	}
	if (l)
	{
		if ((!k) && (o == 1))
			daxie(k, 1);
		daxie(l, 0);
		cout << "分";
		o = 1;
	}
	else
	{
		if (!o)
		{
			daxie(o, 1);
			cout << "圆";
		}
		cout << "整";
	}
	cout << endl;
	return 0;
}