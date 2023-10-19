#include <iostream>
#include <string>
using namespace std;
int main()
{
    for (;;)
    {
        int n;
        string command;
        cout << "请输入n（1<=n<=10）:\n";
        if (n >= 1 && n <= 10)
        {
            cin >> n;
            int total = 1;
            int total_num = 0;
            for (int i = 1; i <= n; i++)
            {
                total = total * i;
                total_num = total_num + total;
            }
            cout << "结果为：" << total_num << endl;
            cout << "是否退出，如需，请输入“ctrl+z”\n";
            cin >> command;
        }

        if (command == "ctrl+z")
        {
            cout << "程序退出！\n";
            break;
        }
    }
}