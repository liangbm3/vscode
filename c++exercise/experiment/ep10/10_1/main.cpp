#include <iostream>
using namespace std;

class Data
{
private:
public:
    Data() { year = 2021, month = 05, day = 20; };
    Data(const Data &d)
    {
        year = d.year;
        month = d.month;
        day = d.day;
    }
    ~Data();
    void set_date();
    void show_date();
    int year;
    int month;
    int day;
};

int main()
{
    Data date1;
    date1.show_date();
    date1.set_date();
    date1.show_date();
}

void Data::set_date()
{
    cout << "请输入年：";
    cin >> year;
    cout << "请输入月：";
    cin >> month;
    cout << "请输入日：";
    cin >> day;
}

void Data::show_date()
{
    cout << "日期为：" << year << "/" << month << "/" << day << endl;
}
