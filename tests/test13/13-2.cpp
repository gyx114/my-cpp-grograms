#include <iostream>
#include <stdexcept>
#include <memory>
using namespace std;

void fun(unsigned long long sz)
{
    char *arr = new char[sz];
    delete[] arr;
}

int main()
{
    unsigned long long l = 1;
    unsigned long long r = 1e15;
    unsigned long long mid;
    unsigned long long ans = 0;
    bool is_first = true;
    while (l <= r)
    {
        bool is_too_big = false;
        mid = l + (r - l) / 2;
        try
        {
            fun(mid);
        }
        catch (const exception &e)
        {
            if (is_first)
            {
                cerr << e.what() << '\n';
                is_first = false;
            }
            is_too_big = true;
        }
        if (is_too_big)
        {
            r = mid - 1;
        }
        else
        {
            ans = mid;
            l = mid + 1;
        }
    }
    cout << ans << endl;
}
