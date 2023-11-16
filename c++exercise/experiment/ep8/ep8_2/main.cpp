#include <iostream>
using namespace std;

int main()
{
    int num;
    float price;
    float result;
    int choice;
    cout << "请输入版本（1.current realse 2.othors）:";
    cin >> choice;
    switch (choice)
    {
    case 1:
        price = 3.5;
        break;
    case 2:
        price = 2.5;
        break;
    default:
        cout << "输入的命令不正确\n";
        exit(0);
        break;
    }
    cout << "请输入张数：";
    cin >> num;
    result = (num / 3) * price * 2 + (num % 3) * price;
    cout << "租赁费用为：" << result << endl;
}
