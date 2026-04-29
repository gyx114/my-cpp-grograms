#include <bits/stdc++.h>
using namespace std;

// 与以往的回溯不太相同，之前的回溯都是值，可以copy到ans中
// 但是这个是一个个节点的指针，即使copy过去，之后撤销操作也会修改ans
// 因此我们不能全局使用一个中间变量来储存生成的树
// 这就表明，每次深入，我们都要生成若干head指针，来存每个可能的树
// 于是便用指针数组来储存回溯结果
// 此时，思路显而易见：分而治之

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
    vector<TreeNode *> backtrack(int begin, int end)
    {
        vector<TreeNode *> ret;
        if (begin > end)
        {
            ret.push_back(nullptr);
            return ret;
        }
        else
        {
            for (int i = begin; i <= end; i++)
            {

                auto lft = backtrack(begin, i - 1);
                auto rht = backtrack(i + 1, end);
                for (auto l : lft)
                {
                    for (auto r : rht)
                    {
                        TreeNode *head = new TreeNode(i);
                        head->left = l;
                        head->right = r;
                        ret.push_back(head);
                    }
                }
            }
            return ret;
        }
    }

    vector<TreeNode *> generateTrees(int n)
    {
        return backtrack(1, n);
    }
};
