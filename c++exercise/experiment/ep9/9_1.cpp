#include <iostream>
using namespace std;

struct DATE
{
    int year;
    int month;
    int day;
};

int main()
{
    DATE date;
    int total;
    cout << "请输入年月日：（以空格分隔）";
    int delet;
    cin >> date.year >> date.month >> date.day;
    date.month = date.month - 1;
    if (date.month > 2)
    {
        if ((date.year % 4 == 0 && date.year % 100 != 0) || (date.year % 400 == 0))
        {
            delet = 1;
        }
        else
        {
            delet = 2;
        }
        if (date.month < 8)
        {
            if (date.month % 2 == 0)
            {
                total = (date.month / 2) * 61 - delet + date.day;
            }
            else
            {
                total = ((date.month - 1) / 2) * 61 - delet + 31 + date.day;
            }
        }
        else
        {
            date.month = date.month - 7;
            if (date.month % 2 == 0)
            {
                total = 61 * 3 + 31 - delet + (date.month / 2) * 61 + date.day;
            }
            else
            {
                total = 61 * 3 + 31 - delet + ((date.month - 1) / 2) * 61 + 30 + date.day;
            }
        }
    }
    else
    {
        if (date.month == 1)
        {
            total = date.day;
        }
        else
        {
            total = 31 + date.day;
        }
    }
    cout << date.year << "年" << date.month << "月" << date.day << "日是本年的第" << total << "天\n";
}