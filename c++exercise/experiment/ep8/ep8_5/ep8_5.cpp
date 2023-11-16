#include <iostream>
#include <fstream>

using namespace std;

int gpa2hundred_score(float gpa);
void hundred_score2gpa();
int main()
{
    int choice;
    int hundred_score;
    float gpa;
    cout << "请选择输入方式（1.从键盘输入或2.从文件读取）:";
    cin >> choice;
    if (choice == 1)
    {
        cout << "请输入一个绩点:";
        cin >> gpa;
        hundred_score = gpa2hundred_score(gpa);
        cout << "百分制成绩为" << hundred_score;
    }
    else if (choice == 2)
    {
        hundred_score2gpa();
    }
    else
    {
        cout << "输入不正确\n";
    }
}

int gpa2hundred_score(float gpa)
{
    int hudred_score;
    hudred_score = (gpa - 1) * 10 + 60;
    return hudred_score;
}

void hundred_score2gpa()
{
    string line;
    string filepath;
    ifstream infile;
    float gpa;
    int hundred_score;
    cout << "请输入文件路径:";
    cin >> filepath;
    infile.open(filepath);
    cout << "全班分数及绩点如下：\n";
    while (!infile.eof())
    {
        getline(infile, line);
        hundred_score = atoi(line.c_str());
        gpa = (float)(hundred_score - 60) / 10.0 + 1;
        if (hundred_score < 60)
        {
            gpa = 0;
        }
        cout << hundred_score << "->" << gpa << endl;
    }
}