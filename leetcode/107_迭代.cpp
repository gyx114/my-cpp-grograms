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
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        deque<vector<int>> ansdq;
        vector<vector<int>> ans;
        if (root == nullptr)
        {
            return ans;
        }
        vector<TreeNode *> nodes = {root};
        while (!nodes.empty())
        {
            vector<int> tmp;
            tmp.reserve(nodes.size());
            vector<TreeNode *> tmpnd;
            tmpnd.reserve(nodes.size());

            for (auto r : nodes)
            {
                tmp.push_back(r->val);
                if (r->left)
                {
                    tmpnd.push_back(r->left);
                }
                if (r->right)
                {
                    tmpnd.push_back(r->right);
                }
            }
            ansdq.push_front(move(tmp));
            nodes.swap(tmpnd);
        }

        ans.assign(make_move_iterator(ansdq.begin()), make_move_iterator(ansdq.end()));
        return ans;
    }
};
