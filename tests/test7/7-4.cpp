#include <iostream>
using namespace std;

class Clock
{
public:
    Clock(int hour = 0, int minute = 0, int second = 0);
    void showTime() const;
    Clock &operator++();   // 前置++（返回引用）
    Clock operator++(int); // 后置++（返回值，非引用）
private:
    int hour, minute, second;
};

// 构造函数：检查时间合法性
Clock::Clock(int hour, int minute, int second)
{
    if (0 <= hour && hour < 24 && 0 <= minute && minute < 60 && 0 <= second && second < 60)
    {
        this->hour = hour;
        this->minute = minute;
        this->second = second;
    }
    else
    {
        cout << "Time error!" << endl;
    }
}

// 显示时间
void Clock::showTime() const
{
    cout << hour << ":" << minute << ":" << second << endl;
}

// 前置++：返回自身引用（支持连续前置++）
Clock &Clock::operator++()
{
    second++;
    if (second >= 60)
    {
        second -= 60;
        minute++;
        if (minute >= 60)
        {
            minute -= 60;
            hour = (hour + 1) % 24;
        }
    }
    return *this; // 返回当前对象的引用
}

// 后置++：返回临时对象（不支持连续后置++，因为返回的是临时对象，临时对象不能再次调用后置++）
Clock Clock::operator++(int)
{
    Clock old = *this; // 保存原始状态
    ++(*this);         // 调用前置++修改自身
    return old;        // 返回原始状态（临时对象）
}

int main()
{
    Clock myClock(23, 59, 59);
    cout << "First time output: ";
    myClock.showTime();
    cout << "Show myClock++:    ";
    (myClock++ ++ ++ ++ ++ ++ ++ ++).showTime();
    (myClock).showTime();
    cout << "Show ++myClock:    ";
    (++ ++myClock).showTime();
    return 0;
}
