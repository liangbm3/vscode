#include <iostream>
#include <string>
using namespace std;

int main()
{
    string lock_list = "abcdefghijklmnopqrstuvwxyz.,";
    string unlock_list = "suvwxz.encryptabdfghijklmoq,";
    string init_string;
    cout << "输入字符串:";
    cin >> init_string;
    string new_string1, new_string2;
    int list1, list2;
    for (int i = 0; i < init_string.size(); i++)
    {
        list1 = lock_list.find(init_string[i]);
        list2 = unlock_list.find(init_string[i]);
        if (list1 != -1)
        {
            new_string1.push_back(unlock_list[list1]);
        }
        if (list2 != -1)
        {
            new_string2.push_back(lock_list[list2]);
        }
    }
    cout << "加密结果为" << new_string1 << endl;
    cout << "解密结果为" << new_string2 << endl;
}
