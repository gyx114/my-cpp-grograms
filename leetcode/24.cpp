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
    ListNode *swapPairs(ListNode *head)
    {

        if (head == nullptr)
        {
            return head;
        }

        ListNode *fst = head;
        ListNode *snd = head->next;
        if (snd == nullptr)
        {
            return head;
        }
        else
        {
            ListNode *tmp = snd->next;
            snd->next = fst;
            fst->next = swapPairs(tmp);
            return snd;
        }
    }
};
