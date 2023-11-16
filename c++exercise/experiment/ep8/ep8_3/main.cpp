#include "function.h"
using namespace std;

int main()
{
    string init_string;
    string result_of_string;
    Count_res res;
    int command;
    cout << "请输入字符串：\n";
    cin >> init_string;
    cout << "请选择加密或解密：（1加密，2解密）\n";
    cin >> command;
    if (command == 1)
    {
        result_of_string = lock(init_string);
        cout << "加密结果为：" << result_of_string << endl;
    }
    if (command == 2)
    {
        result_of_string = unlock(init_string);
        cout << "解密结果为：" << result_of_string << endl;
    }
    res = count_character(init_string);
    for (int i = 0; i < res.word.size(); i++)
    {
        cout << res.word[i] << "出现了" << res.count_flag[i] << "次\n";
    }
    
}