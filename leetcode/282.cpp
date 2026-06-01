#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> ans;
    string tmp;
#define ll long long
    void backtrack(string &num, int target, int idx, ll pre, ll total, int preop, bool premulti)
    // pre:上个数
    // total:上个数之前的结果
    // preop:上个数前面的符号，1:+,0:-
    // premulti:上个符号是不是*,用于限制拼接逻辑
    {
        if (idx == 0) // 开始
        {
            tmp += num[0];
            backtrack(num, target, 1, num[0] - '0', 0, 1, 0);
            return;
        }
        if (idx >= num.size()) // 结束
        {
            total += (preop ? pre : -pre);
            if (total == target)
            {
                ans.push_back(tmp);
            }
            return;
        }

        int val = num[idx] - '0';

        if (!premulti && pre != 0) // 拼接数字，但是不能在乘法中用，并且不能以0开头(等同于pre!=0)
        {
            tmp += num[idx];
            backtrack(num, target, idx + 1, pre * 10 + val, total, preop, 0);
            tmp.pop_back();
        }

        tmp += '+';
        tmp += num[idx];
        backtrack(num, target, idx + 1, val, total + (preop ? pre : -pre), 1, 0);
        tmp.pop_back();
        tmp.pop_back();

        tmp += '-';
        tmp += num[idx];
        backtrack(num, target, idx + 1, val, total + (preop ? pre : -pre), 0, 0);
        tmp.pop_back();
        tmp.pop_back();

        tmp += '*';
        ll multival = 0;
        int k = 1;
        if (num[idx] == '0') // 有前导0，只能是单独一个0
        {
            tmp += num[idx + k - 1];
            multival = multival * 10 + num[idx + k - 1] - '0';
            backtrack(num, target, idx + k, pre * multival, total, preop, 1);
            tmp.pop_back();
            tmp.pop_back();
        }
        else
        {
            for (; idx + k - 1 < num.size(); k++) // 乘法的拼接
            {
                tmp += num[idx + k - 1];
                multival = multival * 10 + num[idx + k - 1] - '0';
                backtrack(num, target, idx + k, pre * multival, total, preop, 1);
            }
            for (int ii = 0; ii < k; ii++)
            // 注意，做完最后一个循环后仍有k++,最终跳出循环时k为push次数+1，因此只需要pop k次
            {
                tmp.pop_back();
            }
        }
    }

    vector<string> addOperators(string &num, int target)
    {
        backtrack(num, target, 0, 0, 0, 1, 0);
        return ans;
    }
};
