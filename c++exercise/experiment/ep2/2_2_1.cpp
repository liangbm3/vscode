#include <iostream>
using namespace std;
int main()
{
    float x, y;
    int a;
    x = 2.5;
    y = 4.7;
    a = 7;
    cout << "x+(int)a%3*(int)(x+y)%2/4的值为:" << (x + (int(a) % 3 * (int)(x + y) % 2 / 4)) << endl;
}