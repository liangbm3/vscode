/* ---------------- 模拟某人在给定命中率（accuracy）的情况下，朝targeAlive射击情况 ---------------- */
#include <iostream>
#include <ctime>
using namespace std;
void shoot(bool &targetAlive, double accuracy);
int main()
{
    double rate;
    int count;
    srand(time(0));
    bool alive = true;
    cout << "请输入命中率(0-1):\n";
    cin >> rate;
    cout << "请输入射击次数：\n";
    cin >> count;
    for (int t = 0; t < count; t++)
    {
        shoot(alive, rate);
        if (alive)
        {
            cout << "目标在" << (t + 1) << "次射击中存活\n";
        }
        else
        {
            cout << "目标在" << (t + 1) << "次射击中死亡\n";
            break;
        }
    }
    cout << "模拟结束！\n";
}

void shoot(bool &targetAlive, double accuracy)
{

    double t;
    t = (static_cast<double>(rand() % 101)) / 100;
    if (t < accuracy)
    {
        targetAlive = false;
    }
}