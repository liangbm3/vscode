#include <iostream>
using namespace std;
#include <iomanip> //cout 格式化输出
int main()
{
    const double PI = 3.1415926;
    cout << "1.PI = [[" << setw(15) << PI << "]]" << endl;
    cout << "2.PI = [[" << setprecision(2) << PI << "]]" << endl;
    double x, y, z;
    x = 3.0;
    y = 4.0;
    x = y + z;
    cout << "With z not initialized, x = y + z =" << x << endl;
    int i = 39990;
    cout << "i =" << i << endl;
    double a = 7, b = 6, c = 5, d = 4, e, p, q;
    int k1 = 10, k, h, m, n;
    k = k1++;
    h = ++k1;
    cout << "k =" << k << endl;
    cout << "h =" << h << endl;
    m = 6 / 4;
    n = 6 / 4.0;
    cout << "m =" << m << ", n =" << n << endl;
    k1 *= (8 / 4);
    cout << "k1 =" << k1 << endl;
    e = 3;
    x = a + b - c / d * e;
    y = a + (b - c) / d * e;
    z = ((a + b) - c / d) * e;
    cout << "x =" << x << endl;
    cout << "y =" << y << endl;
    cout << "z =" << z << endl;
}