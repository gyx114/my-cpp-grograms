#include <iostream>
using namespace std;

class ERR : public exception
{
public:
    ERR(int n) : time(n) {}

    void diagnose()
    {
        cerr << "time=" << time << endl;
    }

    const char *what()
    {
        return "hello";
    }

private:
    int time;
};

void f()
{
    for (int i = 1; i <= 10; i++)
    {
        cout << i << endl;
        if (i == 6)
        {
            throw ERR(i);
        }
    }
}

int main()
{
    try
    {
        try
        {
            f();
        }
        catch (...)
        {
            cout << "abc" << endl;
            throw;
        }
    }
    catch (ERR &e)
    {
        e.diagnose();
        cout << e.what() << endl;
    }
}
