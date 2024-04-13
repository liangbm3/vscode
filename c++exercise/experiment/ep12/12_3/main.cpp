#include <iostream>

using namespace std;

// 加密函数
void encrypt(char *str)
{
    const char key[] = "4962873";
    int keyIndex = 0;

    while (*str)
    {
        *str += key[keyIndex] - '0'; // 将字符加上对应数字
        if (*str > 'z')
        {                                  // 如果超出'z'的ASCII码
            *str = (*str - 'z' - 1) + ' '; // 进行模运算，回到可打印字符的范围内
        }
        keyIndex = (keyIndex + 1) % 7; // 移动到下一个密钥数字
        str++;                         // 移动到下一个字符
    }
}

// 解密函数
void decrypt(char *str)
{
    const char key[] = "4962873";
    int keyIndex = 0;

    while (*str)
    {
        *str -= key[keyIndex] - '0'; // 将字符减去对应数字进行解密
        if (*str < ' ')
        {                                    // 如果小于空格的ASCII码
            *str = ('z' - (' ' - *str - 1)); // 进行模运算，回到可打印字符的范围内
        }
        keyIndex = (keyIndex + 1) % 7; // 移动到下一个密钥数字
        str++;                         // 移动到下一个字符
    }
}

int main()
{
    const int maxSize = 100;
    char input[maxSize];

    cout << "请输入字符串: ";
    cin.getline(input, maxSize);

    cout << "原始字符串为: " << input << endl;

    // 加密
    encrypt(input);
    cout << "加密结果为: " << input << endl;

    // 解密
    decrypt(input);
    cout << "解密结果为: " << input << endl;

    return 0;
}
