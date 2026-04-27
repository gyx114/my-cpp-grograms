#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> st;
        int tmp;
        int maxarea = heights[0];
        for (int i = 0; i <= heights.size(); i++)
        {

            int h = (i == heights.size()) ? 0 : heights[i];

            int j;
            while (!st.empty() && h < heights[st.top()])
            {
                int height = heights[st.top()];
                st.pop();

                int width;
                if (!st.empty())
                {
                    width = i - st.top() - 1;
                }
                else
                {
                    width = i;
                }
                maxarea = max(maxarea, width * height);
            }
            st.push(i);
        }
        return maxarea;
    }
};
