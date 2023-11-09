#include <iostream>
#include <unistd.h>
#include <string>
using namespace std;
int main()
{
    string top = "横联：龙盘虎踞";
    string up = "上联：龙引千江水";
    string down = "下联：虎跃万重山";
    int length1 = top.length();
    int length2 = up.length();
    int length3 = down.length();
    for (int i = 0; i < length1; i++)
    {
        cout << top[i];
        usleep(100000);
    }
    cout << endl;
    for (int i = 0; i < length2; i++)
    {
        cout << up[i];
        usleep(100000);
    }
    cout << endl;
    for (int i = 0; i < length3; i++)
    {
        cout << down[i];
        usleep(100000);
    }
}