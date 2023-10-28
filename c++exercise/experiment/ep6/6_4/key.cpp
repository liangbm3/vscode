#include "key.h"
using namespace std;
void Encry(string *strI, int numB, int model)
{
    string initital = *strI;
    int length = initital.length();
    string result;
    switch (model)
    {
    case 1:
        for (int i = 0; i < length; i++)
        {
            if (initital[i] >= 65 && initital[i] <= 90)
            {
                if ((initital[i] + numB) < 65)
                {
                    result += (char)((initital[i] + numB + 26));
                }
                else if ((initital[i] + numB > 90))
                {
                    result += (char)((initital[i] + numB - 26));
                }
                else
                {
                    result += (char)((initital[i] + numB));
                }
            }
            else if (initital[i] >= 97 && initital[i] <= 122)
            {
                if ((initital[i] + numB) < 97)
                {
                    result += (char)((initital[i] + numB + 26));
                }
                else if ((initital[i] + numB > 122))
                {
                    result += (char)((initital[i] + numB - 26));
                }
                else
                {
                    result += (char)((initital[i] + numB));
                }
            }
            else
            {
                cout << "请输入字母\n";
                return;
            }
        }
        break;
    case 2:
        for (int i = 0; i < length; i++)
        {
            if (initital[i] >= 65 && initital[i] <= 90)
            {
                if ((initital[i] - numB) < 65)
                {
                    result += (char)((initital[i] - numB + 26));
                }
                else if ((initital[i] - numB > 90))
                {
                    result += (char)((initital[i] - numB - 26));
                }
                else
                {
                    result += (char)((initital[i] - numB));
                }
            }
            else if (initital[i] >= 97 && initital[i] <= 122)
            {
                if ((initital[i] - numB) < 97)
                {
                    result += (char)((initital[i] - numB + 26));
                }
                else if ((initital[i] - numB > 122))
                {
                    result += (char)((initital[i] - numB - 26));
                }
                else
                {
                    result += (char)((initital[i] - numB));
                }
            }
            else
            {
                cout << "请输入字母\n";
                return;
            }
        }
        break;
    default:
        break;
    }
    *strI = result;
}