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
    ListNode *insertionSortList(ListNode *head)
    {
        auto dummy = new ListNode(-10000, head);
        auto tmp = head;
        auto tmp_pre = dummy;
        while (tmp)
        {
            auto pre = dummy;
            for (; pre != tmp; pre = pre->next)
            {
                if (tmp->val >= pre->val && tmp->val < pre->next->val)
                {
                    tmp_pre->next = tmp->next;
                    tmp->next = pre->next;
                    pre->next = tmp;
                    tmp = tmp_pre->next;
                    break;
                }
            }
            if (pre == tmp)
            {
                tmp_pre = tmp;
                tmp = tmp->next;
            }
        }
        return dummy->next;
    }
};
