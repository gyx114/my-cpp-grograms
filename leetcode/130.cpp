#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // 直接找被包裹的O比较难实现
    // 换个思路，找不被包裹的O
    // 从边缘的O出发，遇到相邻的O就标记之
    void search(vector<vector<char>> &board, vector<unordered_set<int>> &stay, int i, int j)
    {
        int m = board.size();
        int n = board[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n)
        {
            return;
        }
        if (board[i][j] == 'O')
        {
            stay[i].insert(j);
            board[i][j] = 'X';
            search(board, stay, i + 1, j);
            search(board, stay, i - 1, j);
            search(board, stay, i, j + 1);
            search(board, stay, i, j - 1);
        }
    }
    void solve(vector<vector<char>> &board)
    {
        int m = board.size();
        int n = board[0].size();
        vector<unordered_set<int>> stay(m);
        for (int j = 0; j < n; j++)
        {
            if (board[0][j] == 'O')
            {
                search(board, stay, 0, j);
            }
            if (board[m - 1][j] == 'O')
            {
                search(board, stay, m - 1, j);
            }
        }
        for (int i = 0; i < m; i++)
        {

            if (board[i][0] == 'O')
            {
                search(board, stay, i, 0);
            }
            if (board[i][n - 1] == 'O')
            {
                search(board, stay, i, n - 1);
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (stay[i].count(j))
                {
                    board[i][j] = 'O';
                }
                else
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
