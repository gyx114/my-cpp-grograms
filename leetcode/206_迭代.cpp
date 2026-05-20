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
    ListNode *reverseList(ListNode *head)
    {
        if (!head)
        {
            return nullptr;
        }
        ListNode *pre = nullptr;
        auto tmp = head;
        auto nxt = head->next;
        while (tmp)
        {
            tmp->next = pre;
            pre = tmp;
            tmp = nxt;
            if (nxt)
            {
                nxt = nxt->next;
            }
        }
        return pre;
    }
};
