#include <iostream>
using namespace std;
void merge(const int list1[], int size1, const int list2[], int size2, int list3[]);
int main()
{
    int arr1[80], arr2[80];
    int size1, size2;
    int arr3[180];
    cout << "请输入第一个数组大小：";
    cin >> size1;
    for (int i = 0; i < size1; i++)
    {
        cout << "请输入数组第" << i + 1 << "个元素：";
        cin >> arr1[i];
    }
    cout << "请输入第二个数组大小：";
    cin >> size2;
    for (int i = 0; i < size2; i++)
    {
        cout << "请输入数组第" << i + 1 << "个元素：";
        cin >> arr2[i];
    }
    merge(arr1, size1, arr2, size2, arr3);
    for (int i = 0; i < size1 + size2; i++)
    {
        cout << arr3[i] << " ";
    }
}

void merge(const int list1[], int size1, const int list2[], int size2, int list3[])
{
    int i = 0, j = 0, k = 0;
    while (true)
    {
        if (list1[i] > list2[j])
        {
            list3[k] = list2[j];
            k = k + 1;
            j = j + 1;
        }
        else
        {
            list3[k] = list1[i];
            k = k + 1;
            i = i + 1;
        }
        if (i + j == size1 + size2 - 1)
        {
            if (list1[size1 - 1] > list2[size2 - 1])
            {
                list3[size1 + size2 - 1] = list1[size1 - 1];
            }
            else
            {
                list3[size1 + size2 - 1] = list2[size2 - 1];
            }
            break;
        }
    }
}