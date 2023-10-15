#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    // 定义变量
    float a, b, c;
    float det;
    float x1, x2;
    // 获取输入值
    cout << "请输入二元一次方程的a：\n";
    cin >> a;
    cout << "请输入二元一次方程的b：\n";
    cin >> b;
    cout << "请输入二元一次方程的c：\n";
    cin >> c;
    det = pow(b, 2) - 4 * a * c;
    // 根的判别式判断
    if (det < 0)
    {
        cout << "方程在实数范围内无解\n";
    }
    else if (det == 0)
    {
        x1 = -b / (2 * a);
        cout << "方程有两个相等的实数解，x1=x2=" << x1 << endl;
    }
    else if (det > 0)
    {
        x1 = (-b - pow(det, 0.5)) / (2 * a);
        x2 = (-b + pow(det, 0.5)) / (2 * a);
        cout << "方程有两个不相同的实数解，x1=" << x1 << ",x2=" << x2 << endl;
    }
}