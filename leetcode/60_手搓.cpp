#include <bits/stdc++.h>
using namespace std;

// still just math

class Solution
{
public:
    vector<int> factorial = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

    int getit(int n, int k)
    // n个数全排列，第k个排列的第一个数是可选集中第几个
    // 可选集：未被选中的数组成的升序集合
    {
        return (k - 1) / factorial[n - 1] + 1;
    }

    string ans;
    // 借助匿名对象来构造
    vector<bool> is_used = vector<bool>(10, false);
    void solve(int n, int k)
    {
        if (n == 0)
        {
            return;
        }
        int x = getit(n, k);
        int cnt = 0;
        int which;
        for (int i = 1; i <= 9; i++)
        {
            if (!is_used[i])
            {
                cnt++;
            }
            if (cnt == x)
            {
                which = i;
                break;
            }
        }

        is_used[which] = true;
        ans.push_back(which + '0');
        // 以可选集中第x个数为开头，至少是第几个排列
        // 这是对getit的逆向
        int kmin = (x - 1) * factorial[n - 1] + 1;
        solve(n - 1, k - kmin + 1);
    }
    string getPermutation(int n, int k)
    {
        solve(n, k);
        return ans;
    }
};
