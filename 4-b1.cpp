/* 2153393 ������ ��� */
#include <iostream>
using namespace std;

/* �ɸ�����Ҫ�����Ӧ������ */

/***************************************************************************
  �������ƣ�
  ��    �ܣ������д��0~9
  ���������
  �� �� ֵ��
  ˵    �������������⣬�������κκ�����������㡱-������!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	/* ������Ա��������κ��޸� */
	switch (num) {
		case 0:
			if (flag_of_zero)	//�˱��ʲô��˼������˼��
				cout << "��";
			break;
		case 1:
			cout << "Ҽ";
			break;
		case 2:
			cout << "��";
			break;
		case 3:
			cout << "��";
			break;
		case 4:
			cout << "��";
			break;
		case 5:
			cout << "��";
			break;
		case 6:
			cout << "½";
			break;
		case 7:
			cout << "��";
			break;
		case 8:
			cout << "��";
			break;
		case 9:
			cout << "��";
			break;
		default:
			cout << "error";
			break;
	}
}

/* �ɸ�����Ҫ�Զ�����������(Ҳ���Բ�����) */

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
	double n;
	int m;//Ϊ�˼���Բ�Ƿֲ���
	int a, b, c, d, e, f, g, h, i, j, k, l;//��¼��λ����
	int o = 0;//o��ֵΪ0����λǰ�����֣�o��ֵΪ1����λǰ������
	while (1) {
		cout << "������[0-100��)֮�������:" << endl;
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
	cout << "��д�����:" << endl;
	if (a)
	{
		daxie(a, 0);
		cout << "ʰ";
		o = 1;
	}
	if (b)
	{
		daxie(b, 0);
		o = 1;
	}
	if (o)
		cout << "��";
	if (c)
	{
		daxie(c, 0);
		cout << "Ǫ";
		o = 1;
	}
	if (d)
	{
		if ((!c) && (o == 1))
			daxie(c, 1);
		daxie(d, 0);
		cout << "��";
		o = 1;
	}
	if (e)
	{
		if ((!d) && (o == 1))
			daxie(d, 1);
		daxie(e, 0);
		cout << "ʰ";
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
		cout << "��";
	if (g)
	{
		daxie(g, 0);
		cout << "Ǫ";
		o = 1;
	}
	if (h)
	{
		if ((!g) && (o == 1))
			daxie(g, 1);
		daxie(h, 0);
		cout << "��";
		o = 1;
	}
	if (i)
	{
		if ((!h) && (o == 1))
			daxie(h, 1);
		daxie(i, 0);
		cout << "ʰ";
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
		cout << "Բ";

	if (k)
	{
		daxie(k, 0);
		cout << "��";
		o = 1;
	}
	if (l)
	{
		if ((!k) && (o == 1))
			daxie(k, 1);
		daxie(l, 0);
		cout << "��";
		o = 1;
	}
	else
	{
		if (!o)
		{
			daxie(o, 1);
			cout << "Բ";
		}
		cout << "��";
	}
	cout << endl;
	return 0;
}