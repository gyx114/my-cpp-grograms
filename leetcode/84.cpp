#include <bits/stdc++.h>
using namespace std;
// 单调栈，和42题类似
// 对于某个柱子，其“扩散”范围就是从它开始，左右两边连续的高度比它高的所有柱子
// 因此我们只需找到其两侧第一个比它小的柱子A,B
// 则AB之间(不含A,B)就是其扩散范围(width)
// 由于周围柱子都比它高
// 那么这个扩散出来的矩形的高度height就是这根柱的高度
// 如何找那两个边界
// 维护一个递增栈即可

// 两边找小的，用递增栈
// 两边找大的，用递减栈
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> st;
        int tmp;
        int maxarea = 0;
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
