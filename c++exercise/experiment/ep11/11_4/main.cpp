#include <iostream>
#include <cstring>
using namespace std;

int indexOf(const char s1[], const char s2[]);

int main()
{
    char string1[100];
    char string2[100];
    cout << "请输入第一个字符串:";
    cin >> string1;
    cout << "请输入第二个字符串:";
    cin >> string2;
    int result;
    result = indexOf(string1, string2);
    if (result == -1)
    {
        cout << "“" << string1 << "” 不是 “" << string2 << "” 的子串";
    }
    else
    {
        cout << "“" << string1 << "” 是 “" << string2 << "” 的子串，且在索引" << result << "处\n";
    }
}

int indexOf(const char s1[], const char s2[])
{
    int size1 = strlen(s1);
    int size2 = strlen(s2);
    int flag = -1;
    for (int i = 0; i < size2; i++)
    {
        if (s1[0] == s2[i])
        {
            for (int j = 0; j < size1; j++)
            {
                if (s1[j] != s2[i + j])
                {
                    return flag;
                }
            }
            flag = i;
        }
    }
    return flag;
}