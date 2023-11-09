#include <iostream>
using namespace std;
void fn1();
void fn1(int x);
void fn2(int &x);
int x = 1; // 全局变量
int y = 2; // 全局变量
int main()
{
    int x = 10; // 局部变量
    int y = 20; // 局部变量
    cout << "x=" << x << ",y=" << y << endl;
    fn1(x);
    cout << "x=" << x << ",y=" << y << endl;
    fn2(x);
    cout << "x=" << x << ",y=" << y << endl;
    return 0;
}

void fn1(int x)
{
    int y = 100; // 局部变量
    cout << "x=" << x << ",y=" << y << endl;
}
void fn2(int &x)
{
    int y = 100; // 局部变量
    x = 30;      // 全局变量
    cout << "x=" << x << ",y=" << y << endl;
}