#include <iostream>
#include <iomanip>
#include <unistd.h>
using namespace std;

int main()
{
    cout << "完整型九九乘法表如下：\n";
    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            cout << i << "*" << j << "=" << setw(2) << i * j << "\t";
            // usleep(100000);
        }
        cout << endl;
    }
    cout << "左上三角形九九乘法表如下：\n";
    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            if (j >= i)
            {
                cout << i << "*" << j << "=" << setw(2) << i * j << "\t";
                // usleep(100000);
            }
        }
        cout << endl;
    }
    cout << "右下三角形九九乘法表如下：\n";
    for (int i = 1; i < 10; i++)
    {

        for (int n = 0; n < i - 1; n++)
        {
            cout << "\t";
        }
        for (int j = 1; j < 10; j++)
        {
            if (j >= i)
            {
                cout << i << "*" << j << "=" << setw(2) << i * j << "\t";
                // usleep(100000);
            }
        }
        cout << endl;
    }
    cout << "左下三角形乘法表如下：\n";
    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            if (j <= i)
            {
                cout << i << "*" << j << "=" << setw(2) << i * j << "\t";
                // usleep(100000);
            }
        }
        cout << endl;
    }
    cout << "右下三角形乘法表如下：\n";
    for (int i = 1; i < 10; i++)
    {
        int k = 10 - i;
        for (int n = 0; n < k - 1; n++)
        {
            cout << "\t";
        }

        for (int j = 1; j < 10; j++)
        {
            if (j <= i)
            {
                cout << i << "*" << j << "=" << setw(2) << i * j << "\t";
                // usleep(100000);
            }
        }
        cout << endl;
    }
}
