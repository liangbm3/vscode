#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "请输入一个整数n：\n";
    cin >> n;
    for (int i = 2; i < n; i++)
    {
        for (int j = 2; j < n; j++)
        {
            if (i == j)
            {
                cout << i << endl;
            }
            if ((i % j) == 0)
            {
                break;
            }
        }
    }
}