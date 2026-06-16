#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int nthSuperUglyNumber(int n, vector<int> &primes)
    {
#define ll long long
        int sz = primes.size();
        vector<int> dp(n);
        vector<int> pointers(sz);
        // 多指针，x=pointers[j]表示下一个丑数=primes[j]*dp[x]
        dp[0] = 1;
        for (int i = 1; i < n; i++)
        {
            ll min_x = LONG_LONG_MAX;
            for (int j = 0; j < sz; j++) // 找最小的生成数
            {
                ll x = (ll)dp[pointers[j]] * (ll)primes[j];
                min_x = min(min_x, x);
            }
            for (int j = 0; j < sz; j++)
            {
                ll x = (ll)dp[pointers[j]] * (ll)primes[j];
                if (x == min_x) // 对于所有能得出min_x的pointer,都要右移，否则下一次循环又会生成一遍min_x，重复
                {
                    pointers[j]++;
                }
            }
            dp[i] = min_x;
        }
        return dp[n - 1];
    }
};
