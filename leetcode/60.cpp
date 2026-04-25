#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string getPermutation(int n, int k)
    {
        string ans;
        for (int i = 0; i < n; i++)
        {
            ans.push_back(i + '0' + 1);
        }
        for (int i = 0; i < k - 1; i++)
        {
            next_permutation(ans.begin(), ans.end());
        }
        return ans;
    }
};
