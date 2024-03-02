/*2153393 胡峻玮 软件*/
#include <iostream>
#include <cstring>
using namespace std;
#define num_student 10
#define len_stu_number 8
#define lenth_name 9
void input_data(string id_student[num_student], string name[num_student], int grade[num_student])
{
    for (int i = 0; i < num_student; i++)
    {
        cout << "请输入第" << i + 1 << "个人的学号、姓名、成绩" << endl;
        cin >> id_student[i];
        cin >> name[i];
        cin >> grade[i];
    }
}
void sort_all(string id_student[num_student], string name[num_student], int grade[num_student])
{
    for (int i = num_student - 1; i >= 0; i--) 
    {
        for (int j = 0; j < i; j++) 
        {
            string temp_str;
            int temp;
            int flag = 0;
            if (grade[j] > grade[j + 1])
                flag = -1;
            if (flag < 0) 
            {
                temp_str = id_student[j];
                id_student[j] = id_student[j + 1];
                id_student[j + 1] = temp_str;
                temp_str = name[j];
                name[j] = name[j + 1];
                name[j + 1] = temp_str;
                temp = grade[j];
                grade[j] = grade[j + 1];
                grade[j + 1] = temp;
            }
        }
    }
}
void output_data(string id_student[num_student], string name[num_student], int grade[num_student])
{
    cout << "不及格名单(成绩升序):" << endl;
    for (int i = 0; i < num_student; i++)
    {
        if (grade[i] < 60) 
            cout << name[i] << " " << id_student[i] << " " << grade[i] << endl;
    }
}
int main()
{
    string id_student[num_student];
    string name[num_student];
    int grade[num_student] = { 0 };
    input_data(id_student, name, grade);
    sort_all(id_student, name, grade);
    cout << endl;
    output_data(id_student, name, grade);
	return 0;
}