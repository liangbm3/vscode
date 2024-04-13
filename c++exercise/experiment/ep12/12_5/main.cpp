#include <iostream>

const int maxSize = 100;

// 自定义排序函数（冒泡排序）
void customSort(int *arr, int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// 求两个整数集合的交集
void intersection(int *A, int sizeA, int *B, int sizeB)
{
    customSort(A, sizeA); // 对集合A进行排序
    customSort(B, sizeB); // 对集合B进行排序

    int result[maxSize]; // 存储交集的数组
    int idx = 0;         // 交集数组的索引

    int i = 0, j = 0;
    while (i < sizeA && j < sizeB)
    {
        if (A[i] == B[j])
        {
            result[idx++] = A[i];
            i++;
            j++;
        }
        else if (A[i] < B[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    if (idx == 0)
    {
        std::cout << "没有找到交集" << std::endl;
    }
    else
    {
        std::cout << "交集为: ";
        for (int k = 0; k < idx; k++)
        {
            std::cout << result[k] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    int A[maxSize], B[maxSize];
    int sizeA, sizeB;

    std::cout << "请输入集合A的大小：";
    std::cin >> sizeA;
    std::cout << "请输入集合A的元素：";
    for (int i = 0; i < sizeA; ++i)
    {
        std::cin >> A[i];
    }

    std::cout << "请输入集合B的大小：";
    std::cin >> sizeB;
    std::cout << "请输入集合B的元素：";
    for (int i = 0; i < sizeB; ++i)
    {
        std::cin >> B[i];
    }

    intersection(A, sizeA, B, sizeB);

    return 0;
}
