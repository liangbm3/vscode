#include <iostream>
#include <string>
#include "key.h"
using namespace std;

int main()
{
    int num;
    int model;
    string a;
    bool run = true;
    while (run)
    {
        cout << "请选择模式：(1.加密；2：解密；3.退出)\n";
        cin >> model;
        if (model == 1)
        {
            cout << "请输入位移量：";
            cin >> num;
            cout << "请输入字符串：";
            cin >> a;
            Encry(&a, num, 1);
            cout << "加密后的字符串为：" << a << endl;
        }
        else if (model == 2)
        {
            cout << "请输入位移量：";
            cin >> num;
            cout << "请输入字符串：";
            cin >> a;
            Encry(&a, num, 2);
            cout << "加密后的字符串为：" << a << endl;
        }
        else if (model == 3)
        {
            run = false;
        }
        else
        {
            cout << "你的输入不合法，请输入1-3的数！\n";
        }
    }
}