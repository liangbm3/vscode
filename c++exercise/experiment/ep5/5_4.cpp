#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int x;
    cout << "请输入x的值：\n";
    cin >> x;
    int i = 0;
    float total = 0;
    while (1)
    {
        double n = 1;
        if (i != 0)
        {
            for (int j = i; j > 0; j--)
            {
                n = n * j;
            }
        }
        total = (float)pow(x, i) / n + total;
        i += 1;
        if ((float)pow(x, i) / n < 0.000001)
        {
            break;
        }
    }
    cout << "e的" << x << "次方为：" << total << endl;
}