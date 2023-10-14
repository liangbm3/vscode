/* -------------------------------- 21点游戏简易版 -------------------------------- */

#include <iostream>
#include <ctime>
using namespace std;

int rollDice(void)
{
    int rand_num;
    rand_num = rand() % 13 + 1;
    switch (rand_num)
    {
    case 1:
        cout << "抽到的卡牌为A，点数为11\n";
        return 11;
        break;
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
        cout << "抽到的卡牌为" << rand_num << "，点数为" << rand_num << endl;
        return rand_num;
        break;
    case 11:
        cout << "抽到的卡牌为j，点数为10\n";
        return 10;
        break;
    case 12:
        cout << "抽到的卡牌为Q，点数为10\n";
        return 10;
        break;
    case 13:
        cout << "抽到的卡牌为K，点数为10\n";
        return 10;
        break;
    default:
        return 0;
        break;
    }
}

int getWager(int money)
{
    for (;;)
    {
        int betMoney;
        cin >> betMoney;
        if (betMoney > 0 && betMoney <= money)
        {
            return betMoney;
            break;
        }
        else
        {
            cout << "输入金额不合理，请重新输入：\n";
        }
    }
}

void playerTurn(int &wager, bool &bust, int &total, int &money)
{
    char command;

    cout << "现在是你的回合，总点数为" << total;
    cout << ",是否继续抽牌？(y/n)\n";
    cin >> command;
    if (command == 'y' || command == 'Y')
    {
        total += rollDice();
        cout << "你现在总点数为：" << total << endl;
        if (total >= 22)
        {
            bust = true;
            money -= wager;
            wager = 0;
            cout << "你的点数大于21，爆牌，庄家胜，游戏结束！\n";
        }
        else
        {
            cout << "回合结束！\n";
        }
    }
}

void houseTurn(int &wager, bool &bust, int &you_total, int &house_total, int &money)
{
    if (house_total < 17)
    {
        cout << "现在是庄家回合，庄家点数小于17，继续摸牌。\n";
        house_total += rollDice();
        cout << "庄家总点数为：" << house_total << endl;
        if (house_total >= 22)
        {
            bust = true;
            money += wager;
            wager = 0;
            cout << "庄家的点数大于21，爆牌，你胜，游戏结束！\n";
        }
        else if (house_total <= 21 && house_total >= 17)
        {
            cout << "总点数在17和21之间，比较大小！\n";
            if ((you_total - house_total) > 0)
            {
                cout << "你的点数大，你胜，游戏结束！";
                money += wager;
                wager = 0;
            }
            else if ((you_total - house_total) < 0)
            {
                cout << "庄家点数大，庄家胜，游戏结束！";
                money -= wager;
                wager = 0;
            }
            else if ((you_total - house_total) == 0)
            {
                cout << "点数一样大，平局，游戏结束！";
                wager = 0;
            }
            bust = true;
        }
    }
}

int main()
{
    srand(time(0));
    bool playing = true;
    int money = 50;
    int bet_money = 0;
    cout << "游戏开始!\n";
    char command;
    while (playing)
    {
        bool bust = false;
        int my_total_point = 0;
        int it_total_point = 0;
        cout << "请输入赌注：\n";
        bet_money = getWager(money);
        cout << "你成功输入了" << bet_money << "赌注!\n";
        cout << "开始抽牌！\n";
        cout << "你先抽两张牌。\n";
        my_total_point += rollDice();
        my_total_point += rollDice();
        cout << "现在你的总点数为：" << my_total_point << endl;
        cout << "庄家抽两张牌。\n";
        it_total_point = rollDice();
        cout << "现在庄家的总点数为：" << it_total_point << endl;
        while (!bust)
        {
            playerTurn(bet_money, bust, my_total_point, money);
            if (!bust)
            {

                houseTurn(bet_money, bust, my_total_point, it_total_point, money);
            }
        }
        cout << "你现在的钱为" << money << "，是否继续游戏？（y/n）\n";
        cin >> command;
        if ((command == 'y' || command == 'Y') && money > 0)
        {
            playing = true;
            cout << "继续游戏！\n";
        }
        else if (command == 'n' || command == 'N' || money == 0)
        {
            playing = false;
            cout << "游戏结束！\n";
        }
    }
}
