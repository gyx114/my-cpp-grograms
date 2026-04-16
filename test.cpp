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
    vector<int> v1 = {1, 2, 3, 4};
    list<int> ls = {1, 2, 3, 4};
    auto it = ls.begin();
}
