#include <iostream>
#include <string>
using namespace std;
struct STU
{
    string name;
    int id;
    int class_id;
    float cpp_score;
    float math_score;
    float liner_math_score;
    float average_score;
};

STU students[10];

void input_fun();
void calucate_fun();
int find_fun();
int main()
{
    input_fun();
    calucate_fun();
    for (int i = 0; i < 10; i++)
    {
        cout << students[i].class_id << "班" << students[i].id << students[i].name << "的平均成绩为：" << students[i].average_score << endl;
    }
    int index = find_fun();
    cout << "平均分最高的学生是" << students[index].name << "同学,他的平均分为：" << students[index].average_score;
}
void input_fun()
{
    for (int i = 0; i < 10; i++)
    {
        cout << "请输入第" << i + 1 << "个学生的学号:";
        cin >> students[i].id;
        cout << "请输入第" << i + 1 << "个学生的姓名:";
        cin >> students[i].name;
        cout << "请输入第" << i + 1 << "个学生的班级:";
        cin >> students[i].class_id;
        cout << "请输入第" << i + 1 << "个学生的c++成绩:";
        cin >> students[i].cpp_score;
        cout << "请输入第" << i + 1 << "个学生的高等数学成绩:";
        cin >> students[i].math_score;
        cout << "请输入第" << i + 1 << "个学生的线性代数成绩:";
        cin >> students[i].liner_math_score;
    }
}
void calucate_fun()
{
    for (int i = 0; i < 10; i++)
    {
        students[i].average_score = (students[i].cpp_score + students[i].math_score + students[i].liner_math_score) / 3.0;
    }
}

int find_fun()
{
    int index;
    int init = 0;
    for (int i = 0; i < 10; i++)
    {
        if (students[i].average_score > init)
        {
            index = i;
            init = students[i].average_score;
        }
    }
    return index;
}
