/* 2153393 ������ ��� */
#include <iostream>
#include <iomanip>
using namespace std;

/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2����������ȫ�ֱ�������̬�ֲ�����
   3�������������������
   4��main�����������룬����ѭ��
   --------------------------------------------------------------------- */

   /***************************************************************************
     �������ƣ�
     ��    �ܣ���ӡn�㺺ŵ�����ƶ�˳��
     ���������int n������
               char src����ʼ��
               char tmp���м���
               char dst��Ŀ����
     �� �� ֵ��
     ˵    ����1�����������βΡ��������;���׼��
               2������������������κ���ʽ��ѭ��
   ***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 1)
        cout << " 1# " << src << "-->" << dst << endl;
    else
    {
        hanoi(n - 1, src, dst, tmp);
        cout << setw(2) << n << "# " << src << "-->" << dst << endl;
        hanoi(n - 1, tmp, src, dst);
    }

}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����1��������롢���õݹ麯��
            2�������������ʱ������ʹ��ѭ��
            3��Ϊ��ͳһ��飬���������������������������ʼ/Ŀ�����Ĵ��벻Ҫ��ͳһ����������ֱ�ӷ���main�У�
***************************************************************************/
int main()
{
    int n;
    while (1) 
    {
        cout << "�����뺺ŵ���Ĳ���(1-16)" << endl;
        cin >> n;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        else if (n >= 1 && n <= 16)
        {
            cin.ignore(1024, '\n');
            break;
        }
    }
    char src, tmp = '0', dst;
    while (1)
    {
        cout << "��������ʼ��(A-C)" << endl;
        cin >> src;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        else if ((src == 'a') || (src == 'A') || (src == 'b') || (src == 'B') || (src == 'c') || (src == 'C'))
        {
            cin.clear();
            cin.ignore(1024, '\n');
            break;
        }
        else
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
    }
    while (1)
    {
        cout << "������Ŀ����(A-C)" << endl;
        cin >> dst;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        else if ((dst == 'a') || (dst == 'A') || (dst == 'b') || (dst == 'B') || (dst == 'c') || (dst == 'C'))
        {
            if (src == dst)
            {
                if ((dst == 'a') || (dst == 'A'))
                    cout << "Ŀ����(A)��������ʼ��(A)��ͬ" << endl;
                else if ((dst == 'b') || (dst == 'B'))
                    cout << "Ŀ����(B)��������ʼ��(B)��ͬ" << endl;
                else if ((dst == 'c') || (dst == 'C'))
                    cout << "Ŀ����(C)��������ʼ��(C)��ͬ" << endl;
                cin.clear();
                cin.ignore(1024, '\n');
                continue;
            }
            cin.clear();
            cin.ignore(1024, '\n');
            break;
        }
        else
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
    }
    if (src == 'a')
        src = 'A';
    else if (src == 'b')
        src = 'B';
    else if (src == 'c')
        src = 'C';
    if (dst == 'a')
        dst = 'A';
    else if (dst == 'b')
        dst = 'B';
    else if (dst == 'c')
        dst = 'C';
    if (src == 'A')
    {
        if (dst == 'B')
            tmp = 'C';
        else if (dst == 'C')
            tmp = 'B';
    }
    else if (src == 'B')
    {
        if (dst == 'C')
            tmp = 'A';
        else if (dst == 'A')
            tmp = 'C';
    }
    else if (src == 'C')
    {
        if (dst == 'B')
            tmp = 'A';
        else if (dst == 'A')
            tmp = 'B';
    }
    cout << "�ƶ�����Ϊ:" << endl;
    hanoi(n, src, tmp, dst);
}
