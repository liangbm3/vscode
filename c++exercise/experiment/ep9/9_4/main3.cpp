#include <iostream>
#include <string>
using namespace std;

struct Date
{
    int year, month;
};
struct Person
{
    string name;
    Date birth;
    float money, salary;
};
Person person[5];
float num;
void input_fun()
{
    for (int i = 0; i < 5; i++)
    {
        cout << "请输入第" << i + 1 << "个姓名：";
        cin >> person[i].name;
        cout << "请输入第" << i + 1 << "个出生年月（空格分隔）:";
        cin >> person[i].birth.year >> person[i].birth.month;
        cout << "请输入第" << i + 1 << "个基本工资：";
        cin >> person[i].money;
    }
}
int main()
{
    float total_money = 0, total_num = 0;
    float average_money, average_num;
    input_fun();
    for (int i = 0; i < 5; i++)
    {
        cout << "请输入" << person[i].name << "的奖金金额：";
        cin >> num;
        person[i].salary = person[i].money + num;
        total_num = total_num + num;
        total_money = total_money + person[i].money;
    }
    for (int i = 0; i < 5; i++)
    {
        cout << person[i].name << "年龄：" << (2023 - person[i].birth.year) << "\t 基本工资：" << person[i].money << "\t";
        cout << "应领金额：" << person[i].salary << endl;
    }
    average_money = total_money / 5.0;
    average_num = total_num / 5.0;
    cout << "平均工资为：" << average_money << endl;
    cout << "平均奖金为：" << average_num << endl;
}
