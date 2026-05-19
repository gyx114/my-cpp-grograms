#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // 埃氏筛
    // 埃氏筛可能有重复标记(2*6和3*4)，可用欧拉线性筛
    int countPrimes(int n)
    {
        if (n <= 2)
        {
            return 0;
        }
        vector<bool> is_prime(n, true);
        is_prime[0] = is_prime[1] = false;
        vector<int> primes;
        for (int i = 2; i < n; i++)
        {
            if (is_prime[i])
            {
                primes.push_back(i);
            }
            for (auto p : primes)
            {
                if (p * i >= n)
                {
                    break;
                }
                else
                {
                    is_prime[p * i] = false;
                }
            }
        }
        return primes.size();
    }
};
