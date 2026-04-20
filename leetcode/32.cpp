#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int max_len = 0;
        stack<int> st;
        st.push(-1); // 初始化栈，设置初始边界

        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(')
            {
                st.push(i); // 左括号，压入索引
            }
            else
            {
                st.pop(); // 右括号，弹出栈顶（可能是左括号或之前的边界）
                if (st.empty())
                {
                    st.push(i); // 栈为空，说明当前右括号无匹配，压入当前索引作为新边界
                }
                else
                {
                    max_len = max(max_len, i - st.top()); // 计算当前有效长度
                }
            }
        }

        return max_len;
    }
};
