/*2153393 Èí¼þ ºú¾þçâ*/
#include <iostream>
using namespace std;
int main()
{
	double n;
	int m;
	int a, b, c, d, e, f, g, h, i, j, k, l;
	cout << "ÇëÊäÈë[0-100ÒÚ)Ö®¼äµÄÊý×Ö:" << endl;
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
	cout << "´óÐ´½á¹ûÊÇ:" << endl;
	//Ê®ÒÚ-ÒÚÎ»
	switch (a)
	{
		case 9:
			cout << "¾ÁÊ°";
			break;
		case 8:
			cout << "°ÆÊ°";
			break;
		case 7:
			cout << "ÆâÊ°";
			break;
		case 6:
			cout << "Â½Ê°";
			break;
		case 5:
			cout << "ÎéÊ°";
			break;
		case 4:
			cout << "ËÁÊ°";
			break;
		case 3:
			cout << "ÈþÊ°";
			break;
		case 2:
			cout << "·¡Ê°";
			break;
		case 1:
			cout << "Ò¼Ê°";
			break;
		case 0:
			break;
	}
	switch (b)
	{
		case 9:
			cout << "¾ÁÒÚ";
			break;
		case 8:
			cout << "°ÆÒÚ";
			break;
		case 7:
			cout << "ÆâÒÚ";
			break;
		case 6:
			cout << "Â½ÒÚ";
			break;
		case 5:
			cout << "ÎéÒÚ";
			break;
		case 4:
			cout << "ËÁÒÚ";
			break;
		case 3:
			cout << "ÈþÒÚ";
			break;
		case 2:
			cout << "·¡ÒÚ";
			break;
		case 1:
			cout << "Ò¼ÒÚ";
			break;
		case 0:
			if (a != 0)
				cout << "ÒÚ";
			else
				break;
			break;
	}
	//Ç§Íò-ÍòÎ»
	switch (c)
	{
		case 9:
			cout << "¾ÁÇª";
			break;
		case 8:
			cout << "°ÆÇª";
			break;
		case 7:
			cout << "ÆâÇª";
			break;
		case 6:
			cout << "Â½Çª";
			break;
		case 5:
			cout << "ÎéÇª";
			break;
		case 4:
			cout << "ËÁÇª";
			break;
		case 3:
			cout << "ÈþÇª";
			break;
		case 2:
			cout << "·¡Çª";
			break;
		case 1:
			cout << "Ò¼Çª";
			break;
		case 0:
			if (b == 0)
				break;
			else if (b != 0)
			{
				if ((d == 0) && (e == 0) && (f == 0))
					break;
				else
					cout << "Áã";
			}
			break;
	}
	switch (d)
	{
		case 9:
			cout << "¾Á°Û";
			break;
		case 8:
			cout << "°Æ°Û";
			break;
		case 7:
			cout << "Æâ°Û";
			break;
		case 6:
			cout << "Â½°Û";
			break;
		case 5:
			cout << "Îé°Û";
			break;
		case 4:
			cout << "ËÁ°Û";
			break;
		case 3:
			cout << "Èþ°Û";
			break;
		case 2:
			cout << "·¡°Û";
			break;
		case 1:
			cout << "Ò¼°Û";
			break;
		case 0:
			if (c == 0)
				break;
			else if (c != 0)
			{
				if ((e == 0) && (f == 0))
					break;
				else
					cout << "Áã";
			}
			break;
	}
	switch (e)
	{
		case 9:
			cout << "¾ÁÊ°";
			break;
		case 8:
			cout << "°ÆÊ°";
			break;
		case 7:
			cout << "ÆâÊ°";
			break;
		case 6:
			cout << "Â½Ê°";
			break;
		case 5:
			cout << "ÎéÊ°";
			break;
		case 4:
			cout << "ËÁÊ°";
			break;
		case 3:
			cout << "ÈþÊ°";
			break;
		case 2:
			cout << "·¡Ê°";
			break;
		case 1:
			cout << "Ò¼Ê°";
			break;
		case 0:
			if (d == 0)
				break;
			else if (d != 0)
			{
				if (f == 0)
					break;
				else
					cout << "Áã";
			}
			break;
	}
	switch (f)
	{
		case 9:
			cout << "¾ÁÍò";
			break;
		case 8:
			cout << "°ÆÍò";
			break;
		case 7:
			cout << "ÆâÍò";
			break;
		case 6:
			cout << "Â½Íò";
			break;
		case 5:
			cout << "ÎéÍò";
			break;
		case 4:
			cout << "ËÁÍò";
			break;
		case 3:
			cout << "ÈþÍò";
			break;
		case 2:
			cout << "·¡Íò";
			break;
		case 1:
			cout << "Ò¼Íò";
			break;
		case 0:
			if ((c == 0) && (d == 0) && (e == 0))
				break;
			else
				cout << "Íò";
			break;
	}
	//Ç§Î»-¸öÎ»
	switch (g)
	{
		case 9:
			cout << "¾ÁÇª";
			break;
		case 8:
			cout << "°ÆÇª";
			break;
		case 7:
			cout << "ÆâÇª";
			break;
		case 6:
			cout << "Â½Çª";
			break;
		case 5:
			cout << "ÎéÇª";
			break;
		case 4:
			cout << "ËÁÇª";
			break;
		case 3:
			cout << "ÈþÇª";
			break;
		case 2:
			cout << "·¡Çª";
			break;
		case 1:
			cout << "Ò¼Çª";
			break;
		case 0:
			if (f == 0)
			{
				if ((h != 0) || (i != 0) || (j != 0))
				{
					if ((a != 0) || (b != 0) || (c != 0) || (d != 0) || (e != 0) || (f != 0))
					{
						cout << "Áã";
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
					cout << "Áã";
			}
			break;
	}
	switch (h)
	{
		case 9:
			cout << "¾Á°Û";
			break;
		case 8:
			cout << "°Æ°Û";
			break;
		case 7:
			cout << "Æâ°Û";
			break;
		case 6:
			cout << "Â½°Û";
			break;
		case 5:
			cout << "Îé°Û";
			break;
		case 4:
			cout << "ËÁ°Û";
			break;
		case 3:
			cout << "Èþ°Û";
			break;
		case 2:
			cout << "·¡°Û";
			break;
		case 1:
			cout << "Ò¼°Û";
			break;
		case 0:
			if (g == 0)
				break;
			else if (g != 0)
			{
				if ((i == 0) && (j == 0))
					break;
				else
					cout << "Áã";
			}
			break;
	}
	switch (i)
	{
		case 9:
			cout << "¾ÁÊ°";
			break;
		case 8:
			cout << "°ÆÊ°";
			break;
		case 7:
			cout << "ÆâÊ°";
			break;
		case 6:
			cout << "Â½Ê°";
			break;
		case 5:
			cout << "ÎéÊ°";
			break;
		case 4:
			cout << "ËÁÊ°";
			break;
		case 3:
			cout << "ÈþÊ°";
			break;
		case 2:
			cout << "·¡Ê°";
			break;
		case 1:
			cout << "Ò¼Ê°";
			break;
		case 0:
			if (h == 0)
				break;
			else if (h != 0)
			{
				if (j == 0)
					break;
				else
					cout << "Áã";
			}
			break;
	}
	switch (j)
	{
		case 9:
			cout << "¾ÁÔ²";
			break;
		case 8:
			cout << "°ÆÔ²";
			break;
		case 7:
			cout << "ÆâÔ²";
			break;
		case 6:
			cout << "Â½Ô²";
			break;
		case 5:
			cout << "ÎéÔ²";
			break;
		case 4:
			cout << "ËÁÔ²";
			break;
		case 3:
			cout << "ÈþÔ²";
			break;
		case 2:
			cout << "·¡Ô²";
			break;
		case 1:
			cout << "Ò¼Ô²";
			break;
		case 0:
			if ((a == 0) && (b == 0) && (c == 0) && (d == 0) && (e == 0) && (f == 0)
				&& (g == 0) && (h == 0) && (i == 0) && (k == 0) && (l == 0))
				cout << "ÁãÔ²";
			else if ((a == 0) && (b == 0) && (c == 0) && (d == 0) && (e == 0)
				      && (f == 0)&& (g == 0) && (h == 0) && (i == 0))
				break;
			else	
				cout << "Ô²";
			    break;
	}
	//½Ç-·Ö
	if ((k == 0) && (l == 0))
		cout << "Õû";
	else if ((k != 0) && (l == 0))
	{
		switch (k)
		{
			case 9:
				cout << "¾Á½Ç";
				break;
			case 8:
				cout << "°Æ½Ç";
				break;
			case 7:
				cout << "Æâ½Ç";
				break;
			case 6:
				cout << "Â½½Ç";
				break;
			case 5:
				cout << "Îé½Ç";
				break;
			case 4:
				cout << "ËÁ½Ç";
				break;
			case 3:
				cout << "Èþ½Ç";
				break;
			case 2:
				cout << "·¡½Ç";
				break;
			case 1:
				cout << "Ò¼½Ç";
				break;
		}
		cout << "Õû";
	}
	else if ((k == 0) && (l != 0))
	{
		if ((a != 0) || (b != 0) || (c != 0) || (d != 0) || (e != 0) || (f != 0) || (g != 0) || (h != 0) || (i != 0) || (j != 0))
			cout << "Áã";
		switch (l)
		{
			case 9:
				cout << "¾Á·Ö";
				break;
			case 8:
				cout << "°Æ·Ö";
				break;
			case 7:
				cout << "Æâ·Ö";
				break;
			case 6:
				cout << "Â½·Ö";
				break;
			case 5:
				cout << "Îé·Ö";
				break;
			case 4:
				cout << "ËÁ·Ö";
				break;
			case 3:
				cout << "Èþ·Ö";
				break;
			case 2:
				cout << "·¡·Ö";
				break;
			case 1:
				cout << "Ò¼·Ö";
				break;
		}
	}
	else if ((k != 0) && (l != 0))
	{
		switch (k)
		{
			case 9:
				cout << "¾Á½Ç";
				break;
			case 8:
				cout << "°Æ½Ç";
				break;
			case 7:
				cout << "Æâ½Ç";
				break;
			case 6:
				cout << "Â½½Ç";
				break;
			case 5:
				cout << "Îé½Ç";
				break;
			case 4:
				cout << "ËÁ½Ç";
				break;
			case 3:
				cout << "Èþ½Ç";
				break;
			case 2:
				cout << "·¡½Ç";
				break;
			case 1:
				cout << "Ò¼½Ç";
				break;
		}
		switch (l)
		{
			case 9:
				cout << "¾Á·Ö";
				break;
			case 8:
				cout << "°Æ·Ö";
				break;
			case 7:
				cout << "Æâ·Ö";
				break;
			case 6:
				cout << "Â½·Ö";
				break;
			case 5:
				cout << "Îé·Ö";
				break;
			case 4:
				cout << "ËÁ·Ö";
				break;
			case 3:
				cout << "Èþ·Ö";
				break;
			case 2:
				cout << "·¡·Ö";
				break;
			case 1:
				cout << "Ò¼·Ö";
				break;
		}
	}
	cout << endl;
	return 0;
}