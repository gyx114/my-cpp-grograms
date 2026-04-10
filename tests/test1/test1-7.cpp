#include <iostream>
using namespace std;

int main()
{
    auto a = 0;
    auto b = 0.0;
    auto c = 0.0f;
    auto d = b + c;
    decltype(c) e = a + b;
    cout << sizeof(a) << endl;
    cout << sizeof(b) << endl;
    cout << sizeof(c) << endl;
    cout << sizeof(d) << endl;
    cout << sizeof(e) << endl;
    cout << sizeof(sizeof(e)) << endl;
}
