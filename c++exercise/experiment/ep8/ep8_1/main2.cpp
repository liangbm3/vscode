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
    float total = 1;
    while (run)
    {
        if (i == 1)
        {
            total = total;
        }
        else
        {
            total = total * (2 * i - 2) * (2 * i - 1);
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