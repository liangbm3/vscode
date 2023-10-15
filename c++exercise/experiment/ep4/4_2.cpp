#include <iostream>
using namespace std;

int main()
{
    int i;
    char c;
    cout << "请输入一个0-15的数：\n";
    cin >> i;
    // 判断输入是否合法
    if (i >= 0x00 && i <= 0xF)
    {
        // 判断是转换成字符还是数字
        if (i <= 0x09)
        {
            c = i + 0x30;
        }
        else
        {
            c = i + 0x37;
        }
        cout << "输入的字符为：" << c << endl;
    }
    else
    {
        cout << "请按要求输入正确范围内的数！\n";
    }
}