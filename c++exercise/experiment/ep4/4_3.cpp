#include <iostream>
using namespace std;

int main()
{
    int score;
    cout << "请输入百分制分数：\n";
    cin >> score;
    if (score >= 90 && score <= 100)
    {
        cout << "获得的等级是A\n";
    }
    else if (score >= 80 && score < 90)
    {
        cout << "获得的等级是B\n";
    }
    else if (score >= 70 && score < 80)
    {
        cout << "获得的等级是C\n";
    }
    else if (score >= 60 && score < 70)
    {
        cout << "获得的等级是D\n";
    }
    else if (score >= 0 && score < 60)
    {
        cout << "获得的等级是E\n";
    }
    else
    {
        cout << "请输入正确的数\n";
    }
}