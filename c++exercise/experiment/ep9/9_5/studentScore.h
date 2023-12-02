#include <string>
#include <iostream>
using namespace std;
struct Student // 学生结构体，包括姓名，学号，分数，分数所属区间
{
    string name;
    int id;
    float score;
    int level;
};
class studentScore
{
private:
    Student students[40];                                  // 结构体数组，用于储存键盘输入的学生信息
    int total_num;                                         // 表示输入的学生总数
    float average_score;                                   // 平均成绩
    void print_msg_fun();                                  // 打印提示用户输入的信息
    Student input_fun(int index);                          // 获取用户对一个学生信息的输入
    int cout_average_score_fun(Student arr[], int length); // 计算所输入所有学生分数的平均数
    void sort_level_fun(Student &stu);                     // 将学生的分数按题目所给的区间分类

public:
    studentScore(); // 默认构造函数
    ~studentScore();
    void init();    // 初始化函数，完成学生信息的录入
    void process(); // 处理函数，输入的信息进行处理
    // 以下均为获取处理结果的函数
    int get_num_of_fail();               // 用于获取不及格学生的人数
    int get_num_of_higher_average();     // 用于获取分数高于平均分的人数
    void print_fail_student();           // 用于打印不及格学生的姓名
    void print_higher_average_student(); // 用于打印分数高于平均分学生的姓名
    void show_all_level();               // 打印各分数段学生人数及占比，并用直方图表示
    int get_average_score();             // 获取平均分
};
