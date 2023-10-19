#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    float h1, m1, s1;
    float h2, m2, s2;
    float h(0), m(0), s(0);
    system("time");
    cout << "请分别输入时分秒\n";
    cout << "时:\n";
    cin >> h1;
    cout << "分:\n";
    cin >> m1;
    cout << "秒:\n";
    cin >> s1;
    cout << "请再次输入:\n";
    cout << "时:\n";
    cin >> h2;
    cout << "分:\n";
    cin >> m2;
    cout << "秒:\n";
    cin >> s2;
    s = s1 + s2;
    if (s >= 60)
    {
        s = s - 60;
        m = m + 1;
    }
    m = m + m1 + m2;
    if (m >= 60)
    {
        m = m - 60;
        h = h + 1;
    }
    h = h + h1 + h2;
    cout << h << ":" << m << ":" << s;
}