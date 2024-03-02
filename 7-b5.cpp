/* 2153393 ������ ��� */
#include <iostream>
#include <iomanip>
#include <cmath> 
using namespace std;

/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2����������ȫ�ֱ�������̬�ֲ�������ȫ��ֻ��������궨�岻�ܴ����ƣ�
   3������������һ������������Ҫ����Ҫ��
   ---------------------------------------------------------------------
*/

#define N	10

struct course {
	float value;	//ĳ�γ̵ĳɼ����ٷ��ƣ�
	float weight;	//ĳ�γ̵�ѧ�֣�Ȩ�أ�
	int   gpa;		//ĳ�γ̵ļ��㣨ͬ�ù���[0..60) - 0, [60,70) - 2, [70,80) - 3, [80-90) - 4,[90,100] - 5��
};

struct student {
	int   no;               //ѧ�ţ���Ȼ��int���������˴������ǣ�
	char  name[9];          //���������4������
	struct course score[3]; //��������ſεĳɼ���δʹ�ú궨�壬����ʵ��ʱ��ֱ��д3���ɣ�
	double grade;                     //��������������Ϊ��Ҫ���ӵĽṹ���Ա����һ��������Ҫ��ɾ������
};

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    �����˴�����������һ���������Һ������βΡ��Զ������ȶ������Ǽ򵥱�������������[]��ʽ��
***************************************************************************/

void output_information(struct student* ps, struct course* pc, struct student* stu)
{
	for (int i = 0; i < 10; i++, ps++)
	{
		pc = (*ps).score;
		double sum = 0, sum_1 = 0;
		cout << setiosflags(ios::left);
		cout << setw(5) << i + 1;
		cout << setw(8) << (*ps).no << setw(9) << (*ps).name;
		for (int j = 0; j < 3; j++, pc++)
			cout << setw(6) << (*pc).gpa << setw(6) << (*pc).weight;
		pc -= 3;
		for (int j = 0; j < 3; j++,pc++)
		{
			sum += (*pc).gpa * (*pc).weight;
			sum_1 += (*pc).weight;
		}
		cout << setiosflags(ios::fixed) << setprecision(3) << sum / sum_1 << endl;
		cout << resetiosflags(ios::fixed);
	}
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�����10��ѧ������Ϣ
  ���������
  �� �� ֵ��
  ˵    ������������ֺ궨��N
***************************************************************************/
void input(struct student* stu, int num)
{
	/* �����������ͱ����⣬�����������������κ���ʽ�ı���
		 ������ã�����ɾ�������������ӻ��滻Ϊ������ʽ�ı���
		����for(int k=0; )��ʽ���±�������ͬ����ֹ */
	int i, j;

	/* ������ʵ�ֲ��� */
	for (i = 0; i < 10; i++,stu++)
	{
		cout << "�������" << setw(2) << (i + 1) << "��ѧ������Ϣ : ";
		cin >> (*stu).no >> (*stu).name;
		for (j = 0; j < 3; j++)
		{
			cin >> (stu->score + j)->value >> (stu->score + j)->weight;
			if ((stu->score + j)->value >= 0 && (stu->score + j)->value < 60)
				(stu->score + j)->gpa = 0;
			else if ((stu->score + j)->value >= 60 && (stu->score + j)->value < 70)
				(stu->score + j)->gpa = 2;
			else if ((stu->score + j)->value >= 70 && (stu->score + j)->value < 80)
				(stu->score + j)->gpa = 3;
			else if ((stu->score + j)->value >= 80 && (stu->score + j)->value < 90)
				(stu->score + j)->gpa = 4;
			else if ((stu->score + j)->value >= 90 && (stu->score + j)->value <= 100)
				(stu->score + j)->gpa = 5;
		}
	}
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ����������Ϣ
  ���������
  �� �� ֵ��
  ˵    ������������ֺ궨��N
***************************************************************************/
void output_base(struct student* stu, int num)
{
	/* ��������ָ������⣬�����������������κ���ʽ�ı���
		 ������ã�����ɾ�������������ӻ��滻Ϊ������ʽ�ı���
		����for(int i=0; )��ʽ���±�������ͬ����ֹ */
	struct student* ps;
	struct course* pc;

	/* ������ʵ�ֲ��֣��������κ���ʽ��[]���� */
	ps = stu,  pc = (*ps).score;
	cout << endl;
	cout << "10��ѧ���ĳɼ�" << endl;
	cout << "��� ѧ��    ����     ����1 Ȩ��1 ����2 Ȩ��2 ����3 Ȩ��3 ƽ������" << endl;
	cout << "==================================================================" << endl;
	output_information(ps, pc, stu);
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ����������ߵ�ѧ���������в��У�
  ���������
  �� �� ֵ��
  ˵    ������������ֺ궨��N
***************************************************************************/
void output_max(struct student* stu, int num)
{
	/* ��������������������͵ļ򵥱������������������� */
	struct student* ps;
	struct course* pc;
	double max = 0, temp = 0;
	ps = stu, pc = (*ps).score;
	for (int i = 0; i < 10; i++,ps++) 
	{
		pc = (*ps).score;
		double sum = 0, sum_1 = 0;
		for (int j = 0; j < 3; j++, pc++)
		{
			sum += (*pc).gpa * (*pc).weight;
			sum_1 += (*pc).weight;
			(*ps).grade = temp = sum / sum_1;
		}
		max = temp > max ? temp : max;
	}
	ps = stu;
	cout << endl;
	cout << "������ߵ�ѧ��Ϊ" << endl;
	cout << "��� ѧ��    ����     ����1 Ȩ��1 ����2 Ȩ��2 ����3 Ȩ��3 ƽ������" << endl;
	cout << "==================================================================" << endl;
	for (int i = 0; i < 10; i++,ps++)
	{
		pc = (*ps).score;
		if (fabs(max - (*ps).grade) < 1e-4)
		{
			cout << setiosflags(ios::left);
			cout << setw(5) << i + 1;
			cout << setw(8) << (*ps).no << setw(9) << (*ps).name;
			for (int j = 0; j < 3; j++, pc++)
				cout << setw(6) << (*pc).gpa << setw(6) << (*pc).weight;
			cout << setiosflags(ios::fixed) << setprecision(3) << (*ps).grade << endl;
			cout << resetiosflags(ios::fixed);
		}
	}
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main������׼��
***************************************************************************/
int main()
{
	struct student stu[N];

	input(stu, N);		//����10��ѧ������Ϣ
	output_base(stu, N);	//���10��ѧ���Ļ�����Ϣ
	output_max(stu, N);	//�����ߣ������ж����

	return 0;
}

/*
�������ݣ����Ƶ�cmd���ɣ�����ʱ����������һ�飩

2150844 ���ں� 76.5 4 82 5 52 2
2154284 �� 63 4 49 1 87 6
2253105 �Ժ��� 56 3 76 4 69 5
2254319 ��ϣ�� 44.5 2 83.5 4 87 6
2251754 ��ҫ�� 91 4 43.5 1 66 3
2250269 ˾ͽ�ɂ� 79 6 85.5 3 62 2
2252558 ������ 86 3 63 3 77.5 4
1951475 �Բ��� 49.5 3 86 6 93.5 3
2153879 ��¬��� 81.5 2 64.5 3 87 4
2253636 ������ 73 3 62 2 85 5

*/
