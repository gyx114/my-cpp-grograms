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
    // 定一变一
    // 总是从左到右存节点
    // 遍历时再考虑方向
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (root == nullptr)
        {
            return vector<vector<int>>();
        }
        vector<vector<int>> ans;

        deque<TreeNode *> nodes = {root};
        bool ltor = true;
        while (!nodes.empty())
        {
            vector<int> tmp;
            deque<TreeNode *> tmp_nd;
            if (ltor)
            {
                for (auto p : nodes)
                {
                    tmp.push_back(p->val);
                    if (p->left)
                    {
                        tmp_nd.push_back(p->left);
                    }
                    if (p->right)
                    {
                        tmp_nd.push_back(p->right);
                    }
                }
                ltor = !ltor;
            }
            else
            {
                for (auto it = nodes.rbegin(); it != nodes.rend(); it++)
                {
                    tmp.push_back((*it)->val);
                    if ((*it)->right)
                    {
                        tmp_nd.push_front((*it)->right);
                    }
                    if ((*it)->left)
                    {
                        tmp_nd.push_front((*it)->left);
                    }
                }
                ltor = !ltor;
            }
            ans.push_back(move(tmp));
            nodes.swap(tmp_nd);
        }
        return ans;
    }
};
