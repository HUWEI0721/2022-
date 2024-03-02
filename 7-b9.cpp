/* 2153393 ��� ������ */

/* ���������ϵͳ�ĺ궨�塢��Ҫ��ͷ�ļ��� */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "read_stulist.h"
using namespace std;

#define MAX_FILENAME_LEN		512	//�����ļ�������󳤶�

/* stu_merge ����ÿ��ѧ������Ϣ������ѧ�š�������������Ҫ��˽����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_merge {
private:
	int stu_no;					//ѧ��
	char stu_name[MAX_NAME_LEN];  //����

	/* ���������private���ݳ�Ա����Ա�����Լ�������Ҫ������ */
	int first_sign = 0;
	int second_sign = 0;
	friend class stu_list;
public:
	//���಻�������κεĹ������ݳ�Ա����Ա����
};

/* stu_list ������ѡ����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_list {
private:
	student list_round_1[MAX_STU_NUM];	//��һ��ѡ�ε�ѧ�������������򡢲�ȥ�أ�
	int list_num_1;						//��һ��ѡ�ε�ѧ������

	student list_round_2[MAX_STU_NUM];	//�ڶ���ѡ�ε�ѧ�������������򡢲�ȥ�أ�
	int list_num_2;						//�ڶ���ѡ�ε�ѧ������

	stu_merge list_merge[MAX_STU_NUM];	//�ϲ����ѧ��������ȥ�أ����������У�
	int list_merge_num;					//�ϲ����ѧ��������Ŀǰ����ӡ�����������ڲ������������Ҫ��Ҳ��Ҫɾ����

	/* ���������private���ݳ�Ա�ͳ�Ա����
	   ע�⣬���������array / set / map / vector��STL���� */

public:
	stu_list();										//���캯����������ɳ�ʼ�����ܣ��������Ҫ�������պ�������
	int read(const char* filename, const int round);	//���ļ��ж���ѡ����Ϣ��roundΪ1/2����ʾѡ���ִ�
	int print(const char* prompt = NULL);				//��ӡ���յ�ѡ������

	/* �������������public��Ա��������ʾ���ϲ���ȥ�ء�����ȣ�
	   �������幫�е����ݳ�Ա
	   �������ڳ�Ա������ʹ��array / set / map / vector��STL���� */
	void combine(); // �ϲ���һ�ֺ͵ڶ���ѡ������
	void remove_same(); // ȥ��
	void sort(); // ����
};

/* --- ������Ը���stu_merge/stu_list������ĳ�Ա����������ʵ�� --- */
void stu_list::combine()
{
	this->list_merge_num = 0;

	for (int i = 0; i < list_num_1; i++)
	{
		this->list_merge[list_merge_num].stu_no = list_round_1[i].no;
		strcpy(this->list_merge[list_merge_num].stu_name, list_round_1[i].name);
		this->list_merge[list_merge_num].first_sign = 1;
		this->list_merge[list_merge_num].second_sign = 0;
		list_merge_num++;
	}

	for (int i = 0; i < list_num_2; i++)
	{
		int j;
		for (j = 0; j < list_num_1; j++)
		{
			if (list_round_2[i].no == list_round_1[j].no)
			{
				this->list_merge[j].second_sign = 1;
				break;
			}
		}
		if (j == list_num_1)
		{
			this->list_merge[list_merge_num].stu_no = list_round_2[i].no;
			strcpy(this->list_merge[list_merge_num].stu_name, list_round_2[i].name);
			this->list_merge[list_merge_num].first_sign = 0;
			this->list_merge[list_merge_num].second_sign = 1;
			list_merge_num++;
		}
	}
}


void stu_list::remove_same()
{
	for (int i = 0; i < list_merge_num; i++)
	{
		for (int j = i + 1; j < list_merge_num; j++)
		{
			if (list_merge[i].stu_no == list_merge[j].stu_no)
			{
				for (int k = j; k < list_merge_num - 1; k++)
				{
					list_merge[k] = list_merge[k + 1];
				}
				list_merge_num--;
				j--;
			}
		}
	}
}

void stu_list::sort()
{
	for (int i = 0; i < list_merge_num - 1; i++)
	{
		for (int j = 0; j < list_merge_num - i - 1; j++)
		{
			if (list_merge[j].stu_no > list_merge[j + 1].stu_no)
			{
				stu_merge temp = list_merge[j];
				list_merge[j] = list_merge[j + 1];
				list_merge[j + 1] = temp;
			}
		}
	}
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ����ļ��ж���ѡ����Ϣ��roundΪ1/2����ʾѡ���ִ�
  ���������
  �� �� ֵ��
  ˵    �������캯����������ɳ�ʼ�����ܣ��������Ҫ�������պ�������
***************************************************************************/
stu_list::stu_list()
{
	list_num_1 = 0;
	list_num_2 = 0;
	list_merge_num = 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ���ʾ��̬���ӿ��ʹ�ã��������е��þ�̬���ӿ��е�Ԥ�ú���
  ���������
  �� �� ֵ��
  ˵    ��������������Ҫ�޸�
***************************************************************************/
int stu_list::read(const char* filename, const int round)
{
	int ret = 0;
	/* ��ȡ��1/2�ֵ�ѡ����������ӡ */
	switch (round) {
		case 1:
			list_num_1 = read_stulist(filename, list_round_1, MAX_STU_NUM);
			if (list_num_1 > 0)
				print_stulist("��һ��ѡ��������", list_round_1, list_num_1);
			else
				ret = -1;
			break;
		case 2:
			list_num_2 = read_stulist(filename, list_round_2, MAX_STU_NUM);
			if (list_num_2 > 0)
				print_stulist("�ڶ���ѡ��������", list_round_2, list_num_2);
			else
				ret = -1;
			break;
		default:
			ret = -1;
			break;
	}

	return ret;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
   ˵    ������ӡ���յ�ѡ������
***************************************************************************/
int stu_list::print(const char* prompt)
{
	cout << prompt << endl;
	cout << "============================================================" << endl;
	cout << "��� ѧ��     ����                            ��һ�� �ڶ���" << endl;
	cout << "============================================================" << endl;
	int num = 1;
	for (int i = 0; i < list_merge_num; i++, num++)
	{
		cout << setiosflags(ios::left);
		cout << setw(5) << num << list_merge[i].stu_no << "  " << setw(32)<< list_merge[i].stu_name;
		if (list_merge[i].first_sign == 1)
			cout << "Y      ";
		else
			cout << "/      ";
		if (list_merge[i].second_sign == 0)
		{
			if (list_merge[i].first_sign == 1)
				cout << "�˿�" << endl;
		}
		else
		{
			if (list_merge[i].first_sign == 1)
				cout << "Y" << endl;
			else
				cout << "��ѡ" << endl;
		}
	}
	cout << "============================================================" << endl;
	return 0;
}

int main(int argc, char** argv)
{
	char file1[MAX_FILENAME_LEN], file2[MAX_FILENAME_LEN];

	cout << "������ǰһ��ѡ�ε������ļ� : ";
	cin.getline(file1, MAX_FILENAME_LEN);

	cout << "�������һ��ѡ�ε������ļ� : ";
	cin.getline(file2, MAX_FILENAME_LEN);

	stu_list list;

	/* �������� */
	if (list.read(file1, 1) < 0)
		return -1;
	if (list.read(file2, 2) < 0)
		return -1;

	/* �������� */
	list.combine();
	list.remove_same();
	list.sort();

	/* ��ӡ */
	list.print("����ѡ������");

	return 0;
}


