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

class BSTIterator
{
private:
    stack<TreeNode *> st;
    TreeNode *tmp;

public:
    BSTIterator(TreeNode *root)
    {
        tmp = root;
        while (tmp)
        {
            st.push(tmp);
            tmp = tmp->left;
        }
    }

    int next()
    {
        tmp = st.top();
        st.pop();
        int ret = tmp->val;
        if (tmp->right)
        {
            tmp = tmp->right;
            while (tmp)
            {
                st.push(tmp);
                tmp = tmp->left;
            }
        }

        return ret;
    }

    bool hasNext()
    {
        return (!st.empty());
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
