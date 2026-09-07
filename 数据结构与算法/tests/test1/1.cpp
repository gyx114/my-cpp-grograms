#include <iostream>
#include "my_vector.hpp"
using namespace std;

void dfs(my_vector<int> &vec, int val /*原序列价值*/, int cnt /*序列中已有几个*/, int idx, int &ans)
{
    if (idx == vec.size())
    {
        return;
    }

    int cur_val = val;

    // 不选当前
    dfs(vec, cur_val, cnt, idx + 1, ans);

    // 选当前
    cur_val = val + (cnt + 1) * vec[idx];
    ans ^= cur_val;
    dfs(vec, cur_val, cnt + 1, idx + 1, ans);
}

int main()
{
    int n;
    cin >> n;
    my_vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    int ans = 0;
    dfs(vec, 0, 0, 0, ans);
    cout << ans << endl;
}
