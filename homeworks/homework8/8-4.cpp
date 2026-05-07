#include <iostream>

class Counter
{
private:
    int cnt;

public:
    Counter(int c = 0) : cnt(c) {}
    ~Counter() {}
    int get_cnt()
    {
        return cnt;
    }
    void add_cnt(int n)
    {
        cnt += n;
    }
    void display()
    {
        std::cout << cnt << std::endl;
    }
    Counter operator+(const Counter &other)
    {
        return Counter(this->cnt + other.cnt);
    }
    Counter operator+(const int c)
    {
        return Counter(this->cnt + c);
    }
    friend int operator+(int a, const Counter &cnter);
};

int operator+(int a, const Counter &cnter)
{
    return a + cnter.cnt;
}

int main()
{
    Counter cnt1(1);
    Counter cnt2(2);
    (cnt1 + cnt2).display();
    (cnt1 + 666).display();
    std::cout << (666 + cnt2) << std::endl;
}
