#include <iostream>
#include <cstring>
using namespace std;

void count(const char s[], int counts[]);

int main()
{
    char str[100];
    int counts[26];
    cout << "请输入字符串:";
    cin >> str;
    count(str, counts);
}
void count(const char s[], int counts[])
{
    int size = strlen(s);
    for (int i = 0; i < 26; i++)
    {
        counts[i] = 0;
    }
    for (int i = 0; i < size; i++)
    {
        int ascii = s[i];
        if (ascii >= 97 && ascii < 122)
        {
            counts[ascii - 97] += 1;
        }
        else if (ascii >= 65 && ascii <= 90)
        {
            counts[ascii - 65] += 1;
        }
    }
    int num = 0;
    char word;
    for (int i = 0; i < 26; i++)
    {
        if (counts[i] != 0)
        {
            word = i + 97;
            num += 1;
            cout << word << "出现了" << counts[i] << "次\n";
        }
    }
    cout << "非零次数为" << num << endl;
}