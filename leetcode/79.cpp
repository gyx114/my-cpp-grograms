#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string tmp;
    bool is_ok = false;

    void backtrack(vector<vector<char>> &board, vector<vector<bool>> &visited, string &word, int x, int y)
    {
        int m = board.size();
        int n = board[0].size();
        if (tmp.size() == word.size()) // 比tmp==word更高效，因为tmp严格按照word增长
        {
            is_ok = true;
            return;
        }
        if (x >= m || x < 0 || y < 0 || y >= n)
        {
            return;
        }
        if (visited[x][y])
        {
            return;
        }

        if (board[x][y] == word[tmp.size()]) // 能接上
        {
            visited[x][y] = true;
            tmp.push_back(board[x][y]);

            backtrack(board, visited, word, x + 1, y);
            if (is_ok)
            {
                return;
            }
            backtrack(board, visited, word, x - 1, y);
            if (is_ok)
            {
                return;
            }
            backtrack(board, visited, word, x, y + 1);
            if (is_ok)
            {
                return;
            }
            backtrack(board, visited, word, x, y - 1);
            if (is_ok)
            {
                return;
            }

            visited[x][y] = false;
            tmp.pop_back();
        }
        else // 接不上
        {
            return;
        }
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                backtrack(board, visited, word, i, j);
                if (is_ok)
                {
                    return true;
                }
            }
        }
        return is_ok;
    }
};
