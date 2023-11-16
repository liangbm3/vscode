#include "function.h"

string lock(string instring)
{
    string outstring;

    for (int i = 0; i < instring.size(); i++)
    {
        outstring.push_back(instring[i] + 3);
    }
    return outstring;
}

string unlock(string instring)
{
    string outstring;
    for (int i = 0; i < instring.size(); i++)
    {
        outstring.push_back(instring[i] - 3);
    }
}

Count_res count_character(string in_string)
{
    Count_res res;
    sort(in_string.begin(), in_string.end());
    int count[100];
    string word_;
    int a = 0;
    int total = 0;
    while (true)
    {
        count[a] = 0;
        for (int i = total; i < in_string.size(); i++)
        {
            count[a] += 1;
            if (in_string[i + 1] != in_string[i])
            {
                word_.push_back(in_string[i]);
                break;
            }
        }
        total = total + count[a];
        a += 1;
        if (a > in_string.size())
        {
            break;
        }
    }
    for (int i = 0; i < word_.size(); i++)
    {
        res.count_flag[i] = count[i];
        res.word.push_back(word_[i]);
    }
    return res;
}