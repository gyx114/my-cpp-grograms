#include <iostream>
#include <vector>
using namespace std;

void back_track(vector<int> &vec, vector<bool> &is_chosen, int cnt, int val, int &ans)
{
    if (cnt == vec.size())
    {
        ans |= val;
        return;
    }

    for (int i = 0; i < vec.size(); i++)
    {
        if (!is_chosen[i])
        {
            is_chosen[i] = true;
            int cur_val = val + ((cnt + 1) ^ vec[i]); // 注意优先级。。。。。
            back_track(vec, is_chosen, cnt + 1, cur_val, ans);
            is_chosen[i] = false;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    int ans = 0;
    vector<bool> is_chosen(n, false);
    back_track(vec, is_chosen, 0, 0, ans);
    cout << ans << endl;
}
