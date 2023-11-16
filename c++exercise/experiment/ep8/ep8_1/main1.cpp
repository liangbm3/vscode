#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    float x;
    cout << "请输入x的值：\n";
    cin >> x;
    int i = 1;
    bool run = true;
    float sinx = .0;
    while (run)
    {
        float total = 1;
        for (int b = 1; b <= 2 * i - 1; b++)
        {
            total = total * b;
        }
        sinx = sinx + (pow(x, 2 * i - 1) / total) * (pow(-1, i + 1));
        if (pow(x, 2 * i - 1) / total < pow(10, -5))
        {
            run = false;
        }
        i += 1;
    }
    cout << "sin" << x << "=" << sinx << endl;
}