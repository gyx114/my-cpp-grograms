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

class Solution
{
public:
    vector<ListNode *> idx_to_node;
    void change(int beg, int len)
    {
        if (len <= 2)
        {
            idx_to_node[beg + len - 1]->next = nullptr;
            return;
        }
        idx_to_node[beg + len - 1]->next = idx_to_node[beg]->next;
        idx_to_node[beg]->next = idx_to_node[beg + len - 1];
        change(beg + 1, len - 2);
    }

    void reorderList(ListNode *head)
    {
        int len = 0;
        auto tmp = head;
        while (tmp != nullptr)
        {
            idx_to_node.push_back(tmp);
            len++;
            tmp = tmp->next;
        }
        change(0, len);
    }
};
