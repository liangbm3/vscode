#include "studentScore.h"

studentScore::studentScore()
{
}

studentScore::~studentScore()
{
}

void studentScore::print_msg_fun()
{
    cout << "请依此输入学生的姓名，学号，分数，中间用空格分隔,当输入为负值时输入结束\n";
}

Student studentScore::input_fun(int index)
{
    cout << "请输入第" << index << "个学生的信息:";
    Student stu;
    cin >> stu.name >> stu.id >> stu.score;
    return stu;
}

int studentScore::cout_average_score_fun(Student arr[], int length)
{
    float sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum = sum + arr[i].score;
    }
    return sum / length;
}

void studentScore::sort_level_fun(Student &stu)
{
    if (stu.score < 60)
    {
        stu.level = 0;
    }
    else if (stu.score >= 60 && stu.score < 70)
    {
        stu.level = 1;
    }
    else if (stu.score >= 70 && stu.score < 80)
    {
        stu.level = 2;
    }
    else if (stu.score >= 80 && stu.score < 90)
    {
        stu.level = 3;
    }
    else if (stu.score >= 90 && stu.score < 100)
    {
        stu.level = 4;
    }
    else if (stu.score == 100)
    {
        stu.level = 5;
    }
    else
    {
        cout << "成绩不合法";
        exit(-1);
    }
}

void studentScore::init()
{
    print_msg_fun();
    int i = 0;
    while (true)
    {
        students[i] = input_fun(i + 1);
        if (students[i].score < 0)
        {
            total_num = i;
            break;
        }
        i = i + 1;
    }
}

void studentScore::process()
{
    for (int i = 0; i < total_num; i++)
    {
        sort_level_fun(students[i]);
    }
    average_score = cout_average_score_fun(students, total_num);
}

int studentScore::get_num_of_fail()
{
    int sum = 0;
    for (int i = 0; i < total_num; i++)
    {
        if (students[i].level == 0)
        {
            sum += 1;
        }
    }
    return sum;
}

int studentScore::get_num_of_higher_average()
{
    int sum = 0;
    for (int i = 0; i < total_num; i++)
    {
        if (students[i].score >= average_score)
        {
            sum += 1;
        }
    }
    return sum;
}

void studentScore::print_fail_student()
{
    cout << "成绩不及格的名单如下:\n";
    for (int i = 0; i < total_num; i++)
    {
        if (students[i].score < 60)
        {
            cout << students[i].name << "、";
        }
    }
    cout << endl;
}

void studentScore::print_higher_average_student()
{
    cout << "成绩大于平均分的名单如下:\n";
    for (int i = 0; i < total_num; i++)
    {
        if (students[i].score >= average_score)
        {
            cout << students[i].name << "、";
        }
    }
    cout << endl;
}

void studentScore::show_all_level()
{
    int level[] = {0, 0, 0, 0, 0, 0};
    for (int i = 0; i < total_num; i++)
    {
        switch (students[i].level)
        {
        case 0:
            level[0] += 1;
            break;
        case 1:
            level[1] += 1;
            break;
        case 2:
            level[2] += 1;
            break;
        case 3:
            level[3] += 1;
            break;
        case 4:
            level[4] += 1;
            break;
        case 5:
            level[5] += 1;
            break;
        default:
            break;
        }
    }
    cout << "学生人数百分比如下：\n";
    cout << "分数段\t人数\t\t图像\n";
    cout << "<60\t" << level[0] << "(" << (float)level[0] / (float)total_num << ")\t\t";
    for (int i = 0; i < level[0]; i++)
    {
        cout << "*";
    }
    cout << "\n60~69\t" << level[1] << "(" << (float)level[1] / (float)total_num << ")\t\t";
    for (int i = 0; i < level[1]; i++)
    {
        cout << "*";
    }
    cout << "\n70~79\t" << level[2] << "(" << (float)level[2] / (float)total_num << ")\t\t";
    for (int i = 0; i < level[2]; i++)
    {
        cout << "*";
    }
    cout << "\n80~89\t" << level[3] << "(" << (float)level[3] / (float)total_num << ")\t\t";
    for (int i = 0; i < level[3]; i++)
    {
        cout << "*";
    }
    cout << "\n90~99\t" << level[4] << "(" << (float)level[4] / (float)total_num << ")\t\t";
    for (int i = 0; i < level[4]; i++)
    {
        cout << "*";
    }
    cout << "\n100\t" << level[5] << "(" << (float)level[5] / (float)total_num << ")\t\t";
    for (int i = 0; i < level[5]; i++)
    {
        cout << "*";
    }
}

int studentScore::get_average_score()
{
    return average_score;
}
