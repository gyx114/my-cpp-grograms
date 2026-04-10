#include <iostream>
using namespace std;

struct People
{
    int food;
};

// 在这里实现eat和how_are_you两个函数

void eat(People p, int val)
{
    p.food += val;
}

void how_are_you(People p)
{
    int fd = p.food;
    if (fd == 0)
    {
        cout << "I am starved" << endl;
    }
    else if (fd < 5)
    {
        cout << "I am hungry" << endl;
    }
    else
    {
        cout << "I am fine, thank you and you?" << endl;
    }
}

int main()
{
    struct People p = {0};
    eat(p, 3);
    p.food -= 10;
    cout << p.food << endl;
    how_are_you(p);
}
