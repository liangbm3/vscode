#include <iostream>
using namespace std;

struct Date
{
    int year,month;
};
struct Person
{
    char name[20];
    Date birth;
    float money,salary;
};
int main()
{
    Person p={"张三",{1982,3},1250,0};
    float num;
    cout<<"请输入"<<p.name<<"的奖金金额：";
    cin>>num;
    p.salary=p.money+num;
    cout<<p.name<<"年龄："<<(2023-p.birth.year)<<"\t 基本工资："<<p.money<<"\t";
    cout<<"应领金额："<<p.salary<<endl;
}

