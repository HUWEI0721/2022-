/*2153393 ��� ������*/
#include <iostream>
using namespace std;
int main()
{
	double n;
	int m;
	int a, b, c, d, e, f, g, h, i, j, k, l;
	cout << "������[0-100��)֮�������:" << endl;
	cin >> n;
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
	//ʮ��-��λ
	switch (a)
	{
		case 9:
			cout << "��ʰ";
			break;
		case 8:
			cout << "��ʰ";
			break;
		case 7:
			cout << "��ʰ";
			break;
		case 6:
			cout << "½ʰ";
			break;
		case 5:
			cout << "��ʰ";
			break;
		case 4:
			cout << "��ʰ";
			break;
		case 3:
			cout << "��ʰ";
			break;
		case 2:
			cout << "��ʰ";
			break;
		case 1:
			cout << "Ҽʰ";
			break;
		case 0:
			break;
	}
	switch (b)
	{
		case 9:
			cout << "����";
			break;
		case 8:
			cout << "����";
			break;
		case 7:
			cout << "����";
			break;
		case 6:
			cout << "½��";
			break;
		case 5:
			cout << "����";
			break;
		case 4:
			cout << "����";
			break;
		case 3:
			cout << "����";
			break;
		case 2:
			cout << "����";
			break;
		case 1:
			cout << "Ҽ��";
			break;
		case 0:
			if (a != 0)
				cout << "��";
			else
				break;
			break;
	}
	//ǧ��-��λ
	switch (c)
	{
		case 9:
			cout << "��Ǫ";
			break;
		case 8:
			cout << "��Ǫ";
			break;
		case 7:
			cout << "��Ǫ";
			break;
		case 6:
			cout << "½Ǫ";
			break;
		case 5:
			cout << "��Ǫ";
			break;
		case 4:
			cout << "��Ǫ";
			break;
		case 3:
			cout << "��Ǫ";
			break;
		case 2:
			cout << "��Ǫ";
			break;
		case 1:
			cout << "ҼǪ";
			break;
		case 0:
			if (b == 0)
				break;
			else if (b != 0)
			{
				if ((d == 0) && (e == 0) && (f == 0))
					break;
				else
					cout << "��";
			}
			break;
	}
	switch (d)
	{
		case 9:
			cout << "����";
			break;
		case 8:
			cout << "�ư�";
			break;
		case 7:
			cout << "���";
			break;
		case 6:
			cout << "½��";
			break;
		case 5:
			cout << "���";
			break;
		case 4:
			cout << "����";
			break;
		case 3:
			cout << "����";
			break;
		case 2:
			cout << "����";
			break;
		case 1:
			cout << "Ҽ��";
			break;
		case 0:
			if (c == 0)
				break;
			else if (c != 0)
			{
				if ((e == 0) && (f == 0))
					break;
				else
					cout << "��";
			}
			break;
	}
	switch (e)
	{
		case 9:
			cout << "��ʰ";
			break;
		case 8:
			cout << "��ʰ";
			break;
		case 7:
			cout << "��ʰ";
			break;
		case 6:
			cout << "½ʰ";
			break;
		case 5:
			cout << "��ʰ";
			break;
		case 4:
			cout << "��ʰ";
			break;
		case 3:
			cout << "��ʰ";
			break;
		case 2:
			cout << "��ʰ";
			break;
		case 1:
			cout << "Ҽʰ";
			break;
		case 0:
			if (d == 0)
				break;
			else if (d != 0)
			{
				if (f == 0)
					break;
				else
					cout << "��";
			}
			break;
	}
	switch (f)
	{
		case 9:
			cout << "����";
			break;
		case 8:
			cout << "����";
			break;
		case 7:
			cout << "����";
			break;
		case 6:
			cout << "½��";
			break;
		case 5:
			cout << "����";
			break;
		case 4:
			cout << "����";
			break;
		case 3:
			cout << "����";
			break;
		case 2:
			cout << "����";
			break;
		case 1:
			cout << "Ҽ��";
			break;
		case 0:
			if ((c == 0) && (d == 0) && (e == 0))
				break;
			else
				cout << "��";
			break;
	}
	//ǧλ-��λ
	switch (g)
	{
		case 9:
			cout << "��Ǫ";
			break;
		case 8:
			cout << "��Ǫ";
			break;
		case 7:
			cout << "��Ǫ";
			break;
		case 6:
			cout << "½Ǫ";
			break;
		case 5:
			cout << "��Ǫ";
			break;
		case 4:
			cout << "��Ǫ";
			break;
		case 3:
			cout << "��Ǫ";
			break;
		case 2:
			cout << "��Ǫ";
			break;
		case 1:
			cout << "ҼǪ";
			break;
		case 0:
			if (f == 0)
			{
				if ((h != 0) || (i != 0) || (j != 0))
				{
					if ((a != 0) || (b != 0) || (c != 0) || (d != 0) || (e != 0) || (f != 0))
					{
						cout << "��";
						break;
					}
					else
						break;
				}
				else
					break;
			}
				
			else if (f != 0)
			{
				if ((h == 0) && (i == 0) && (j == 0))
					break;
				else
					cout << "��";
			}
			break;
	}
	switch (h)
	{
		case 9:
			cout << "����";
			break;
		case 8:
			cout << "�ư�";
			break;
		case 7:
			cout << "���";
			break;
		case 6:
			cout << "½��";
			break;
		case 5:
			cout << "���";
			break;
		case 4:
			cout << "����";
			break;
		case 3:
			cout << "����";
			break;
		case 2:
			cout << "����";
			break;
		case 1:
			cout << "Ҽ��";
			break;
		case 0:
			if (g == 0)
				break;
			else if (g != 0)
			{
				if ((i == 0) && (j == 0))
					break;
				else
					cout << "��";
			}
			break;
	}
	switch (i)
	{
		case 9:
			cout << "��ʰ";
			break;
		case 8:
			cout << "��ʰ";
			break;
		case 7:
			cout << "��ʰ";
			break;
		case 6:
			cout << "½ʰ";
			break;
		case 5:
			cout << "��ʰ";
			break;
		case 4:
			cout << "��ʰ";
			break;
		case 3:
			cout << "��ʰ";
			break;
		case 2:
			cout << "��ʰ";
			break;
		case 1:
			cout << "Ҽʰ";
			break;
		case 0:
			if (h == 0)
				break;
			else if (h != 0)
			{
				if (j == 0)
					break;
				else
					cout << "��";
			}
			break;
	}
	switch (j)
	{
		case 9:
			cout << "��Բ";
			break;
		case 8:
			cout << "��Բ";
			break;
		case 7:
			cout << "��Բ";
			break;
		case 6:
			cout << "½Բ";
			break;
		case 5:
			cout << "��Բ";
			break;
		case 4:
			cout << "��Բ";
			break;
		case 3:
			cout << "��Բ";
			break;
		case 2:
			cout << "��Բ";
			break;
		case 1:
			cout << "ҼԲ";
			break;
		case 0:
			if ((a == 0) && (b == 0) && (c == 0) && (d == 0) && (e == 0) && (f == 0)
				&& (g == 0) && (h == 0) && (i == 0) && (k == 0) && (l == 0))
				cout << "��Բ";
			else if ((a == 0) && (b == 0) && (c == 0) && (d == 0) && (e == 0)
				      && (f == 0)&& (g == 0) && (h == 0) && (i == 0))
				break;
			else	
				cout << "Բ";
			    break;
	}
	//��-��
	if ((k == 0) && (l == 0))
		cout << "��";
	else if ((k != 0) && (l == 0))
	{
		switch (k)
		{
			case 9:
				cout << "����";
				break;
			case 8:
				cout << "�ƽ�";
				break;
			case 7:
				cout << "���";
				break;
			case 6:
				cout << "½��";
				break;
			case 5:
				cout << "���";
				break;
			case 4:
				cout << "����";
				break;
			case 3:
				cout << "����";
				break;
			case 2:
				cout << "����";
				break;
			case 1:
				cout << "Ҽ��";
				break;
		}
		cout << "��";
	}
	else if ((k == 0) && (l != 0))
	{
		if ((a != 0) || (b != 0) || (c != 0) || (d != 0) || (e != 0) || (f != 0) || (g != 0) || (h != 0) || (i != 0) || (j != 0))
			cout << "��";
		switch (l)
		{
			case 9:
				cout << "����";
				break;
			case 8:
				cout << "�Ʒ�";
				break;
			case 7:
				cout << "���";
				break;
			case 6:
				cout << "½��";
				break;
			case 5:
				cout << "���";
				break;
			case 4:
				cout << "����";
				break;
			case 3:
				cout << "����";
				break;
			case 2:
				cout << "����";
				break;
			case 1:
				cout << "Ҽ��";
				break;
		}
	}
	else if ((k != 0) && (l != 0))
	{
		switch (k)
		{
			case 9:
				cout << "����";
				break;
			case 8:
				cout << "�ƽ�";
				break;
			case 7:
				cout << "���";
				break;
			case 6:
				cout << "½��";
				break;
			case 5:
				cout << "���";
				break;
			case 4:
				cout << "����";
				break;
			case 3:
				cout << "����";
				break;
			case 2:
				cout << "����";
				break;
			case 1:
				cout << "Ҽ��";
				break;
		}
		switch (l)
		{
			case 9:
				cout << "����";
				break;
			case 8:
				cout << "�Ʒ�";
				break;
			case 7:
				cout << "���";
				break;
			case 6:
				cout << "½��";
				break;
			case 5:
				cout << "���";
				break;
			case 4:
				cout << "����";
				break;
			case 3:
				cout << "����";
				break;
			case 2:
				cout << "����";
				break;
			case 1:
				cout << "Ҽ��";
				break;
		}
	}
	cout << endl;
	return 0;
}