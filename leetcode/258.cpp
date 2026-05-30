#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // /*math*/
    // int addDigits(int num)
    // {
    //     return (num - 1) % 9 + 1;
    // }
    int addDigits(int num)
    {
        int ans = 0;
        while (true)
        {
            while (num)
            {
                ans += num % 10;
                num /= 10;
            }
            num = ans;
            if (ans < 10)
            {
                break;
            }
            ans = 0;
        }
        return ans;
    }
};
