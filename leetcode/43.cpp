#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string multiply(string num1, string num2)
    {

        if (num1 == "0" || num2 == "0")
        {
            return "0";
        }

        if (num1.length() < num2.length())
        {
            num1.swap(num2);
        }

        string ans;
        int jinwei = 0;
        int remain = 0;
        int tmp = 0;
        for (auto it2 = num2.rbegin(); it2 != num2.rend(); it2++)
        {
            for (auto it1 = num1.rbegin(); it1 != num1.rend(); it1++)
            {
                int i = it2 - num2.rbegin();
                int j = it1 - num1.rbegin();
                int idx = i + j;
                tmp = (*it1 - '0') * (*it2 - '0') + jinwei;
                remain = tmp % 10;
                jinwei = tmp / 10;
                if (ans.length() < idx + 1)
                {
                    ans.push_back(remain + '0');
                }
                else
                {
                    tmp = remain + ans[idx] - '0';
                    remain = tmp % 10;
                    jinwei += tmp / 10;
                    ans[idx] = remain + '0';
                }
            }
            if (jinwei != 0)
            {
                ans.push_back(jinwei + '0');
                jinwei = 0;
            }
        }
        if (jinwei != 0)
        {
            ans.push_back(jinwei + '0');
            jinwei = 0;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
