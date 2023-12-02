#include "studentScore.h"
using namespace std;

int main()
{
    studentScore stu;
    stu.init();
    stu.process();
    cout << "不及格的人数为：" << stu.get_num_of_fail() << endl;
    stu.print_fail_student();
    cout << "分数大于平均分的人数为：" << stu.get_num_of_higher_average() << endl;
    stu.print_higher_average_student();
    stu.show_all_level();
}