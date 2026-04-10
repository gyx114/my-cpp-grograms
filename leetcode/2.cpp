#include <bits/stdc++.h>

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
    ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
    {
        ListNode ans;
        ListNode *head = &ans;
        ListNode *tmp_ans = head;
        ListNode *tmp1 = l1;
        ListNode *tmp2 = l2;

        int jinwei = 0;
        int zhi = 0;
        while (tmp1 != nullptr || tmp2 != nullptr)
        {
            tmp_ans->next = new ListNode();
            tmp_ans = tmp_ans->next;
            int add = 0;

            if (tmp1 == nullptr)
            {
                add = tmp2->val + jinwei;
            }
            else if (tmp2 == nullptr)
            {
                add = tmp1->val + jinwei;
            }

            else
            {
                add = tmp1->val + tmp2->val + jinwei;
            }
            zhi = add % 10;
            jinwei = add / 10;

            tmp_ans->val = zhi;
            if (tmp1)
            {
                tmp1 = tmp1->next;
            }
            if (tmp2)
            {
                tmp2 = tmp2->next;
            }
        }
        if (jinwei != 0)
        {
            tmp_ans->next = new ListNode();
            tmp_ans = tmp_ans->next;
            tmp_ans->val = jinwei;
        }
        else
        {
            tmp_ans->next = nullptr;
        }

        return head->next;
    }
};
