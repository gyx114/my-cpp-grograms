#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    // 中序遍历递增
    int kthSmallest(TreeNode *root, int k)
    {
        auto tmp = root;
        stack<TreeNode *> st;
        int cnt = 0;
        while (!st.empty() || tmp)
        {
            while (tmp)
            {
                st.push(tmp);
                tmp = tmp->left;
            }
            if (!st.empty())
            {
                cnt++;
                if (cnt == k)
                {
                    return st.top()->val;
                }
                tmp = st.top()->right;
                st.pop();
            }
        }
        return 0;
    }
};
