#ifndef __FUNCTION_H__
#define __FUNCTION_H__

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Count_res
{
    int count_flag[100];
    string word;
};
char map_lock(char in_word);
char map_unlock(char in_word);
string lock(string in_string);
string unlock(string in_string);
Count_res count_character(string in_string);


#endif