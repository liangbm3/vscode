#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Score
{
    float usual_score;
    float mid_term_score;
    float end_term_score;
    float total_score;
};
int getRand(int min, int max);
int main()
{
    Score stu_scores[51];
    srand(time(0));
    float total = 0;
    for (int i = 0; i < 51; i++)
    {
        stu_scores[i].usual_score = getRand(50, 100);
        stu_scores[i].mid_term_score = getRand(20, 100);
        stu_scores[i].end_term_score = getRand(20, 100);
        stu_scores[i].total_score = 0.1 * stu_scores[i].usual_score + 0.3 * stu_scores[i].mid_term_score + 0.6 * stu_scores[i].end_term_score;
        total = total + stu_scores[i].total_score;
    }
    float average_score = total / 51;
    for (int i = 0; i < 51; i++)
    {
        cout << "第" << i + 1 << "个学生平时成绩为：" << stu_scores[i].usual_score;
        cout << "，期中成绩为：" << stu_scores[i].mid_term_score;
        cout << "，期末成绩为：" << stu_scores[i].end_term_score;
        cout << "，总成绩为：" << stu_scores[i].total_score << endl;
    }
    cout << "该班的平均分为：" << average_score << endl;
}

int getRand(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}