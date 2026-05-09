#include <bits/stdc++.h>
using namespace std;
class Solution
// 抽象为图
// 一个单词抽象为一个节点
// 如果两个单词只差一个字母，将其相连
// 于是可以bfs搜索
{
public:
    void connect_next(string str1, int idx, vector<string> &wordList, unordered_set<int> &st_tmp, vector<bool> &visited)
    {
        if (visited[idx])
        {
            return;
        }
        auto str2 = wordList[idx];
        int diff = 0;
        for (int i = 0; i < str1.length(); i++)
        {
            if (str1[i] != str2[i])
            {
                diff++;
            }
            if (diff >= 2)
            {
                return;
            }
        }
        if (diff == 1)
        {
            st_tmp.insert(idx);
            visited[idx] = true;
        }
    }
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        int n = wordList.size();
        vector<bool> visited(n, false);
        int endidx = -1;
        for (int i = 0; i < n; i++)
        {
            if (wordList[i] == endWord)
            {
                endidx = i;
                break;
            }
        }
        if (endidx == -1)
        {
            return 0;
        }
        unordered_set<int> st;
        for (int i = 0; i < n; i++)
        {
            connect_next(beginWord, i, wordList, st, visited);
        }
        int cnt = 1;
        while (!st.empty())
        {
            unordered_set<int> st_tmp;
            if (st.count(endidx))
            {
                return cnt + 1;
            }
            for (int j : st)
            {
                for (int i = 0; i < n; i++)
                {
                    connect_next(wordList[j], i, wordList, st_tmp, visited);
                }
            }
            cnt++;
            st.swap(st_tmp);
        }
        return 0;
    }
};
