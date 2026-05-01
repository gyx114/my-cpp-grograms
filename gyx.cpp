#include <bits/stdc++.h>

using namespace std;
void f()
{
    ios::right;
}
int main()
{
    cout << "管宇轩" << endl;
    try
    {
        __throw_bad_alloc();
    }

    catch (exception &e)
    {
        cout << e.what() << endl;
    }
    cout.setf(ios::right);
    cout << setw(8) << setfill('g') << internal << showpos << +330 << endl;
}
