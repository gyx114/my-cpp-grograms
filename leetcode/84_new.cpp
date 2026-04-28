#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int maxarea = 0;
        stack<int> st;
        for (int i = 0; i <= heights.size(); i++)
        {
            int hi = i == heights.size() ? 0 : heights[i];
            if (st.empty() || hi > heights[st.top()])
            {
                st.push(i);
            }
            else
            {

                while (!(st.empty() || hi > heights[st.top()]))
                {

                    int height = heights[st.top()];
                    st.pop();
                    int width = st.empty() ? i - (-1) - 1 : i - st.top() - 1;

                    maxarea = max(maxarea, width * height);
                }
                st.push(i);
            }
        }

        return maxarea;
    }
};
