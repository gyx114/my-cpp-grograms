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

    auto it = v1.begin() + 3;
    v1.insert(it, 8);
    cout << *it << endl;
    cout << *(it - 1) << endl;
}
