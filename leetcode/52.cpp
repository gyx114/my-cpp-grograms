#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<string>> ans;
    vector<string> tmp;

    void backtrack(int n, int row, vector<bool> &col_used, vector<bool> &diag1_used, vector<bool> &diag2_used)
    {
        if (row == n)
        {
            ans.push_back(tmp);
            return;
        }

        for (int j = 0; j < n; j++)
        {
            if (col_used[j] || diag1_used[row + j] || diag2_used[n - 1 + j - row])
            {
                continue;
            }

            string s(n, '.');
            s[j] = 'Q';
            tmp.push_back(move(s));
            col_used[j] = true;
            diag1_used[row + j] = true;
            diag2_used[n - 1 + j - row] = true;

            backtrack(n, row + 1, col_used, diag1_used, diag2_used);

            col_used[j] = false;
            diag1_used[row + j] = false;
            diag2_used[n - 1 + j - row] = false;
            tmp.pop_back();
        }
    }

    int totalNQueens(int n)
    {
        vector<bool> col_used(n, false);
        vector<bool> diag1_used(2 * n - 1, false); // 不能填的副对角线
        vector<bool> diag2_used(2 * n - 1, false); // 不能填的主对角线
        backtrack(n, 0, col_used, diag1_used, diag2_used);
        return ans.size();
    }
};
