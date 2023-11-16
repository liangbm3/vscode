#include <iostream>
#include <string>
using namespace std;

int main()
{
    int choice;
    string select;
    bool run = true;
    while (run)
    {
        cout << "菜单如下：\n";
        cout << "\t 0.Apple\n";
        cout << "\t 1.Orange\n";
        cout << "\t 2.Peach\n";
        cout << "\t 3.Pear\n";
        cout << "\t 4.Exit\n";
        cout << "请输入选择：";
        if (cin >> choice)
        {
            switch (choice)
            {
            case 0:
                cout << "Apple每斤10元\n";
                break;
            case 1:
                cout << "Orange每斤12元\n";
                break;
            case 2:
                cout << "Peach每斤15元\n";
            case 3:
                cout << "Pear每斤12元\n";
                break;
            case 4:
                run = false;
                break;
            default:
                break;
            }
        }
        else
        {
            cin.clear();
            cin >> select;
            if (select == "q" || "Q" || "exit" || "Exit")
            {
                run = false;
            }
        }
    }
}