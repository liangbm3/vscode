/* ---------------------------------- 格式化打印 --------------------------------- */

#include <iostream>
using namespace std;

void tradition(void);

int main()
{
    // 魔法配方

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(3);
    tradition();
}

// 传统方案
void tradition(void)
{
    double one = 1.000, two = 1.414, three = 1.732, four = 2.000, five = 2.236;
    cout << "\tN\tSquare Root\n";
    cout << "\t1\t" << one << "\n";
    cout << "\t2\t" << two << "\n";
    cout << "\t3\t" << three << "\n";
    cout << "\t4\t" << four << "\n";
    cout << "\t5\t" << five << "\n";
}