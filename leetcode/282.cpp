#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> ans;
    string tmp;
#define ll long long
    void backtrack(string &num, int target, int idx, ll pre, ll total, int preop, bool premulti) // 1:+,0:-
    {
        if (idx == 0)
        {
            tmp += num[0];
            backtrack(num, target, 1, num[0] - '0', 0, 1, 0);
            return;
        }
        if (idx >= num.size())
        {
            total += (preop ? pre : -pre);
            if (total == target)
            {
                ans.push_back(tmp);
            }
            return;
        }

        int val = num[idx] - '0';

        if (!premulti && pre != 0)
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
        if (num[idx] == '0')
        {
            tmp += num[idx + k - 1];
            multival = multival * 10 + num[idx + k - 1] - '0';
            backtrack(num, target, idx + k, pre * multival, total, preop, 1);
            tmp.pop_back();
            tmp.pop_back();
        }
        else
        {
            for (; idx + k - 1 < num.size(); k++)
            {
                tmp += num[idx + k - 1];
                multival = multival * 10 + num[idx + k - 1] - '0';
                backtrack(num, target, idx + k, pre * multival, total, preop, 1);
            }
            for (int ii = 0; ii < k; ii++)
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
