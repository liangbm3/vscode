#include <iostream>
using namespace std;

int main()
{
    int line;
    cout << "请输入打印的行数";
    cin >> line;
    int number[line][line];
    for (int i = 0; i < line; i++)
    {
        number[i][0] = 1;
        number[i][i] = 1;
        if (i > 1)
        {
            for (int j = 1; j < i; j++)
            {
                number[i][j] = number[i - 1][j - 1] + number[i - 1][j];
            }
        }
    }
    for (int i = 0; i < line; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << number[i][j] << " ";
        }
        cout << endl;
    }
}