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
    vector<TreeNode *> roots;
    deque<vector<int>> ans_dq;
    void bfs()
    {
        if (roots.empty())
        {
            return;
        }
        vector<int> tmp;
        vector<TreeNode *> tmp_rt;
        tmp_rt.reserve(roots.size());
        tmp.reserve(roots.size());
        for (auto r : roots)
        {
            tmp.push_back(r->val);
            if (r->left)
            {
                tmp_rt.push_back(r->left);
            }
            if (r->right)
            {
                tmp_rt.push_back(r->right);
            }
        }
        ans_dq.push_front(move(tmp));
        roots.swap(tmp_rt);
        bfs();
    }

    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        roots.push_back(root);
        vector<vector<int>> ans;
        if (root == nullptr)
        {
            return ans;
        }
        bfs();
        ans.assign(make_move_iterator(ans_dq.begin()), make_move_iterator(ans_dq.end()));
        return ans;
    }
};
