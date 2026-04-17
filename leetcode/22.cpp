#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string tmp;
    vector<string> ans;

    void backtrack(int l, int r, int n)
    {
        if (tmp.length() == 2 * n)
        {

            ans.push_back(tmp);

            return;
        }
        if (l < n)
        {
            tmp.push_back('(');
            backtrack(l + 1, r, n);
            tmp.pop_back();
        }

        if (r < l)
        {
            tmp.push_back(')');
            backtrack(l, r + 1, n);
            tmp.pop_back();
        }
    }

    vector<string> generateParenthesis(int n)
    {
        backtrack(0, 0, n);
        return ans;
    }
};
