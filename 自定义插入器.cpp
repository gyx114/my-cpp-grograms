#include <bits/stdc++.h>
using namespace std;

template <class T>
ostream &operator<<(ostream &os, const vector<T> &vec)
{
    for (const auto &i : vec)
    {
        os << i << " ";
    }
    return os;
}

int main()
{
    vector<string> vec = {"hello", "world", "gyx", "nb"};
    cout << vec << endl;
    return 0;
}
