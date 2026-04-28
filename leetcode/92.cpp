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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (left == right || head->next == nullptr)
        {
            return head;
        }
        ListNode *dummy = new ListNode(0, head);
        ListNode *l = head;
        ListNode *ll = dummy;
        ListNode *r = head;
        ListNode *pre = dummy;
        ListNode *tmp = head;
        ListNode *aft = head->next;
        for (int i = 1;; i++)
        {
            if (i < left)
            {
                l = l->next;
                ll = ll->next;
            }
            if (i < right)
            {
                r = r->next;
            }
            if (i > left && i <= right)
            {
                tmp->next = pre;
                pre = tmp;
                tmp = aft;
                if (aft)
                    aft = aft->next;
            }
            else if (i == right + 1)
            {
                ll->next = r;
                l->next = tmp;
                return dummy->next;
            }
            else
            {
                pre = pre->next;
                tmp = tmp->next;
                if (aft)
                    aft = aft->next;
            }
        }
        return dummy->next;
    }
};
