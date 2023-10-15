#include <iostream>
using namespace std;

int main()
{
    int num1, num2, num3;
    int max_num, min_num;
    cout << "请依次输入三个整数：\n";
    cin >> num1 >> num2 >> num3;
    // 比较前两个数
    if (num1 >= num2)
    {
        max_num = num1;
        min_num = num2;
    }
    else
    {
        max_num = num2;
        min_num = num1;
    }
    // 前两个数的较大者和第三个数比较得出较大者
    if (max_num <= num3)
    {
        max_num = num3;
    }
    // 前两个数的较小者和第三个数比较得出较小者
    if (min_num >= num3)
    {
        min_num = num3;
    }
    cout << "最大的数为：" << max_num << "，最小的数为：" << min_num << endl;
}