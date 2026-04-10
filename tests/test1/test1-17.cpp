#include <iostream>
using namespace std;

void fun(short a)
{
    cout << "short " << a << endl;
}

void fun(int a)
{
    cout << "int " << a << endl;
}

void fun(long a)
{
    cout << "long " << a << endl;
}

int main()
{
    fun(315);
    fun(315L);
    fun(315LL);
}
