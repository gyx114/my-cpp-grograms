#include <iostream>

using namespace std;

class C
{
    static int count;

public:
    C()
    {
        count++;
    }
    static void showCount()
    {
        cout << count << endl;
    }
};

int C::count = 0;

int main()
{
    C c[2];
    C::showCount();
    C *d[2];
    C::showCount();
}
