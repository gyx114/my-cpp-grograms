#include <bits/stdc++.h>
using namespace std;
int main()
{
    map<string, int> mp;
    string tmp;
    while (cin >> tmp)
    {
        if (mp[tmp])
        {
            cout << tmp << "出现过,之前出现过" << mp[tmp] << "次" << endl;
        }
        else
        {
            cout << "没出现过" << endl;
        }
        mp[tmp]++;
    }
}
