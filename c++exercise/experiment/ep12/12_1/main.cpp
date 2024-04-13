#include <iostream>

using namespace std;

void classifyCharacters(const char *str)
{
    int letters = 0, spaces = 0, digits = 0, others = 0;

    while (*str)
    {
        if ((*str >= 'A' && *str <= 'Z') || (*str >= 'a' && *str <= 'z'))
        { // 判断是否为字母
            letters++;
        }
        else if (*str == ' ')
        { // 判断是否为空格
            spaces++;
        }
        else if (*str >= '0' && *str <= '9')
        { // 判断是否为数字
            digits++;
        }
        else
        { // 其他字符
            others++;
        }
        str++; // 移动指针到下一个字符
    }

    cout << "字母: " << letters << endl;
    cout << "空格: " << spaces << endl;
    cout << "数字: " << digits << endl;
    cout << "其他: " << others << endl;
}

int main()
{
    const int maxSize = 81;
    char ch[maxSize];

    cout << "输入字符串: ";
    cin.getline(ch, maxSize);

    classifyCharacters(ch);

    return 0;
}
