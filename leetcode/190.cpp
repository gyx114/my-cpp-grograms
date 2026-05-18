#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int reverseBits(int n)
    {
        vector<int> tmp(32);
        int cnt = 0;
        while (n)
        {
            tmp[cnt++] = n % 2;
            n >>= 1;
        }
        int ans = 0;
        for (auto i : tmp)
        {
            ans <<= 1;
            ans += i;
        }
        return ans;
    }
};
