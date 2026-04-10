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
    vector<int> v1 = {1, 2, 3};
    v1.insert(v1.begin() + 3, 6);
    cout << v1 << endl;
}
