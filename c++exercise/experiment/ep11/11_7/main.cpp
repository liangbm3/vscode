#include <iostream>
using namespace std;

int main()
{
    int max;
    int choice;
    cout << "请输入方阵的阶数：";
    cin >> max;
    int init_array[max][max];
    int result_arry[max][max];
    cout << "请输入方阵的所有元素：";
    for (int i = 0; i < max; i++)
    {
        for (int j = 0; j < max; j++)
        {
            cin >> init_array[i][j];
        }
    }
    cout << "请输入顺时针旋转的度数:";
    cin >> choice;
    for (int i = 0; i < max; i++)
    {
        for (int j = 0; j < max; j++)
        {
            switch (choice)
            {
            case 90:
                result_arry[i][j] = init_array[max - 1 - j][i];
                break;
            case 180:
                result_arry[i][j] = init_array[max - 1 - i][max - 1 - j];
                break;
            case 270:
                result_arry[i][j] = init_array[j][max - 1 - i];
                break;
            default:
                cout << "输入的选择不正确！\n";
                break;
            }
        }
    }
    cout << "初始矩阵为：\n";
    for (int i = 0; i < max; i++)
    {
        for (int j = 0; j < max; j++)
        {
            cout << init_array[i][j] << " ";
        }
        cout << endl;
    }
    cout << "旋转后的矩阵为：\n";
    for (int i = 0; i < max; i++)
    {
        for (int j = 0; j < max; j++)
        {
            cout << result_arry[i][j] << " ";
        }
        cout << endl;
    }
}