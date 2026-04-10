#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Dice
{
private:
    int value;

public:
    Dice()
    {
        roll();
    }

    void roll()
    {
        value = rand() % 6 + 1;
    }

    int getValue() const
    {
        return value;
    }
};

int main()
{
    unsigned int seed;
    cout << "请输入随机数种子（无符号整数）：";
    cin >> seed;

    srand(seed);

    Dice dice1, dice2;
    int point = 0;
    bool gameOver = false;

    dice1.roll();
    dice2.roll();
    int sum = dice1.getValue() + dice2.getValue();
    cout << "第一轮投骰子和：" << sum << endl;

    if (sum == 7 || sum == 11)
    {
        cout << "恭喜！第一轮获胜！" << endl;
        gameOver = true;
    }
    else if (sum == 2 || sum == 3 || sum == 12)
    {
        cout << "很遗憾！第一轮失败！" << endl;
        gameOver = true;
    }
    else
    {
        point = sum;
        cout << "目标点数：" << point << "，继续游戏..." << endl;
    }

    while (!gameOver)
    {
        dice1.roll();
        dice2.roll();
        sum = dice1.getValue() + dice2.getValue();
        cout << "当前轮投骰子和：" << sum << endl;

        if (sum == point)
        {
            cout << "恭喜！达成目标点数，获胜！" << endl;
            gameOver = true;
        }
        else if (sum == 7)
        {
            cout << "很遗憾！和为7，失败！" << endl;
            gameOver = true;
        }
    }

    return 0;
}
