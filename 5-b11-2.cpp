/* 软件 2153393 胡峻玮 */
#include <iostream>
#include <string>
//可按需增加需要的头文件
using namespace std;

const char chnstr[] = "零壹贰叁肆伍陆柒捌玖"; /* 所有输出大写 "零" ~ "玖" 的地方，只允许从这个数组中取值 */
string result;  /* 除result外，不再允许定义任何形式的全局变量 */

/* --允许添加需要的函数 --*/
void daxie(int num, int flag_of_zero)
{
	if (num == 0 && flag_of_zero) 
		result = result + chnstr[0] + chnstr[1];
	if (num != 0) 
		result = result + chnstr[num * 2] + chnstr[num * 2 + 1];
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
    /* --允许添加需要的内容 --*/
	const char end[] = "拾佰仟万亿圆角分整";
	double n;
    int otag = 0, fn_tag = 0, w_tag = 0;
    int m, sy, y, qw, bw, sw, w, q, b, s, yu, j, f;
    cout << "请输入[0-100亿)之间的数字:" << endl;
    cin >> n;
	n = n / 10;
	long zheng = (long)n;
	m = (int)((n - zheng + 0.0001) * 1000);
	sy = zheng / 100000000 % 10;
	y = zheng / 10000000 % 10;
	qw = zheng / 1000000 % 10;
	bw = zheng / 100000 % 10;
	sw = zheng / 10000 % 10;
	w = zheng / 1000 % 10;
	q = zheng / 100 % 10;
	b = zheng / 10 % 10;
	s = zheng / 1 % 10;
	yu = m / 100 % 10;
	j = m / 10 % 10;
	f = m / 1 % 10;
	cout << "大写结果是:" << endl;
	if (sy > 0)
	{
		fn_tag = 1;
		daxie(sy, 0);
		result = result + end[0] + end[1];
	}
	if (y > 0)
	{
		fn_tag = 1;
		daxie(y, 0);
	}
	if (fn_tag)
		result = result + end[8] + end[9];
	if (qw > 0)
	{
		fn_tag = 1;
		w_tag = 1;
		daxie(qw, 0);
		result = result + end[4] + end[5];
	}
	else
		otag = 1;
	if (bw > 0)
	{
		if (fn_tag && otag)
			daxie(0, fn_tag && otag);
		fn_tag = 1;
		otag = 0;
		w_tag = 1;
		daxie(bw, 0);
		result = result + end[2] + end[3];
	}
	else
		otag = 1;
	if (sw > 0)
	{
		if (fn_tag && otag)
			daxie(0, fn_tag && otag);
		fn_tag = 1;
		otag = 0;
		w_tag = 1;
		daxie(sw, 0);
		result = result + end[0] + end[1];
	}
	else
		otag = 1;
	if (w > 0)
	{
		if (fn_tag && otag)
			daxie(0, fn_tag && otag);
		fn_tag = 1;
		otag = 0;
		w_tag = 1;
		daxie(w, 0);
	}
	if (w_tag)
		result = result + end[6] + end[7];
	otag = 0;
	if (q > 0)
	{
		fn_tag = 1;
		otag = 0;
		daxie(q, 0);
		result = result + end[4] + end[5];
	}
	else
		otag = 1;
	if (b > 0)
	{
		if (fn_tag && otag)
			daxie(0, fn_tag && otag);
		fn_tag = 1;
		otag = 0;
		daxie(b, 0);
		result = result + end[2] + end[3];
	}
	else
		otag = 1;
	if (s > 0)
	{
		if (fn_tag && otag)
			daxie(0, fn_tag && otag);
		fn_tag = 1;
		otag = 0;
		daxie(s, 0);
		result = result + end[0] + end[1];
	}
	else
		otag = 1;
	if (yu > 0)
	{
		if (fn_tag && otag)
			daxie(0, fn_tag && otag);
		fn_tag = 1;
		otag = 0;
		daxie(yu, 0);
	}
	otag = 0;
	if (fn_tag)
		result = result + end[10] + end[11];
	if (!fn_tag && j == 0 && f == 0)
	{
		daxie(0, 1);
		result = result + end[10] + end[11];
	}
	if (j > 0)
	{
		daxie(j, 0);
		result = result + end[12] + end[13];
	}
	else
		otag = 1;
	if (f > 0)
	{
		if (fn_tag && otag)
			daxie(0, fn_tag && otag);
		daxie(f, 0);
		result = result + end[14] + end[15];
	}
	else
		result = result + end[16] + end[17];

    cout << result << endl;  /* 转换得到的大写结果，只允许用本语句输出，其它地方不允许以任何形式对大写结果进行全部/部分输出 */
    return 0;
}