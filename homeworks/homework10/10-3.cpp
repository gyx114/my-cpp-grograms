#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v;
    int pre = -1;
    for (int i = 0; i < 1e4; i++)
    {
        if (v.capacity() != pre)
        {
            pre = v.capacity();
            cout << pre << endl;
        }
        v.push_back(0);
    }
}
