#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int trap(vector<int> &height)
    {
        stack<int> st;
        int total = 0;
        for (int i = 0; i < height.size(); i++)
        {
            if (st.empty() || height[i] < height[st.top()])
            {
                st.push(i);
            }
            else
            {
                int hei = 0;

                while (!st.empty() && height[i] > height[st.top()])
                {
                    int h = height[st.top()];
                    st.pop();
                    hei = st.empty() ? 0 : min(height[st.top()], height[i]) - h;
                    int width = st.empty() ? 0 : i - st.top() - 1;
                    total += width * hei;
                }
                st.push(i);
            }
        }
        return total;
    }
};
