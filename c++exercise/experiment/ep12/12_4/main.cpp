#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

// 不考虑大小写的单词查找
const char *findWordIgnoreCase(const char *sentence, const char *word)
{
    int sentenceLength = strlen(sentence);
    int wordLength = strlen(word);

    for (int i = 0; i <= sentenceLength - wordLength; ++i)
    {
        const char *ptr_sentence = sentence + i;
        const char *ptr_word = word;

        while (*ptr_word && (toupper(*ptr_sentence) == toupper(*ptr_word)))
        {
            ++ptr_sentence;
            ++ptr_word;
        }

        if (!*ptr_word)
        {
            return sentence + i; // 单词找到，返回位置
        }
    }

    return nullptr; // 没有找到
}

// 考虑大小写的单词查找
const char *findWordCaseSensitive(const char *sentence, const char *word)
{
    int sentenceLength = strlen(sentence);
    int wordLength = strlen(word);

    for (int i = 0; i <= sentenceLength - wordLength; ++i)
    {
        const char *ptr_sentence = sentence + i;
        const char *ptr_word = word;

        while (*ptr_word && (*ptr_sentence == *ptr_word))
        {
            ++ptr_sentence;
            ++ptr_word;
        }

        if (!*ptr_word)
        {
            return sentence + i; // 单词找到，返回位置
        }
    }

    return nullptr; // 没有找到
}

int main()
{
    const int maxSize = 100;
    char sentence[maxSize];
    char word[maxSize];

    cout << "输入一个句子: ";
    cin.getline(sentence, maxSize);

    cout << "输入要查找的单词: ";
    cin.getline(word, maxSize);

    // 不考虑大小写的查找
    const char *foundIgnoreCase = findWordIgnoreCase(sentence, word);
    if (foundIgnoreCase)
    {
        cout << "单词在的位置(不考虑大小写): " << foundIgnoreCase - sentence << endl;
    }
    else
    {
        cout << "单词没有找到(不考虑大小写)" << endl;
    }

    // 考虑大小写的查找
    const char *foundCaseSensitive = findWordCaseSensitive(sentence, word);
    if (foundCaseSensitive)
    {
        cout << "单词在的位置(考虑大小写): " << foundCaseSensitive - sentence << endl;
    }
    else
    {
        cout << "单词没有找到(考虑大小写)" << endl;
    }

    return 0;
}
