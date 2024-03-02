/* 2153393 胡峻玮 软件 */
#include <iostream>
using namespace std;

/* 1、不允许定义任何类型的全局变量，包括常变量及宏定义等
   2、不允许给出任何形式的全局函数
*/

/* --- 将类的定义补充完整 --- */
class Days {
private:
	int year;
	int month;
	int day;
	//除上面的三个private数据成员外，不再允许添加任何类型的数据成员

	/* 下面可以补充需要的类成员函数的定义（不提供给外界，仅供本类的其它成员函数调用，因此声明为私有，数量不限，允许不定义） */
	bool leap_year();
public:
	int calc_days();     //计算是当年的第几天

	/* 下面可以补充其它需要的类成员函数的定义(体外实现)，数量不限，允许不定义 */
	Days(int y, int m, int d);
};

/* --- 此处给出类成员函数的体外实现 --- */
Days::Days(int y = 0, int m = 0, int d = 0) :year(y), month(m), day(d)
{

}
bool Days::leap_year()
{
	if ((year % 100 != 0 && year % 4 == 0) || (year % 400 == 0))
		return true;
	else
		return false;
}
int Days::calc_days()
{
	int day_count[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int sum = 0;
	bool tag = leap_year();
	if (tag == 1)
		day_count[2] = 29;
	if (day > day_count[month])
		return -1;
	for (int i = 1; i < month; i++)
		sum += day_count[i];
	sum += day;
	return sum;
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数不准动
 ***************************************************************************/
int main()
{
	if (1) {
		Days d1(2020, 3, 18);
		cout << "应该输出78， 实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2023, 3, 18);
		cout << "应该输出77， 实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2020, 12, 31);
		cout << "应该输出366，实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2023, 12, 31);
		cout << "应该输出365，实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2020, 2, 29);
		cout << "应该输出60， 实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2023, 2, 29);
		cout << "应该输出-1， 实际是：" << d1.calc_days() << endl;
	}

	return 0;
}