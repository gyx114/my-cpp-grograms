#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    stack<int> st;
    int trap(vector<int> &height)
    {
        int ans = 0;
        for (int i = 0; i < height.size(); i++)
        {
            if (st.empty() || height[i] <= height[st.top()])
            {
                st.push(i);
            }
            else
            {
                while (!st.empty() && height[i] > height[st.top()])
                {
                    int tmp = st.top();
                    st.pop();
                    if (st.empty())
                    {
                        break;
                    }
                    int min_height = min(height[i], height[st.top()]);
                    ans += (min_height - height[tmp]) * (i - st.top() - 1);
                }
                st.push(i);
            }
        }
        return ans;
    }
};
