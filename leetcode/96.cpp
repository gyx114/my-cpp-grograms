#include <bits/stdc++.h>
using namespace std;

// just math
// 找递推：
// 显然，升序序列[a,b]能生成的bst数只与区间长度有关
// 因此长度为n的序列等价于[1,n]的序列
// 对于[1,n] 我选择一个i作为根，由于bst的性质，[1,i-1]组成左子树，[i+1,n]组成右子树
// 设长度为n的序列生成的bst数为A(n)
// 则有:A(n)=sigma[i=1->n](A(i-1)*A(n-i))
// 有递推式了，用dp

class Solution
{
public:
    int d_p(int n, vector<int> &dp)
    {
        if (dp[n] != -1)
        {
            return dp[n];
        }
        if (n == 0)
        {
            return dp[n] = 1;
        }
        else
        {
            int tmp = 0;
            for (int i = 1; i <= n; i++)
            {
                tmp += d_p(i - 1, dp) * d_p(n - i, dp);
            }
            return dp[n] = tmp;
        }
    }
    int numTrees(int n)
    {
        vector<int> dp(n + 1, -1);
        return d_p(n, dp);
    }
};
