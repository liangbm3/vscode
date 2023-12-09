#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
void sort_fun(double init_arr[], double sorted_arr[], int length);

int main()
{
    double init_arr[10];
    double sorted_arr[10];
    cout << "原始数组为：";
    srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        init_arr[i] = (double)rand() / 100;
        cout << init_arr[i] << " ";
    }
    cout << endl;
    sort_fun(init_arr, sorted_arr, 10);
    cout << "排序后的数组为：";
    for (int i = 0; i < 10; i++)
    {

        cout << sorted_arr[i] << " ";
    }
}

void sort_fun(double init_arr[], double sorted_arr[], int length)
{
    int index = length - 1;
    for (int j = index; j > 0; j--)
    {
        for (int i = 0; i < j; i++)
        {
            if (init_arr[i] > init_arr[i + 1])
            {
                double tmp = init_arr[i];
                init_arr[i] = init_arr[i + 1];
                init_arr[i + 1] = tmp;
            }
        }
    }
    for (int i = 0; i < length; i++)
    {
        sorted_arr[i] = init_arr[i];
    }
}