/* 2153393 ������ ��� */
#include <iostream>
using namespace std;

#define  N  10	/* �������ת��10������ */

/* �������ٶ�������������ȫ�ֱ��� */

int main()
{
	/* ����в���Ҫ�ı���������ɾ��������������ӻ��滻Ϊ�������͵ı��� */
	char str[256], * p;
	int  a[N] = { 0 }, * pnum, * pa;
	bool is_num;

	/* ����Ķ��岻׼��(ɾ������Ҫ�ı�������)������Ϊ����ľ���ʵ�֣�Ҫ�󲻵��ٶ����κα����������������� */
	cout << "�����������������������ֵ��ַ���" << endl;
	gets_s(str);
	pa = a;
	p = str;
	is_num = 0;
	while (1)
	{
		if (*p >= ' ' && *p <= '~')
		{
			if (*p >= '0' && *p <= '9' && pa - a < N)
			{
				*pa = *p - '0';
				if (*(p + 1) >= '0' && *(p + 1) <= '9')
					is_num = 1;
				else
					is_num = 0;
				p++;
				if (is_num)
				{
					while (*p >= '0' && *p <= '9')
					{
						*pa *= 10;
						*pa += (*p - '0');
						p++;
					}
				}
				pa++;
			}
			p++;
		}
		else
			break;
	}
	cout << "����" << pa - a << "������" << endl;
	pnum = pa;
	pa = a;
	while (pnum != pa) 
	{
		cout << *pa << " ";
		pa++;
	}
	cout << endl;
	return 0;
}
//a1b2c3d4e5f6g7h8i9j10k11