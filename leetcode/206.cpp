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
    // 反转后头，尾
    pair<ListNode *, ListNode *> rev(ListNode *head)
    {
        if (!head->next)
        {
            return {head, head};
        }
        auto [h, t] = rev(head->next);
        head->next = nullptr;
        t->next = head;
        return {h, head};
    }

    ListNode *reverseList(ListNode *head)
    {
        if (!head)
        {
            return nullptr;
        }
        return rev(head).first;
    }
};
