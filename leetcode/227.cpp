#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int calculate(string s)
    {
        vector<long long> nums;
        vector<char> ops;
        long long val = 0;
        int flag = 0; //-1:* -2:/
        for (int i = 0; i < s.size(); i++)
        {
            auto si = s[i];
            if (si != ' ')
            {
                if (si < '0' || si > '9')
                {
                    if (flag == -1)
                    {
                        nums.back() *= val;
                        ops.pop_back();
                        flag = 0;
                    }
                    else if (flag == -2)
                    {
                        nums.back() /= val;
                        ops.pop_back();
                        flag = 0;
                    }
                    else
                    {
                        nums.push_back(val);
                    }

                    if (si == '*')
                    {
                        flag = -1;
                    }
                    else if (si == '/')
                    {
                        flag = -2;
                    }

                    val = 0;
                    ops.push_back(si);
                }
                else
                {
                    val = val * 10 + (si - '0');
                }
            }
        }
        if (flag == -1)
        {
            nums.back() *= val;
            ops.pop_back();
            flag = 0;
        }
        else if (flag == -2)
        {
            nums.back() /= val;
            ops.pop_back();
            flag = 0;
        }
        else
        {
            nums.push_back(val);
        }

        int ans = nums.front();
        for (int i = 1; i < nums.size(); i++)
        {
            if (ops[i - 1] == '+')
            {
                ans += nums[i];
            }
            else
            {
                ans -= nums[i];
            }
        }

        return ans;
    }
};
