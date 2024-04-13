#include <iostream>
using namespace std;
int *findmax(int *arr, int size, int *index)
{
    int max = arr[0];
    *index = 0;
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            *index = i;
        }
    }
    return &arr[*index];
}

int main()
{
    int a[10] = {33, 91, 54, 67, 82, 37, 85, 63, 19, 67};
    int *maxaddr;
    int index;
    maxaddr = findmax(a, sizeof(a) / sizeof(*a), &index);
    cout << "下标为：" << index << endl;
    cout << "最大元素地址为" << maxaddr << ",最大元素为：" << *maxaddr << endl;
    return 0;
}