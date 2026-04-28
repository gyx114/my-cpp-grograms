#include <bits/stdc++.h>
using namespace std;
// 复用84题的单调栈
// 对每一行建立柱状图，转化为84题的求解
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

    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> matrixcp(n);

        int maxarea = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0)
                {
                    matrixcp[j] = matrix[i][j] - '0';
                }
                else
                {
                    matrixcp[j] = matrix[i][j] == '0' ? 0 : matrix[i][j] - '0' + matrixcp[j];
                }
            }
            int area = largestRectangleArea(matrixcp);
            maxarea = max(maxarea, area);
        }
        return maxarea;
    }
};
