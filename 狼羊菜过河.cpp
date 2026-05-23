#include <bits/stdc++.h>
using namespace std;
bool check(unsigned s)
{
    unsigned W = 0b1000, S = 0b0100, V = 0b0010, P = 0b0001;
    // 如果狼和羊在同一侧且人不在该侧 -> 不合法
    bool wolf_side = (s & W) != 0;
    bool sheep_side = (s & S) != 0;
    bool people_side = (s & P) != 0;
    if ((wolf_side == sheep_side) && (people_side != wolf_side))
        return false;
    // 如果羊和菜在同一侧且人不在该侧 -> 不合法
    bool veg_side = (s & V) != 0;
    if ((sheep_side == veg_side) && (people_side != sheep_side))
        return false;
    return true;
}
int main()
{
    unsigned final = 0b1111;
    unsigned wolf = 0b1000;
    unsigned sheep = 0b0100;
    unsigned vegetable = 0b0010;
    unsigned people = 0b0001;
    queue<unsigned> q;
    unordered_map<unsigned, unsigned> prev;
    vector<char> visited(16, 0);

    const unsigned start = 0;
    visited[start] = 1;
    q.push(start);

    bool found = false;
    while (!q.empty())
    {
        unsigned cur = q.front();
        q.pop();
        if (cur == final)
        {
            found = true;
            break;
        }

        // 生成四种可能的移动：不带/带菜/带羊/带狼
        unsigned candidates[4] = {
            cur ^ people,
            cur ^ people ^ vegetable,
            cur ^ people ^ sheep,
            cur ^ people ^ wolf};

        for (unsigned nx : candidates)
        {
            if (visited[nx])
                continue;
            if (!check(nx))
                continue;
            visited[nx] = 1; // 标记为已发现，避免重复入队
            prev[nx] = cur;  // 记录前驱（首次发现）
            q.push(nx);
            if (nx == final)
            {
                found = true;
                break;
            }
        }
        if (found)
            break;
    }

    if (!found)
    {
        cout << "No solution" << endl;
        return 0;
    }

    // 重建路径并正序输出
    vector<unsigned> path;
    unsigned x = final;
    path.push_back(x);
    while (x != start)
    {
        x = prev[x];
        path.push_back(x);
    }
    reverse(path.begin(), path.end());
    for (unsigned p : path)
        cout << bitset<4>(p) << '\n';
}
