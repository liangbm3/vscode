#include <iostream>
using namespace std;

struct Date
{
    int year, month;
};
struct Person
{
    char name[20];
    Date birth;
    float money, salary;
};
Person input_fun()
{
    Person person;
    cout << "请输入姓名：";
    gets(person.name);
    // cin.getline(person.name,20);
    cout << "请输入出生年月（空格分隔）:";
    cin >> person.birth.year >> person.birth.month;
    cout << "请输入基本工资：";
    cin >> person.money;
    return person;
}
int main()
{
    Person p = input_fun();
    float num;
    cout << "请输入" << p.name << "的奖金金额：";
    cin >> num;
    p.salary = p.money + num;
    cout << p.name << "年龄：" << (2023 - p.birth.year) << "\t 基本工资：" << p.money << "\t";
    cout << "应领金额：" << p.salary << endl;
}
