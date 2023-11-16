#include "function.h"

string lock(string instring)
{
    string outstring;
    for (int i = 0; i < instring.size(); i++)
    {
        outstring.push_back(map_lock(instring[i]));
    }
    return outstring;
}

string unlock(string instring)
{
    string outstring;
    for (int i = 0; i < instring.size(); i++)
    {
        outstring.push_back(map_unlock(instring[i]));
    }
    return outstring;
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

char map_lock(char in_word)
{
    char new_word;
    switch (in_word)
    {
    case 'a':
        new_word = 's';
        break;
    case 'b':
        new_word = 'u';
        break;
    case 'c':
        new_word = 'v';
        break;
    case 'd':
        new_word = 'w';
        break;
    case 'e':
        new_word = 'x';
        break;
    case 'f':
        new_word = 'z';
        break;
    case 'g':
        new_word = '.';
        break;
    case 'h':
        new_word = 'e';
        break;
    case 'i':
        new_word = 'n';
        break;
    case 'j':
        new_word = 'c';
        break;
    case 'k':
        new_word = 'r';
        break;
    case 'l':
        new_word = 'y';
        break;
    case 'm':
        new_word = 'p';
        break;
    case 'n':
        new_word = 't';
        break;
    case 'o':
        new_word = 'a';
        break;
    case 'p':
        new_word = 'b';
        break;
    case 'q':
        new_word = 'd';
        break;
    case 'r':
        new_word = 'f';
        break;
    case 's':
        new_word = 'g';
        break;
    case 't':
        new_word = 'h';
        break;
    case 'u':
        new_word = 'i';
        break;
    case 'v':
        new_word = 'j';
        break;
    case 'w':
        new_word = 'k';
        break;
    case 'x':
        new_word = 'l';
        break;
    case 'y':
        new_word = 'm';
        break;
    case 'z':
        new_word = 'o';
        break;
    case '.':
        new_word = 'q';
        break;
    case ',':
        new_word = ',';
        break;
    default:
        break;
    }
    return new_word;
}

char map_unlock(char in_word)
{
    char new_word;
    switch (in_word)
    {
    case 's':
        new_word = 'a';
        break;
    case 'u':
        new_word = 'b';
        break;
    case 'v':
        new_word = 'c';
        break;
    case 'w':
        new_word = 'd';
        break;
    case 'x':
        new_word = 'e';
        break;
    case 'z':
        new_word = 'f';
        break;
    case '.':
        new_word = 'g';
        break;
    case 'e':
        new_word = 'h';
        break;
    case 'n':
        new_word = 'i';
        break;
    case 'c':
        new_word = 'j';
        break;
    case 'r':
        new_word = 'k';
        break;
    case 'y':
        new_word = 'l';
        break;
    case 'p':
        new_word = 'm';
        break;
    case 't':
        new_word = 'n';
        break;
    case 'a':
        new_word = 'o';
        break;
    case 'b':
        new_word = 'p';
        break;
    case 'd':
        new_word = 'q';
        break;
    case 'f':
        new_word = 'r';
        break;
    case 'g':
        new_word = 's';
        break;
    case 'h':
        new_word = 't';
        break;
    case 'i':
        new_word = 'u';
        break;
    case 'j':
        new_word = 'v';
        break;
    case 'k':
        new_word = 'w';
        break;
    case 'l':
        new_word = 'x';
        break;
    case 'm':
        new_word = 'y';
        break;
    case 'o':
        new_word = 'z';
        break;
    case 'q':
        new_word = '.';
        break;
    case ',':
        new_word = ',';
        break;
    default:
        break;
    }
    return new_word;
}