#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    TreeNode *mktree(ListNode *&head, int len)
    {
        if (len <= 0)
        {
            return nullptr;
        }
        TreeNode *root = new TreeNode();
        if (len == 1)
        {
            root->val = head->val;
            head = head->next;
            return root;
        }

        root->left = mktree(head, (len - 1) / 2);
        root->val = head->val;
        head = head->next;
        root->right = mktree(head, len / 2);
        return root;
    }
    TreeNode *sortedListToBST(ListNode *head)
    {
        int len = 0;
        auto tmp = head;
        while (tmp != nullptr)
        {
            tmp = tmp->next;
            len++;
        }
        return mktree(head, len);
    }
};
